#include"student.h"
class Major{
public:
    int id;
    char name;
    int stunum = 0;
    Student mstu[20];
    Major(){

    }
    Major(int m_id,char m_name);
    void show();
    void delets(char m_name);
};