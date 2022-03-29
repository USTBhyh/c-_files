/**
@File    :   Maze_question.cpp
@Time    :   2022/03/25 14:38:35
@Author  :   hyh
@Version :   1.0
@Contact :   1360895771@qq.com
@Desc    :   队列应用_迷宫问题:广度优先搜索
**/

#include <iostream>
using namespace std;
#define maxsize 1001
#define M2 8
#define N2 11
int m = M2 - 2;
int n = N2 - 2;
int maze[M2][N2] =
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1,
        1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1,
        1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1,
        1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1,
        1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1,
        1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
class queue
{
public:
    struct data
    {
        int x, y, be;
    };
    data datas[maxsize];
    int front, rear;

    queue(){};
    ~queue(){};
};
struct madd
{
    int u, v;
};
void modds_fuzhi(madd madds[])
{
    madds[0].u = 0;
    madds[0].v = 1;
    madds[1].u = 1;
    madds[1].v = 1;
    madds[2].u = 1;
    madds[2].v = 0;
    madds[3].u = 1;
    madds[3].v = -1;
    madds[4].u = 0;
    madds[4].v = -1;
    madds[5].u = -1;
    madds[5].v = -1;
    madds[6].u = -1;
    madds[6].v = 0;
    madds[7].u = -1;
    madds[7].v = 1;
}
void Path(queue &q)
{
    int i = q.rear;
    do
    {
        printf("\n(%d,%d)", q.datas[i].x, q.datas[i].y);
        i = q.datas[i].be;
    } while (i);
}
int mazepath(int maze[M2][N2])
{
    int ma[M2][N2], i, j, k, x, y;
    madd madds[8];
    modds_fuzhi(madds);
    queue Q = queue();
    for (int i = 0; i < M2; i++)
        for (int j = 0; j < N2; j++)
        {
            ma[i][j] = maze[i][j];
        }
    Q.front = Q.rear = 1;
    Q.datas[Q.rear].x = Q.datas[Q.rear].y = 1;
    Q.datas[Q.rear].be = 0;
    ma[1][1] = -1;
    while (Q.front <= Q.rear)
    {
        x = Q.datas[Q.front].x;
        y = Q.datas[Q.front].y;
        //依次取八方向坐标
        for (k = 0; k < 8; k++)
        {
            i = x + madds[k].u;
            j = y + madds[k].v;
            if (ma[i][j] == 0)
            {
                Q.rear++;
                Q.datas[Q.rear].x = i;
                Q.datas[Q.rear].y = j;
                Q.datas[Q.rear].be = Q.front;
                ma[i][j] = 0;
            }
            if ((i == m) && (j == n))
            {
                Path(Q);
                return 1;
            }
        }
        Q.front++;
    }
    return 0;
}
int main()
{
    mazepath(maze);
    return 0;
}
