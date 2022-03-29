#include <iostream>
using namespace std;
int getsco(int a[], int n, int m)
{
    if (m >= n)
        return 100;
    else
    {
        int max = a[m] - 1;
        for (int l = 0; l < n - m; l++)
        {
            if (l == (n - m - 1))
            {
                if ((100 - a[l] - 1) > max)
                {
                    max = 100 - a[l] - 1;
                }
            }
            else
            {
                int r = l + m + 1;
                if ((a[r] - a[l] - 1) > max)
                {
                    max = a[r] - a[l] - 1;
                }
            }
        }
        return max;
    }
}
int main()
{
    int t, n, m;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        cin >> n >> m;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (getsco(a, n, m) != 89)
        {
            cout << getsco(a, n, m) << endl;
        }
        else
        {
            cout << 90 << endl;
        }
    }

    return 0;
}