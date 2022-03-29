#include"major.h"
#include<iostream>
using namespace std;
Major::Major(int m_id,char m_name){
    id = m_id;
    name = m_name;
}
void Major::show()
{
    cout<<"Major "<<id<<'-'<<name<<': ';
    for(int i = 0;i<stunum;i++)
    {
        mstu[i].show();
        cout<<' ';
    }
    cout<<endl;
}
void Major::delets(char m_name)
{
    for(int i = 0;i<stunum;i++)
    {
        if(mstu[i].name == m_name)
        {
            for(int j = i;j<stunum-1;j++)
            {
                mstu[j]=mstu[j+1];
            }
        }
    }
}