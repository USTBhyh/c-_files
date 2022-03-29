#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define maxsize 1001
class Stack
{
private:
	char post[maxsize];
	int top;

public:
	bool Emptystack();
	char Pop();
	void Push(char x);
	void Clearstack();
	char Getstop();
	Stack() { top = -1; };
	~Stack() {};
};
//栈空检测
bool Stack::Emptystack()
{
	if (top == -1)
		return 1;
	return 0;
}
//出栈
char Stack::Pop()
{
	if (Emptystack())
		return 0;
	else
	{
		char a = post[top];
		top--;
		return a;
	}
}
//进栈
void Stack::Push(char x)
{
	if (top >= maxsize - 1);
	else
	{
		top++;
		post[top] = x;
	}
}
//置空栈
void Stack::Clearstack()
{
	top = -1;
}
//取栈顶
char Stack::Getstop()
{
	if (!Emptystack())
	{
		return post[top];
	}
	else
	{
		return 0;
	}
}