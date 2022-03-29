#include <iostream>
using namespace std;
/**
 * @description 二分查找的递归实现
 * @param array 目标数组
 * @param low 左边界
 * @param high 右边界
 * @param target 目标值
 * @return 目标值所在位置
 */

int binarySearch(int array[], int low, int high, int target)
{

    //递归终止条件
    if (low <= high)
    {
        int mid = (low + high) >> 1;
        if (array[mid] == target)
        {
            return mid + 1; // 返回目标值的位置，从1开始
        }
        else if (array[mid] > target)
        {
            // 由于array[mid]不是目标值，因此再次递归搜索时，可以将其排除
            return binarySearch(array, low, mid - 1, target);
        }
        else
        {
            // 由于array[mid]不是目标值，因此再次递归搜索时，可以将其排除
            return binarySearch(array, mid + 1, high, target);
        }
    }
    return -1; //表示没有搜索到
}

int main()
{
    int n, t;
    cin>>n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> t;
    cout << binarySearch(a, 0, n, t);
    return 0;
}