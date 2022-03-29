#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int p[n][3];
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
        {
            cin>>p[i][j];
        }
    
    return 0;
}