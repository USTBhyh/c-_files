#include"student.h"
#include"major.h"
#include<iostream>
using namespace std;
int main()
{
    char cmd,s_name,m_name;
    int num = 0,id = 0;
    Student stu[100];
    Major maj[100];
    do{
        switch (cmd)
        {
        case 's':
        {
            cin>>s_name;
            stu[num] = Student(num,s_name);
            num++;
        }break;
        case 'm':
        {
            cin>>m_name;
            maj[id] = Major(id++,m_name);
        }break;
        case 'a':
        {
            int m_num,m_id;
            cin>>m_num>>m_id;
            maj[m_id].mstu[maj[m_id].stunum] = stu[m_num];
            maj[m_id].stunum++;
        }break;
        case 'd':
        {
            int m_num,m_id;
            cin>>m_num>>m_id;
            maj[m_id].delets(stu[m_num].name);
            maj[m_id].stunum--;
        }break;
        case 'v':
        {
            int m_num,m_pid,m_aid;
            cin>>m_num>>m_pid>>m_aid;
            maj[m_pid].delets(stu[m_num].name);
            maj[m_aid].mstu[maj[m_aid].stunum] = stu[m_num];
            maj[m_pid].stunum--;
            maj[m_aid].stunum++;
        }break;
        case 'n':
        {
            for(int i = 0;i<num;i++)
            {
                stu[i].show();
                cout<<endl;
            }
        }break;
        case 'l':
        {
            for(int i = 0;i<id;i++)
            {
                maj[i].show();
            }
        }break;
        default:
            break;
        }
    }while(cmd != 'e');
    return 0;
}