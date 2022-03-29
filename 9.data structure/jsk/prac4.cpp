/**
 *计蒜客：蜗牛旅行
 *蜗牛在制定今天的旅游计划，有 n个景点可选，它已经把这些景点按照顺路游览的顺序排成一排了，每个地方有相应的景观
 这里用一个整数表示。
 *蜗牛希望选取连续的一段景点，还要选出来的每一个景点的景观都不同，问它最多能选出多少个景点进行旅游。

 *输入格式
 *第一行，一个正整数 
 *第二行，包含 n 个正整数 ，第 i 个整数表示第 i 个景点的景观。

 *输出格式
 *输出一行，包含一个整数，表示蜗牛最多能选出的景点数。
 
 *解题思路
 *用一个队列维护以现在这个位置为结尾选择的一段，遇到一个不在队列里的数就放进队列，遇到在的就需要把
 队列中截止到这个数的元素都弹出，再把它放进去。
**/
#include <iostream>
#include <vector>
using namespace std;
class MyQueue
{
private:
    vector<int> data;
    int p_start;

public:
    MyQueue() { p_start = 0; }

    bool enQueue(int x)
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
    int Front()
    {
        return data[p_start];
    };

    bool isEmpty()
    {
        return p_start >= data.size();
    }
    int size()
    {
        return data.size()-p_start;
    }
};
const int NUM = 1e6 + 1;
bool markList[NUM];
int main()
{
    MyQueue q;
    int n;
    cin >> n;
    int *num = new int[n];
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < n; i++)
    {
        // 判断是否在队列中
        if (markList[num[i]] == 0)
        {
            // 若不在，加入队列
            q.enQueue(num[i]);
            // 标记数字
            markList[num[i]] = 1;
        }
        else
        {
            // 若在，将队首元素出队直到没有元素和即将新入队的元素重复
            while (markList[num[i]] != 0)
            {
                markList[q.Front()] = 0;
                q.deQueue();
            }
            // 加入队列
            q.enQueue(num[i]);
            // 标记数字
            markList[num[i]] = 1;
        }
        // 存储最长队列
        if (q.size() > max)
        {
            max = q.size();
        }
    }
    cout<<max;
}