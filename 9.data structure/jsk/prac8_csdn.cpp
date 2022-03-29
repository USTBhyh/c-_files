/**
@File    :   1.cpp
@Time    :   2022/03/21 22:59:48
@Author  :   hyh
@Version :   1.0
@Contact :   1360895771@qq.com
@Desc    :   逆波兰式—CSDN
**/
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

void getPostfixNotation(); //获得逆波兰式
void initializeOperatorPriority(); //设置操作符优先级
string CharToString(char ch);
bool isOperator(string str); //判断是否为操作符
bool isDigit(char ch);
int processDigit(int input); //处理操作符
void processOperator(int input);
int calculate(char ch);
int stackCalculate(); //计算逆波兰式

stack<char> operators;
map<char, int> opPriority;
stack<int> calStack;
queue<string> postNot;
string expression;

void initializeOperatorPriority()
{
	opPriority['+'] = 1;
	opPriority['-'] = 1;
	opPriority['*'] = 2;
	opPriority['/'] = 2;
	opPriority['('] = 3;
}

bool isDigit(char ch)
{
	bool flag = false;
	if(ch >= '0' && ch <= '9')
		flag = true;
	return flag;
}

bool isOperator(string str)
{
	bool flag = true;
	if (str[0] >= '0' && str[0] <= '9')
		flag = false;
	return flag;
}

string CharToString(char ch)
{
	string temp = " ";
	temp[0] = ch;
	return temp;
}

int processDigit(int input)
{
	string num;
	while (isDigit(expression[input])) //当扫描到数字时，一直扫描下去，直到扫到操作符
	{
		num += expression[input];
		input++;
	}
	postNot.push(num);
	return input;
}

void processOperator(int input)
{
	if (operators.empty())
		operators.push(expression[input]);
	else
	{
		if (expression[input] != ')')
		{
			while ((!operators.empty()) && (opPriority[operators.top()] >= opPriority[expression[input]]) && (operators.top() != '(')) //优先级：操作符栈内元素>=扫描到的操作符
			{
				postNot.push(CharToString(operators.top())); //将元素压入新栈后弹出
				operators.pop(); 
			}
			operators.push(expression[input]);
		}
		else //操作符为右括号时，pop出栈内元素直到遇见左括号
		{
			while (operators.top() != '(')
			{
				postNot.push(CharToString(operators.top()));
				operators.pop();
			}
			operators.pop();
		}
	}
}

void getPostfixNotation()
{
	int i = 0;
	while(i < expression.length())
	{
		if (isDigit(expression[i])) //从左向右扫描，扫描到数字
			i = processDigit(i);
		else
		{
			processOperator(i);
			i += 1;
		}
	}
	while(!operators.empty()) //扫完后弹出操作符栈内所有操作符
	{
		postNot.push(CharToString(operators.top()));
		operators.pop();
	}
}

int stackCalculate()
{
	while (!postNot.empty())
	{
		if (isOperator(postNot.front()))
		{
			int result = calculate(postNot.front()[0]);
			calStack.push(result);
		}
		else
		{
			int num = atoi(postNot.front().c_str());
			calStack.push(num);
		}
		postNot.pop();
	}
	return 0;
}

int calculate(char ch)
{
	int result;
	int r = calStack.top();
	calStack.pop();
	int l = calStack.top();
	calStack.pop();
	switch (ch)
	{
	case '+':
		result = l + r;
		break;
	case '-':
		result = l - r;
		break;
	case '*':
		result = l * r;
		break;
	case '/':
		result = l / r;
		break;
	}
	return result;
}

int main()
{
	cin >> expression;
	initializeOperatorPriority();
	getPostfixNotation();
	stackCalculate();
	cout << calStack.top() << endl;
	return 0;
}