#include<iostream>
using namespace std;
class StackNode {
public:
	char value;//值
	StackNode* next;
	StackNode(char value){
		this->value = value;
		this->next = NULL;
	}
	//遍历链式栈
	void outStack();
	//创建一个空栈
	void initStack(StackNode* s);
	//入栈
	void push(char value);
	//出栈
	void pop();
};

//遍历
void StackNode::outStack() {
	StackNode* p = this->next;
	while (p != NULL) {
		cout << p->value << " ";
		p = p->next;
	}
	cout << "全部输出完毕" << endl;
}

//初始化
void StackNode::initStack(StackNode* s) {
	s->next = NULL;
	cout << "创建空栈成功！" << endl;
}

//入栈
void StackNode::push(char value) {
	//将值为value压入链式栈中

	//创建一个新的节点 
	StackNode* p = new StackNode(value);

	p->next = this->next;

	//栈顶指针改变为新的节点
	this->next = p;

	cout << "插入成功！" << endl;
}

//出栈
void StackNode::pop() {

	if (this->next == NULL) {
		cout << "请检查操作，该链栈为空！" << endl;
		return;
	}

	//直接将链式栈的栈顶指针指向的结点弹出即可
	this->next = this->next->next;
	cout << "出栈成功" << endl;
	this->outStack();
}


int main() {
	
	int op = 0;
	StackNode* s = new StackNode(-1);
	cout << "1、创建一个空栈  2、入栈操作  3、出栈操作 4、遍历操作 5、退出" << endl;
	cin >> op;
	char value = '0';
	while (op != 5) {
		switch (op)
		{
		case 1:
			s->initStack(s);
			break;
		case 2:
			cout << "输入#以停止操作" << endl;
			while (value != '#') {
				cout << "请输入要入栈的元素的值" << endl;
				cin >> value;
				if (value == '#') {
					value = '0';
					break;
				}
				s->push(value);
			}
			break;
		case 3:
			s->pop();
			break;
		case 4:
			s->outStack();
		}

		cout << "1、创建一个空栈  2、入栈操作  3、出栈操作 4、遍历操作 5、退出" << endl;
		cin >> op;
	}
	
	system("pause");
	return 0;
}
