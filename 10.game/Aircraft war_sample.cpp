#include <iostream>
#include <conio.h> // _kbhit(), _getch()
#include <windows.h>
#include <random>
using namespace std;
//变量定义
int i, j;                 //循环变量
int x, y;                 //坐标
char input;               //键盘输入
bool isfire = 0;          //开火判断
bool iscrash = 0;         //敌机坠毁判断
int p_x, p_y;             //敌机初始坐标
bool gameover;            //游戏结束判断
int score = 0;            //游戏得分

void gotoxy(int x, int y) //光标移动到(x,y)位置
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void HideCursor() // 用于隐藏光标
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0}; // 第二个值为0表示隐藏光标
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
int main()
{
    HideCursor();
    x = 10;
    y = 5;
    p_x = rand() % 10;
    p_y = 4;
    while (1)
    {
        system("cls");
        if (!iscrash)
        {

            for (i = 0; i < p_x; i++)
                cout << endl;
            for (j = 0; j < p_y; j++)
                cout << " ";
            cout << "\\+/" << endl;
            for (j = 0; j < p_y; j++)
                cout << " ";
            cout << " | " << endl;
        }
        if (!isfire)
        {
            for (i = 0; i < x; i++)
                cout << endl;
        }
        else
        {
            for (i = 0; i < x; i++)
            {
                for (j = 0; j < y; j++)
                    cout << " ";
                cout << "  |" << endl;
                isfire = 0;
                if (y <= p_y && y >= p_y - 2)
                {
                    iscrash = 1;
                    p_y = rand() % 50;
                    iscrash = 0;
                    score++;
                }
            }
        }
        for (j = 0; j < y; j++)
            cout << " ";
        cout << " /=\\" << endl;
        for (j = 0; j < y; j++)
            cout << " ";
        cout << "<<*>>" << endl;
        for (j = 0; j < y; j++)
            cout << " ";
        cout << " * * " << endl;
        cout << "score:" << score;
        if (_kbhit())
        {
            input = _getch();
            if (input == 's' || input == 'S')
                x++;
            if (input == 'w' || input == 'W')
                x--;
            if (input == 'a' || input == 'A')
                y--;
            if (input == 'd' || input == 'D')
                y++;
            if (input == ' ')
                isfire = 1;
        }
    }

    return 0;
}