#include<string.h>
#include<iostream>
#include<math.h>
using namespace std;

int main()

{
	string num1, num2;
	cin >> num1 >> num2;
	//cout << num1.size() << " " << num2.size() << endl;
	const char* n1;
	const char* n2;
	if (num1.size() < num2.size())
	{
		n1 = num2.c_str();
		n2 = num1.c_str();
	}
	else
	{
		n1 = num1.c_str();
		n2 = num2.c_str();
	}
	char* n = new char[strlen(n1) + strlen(n2) + 1];
	for (unsigned int i = 0; i < strlen(n1) + strlen(n2); i++)
		n[i] = '0';
	n[strlen(n1) + strlen(n2)] = '\0';
	//cout << strlen(n) << endl;
	int count = 0, flag = 0;
	for (int i = strlen(n1) - 1; i >= 0; i--)
	{
		flag++;
		int x1 = n1[i] - '0';
		//cout << "n1["<< i << "]为：" << x1 << endl;
		char carry = '0';
		for (int j = strlen(n2) - 1; j >= 0; j--)
		{
			int x2 = n2[j] - '0';
			//cout << "n2["<< j << "]为：" << x2 << endl;
			//cout << "当前位未改变前值为: " << n[count] << endl;
			int sum = x1 * x2 + (carry - '0') + n[count] - '0';
			//cout << "sum is " << sum << endl;
			n[count++] = (sum % 10) + '0';
			carry = (sum / 10) + '0';
			//cout << "当前位的值为: " << n[count-1] << endl;
			//cout << "carry的值为：" << carry << endl;
		}
		if (carry != '0')
		{
			n[count] = carry;
			count = flag;
			//cout << "当前位的值为: " << n[count] << endl;
		}
		else
			count = flag;
	}
	for (int i = strlen(n) - 1; i >= 0; i--)
	{
		if ((i == strlen(n) - 1) && (n[i] == '0'))
			continue;
		cout << n[i];
	}
	cout << endl;
	delete[]n;
	system("pause");
	return 0;

}