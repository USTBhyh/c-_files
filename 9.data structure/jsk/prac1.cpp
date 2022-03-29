#include <iostream>
using namespace std;
int main()
{
    int m, n, num;
    cin >> m;
    int *a1 = new int[m];
    for (int i = 0; i < m; i++)
        cin >> a1[i];
    cin >> n;
    int *a2 = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a2[i];
    int *a3 = new int[50];
    int k = 0;

    if (n > m)
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (a1[i] == a2[j])
                {
                    a3[k++] = a1[i];
                }
            }
    }
    else
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (a1[j] == a2[i])
                {
                    a3[k++] = a1[i];
                }
            }
    }
    for (int i = 0; i < k - 1; i++)
        cout << a3[i] << " ";
    cout << a3[k - 1];
    return 0;
}