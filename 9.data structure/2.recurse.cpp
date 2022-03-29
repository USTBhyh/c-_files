#include <iostream>
using namespace std;
//递归求1+2+3+……+N
int sum_r(int N)
{
    if (N == 1)
        return 1;
    else
    {
        return N + sum_r(N - 1);
    }
}
//递归求N个数的最大值
int max_r(int num[], int n)
{
    if (n == 1)
        return num[0];
    return max(num[n], max_r(num, n - 1));
}
//递归求数列倒序
void reverse(int a[],int i)
{
    if(i>0){
        cout<<a[i-1];
        reverse(a,--i);
    }
}
int main()
{
    int n;
    cin >> n;
    // cout<<sum_r(n);

    int *num = new int[n];
    for (int i = 0; i < n; i++)
        cin >> num[i];
    //cout << max_r(num, n);
    reverse(num,n);
    return 0;
}