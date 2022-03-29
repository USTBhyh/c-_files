//#include<iostream>
//using namespace std;
//int Next[1000] = {0};
//
//void getNext(string a)
//{
//	int j = -1;
//	Next[0] = -1;
//	for (int i = 1; i <a.size(); i++)//为什么i从1开始？？(Next[0]已经初始化了)
//	{
//		while (j != -1 && a[i] != a[j + 1])
//		{
//			j = Next[j];//回退，直到j=-1或者a[i]==a[j+1]
//		}
//		if (a[i] == a[j + 1])
//		{
//			j++;//匹配上的字符数加一
//		}
//		Next[i] = j;
//	}
//
//}
//
//在彻底理解了next数组的求解之后，会发现KMP算法主体只是在此基础上发生了一点点改变
//bool KMP(string a, string b)
//{
//	getNext(b);//获取b的next数组
//	int j = -1;
//	for (int i = 0; i < a.size(); i++)
//	{
//		while (j != -1 && a[i] != b[j + 1])
//		{
//			j = Next[j];//回退
//		}
//		if (a[i] == b[j + 1])
//		{
//			j++;//匹配上的字符数加一
//		}
//		if (j == b.size()-1)//在a中找到了b
//		{
//			return true;
//		}
//	}
//	return false;//到最后也没匹配成功，说明b不是a的子串
//}
//
//int KMPplus(string a, string b)
//{
//	//真的是plus吗？非也,只是有一点点改动而已。
//	int ans = 0;
//	getNext(b);
//	int j = -1;
//	for (int i = 0; i < a.size(); i++)
//	{
//		while (j != -1 && a[i] != b[j + 1])
//		{
//			j = Next[j];//回退
//		}
//		if (a[i] == b[j + 1])
//		{
//			j++;//匹配上的字符数加一
//		}
//		if (j == b.size() - 1)//在a中找到了b
//		{
//			ans++;//匹配成功次数加一
//		}
//	}
//	return ans;//返回匹配成功的次数
//}
//int main()
//{
//	string a, b;
//	cout << "请输入字符串a" << endl;
//	cin >> a ;
//	cout << "请输入字符串b" << endl;
//	cin >> b;
//	cout << (KMP(a, b) ? "b是a的子串" : "b不是a的子串") << endl;
//	cout << "字符串b在字符串a中出现了"<<KMPplus(a,b)<<"次" << endl;
//}