#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
    int i, j;                                       //循环变量
    int x = 5, y = 10;                              //小球坐标
    int v_x = 1, v_y = 1;                           //小球运动速度
    int right = 20, left = 0, top = 0, bottom = 20; //边界
    while (1)
    {
        system("cls");
        for (i = 0; i < x; i++)
            cout << endl;
        for (j = 0; j < y; j++)
            cout << " ";
        cout << "o";
        Sleep(50);
        x = x + v_x;
        y = y + v_y;
        if (x >= bottom || x <= top)
        {
            v_x = -v_x;
            cout << "\a";
        }

        if (y >= right || y <= left)
        {
            v_y = -v_y;
            cout << "\a";
        }
    }
    return 0;
}