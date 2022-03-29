#include <iostream>
#include <stdlib.h>
#include <math.h>
#define N 10 //定义方阵的最大阶数为10
#include <iomanip>
using namespace std;
double MatDet(double *p, int n);				//求矩阵的行列式
double Creat_M(double *p, int m, int n, int k); //求矩阵元素A(m, n)的代数余子式
void print(double *p, int n);					//输出矩阵n*n
class Matrix
{
private:
	int row, col;
	double **eM;

public:
	void creatM();					  //创造矩阵
	void outM(Matrix A);			  //输出矩阵
	void add(Matrix A, Matrix B);	  //矩阵相加
	void minus(Matrix A, Matrix B);	  //矩阵相减
	void transpose(Matrix A);		  //矩阵转置
	void mutiply(Matrix A, Matrix B); //矩阵相乘
	void h(Matrix A);				  //求行列式,和上三角
	void inverse(Matrix A);			  //矩阵的逆
};
int main()
{
	cout << "******矩阵计算器******" << endl;
	cout << "请选择你要进行的操作"
		 << "\n"
		 << "0:退出 1:相加 2:相减 3:转置 4:相乘 5:求行列式和上三角 6:求逆" << endl;
	int c;
do{
	cin >> c;
	switch (c)
	{
	case 1:
	{
		Matrix m1, m2;
		cout << "请输入第一个矩阵" << endl;
		m1.creatM();
		cout << "请输入第二个矩阵" << endl;
		m2.creatM();
		m1.add(m1, m2);
		break;
	}

	case 2:
	{
		Matrix m1, m2;
		cout << "请输入第一个矩阵" << endl;
		m1.creatM();
		cout << "请输入第二个矩阵" << endl;
		m2.creatM();
		m1.minus(m1, m2);
		break;
	}
	case 3:
	{
		Matrix A;
		A.transpose(A);
		break;
	}
	case 4:
	{
		Matrix m1, m2;
		cout << "请输入第一个矩阵" << endl;
		m1.creatM();
		cout << "请输入第二个矩阵" << endl;
		m2.creatM();
		m1.mutiply(m1, m2);
		break;
	}
	case 5:
	{
		Matrix m;
		cout << "请输入矩阵" << endl;
		m.creatM();
		m.h(m);
		break;
	}
	case 6:
	{
		double *buffer, *p; //定义数组首地址指针变量
		int row, num;		//定义矩阵的行数和矩阵元素个数
		int i, j;
		double determ; //定义矩阵的行列式
		double a[N][N], b[N][N];
		int n;
		cout << "采用逆矩阵的定义法求矩阵的逆矩阵!\n";
		cout << "请输入矩阵的行数: ";
		cin >> row;
		num = 2 * row * row;
		buffer = (double *)calloc(num, sizeof(double)); //分配内存单元
		p = buffer;
		if (NULL != p)
		{
			for (i = 0; i < row; i++)
			{
				cout << "Please input the number of " << i + 1 << " row: ";
				for (j = 0; j < row; j++)
				{
					cin >> *p++;
				}
			}
		}
		else
		{
			cout << "无法分配内存\n";
		}
		cout << "The original matrix : \n";
		print(buffer, row); //打印该矩阵

		determ = MatDet(buffer, row); //求整个矩阵的行列式
		p = buffer + row * row;
		if (determ != 0)
		{
			cout << "The determinant of the matrix is " << determ << endl;
			for (i = 0; i < row; i++) //求逆矩阵
			{
				for (j = 0; j < row; j++)
				{
					*(p + j * row + i) = (double)Creat_M(buffer, i, j, row) / determ;
				}
			}
			cout << "The inverse matrix is: " << endl;
			print(p, row); //打印该矩阵
		}
		else
		{
			cout << "The determinant is 0, and there is no inverse matrix!\n";
		}
		free(buffer); //释放内存空间

		getchar();
		break;
	}
	}
}while(c!=0);
	return 0;
}
void Matrix::creatM()
{
	cout << "请依次输入矩阵的行和列" << endl;
	cin >> row >> col;
	eM = (double **)malloc(row * sizeof(double *));
	for (int i = 0; i < row; i++)
		eM[i] = (double *)malloc(col * sizeof(double));
	cout << "请输入矩阵" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cin >> eM[i][j];
	}
}
void Matrix::outM(Matrix A)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << eM[i][j] << " ";
		cout << endl;
	}
}
void Matrix::add(Matrix A, Matrix B)
{
	if (A.col != B.col || A.row != B.row)
	{
		cout << "行列不同" << endl;
	}
	else
	{
		for (int i = 0; i < A.row; i++)
		{
			for (int j = 0; j < A.col; j++)
			{
				A.eM[i][j] = A.eM[i][j] + B.eM[i][j];
			}
		}
		cout << "结果为：\n";
		A.outM(A);
	}
}
void Matrix::minus(Matrix A, Matrix B)
{
	if (A.col != B.col || A.row != B.row)
	{
		cout << "行列不同" << endl;
	}
	else
	{
		for (int i = 0; i < A.row; i++)
		{
			for (int j = 0; j < A.col; j++)
			{
				A.eM[i][j] = A.eM[i][j] + B.eM[i][j];
			}
		}
		cout << "结果为：\n";
		A.outM(A);
	}
}
void Matrix::transpose(Matrix A)
{
	int i, j;
	cout << "请输入矩阵" << endl;
	A.creatM();
	cout << "原矩阵为：\n";
	A.outM(A);
	Matrix R;
	R.row = A.col;
	R.col = A.row;
	R.eM = (double **)malloc(R.row * sizeof(double *));
	for (i = 0; i < R.row; i++)
		R.eM[i] = (double *)malloc(R.col * sizeof(double));
	for (i = 0; i < R.row; i++)
	{
		for (int j = 0; j < R.col; j++)
		{
			R.eM[i][j] = 0;
		}
	}
	for (i = 0; i < R.row; i++)
	{
		for (int j = 0; j < R.col; j++)
		{
			R.eM[i][j] = A.eM[j][i];
		}
	}
	cout << "结果为：" << endl;
	R.outM(R);
}
void Matrix::mutiply(Matrix A, Matrix B)
{
	if (A.col != B.row)
	{
		cout << "不能相乘" << endl;
	}
	else
	{
		int i;
		Matrix R;
		R.row = A.row;
		R.col = B.col;
		R.eM = (double **)malloc(R.row * sizeof(double *));
		for (i = 0; i < row; i++)
			R.eM[i] = (double *)malloc(R.col * sizeof(double));
		for (i = 0; i < R.row; i++)
		{
			for (int j = 0; j < R.col; j++)
			{
				R.eM[i][j] = 0;
			}
		}
		for (i = 0; i < R.row; i++)
		{
			for (int j = 0; j < R.col; j++)
			{
				for (int k = 0; k < A.col; k++)
				{
					R.eM[i][j] += A.eM[i][k] * B.eM[k][j];
				}
			}
		}
		cout << "结果为：\n"
			 << endl;
		R.outM(R);
	}
}
void Matrix::h(Matrix A)
{
	if (A.col != A.row)
	{
		cout << "不是方阵" << endl;
	}
	else
	{

		int ii, jj, k, u;
		int iter = 0; //记录行变换的次数（交换）
		double det1 = 1, yin;
		int n = A.row;

		for (ii = 0; ii < n; ii++)
		{
			if (A.eM[ii][ii] == 0)

				for (jj = ii; jj < n; jj++)
				{
					if (A.eM[jj][ii] != 0)
					{
						double temp1;
						for (int i = 0; i < n; i++)
						{
							temp1 = A.eM[ii][i];
							A.eM[ii][i] = A.eM[jj][i];
							A.eM[ii][i] = temp1;
						}
						iter++;
					}
				}

			for (k = ii + 1; k < n; k++)
			{
				yin = -1 * A.eM[k][ii] / A.eM[ii][ii];

				for (u = 0; u < n; u++)
				{
					A.eM[k][u] = A.eM[k][u] + A.eM[ii][u] * yin;
				}
			}
		}
		for (ii = 0; ii < n; ii++) //求对角线的积 即 行列式的值
			det1 = det1 * A.eM[ii][ii];
		//行变换偶数次符号不变
		if (iter % 2 == 1)
			det1 = -det1;
		cout << "矩阵的行列式的值为：" << det1 << endl;
		cout << "转换的上三角矩阵为：" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << "   " << A.eM[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}
double MatDet(double *p, int n)
{
	int ii, jj, k, u;
	int iter = 0; //记录行变换的次数（交换）
	double det1 = 1, yin;
	for (ii = 0; ii < n; ii++)
	{
		if (*(p + ii * n + ii) == 0)

			for (jj = ii; jj < n; jj++)
			{
				if (*(p + jj * n + ii) != 0)
				{
					double temp1;
					for (int i = 0; i < n; i++)
					{
						temp1 = *(p + ii * n + i);
						*(p + ii * n + i) = *(p + jj * n + i);
						*(p + ii * n + i) = temp1;
					}
					iter++;
				}
			}
		for (k = ii + 1; k < n; k++)
		{
			yin = -1 * (*(p + k * n + ii)) / (*(p + ii * n + ii));

			for (u = 0; u < n; u++)
			{
				*(p + k * n + u) = *(p + k * n + u) + *(p + ii * n + u) * yin;
			}
		}
	}
	for (ii = 0; ii < n; ii++) //求对角线的积 即 行列式的值
		det1 = det1 * (*(p + ii * n + ii));
	//行变换偶数次符号不变
	if (iter % 2 == 1)
		det1 = -det1;
	return det1;
}
//----------------------------------------------------------------------------
//功能: 求k*k矩阵中元素A(m, n)的代数余之式
//入口参数: k*k矩阵的首地址，矩阵元素A的下标m,n,矩阵行数k
//返回值: k*k矩阵中元素A(m, n)的代数余之式
//----------------------------------------------------------------------------
double Creat_M(double *p, int m, int n, int k)
{
	int len, t;
	int i, j;
	double mid_result = 0;
	int sign = 1;
	double *p_creat, *p_mid;
	len = (k - 1) * (k - 1);						 // k阶矩阵的代数余之式为k-1阶矩阵
	p_creat = (double *)calloc(len, sizeof(double)); //分配内存单元
	p_mid = p_creat;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < k; j++)
		{
			if (i != m && j != n) //将除第i行和第j列外的所有元素存储到以p_mid为首地址的内存单元
			{
				*p_mid++ = *(p + i * k + j);
			}
		}
	}
	sign = ((m + n) % 2 == 0 ? 1 : -1); //代数余之式前面的正、负号
	t = MatDet(p_creat, k - 1);
	mid_result = sign * t;
	return mid_result;
	free(p_creat);
}
//-----------------------------------------------------
//功能: 打印n*n矩阵
//入口参数: n*n矩阵的首地址,矩阵的行数n
//返回值: 无返回值
//-----------------------------------------------------
void print(double *p, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		cout << setw(4);
		for (j = 0; j < n; j++)
		{
			cout << setiosflags(ios::right) << *p++ << setw(10);
		}
		cout << endl;
	}
}
