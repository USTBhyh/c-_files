#include <iostream>
#include <string>
using namespace std;
struct student
{
   string name;
   int chengji;
};

int main()
{
    int n;
    cin>>n;
    student* stu = new student[n];
    for(int i=0;i<n;i++)
    {
        cin>>stu[i].chengji>>stu[i].name;
    }
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
        {
            if(stu[j].chengji>stu[j+1].chengji)
            {
                student temp;
                temp = stu[j];
                stu[j] = stu[j+1];
                stu[j+1] = temp;
            }
        }
    if(n%2==0)
    {
        cout<<stu[n/2-1].name<<endl<<stu[n/2+1-1].name;
    }else
    {
        cout<<stu[(n+1)/2-1].name;
    }
    return 0;
}