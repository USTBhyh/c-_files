/*
    屏幕的输出: 之前我们学习和使用的输出就是cout，如果要在指定位置上输出字符，会出现两
个问题，之前输出的内容一直还在，屏幕上始终有光标会闪烁，因此需要在输出的时候，要配合其
他的输出操作。
        ·使用gotoxy函数，将光标移动到(x,y)位置。这样，就不需要一直清屏，但是光标的闪烁
    的问题，可以利用隐藏光标函数HideCursor()。完成上述两个函数需要#include <windows.h>，
    用到了一些windows提供的API函数。
*/
#include <windows.h>
void gotoXY(int x, int y) //光标移动到(x,y)位置
{
COORD pos = { x,y };
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
SetConsoleCursorPosition(hOut, pos);//两参数分别是指定哪个窗体，具体位置
}
void HideCursor()
{
CONSOLE_CURSOR_INFO cursor_info = { 1,0 };//第二个值为0表示隐藏光标
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
