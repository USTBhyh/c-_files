#include"student.h"
#include<iostream>
using namespace std;
Student::Student(int m_num,char m_name)
{
    name = m_name;
    num = m_name;
}
void Student::show()
{
    cout<<num<<'-'<<name<<' ';
}