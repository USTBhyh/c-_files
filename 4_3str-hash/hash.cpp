//--------------------------------查找数字是否存在--------------------------------------

#include<iostream>
#define MAX 10001
using namespace std;

int main()
{
	int m, n,temp;//temp为存储数组初始化和查询时的数据
	bool hashTable[MAX] = { false };
	cout << "请输入存储数组的数字个数和要查询的数字个数";
	cin >> m >> n;//输入存储数组的数字个数m，查询数字数组的大小n
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		hashTable[temp] = true;//数字temp出现过
	}
	cout << "请输入查询数字" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (hashTable[temp])
			cout << "yes"<<endl;
		else
			cout << "no" << endl;
	}
}

//--------------------------------查找数字出现次数和排序----------------------------------
 
//#include<iostream>
//#define MAX 1001
//using namespace std;
//
//int main()
//{
//	int m, n,temp;//temp为存储数组初始化和查询时的数据
//	int hashTable[MAX] = { 0 };
//	cout << "请输入存储数组的数字个数和要查询的数字个数"<<endl;
//	cin >> m >> n;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> temp;
//		hashTable[temp]++;
//	}
//	cout << "请输入查询数字" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		if (hashTable[temp])
//			cout << temp<<"出现了" << hashTable[temp] << "次" << endl;
//		else
//			cout << "此数字不存在" << endl;
//	}
//
//	//for (int i = 0; i < MAX; i++)
//	//{
//	//	while(hashTable[i]--)
//	//	{
//	//		cout << i << " ";
//	//	}
//	//}
//}

//---------------------------字符串hash初步（有初步就有进阶，悲）-------------------------------
//#include<iostream>
//using namespace std;
//int hashTable[1000000] = { 0 };
//
//int hashFunc(string a)
//{
//	int index = 0;
//	for (int i = 0; i < a.size(); i++)
//	{
//		index = index * 26 + a[i] - 'A';
//	}
//	return index;
//}
//
//int main()
//{
//	int m, n;
//	string a;
//	cout << "输入要存储的字符串的总数和要查询的字符串总数";
//	cin >> m >> n;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> a;
//		int index=hashFunc(a);
//		hashTable[index]++;
//	}
//	cout << "请输入需要查询的字符串" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a;
//		int index = hashFunc(a);
//		if (hashTable[index])
//			cout << "字符串" << a << "出现了" << hashTable[index] << "次" << endl;
//		else
//			cout << "字符串" << a << "不存在" << endl;
//	}
//}



