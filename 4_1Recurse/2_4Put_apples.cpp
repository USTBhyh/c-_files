/**
@File    :   2_4Put_apples.cpp
@Time    :   2022/03/29 00:35:32
@Author  :   hyh
@Version :   1.0
@Contact :   1360895771@qq.com
@Desc    :   放苹果
**/
//说明：i个苹果，放k个盘子；k>i时,f(i,k)=f(i,i);k<=i时,f(i,k)=f(i,k-1)+f(i-k,k)
//(有盘子为空的情况加全不空的情况)

#include <iostream>
using namespace std;
int appleput(int m, int n)
{
    if (n > m)
        return appleput(m, m);
    if (m == 0)
        return 1;
    if (n == 0)
        return 0;
    return appleput(m - n, n) + appleput(m, n - 1);
}
int main()
{
    int m, n, t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        cout << appleput(m, n) << endl;
    }

    return 0;
}
