/**
@File    :   Physiological cycle.cpp
@Time    :   2022/03/24 23:49:03
@Author  :   hyh
@Version :   1.0
@Contact :   1360895771@qq.com
@Desc    :   生理周期；三高峰问题
**/


#include <iostream>
#include<cstdio>
using namespace std;
#define N 21252
int main()
{
    int p,e,i,d,caseNo=0;
    while (cin>>p>>e>>i>>d&&p!=-1)
    {
        ++caseNo;
        int k;
        for(k=d+1;(k-p)%23;++k);
        for(;(k-e)%28;k+=23);
        for(;(k-i)%33;k+=23*28);
        cout<<"Case "<<caseNo<<": the next triple peak occurs in "<<k-d;
    }
    
    return 0;
}
