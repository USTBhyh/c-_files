/**
@File    :   fakecoin.cpp
@Time    :   2022/03/25 00:27:00
@Author  :   hyh
@Version :   1.0
@Contact :   1360895771@qq.com
@Desc    :   称硬币，与传统不同，该题为给出三次称量的结果，然后枚举得出那一枚是假币
**/

#include <iostream>
#include <cstring>
using namespace std;
char Left[3][7];                //天平左边硬币
char Right[3][7];               //天平右边硬币
char result[3][7];              //称量结果
bool Isfake(char c, bool light) // light==1:假币是轻的；反之假币偏重
{
    char *pleft, *pright;
    for (int i = 0; i < 3; i++)
    {
        if (light)
        {
            pleft = Left[i];
            pright = Right[i];
        }
        else
        {
            pleft = Right[i];
            pright = Left[i];
        }
        switch (result[i][0])
        {
        case 'u':
            if (strchr(pright, c) == NULL)
                return false;
            break;
        case 'e':
            if (strchr(pright, c) || strchr(pleft, c))
                return false;
            break;
        case 'd':
            if (strchr(pleft, c) == NULL)
                return false;
            break;
        default:
            break;
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 3; i++)
            cin >> Left[i] >> Right[i] >> result[i];
        for (char c = 'A'; c <= 'L'; c++)
        {
            if (Isfake(c, 1))
            {
                cout << c << " is fake,light";
                break;
            }
            else if (Isfake(c, 0))
            {
                cout << c << "is fake,heavy";
                break;
            }
        }
    }

    return 0;
}
