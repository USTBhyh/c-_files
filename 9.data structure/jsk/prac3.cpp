/**
 *计蒜客：单向循环列表变双向
 *已知有一个单向循环链表，其每个结点中含三个域：prior，data 和 next，其中 data 域为数据域，
 next 为指向后继结点的指针域，prior 也为指针域，但它的值为空 (NULL) ，试编写算法将此单向循
 环链表改为双向循环链表，即使 prior 成为指向前驱结点的指针域。

 *输入格式
 *输入共有三行，第一行为该单向循环链表的长度 n。
 *第二行为该单向循环链表的各个元素 a它们各不相同且都为数字。
 *第三行为一个数字 m，表示链表中的一个元素值，要求输出时以该元素为起点反向输出整个双向链表。

 *输出格式
 *输出为一行，即完成双向链表后以反向顺序输出该链表，每两个整数之间一个空格，最后一个整数后面没有空格。
 
 *解题思路
 *双向链表
**/
#include <iostream>
using namespace std;
class MyLinkedList
{
public:
    struct node
    {
        int val;
        node *pre;
        node *next;
        node(int _val)
        {
            val = _val;
            pre = NULL;
            next = NULL;
        }
    };
    int size;
    node *head;
    node *tial;

    MyLinkedList()
    {
        size = 0;
        head = new node(0);
        tial = head;
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;
        node *cur = head->next;
        while (index--)
            cur = cur->next;
        return cur->val;
    }

    void addAtTail(int val)
    {
        node *cur = head;
        node *newnode = new node(val);
        while (cur != tial)
            cur = cur->next;
        cur->next = newnode;
        newnode->pre = cur;
        newnode->next = head->next;
        head->next->pre = newnode;
        tial = newnode;
        size++;
    }

    void outputdao(int Val)
    {
        node *cur = head->next;
        while (cur->val != Val)
        {
            cur = cur->next;
        }
        while (cur->pre->val != Val)
        {
            cout << cur->val<<" ";
            cur = cur->pre;
        }
        cout << cur->val;
    }
};

int main()
{
    MyLinkedList list = MyLinkedList();
    int N, M;
    cin >> N;
    int *num = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
        list.addAtTail(num[i]);
    }
    cin>>M;
    list.outputdao(M);
    return 0;
}