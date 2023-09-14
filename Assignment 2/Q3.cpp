// Q3. Create a namespace NStudent. Create the Student class(created
// as per assignment-1 Q3) inside namespace. Test the functionalities.

#include<iostream>
using namespace std;
namespace NStudent{

class Student
{
private :
    int rollno;
    string name;
    int marks;

public:
    void initStudent()
    {
        this->rollno = 0;
        this->name = "noname";
        this->marks = 0;
    }

    void printStudentOnConsole()
    {
        cout<< "roll no. = "<< this->rollno << endl;
        cout<< "Name = "<< this->name << endl;
        cout<< "Marks = "<< this->marks << endl;
    }

    void acceptStudentFromConsole()
    {
        cout<< "Enter Roll No. = " ;
        cin>>this->rollno;
        cout<< "Enter Name = ";
        cin>>this->name;
        cout << "Enter Marks = ";
        cin>>this->marks;

    }
};
    namespace SStudent{
        Student s2;
    }

};

namespace AStudnet{
    NStudent::Student s2;
}

int main()
{
    NStudent::Student s1;
    s1.acceptStudentFromConsole();
    s1.printStudentOnConsole();

    NStudent::SStudent::s2.acceptStudentFromConsole();

    using namespace NStudent;
    SStudent::s2.printStudentOnConsole();

    AStudnet::s2.acceptStudentFromConsole();
    using namespace AStudnet;
    
    s2.printStudentOnConsole();


    return 0;

}