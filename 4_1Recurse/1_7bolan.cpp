/**
@File    :   1_7bolan.cpp
@Time    :   2022/03/28 23:28:44
@Author  :   hyh
@Version :   1.0
@Contact :   1360895771@qq.com
@Desc    :   波兰表达式（递归求解）
**/

#include <iostream>

using namespace std;

double exp()
{
    char s[20];
    cin >> s;
    switch (s[0])
    {
    case '+':
        return exp() + exp();
    case '-':
        return exp() - exp();
    case '*':
        return exp() * exp();
    case '/':
        return exp() / exp();
    default:
        return atof(s);
        break;
    }
}
int main()
{
    printf("%1f",exp());
    return 0;
}
