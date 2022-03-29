/**
 *计蒜客：哪位同学最优秀
 *蒜头君想把计算机专业相关的课程都写一遍，放到计蒜客上面帮助同学们学习。但是蒜头君意识到要写的课程有很多很多，
 蒜头君实在忙不过来，于是他想招几位实习生帮助一块写课程。招聘广告一发，吸引了好多大牛前来应聘，于是蒜头君每天
 都要安排面试。
 *有一天，结束了一天面试后，boss 跑来问蒜头君：“小蒜，你觉得今天面试的同学里面，谁最优秀呀，谁最适合写课程呀？”
 蒜头君递给 boss 一沓简历，回答到：“这里有 N 份简历，boss 你猜猜哪位同学最优秀。”
 *每份简历都有一个对应的 idid，编号从 11 开始，依次从第一份简历到最后一份简历。boss 会从简历里抽掉 M 份简历，
 每次他随机念一个数字 num_i，然后从第一份简历开始数，数到第 num_i份时，就会把对应的简历抽掉，接着念下一个数字。
 抽掉 M 份简历后，boss 从剩余的简历中，取出最中间的一份简历，然后点点头念道：“我相信这位同学一定最优秀，哈哈”。
 现在蒜头君想知道这份简历的 id 是多少，聪明的你能帮他算出来吗？

 *输入格式
 *第一行输入两个正整数 N 和 M
 *第二行输入 M 个整数 num_i，表示 boss 依次念出来的数字。
 *保证 N - M是奇数，输入的 num_i小于等于当前剩余简历数量。

 *输出格式
 *输出为一行，输出 boss 认为最优秀的同学的 idid 是多少。

 *解题思路
 *单向链表
*/
#include<iostream>
using namespace std;
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    struct node{//单链表节点结构
        int val;//数据域
        node *next;//指针域
        node(int x): val(x),next(NULL){}//表示的含义就是节点数值为x，指针为空（初始化一个新节点）
    };
    MyLinkedList() {//初始化链表
        head=new node(0);//初始化头指针，数据为0(0-0(index))--->相当于定义了一个空节点作为头，它本身不算节点
        size=0;//链表长度为0
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {//获取索引节点数值
        if(index<0||index>(size-1)) return -1;//索引比0小或者比最大索引大，返回-1
        node *cur=head->next;//辅助指针指向第一个节点
        while(index--) cur=cur->next;//循环index次遍历到第index个节点
        return cur->val;//指向数值输出
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {//插入头
        node *newnode=new node(val);//创建新节点
        newnode->next=head->next;//将头节点的next赋值给新的节点--->相当于连接新插入节点与第一个节点
        head->next=newnode;//连接头指针与第一个新节点
        size++;//长度加1
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {//插入尾
        node *cur=head;//辅助指针从头指针开始
        while(cur->next) cur=cur->next;//遍历到最后一个节点,如果是空链表，则直接不循环，指针还是在头指针
        node *newnode=new node(val);//创造新节点并赋值
        newnode->next=cur->next;//复制原最后节点的next信息
        cur->next=newnode;//连接最后一个新节点和上一个节点
        size++;//长度加1
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index<=0) addAtHead(val);//插入index的时候，如果下标是=0,就相当于从头插入，所以要包含<=
        else if(index==size) addAtTail(val);
        else if(index>size) return ;
        else{
            node *newnode=new node(val);
            node *cur=head;//辅助指针从头指针开始
            while(index--) cur=cur->next;//遍历到第index-1的节点，循环次数是index次 但是辅助指针是从头指针开始而不是第一个节点
            newnode->next=cur->next;//连接index
            cur->next=newnode;//连接前一个
            size++;//长度+1
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0||index>=size) return ;
        node *cur=head;//从头指针开始
        while(index--){//遍历到index-1的位置,循环次数是index次
            cur=cur->next;
        }
        cur->next = cur->next->next;//相当于直接跨过了index节点
        size--;
    }
private://私人函数定义
    int size;//表示链表长度
    node *head;//定义头指针
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main()
{
    int N,M;
    cin>>N>>M;
    int* num = new int[M];
    for(int i =0;i<M;i++)
    {
        cin>>num[i];
    }
    MyLinkedList list = MyLinkedList();
    for(int i=1;i<N+1;i++)
    {
        list.addAtTail(i);
    }
    for(int i=0;i<M;i++)
        list.deleteAtIndex(num[i]-1);
    cout<<list.get((N-M)/2);
    
    return 0;
}