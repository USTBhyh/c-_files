/**
@File    :   2_3Climb_stairs.cpp
@Time    :   2022/03/29 00:24:35
@Author  :   hyh
@Version :   1.0
@Contact :   1360895771@qq.com
@Desc    :   爬楼梯(一次一层或两层)
**/

#include <iostream>
using namespace std;
int N;
int stars(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return stars(n - 1) + stars(n - 2);
}
int main()
{
    while(cin >> N){
        cout<<stars(N)<<endl;
    }
    return 0;
}
