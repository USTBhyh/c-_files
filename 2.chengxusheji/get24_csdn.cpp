#include <iostream>

using namespace std;

void init();
int calc(int n);
int x, y;
int a[4];

int main()
{
    int i, j, k, l, m;
    int b[3];

    init();

    for (l = 0; l < 3; l++)
    {
        x = a[l];
        y = a[l + 1];
        for (m = 0; m < 3; m++)
        {
            b[l] = calc(m);
            int z = b[l];
            b[(l + 1) % 3] = a[(l + 2) % 4];
            b[(l + 2) % 3] = a[(l + 3) % 4];
            for (i = 0; i < 2; i++)
            {
                x = b[i];
                y = b[i + 1];
                for (j = 0; j < 3; j++)
                {
                    x = calc(j);
                    y = b[(i + 2) % 3];
                    for (k = 0; k < 3; k++)
                    {
                        if (calc(k) == 24)
                        {
                            cout << "Yes" << endl;
                            return 0;
                        }
                    }
                    x = b[i];
                    y = b[i + 1];
                }
                x = a[l];
                y = a[l + 1];
            }
        }
    }
    cout << "No" << endl;
    return 0;
}

int calc(int n)
{
    if (n == 0)
    {
        return (x + y);
    }
    else if (n == 1)
    {
        return (x - y);
    }
    else if (n == 2)
    {
        return (x * y);
    }
}

void init()
{
    int i;

    for (i = 0; i < 4; i++)
    {
        cin >> a[i];
    }
}