#include <iostream>
using namespace std;
/**
 * @description 经典递归法求解
 * 斐波那契数列如下：
 **  1,1,2,3,5,8,13,21,34,...
 * *那么，计算fib(5)时，需要计算1次fib(4),2次fib(3),3次fib(2)，调用了2次fib(1)*，即：
 *  fib(5) = fib(4) + fib(3)
 *  fib(4) = fib(3) + fib(2) ；fib(3) = fib(2) + fib(1)
 *  fib(3) = fib(2) + fib(1)
 * 这里面包含了许多重复计算，而实际上我们只需计算fib(4)、fib(3)、fib(2)和fib(1)各一次即可，
 * 后面的optimizeFibonacci函数进行了优化，使时间复杂度降到了O(n).
 * @param n
 * @return
 */
int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {             // 递归终止条件
        return 1; // 简单情景
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // 相同重复逻辑，缩小问题的规模
}
/**
 * @description 对经典递归法的优化
 *
 * 斐波那契数列如下：
 *
 *  1,1,2,3,5,8,13,21,34,...
 *
 * 那么，我们可以这样看：fib(1,1,5) = fib(1,2,4) = fib(2,3,3) = 5
 *
 * 也就是说，以1,1开头的斐波那契数列的第五项正是以1,2开头的斐波那契数列的第四项，
 * 而以1,2开头的斐波那契数列的第四项也正是以2,3开头的斐波那契数列的第三项，
 * 更直接地，我们就可以一步到位：fib(2,3,3) = 2 + 3 = 5,计算结束。
 *
 * 注意，前两个参数是数列的开头两项，第三个参数是我们想求的以前两个参数开头的数列的第几项。
 *
 */
/* 时间复杂度：O(n)
 *
 * @param first 数列的第一项
 * @param second 数列的第二项
 * @param n 目标项
 * @return
 */
int optimizeFibonacci(int first, int second, int n)
{
    if (n > 0)
    {
        if (n == 1)
        {                 // 递归终止条件
            return first; // 简单情景
        }
        else if (n == 2)
        {                  // 递归终止条件
            return second; // 简单情景
        }
        else if (n == 3)
        {                          // 递归终止条件
            return first + second; // 简单情景
        }
        return optimizeFibonacci(second, first + second, n - 1); // 相同重复逻辑，缩小问题规模
    }
    return -1;
}

/**
 * @description 非递归解法：有去无回
 * @author rico
 * @created 2017年5月10日 下午12:03:04
 * @param n
 * @return
 */
int fibonacci_loop(int n)
{

    if (n == 1 || n == 2)
    {
        return 1;
    }

    int result = -1;
    int first = 1;  
    int second = 1; 

    for (int i = 3; i <= n; i++)
    { // 循环
        result = first + second;
        first = second;
        second = result;
    }
    return result;
}

int main()
{
    cout << fibonacci(10)<<endl<<fibonacci_loop(10)<<endl;
    return 0;
}