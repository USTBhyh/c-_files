/**
@File    :   prac8.cpp
@Time    :   2022/03/25 14:14:39
@Author  :   hyh
@Version :   1.0
@Contact :   1360895771@qq.com
@Desc    :   十以内的加减乘除运算
**/


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
	~Stack(){};
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
	if (top >= maxsize - 1)
		;
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
class iStack
{
private:
	float post[1001] = {0};
	int top;

public:
	bool Emptystack();
	float Pop();
	void Push(float x);
	void Clearstack();
	float Getstop();
	iStack() { top = -1; };
	~iStack(){};
};
//栈空检测
bool iStack::Emptystack()
{
	if (top == -1)
		return 1;
	return 0;
}
//出栈
float iStack::Pop()
{
	if (Emptystack())
		return 0;
	else
	{
		float a = post[top];
		top--;
		return a;
	}
}
//进栈
void iStack::Push(float x)
{
	if (top >= maxsize - 1)
		;
	else
	{
		top++;
		post[top] = x;
	}
}
//置空栈
void iStack::Clearstack()
{
	while (top != -1)
	{
		Pop();
	}
	top = -1;
}
//取栈顶
float iStack::Getstop()
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
/***************/
/*符号优先级比较*/
/***************/
int Precede(char x, char y)
{
	int m = -1, n = -1;
	switch (x)
	{
	case '(':
		m = 0;
		break;
	case '+':
	case '-':
		m = 1;
		break;
	case '*':
	case '/':
		m = 2;
		break;
	}
	switch (y)
	{
	case '+':
	case '-':
		n = 1;
		break;
	case '*':
	case '/':
		n = 2;
		break;
	case ')':
		n = 3;
		break;
	default:
		break;
	}
	if (m >= n)
		return 1;
	else
		return 0;
}
/***************/
/***中后序转换***/
/***************/
void mid_post(char post[], char mid[])
{
	int i = 0, j = 0;
	char x;
	Stack S = Stack();
	do
	{
		x = mid[i++];
		switch (x)
		{
		case '\0':
		{
			while (!S.Emptystack())
				post[j++] = S.Pop();
			post[j] = '\0';
		}
		break;
		case ')':
		{
			while (S.Getstop() != '(')
			{
				post[j++] = S.Pop();
				S.Pop();
			}
		}
		break;
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		{
			while (Precede(S.Getstop(), x))
			{
				post[j++] = S.Pop();
			}
			S.Push(x);
		}
		break;
		default:
			post[j++] = x;
			break;
		}

	} while (x != '\0');
}
/***************/
/*后缀表达式求值*/
/***************/
int postcount(char post[])
{
	int i = 0;
	char x;
	float z, a, b;
	iStack S = iStack();
	while (post[i] != '\0')
	{
		x = post[i];
		switch (x)
		{
		case '+':
			b = S.Pop();
			a = S.Pop();
			z = a + b;
			S.Push(z);
			break;
		case '-':
			b = S.Pop();
			a = S.Pop();
			z = a - b;
			S.Push(z);
			break;
		case '*':
			b = S.Pop();
			a = S.Pop();
			z = a * b;
			S.Push(z);
			break;
		case '/':
			b = S.Pop();
			a = S.Pop();
			z = a / b;
			S.Push(z);
			break;
		default:
			x = post[i] - '0';
			S.Push(x);
		}
		i++;
	}
	if (!S.Emptystack())
		return (S.Getstop());
}
int main()
{
	char expression[1001], post[1001];
	cin >> expression;
	mid_post(post, expression);
	cout << postcount(post);
	return 0;
}