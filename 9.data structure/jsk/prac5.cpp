/**
 *计蒜客：通话记录
 *已知不超过 50 条通话记录，通话记录有三种类型：0 代表未接来电，1 代表已接来电，2 代表已拨电话。要求分别将三种类型
 前 10 条通话记录以三列的形式输出。

 *输入格式
 *输入不超过 50 条通话记录，每条通话记录都占一行。每一行的第一个数字代表通话记录的类型，第二个数字代表电话号码，
 电话号码均由 11 个数字组成。他们之间用一个空格隔开。

 *输出格式
 *分三列输出未接来电、已接电话和已拨电话。
 *每列之间用一个空格分割，最后一列后没有空格。每种类型输出前十个电话，先出现的通话记录先输出，不足十个的用 0 占位。

 *解题思路
 *用三个队列分别存储三种类型的通话记录，在输出时对队列的size进行判断。(大于10则依次输出，否则添0)
**/
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
class MyQueue
{
private:
    vector<string> data;
    int p_start;

public:
    MyQueue() { p_start = 0; }

    bool enQueue(string x)
    {
        data.push_back(x);
        return true;
    }
    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }
        p_start++;
        return true;
    };
    string Front()
    {
        return data[p_start];
    };

    bool isEmpty()
    {
        return p_start >= data.size();
    }
    int size()
    {
        return data.size() - p_start;
    }
};
int main()
{
    MyQueue q0, q1, q2;
    int type;
    string number;
    /*while (scanf("%d %s", &type, &number) != EOF)
    {
        cout << type << number;
    }*/
    while (cin >> type) //判断输入是否停止
    {
        cin >> number;
        switch (type)
        {
        case 0:
            q0.enQueue(number);
            break;
        case 1:
            q1.enQueue(number);
            break;
        case 2:
            q2.enQueue(number);
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (!q0.isEmpty())
        {
            cout << q0.Front();
            q0.deQueue();
        }
        else
            cout << 0;
        cout << " ";
        if (!q1.isEmpty())
        {
            cout << q1.Front();
            q1.deQueue();
        }
        else
            cout << 0;
        cout << " ";
        if (!q2.isEmpty())
        {
            cout << q2.Front();
            q2.deQueue();
        }
        else
            cout << 0;
        cout << endl;
    }
}