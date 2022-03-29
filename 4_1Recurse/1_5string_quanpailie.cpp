#include <iostream>
using namespace std;
/**
 * @description 从字符串数组中每次选取一个元素，作为结果中的第一个元素;然后，对剩余的元素全排列
 * @param s
 *            字符数组
 * @param from
 *            起始下标
 * @param to
 *            终止下标
 */

void swap(char s[], int from, int to)
{
    char temp = s[from];
    s[from] = s[to];
    s[to] = temp;
}

void getStringPermutations3(char s[], int from, int to)
{
    if (s != NULL && to >= from && to < 10 && from >= 0)
    { // 边界条件检查
        if (from == to)
        {
            for (int i = 0; i < 10; i++)
            {
                cout << s[i] << ' ';
            }
        }
        else
        {
            for (int i = from; i <= to; i++)
            {
                swap(s, i, from);                        // 交换前缀,作为结果中的第一个元素，然后对剩余的元素全排列
                getStringPermutations3(s, from + 1, to); // 递归调用，缩小问题的规模
                swap(s, from, i);                        // 换回前缀，复原字符数组
            }
        }
    }
}

int main()
{
    char s[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> s[i];
    }
    getStringPermutations3(s, 0, 10);
    return 0;
}