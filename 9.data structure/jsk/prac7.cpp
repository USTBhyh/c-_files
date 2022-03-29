/**
 *计蒜客：回文序列
 *我们把正读和反读都相同的字符序列称为“回文”，例如abba和abcba是回文，abcde不是回文。尝试写一个算法判别读入
 的一个以@为结束符的字符是否是回文。

 *输入格式
 *输入为一行，为待判断的字符串，以@结尾。字符串长度不超过 30，除最后一个字符外，其余字符均由小写字母组成。

 *输出格式
 *输出一行，如果输入的字符串是回文，则输出true；如果输入的字符串不是回文，则输出false。

 *解题思路
 *递归求解
**/
#include <iostream>
#include <string.h>
using namespace std;
bool isPalindromeString_recursive(string s)
{
    int start = 0;
    int end = s.length() - 1;
    if (end > start)
    { // 递归终止条件:两个指针相向移动，当start超过end时，完成判断
        if (s[start] != s[end])
        {
            return false;
        }
        else
        {
            // 递归调用，缩小问题的规模
            string ns;
            ns.assign(s, 1, s.length() - 2);
            return isPalindromeString_recursive(ns);
        }
    }
    return true;
}

int main()
{
    string s,m_s;
    cin >> s;
    m_s.assign(s, 0, s.length() - 1);
    if (isPalindromeString_recursive(m_s))
        cout << "true";
    else
        cout << "false";
    return 0;
}
/*int main()
{

    string m_s,s;
    cin>>m_s;
    s.assign(m_s, 0, m_s.length() - 1);
    cout<<s;
    return 0;
}*/
