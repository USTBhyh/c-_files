#include <iostream>
#include <cmath>
using namespace std;
double a[5];
#define EPS 1e-6;
//判断是否为0，用于浮点是否相等比较
bool iszero(double x)
{
    return fabs(x) <= EPS;
}
bool get24(double a[], int n)
{ //用数组a里的n个数计算24
    if (n == 1)
    {
        if (iszero(a[0] - 24))
        {
            return true;
        }
        else
            return false;
    }
    double b[5]; //临时数组
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) //遍历取两个数的所有情况
        {
            // n-2个数存入到临时数组中
            int m = 0;
            for (int k = 0; k < n; k++)
                if (k != i && k != j)
                    b[m++] = a[k];
            //对取出的两个数进行四则运算,并进行递归操作
            b[m] = a[i] + a[j];
            if (get24(b, m + 1))
                return true;
            b[m] = a[i] - a[j];
            if (get24(b, m + 1))
                return true;
            b[m] = a[i] * a[j];
            if (get24(b, m + 1))
                return true;
            //除法运算要考虑除数是否为0
            if (!(iszero(a[i])))
            {
                b[m] = a[j] / a[i];
                if (get24(b, m + 1))
                    return true;
            }
            if (!(iszero(a[j])))
            {
                b[m] = a[i] / a[j];
                if (get24(b, m + 1))
                    return true;
            }
        }
    return false;
}
int main()
{
    double a[100][5];
    for (int i = 0;; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
        if (a[i][0] == 0 || a[i][1] == 0 || a[i][2] == 0 || a[i][3] == 0)
            break;
    }

    for (int i = 0;; i++)
    {
        if (a[i][0] == 0 || a[i][1] == 0 || a[i][2] == 0 || a[i][3] == 0)
            break;
        else
        {
            if (get24(a[i], 4))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}