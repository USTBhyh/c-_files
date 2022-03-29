/**
@File    :   1_8Expression_evaluation.cpp
@Time    :   2022/03/29 00:03:52
@Author  :   hyh
@Version :   1.0
@Contact :   1360895771@qq.com
@Desc    :   表达式求值（递归求解）\\说明：如(1*2)+(2/4)为一个表达式；其中，1*2和2/4为项；1,2,2,4为因子；需要注意的是
             因子也可能是括号内的表达式或项。
**/

#include <iostream>
#include <string>
using namespace std;
int factor_value();     //因子求值（因子可能是数字--递归出口；也可能是一个（表达式））
int term_value();       //项求值（项由因子组成）
int expression_value(); //表达式求值（表达式由项构成）
int main()
{
    cout << expression_value() << endl;
    return 0;
}

int expression_value() //表达式由项构成
{
    int result = term_value(); //求第一项的值
    bool more = true;          //不止一项
    while (more)
    {
        char op = cin.peek(); //看一个字符，但是不取走
        if (op == '+' || op == '-')
        {
            cin.get(); //从cin中取走一个字符
            int value = term_value();
            if (op == '+')
                result += value;
            else
                result -= value;
        }
        else
            more = false;
    }
    return result;
}

int term_value() //项由因子构成
{
    int result = factor_value(); //求第一个因子的值
    while (true)
    {
        char op = cin.peek();
        if (op == '*' || op == '/')
        {
            cin.get();
            int value = factor_value();
            if (op == '*')
                result *= value;
            else
                result /= value;
        }
        else
            break;
    }
    return result;
}

int factor_value() //因子由数字或表达书构成
{
    int result = 0;
    char c = cin.peek();
    if (c == '(')
    {
        cin.get();
        result = expression_value();
        cin.get();
    }
    else
    {
        while (isdigit(c))
        {
            result = 10 * result + c - '0';
            cin.get();
            c = cin.peek();
        }
    }
    return result;
}