#include <iostream>
#include <string>
#include <cstring>
#include <memory>
using namespace std;
char oriLigjts[5];
char light[5];
char result[5];
//获得c的第i位
int getbit(char c, int i)
{
    return (c >> i) & 1;
}
//设置c的第i位为v
void setbit(char &c, int i, int v)
{
    if (v) // v==1
    {
        c |= (1 << i);
    }
    else // v==0
    {
        c &= ~(1 << i);
    }
}
//周围灯的状态变换（翻转）
void flipbit(char &c, int i)
{
    c ^= (1 << i);
}
//结果展示
void outputresult(int t, char result[])
{
    cout << "PUZZLE #" << t << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << getbit(result[i], j);
            if (j < 5)
                cout << " ";
        }
        cout << endl;
    }
}
int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 6; j++)
            {
                int s; //第i行第j列的灯的状态
                cin >> s;
                setbit(oriLigjts[i], j, s);
            }
        for (int n = 0; n < 64; n++)
        { //枚举第一行所有可能
            int switchs = n;
            memcpy(light, oriLigjts, sizeof(oriLigjts));
            for (int i = 0; i < 5; i++)
            {
                result[i] = switchs;
                for (int j = 0; j < 6; j++)
                {
                    if (getbit(switchs, j))
                    {
                        if (j > 0)
                            flipbit(light[i], j - 1);
                        flipbit(light[i], j);
                        if (j < 5)
                            flipbit(light[i], j + 1);
                    }
                }
                if (i < 5)
                    light[i + 1] ^= switchs;
                switchs = light[i];
            }
            if (light[4] == 0)
            {
                outputresult(t, result);
                break;
            }
        }
    }

    return 0;
}