#include <iostream>
#include<string>
using namespace std;

/**
 * @description 递归判断一个字符串是否是回文字符串
 * @param s
 * @return
 */
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
            ns.assign(s,1,s.length()-2);
            return isPalindromeString_recursive(ns);
        }
    }
    return true;
}

int main()
{
    string s;
    cin>>s;
    if(isPalindromeString_recursive(s))
        cout<<"是回文序列！";
    else
        cout<<"不是回文序列！";
    return 0;
}



/*
 * @description 循环判断回文字符串
 * @return
bool isPalindromeString_loop(string s)
{
    char[] str = s.toCharArray();
    int start = 0;
    int end = str.length - 1;
    while (end > start)
    { // 循环终止条件:两个指针相向移动，当start超过end时，完成判断
        if (str[end] != str[start])
        {
            return false;
        }
        else
        {
            end--;
            start++;
        }
    }
    return true;
}
*/