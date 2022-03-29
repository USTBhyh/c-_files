/**
@File    :   2_2nprinces.cpp
@Time    :   2022/03/28 21:37:07
@Author  :   hyh
@Version :   1.0
@Contact :   1360895771@qq.com
@Desc    :   N皇后问题（递归解决）
**/
#include <iostream>
#include <cmath>
using namespace std;

int N;
int queenPos[100];
//递归函数
void Nqueen(int k)
{
    int i;
    if (k == N)
    {
        for (i = 0; i < N; i++)
            cout << queenPos[i] + 1 << " ";
        cout << endl;
        return;
    }
    for (i = 0; i < N; i++)
    {
        int j;
        for (j = 0; j < k; j++)
        {
            if (queenPos[j] == i || abs(queenPos[j] - i == abs(k - j)))
                break;
        }
        if(j==k){
            queenPos[k]=i;
            Nqueen(k+1);
        }
    }
}
int main()
{
    cin >> N;
    Nqueen(0); //从第0行开始
    return 0;
}
