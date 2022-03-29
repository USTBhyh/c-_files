//--------------------------------如何尽可能的避免哈希碰撞-----------------------------------
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;
const int P = 10000019;
vector<int>ans;//可以用简单的数组，操作略微复杂。

long long hashFunc(string str)//为什么使用long long？？
{
	long long H = 0;
	for (int i = 0; i < str.size(); i++)
	{
		H = (H * P + str[i] - 'a') % MOD;//和基础版的hash函数区别在哪里？
	}
	return H;
}

int main()
{
	string str;
	while (getline(cin, str), str != "#")//这么写的好处是什么？？
	{
		long long id = hashFunc(str);
		ans.push_back(id);
	}
	sort(ans.begin(), ans.end());
	int count = 0;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i == 0 || ans[i] != ans[i - 1])
		{
			count++;
		}
	}
	cout <<"相同的字符串个数为" << count << endl;
}
//
// ---------------------------两个字符串的最长公共子串-----------------------------------
//#include<iostream>
//#include<cstdio>
//#include<string>
//#include<vector>
//#include<map>
//#include<algorithm>
//using namespace std;
//typedef long long LL;
//const LL MOD = 1000000007;
//const LL P = 10000019;
//const LL MAXN = 345;//字符串的最大长度(自定义)
//LL powP[MAXN], H1[MAXN] = { 0 }, H2[MAXN] = { 0 };
////分别用来存放P^i%MOD、str1的hash值、str2的hash值
//vector<pair<int, int>>pr1, pr2;//<子串hash值，子串长度>
//
////init函数用以初始化powP;
//void init(int len)
//{
//	powP[0] = 1;
//	for (int i = 1; i <= len; i++)
//	{
//		powP[i] = (powP[i - 1] * P) % MOD;
//	}
//}
////哈希函数
//void hashFunc(LL H[], string& str)
//{
//	H[0] = str[0];
//	for (int i = 1; i <str.length(); i++)
//	{
//		H[i] = (H[i - 1] * P+str[i]) % MOD;
//	}
//}
////遍历并计算每一个子串的hash值
//void calSubHash(LL H[],int len,vector<pair<int ,int>>& pr)
//{
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = i; j < len; j++)
//		{
//			int hashValue = ((i == 0) ? H[j] : H[j] - H[i - 1] * powP[j - i + 1] % MOD + MOD) % MOD;
//			pr.push_back(make_pair(hashValue, j - i + 1));//<子串hash值，子串长度>
//		}
//	}
//}
//
////找出字串中相同的hash值，并比较出最大长度
//int getMax()
//{
//	int ans = 0;
//	for (int i = 0; i < pr1.size(); i++)
//	{
//		for (int j = 0; j < pr2.size(); j++)
//		{
//			if (pr1[i].first == pr2[j].first)
//			{
//				ans = max(ans, pr1[i].second);
//			}
//		}
//	}
//	return ans;
//}
//
//
//int main()
//{
//	string str1, str2;
//	cin >> str1 >> str2;
//	init(max(str1.length(), str2.length()));//powP数组初始化。为什么要用max？？
//	hashFunc(H1, str1);//计算hash值
//	hashFunc(H2, str2);//计算hash值
//	calSubHash(H1, str1.length(), pr1);
//	calSubHash(H2, str2.length(), pr2);//计算出所有的子列，将长度和hash值对应。
//	cout << "最大公共子串长度为" << getMax() << endl;//找出字串中相同的hash值，比较并输出最大长度
//}