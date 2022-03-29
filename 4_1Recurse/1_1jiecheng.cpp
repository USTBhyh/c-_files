#include <iostream>
using namespace std;
/*
 * Title: 阶乘的实现
 * Description:
 *      递归解法
 *      非递归解法
 */
//递归实现
int f(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * f(n - 1);
}
//非递归实现
int f_loop(int n)
{
    long result = n;
    while (n > 1)
    {
        n--;
        result = result * n;
    }
    return result;
}

int main()
{
    cout<<f(10)<<endl;
    cout<<f_loop(10);
    return 0;
}