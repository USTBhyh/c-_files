/**
@File    :   prac1.cpp
@Time    :   2022/03/30 00:11:30
@Author  :   hyh
@Version :   1.0
@Contact :   1360895771@qq.com
@Desc    :   N个给定的数，找两个和为m的数（N<10,0000)
             说明：复杂度为n方时，即100，0000，0000；必然超时（最好是百万数级，千万也可以，亿就有点危险了）
**/

#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
//快速排序：复杂度O（nlogn）
void QuickSort(int iArray[], int left, int right)
{
    //快速排序之前先判断一下当前待排序数组元素个数是不是大于1 否则就没有必要排序
    if (left >= right)
    {
        //直接退出排序代码  没有必要进行排序了
        return;
    }

    int stand = iArray[left];
    int r_index = right, l_index = left;
    while (l_index < r_index)
    {
        while (l_index < r_index)
        {
            if (iArray[r_index] >= stand)
            {
                r_index--;
            }
            else
            {
                iArray[l_index] = iArray[r_index];
                l_index++;
                break;
            }
        }
        while (l_index < r_index)
        {
            if (iArray[l_index] <= stand)
            {
                l_index++;
            }
            else
            {
                iArray[r_index] = iArray[l_index];
                r_index--;
                break;
            }
        }
        iArray[l_index] = stand;
        QuickSort(iArray, left, l_index - 1);
        QuickSort(iArray, r_index + 1, right);
    }
}
//二分法查找：a[i=0]和a[j=N-1]开始，小于m，右移i，反之左移j（nlogn）
void binary_search(int a[], int N, int m)
{
    int l = 0, r = N - 1;
    while (l < r)
    {
        if (a[l] + a[r] == m)
            cout<< a[l]<<" "<< a[r];
        else if (a[l] + a[r] < m)
            l++;
        else
            r--;
    }
    
}

int main()
{
    int N, m;
    cin >> N >> m;
    int *a = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> N;
    }
    QuickSort(a, 0, N-1);
    for (int i = 0; i < N; i++)
    {
        cout <<a[i]<<endl;
    }
    binary_search(a, N, m);
    return 0;
}
