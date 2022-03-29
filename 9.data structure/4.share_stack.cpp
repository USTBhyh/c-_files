/**
@File    :   4.share_stack.cpp
@Time    :   2022/03/25 14:08:48
@Author  :   hyh
@Version :   1.0
@Contact :   1360895771@qq.com
@Desc    :   共享栈的实现
**/

#include <iostream>
using namespace std;

#define maxsize 1000
class share_stack
{
private:
    char data[maxsize];
    int top1=-1;//栈1指针
    int top2=maxsize;//栈2指针
public:
    share_stack(){};
    ~share_stack(){};
    int push1(char x);
    int push2(char x);
    char pop1();
    char pop2();
};
//栈1进栈
int share_stack::push1(char x)
{
    if(top2-top1>=2)
    {
        top1++;
        data[top1]=x;
        return 1;
    }else 
    return 0;
}
//栈2进栈
int share_stack::push2(char x)
{
    if(top2-top1>=2)
    {
        top2--;
        data[top2]=x;
        return 1;
    }else 
    return 0;
}
//栈1出栈
char share_stack::pop1()
{
    if(top1==-1)return NULL;
    else{
        top1--;
        return data[top1+1];
    }
}
//栈2出栈
char share_stack::pop2()
{
    if(top2==maxsize)return NULL;
    else{
        top1++;
        return data[top1-1];
    }
}