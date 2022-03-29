/**
 *计蒜客：蒜头君的魔法机
 *蒜头君有一台神奇的魔法机，它能将输入的序列进行一系列复杂的变换，输出原序列的另一种排列方式。蒜头君十分好奇魔法机的
 工作原理，终于有一天他尝试着把魔法机拆开研究了。
 *通过一系列复杂的演算，蒜头君终于发现了魔法机的工作原理：其实魔法机就是一个栈，根据栈先进后出的性质，每次一个数字进栈
 或将栈顶元素弹出，由此可以产生不同的出栈序列，出栈序列就是原序列的另一种排列了。
 *在研究完原理后，蒜头君凭借记忆很快就把魔法机组装好了。现在蒜头君想测试下魔法机在组装完成后是否出现问题。
 *首先他将 1 到 N 这 N 个数字依次输入魔法机里，然后随机写下一组序列a，现在他想知道能否通过魔法机得到序列a，聪明的你能
 帮蒜头君算一算吗？

 *输入格式
 *输入有两行，第一行是一个正整数 N ,表示输入魔法机序列的长度，第二行是序列a，共有 N 个整数，表示要得到的目标序列。
 *序列为 1 到 N 的排列，即序列a长度为 N，保证序列中的整数都不相同，且整数在区间 [1, N] 内。

 *输出格式
 *输出一行，如果能通过魔法机得到序列a，则输出YES，否则输出NO。

 *解题思路
 *将要判断的顺序存到一个线性数据表中，然后遍历【1，n+1），每次若栈顶元素与表中第count个的元素相同则弹出并count++，
 结束循环后，判断该弹出的过程是否进行了n次，是则说明能够输出该序列。
**/
#include <iostream>
#include <vector>
using namespace std;
class Stack
{
private:
    int *x;
    int size, top_index;

public:
    Stack(int length)
    {
        x = new int[length];
        top_index = -1;
        size = length;
    }
    ~Stack()
    {
        delete[] x;
    }
    int top()
    {
        return x[top_index];
    }
    bool push(const int &input)
    {
        if (top_index >= (size - 1))
            return false;
        else
        {
            top_index += 1;
            x[top_index] = input;
            return true;
        }
    }
    bool pop()
    {
        if (top_index < 0)
            return false;
        else
        {
            top_index -= 1;
            return true;
        }
    }
    bool IsEmpty()
    {
        if (top_index < 0)
            return true;
        else
            return false;
    }
};

int main()
{
    int n, a;
    int count = 0;
    cin >> n;
    vector<int> num(n);
    Stack s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        num[i] = a;
    }
    for (int i = 1; i < (n + 1); i++)
    {

        s.push(i);
        while (!s.IsEmpty() && (s.top() == num[count]))
        {
            s.pop();
            count++;
        }
    }
    if (count == n)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}