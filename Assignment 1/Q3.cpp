// Q3. Write a menu driven program for Student in CPP language.
// Create a class student with data members roll no, name and marks.
// Implement the following functions
// void initStudent();
// void printStudentOnConsole();
// void acceptStudentFromConsole();

#include<iostream>
using namespace std;

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

int menu()
{
    int choice;
    cout<< "  0. Exit" <<endl;
    cout<< "  1. To Enter studnet information" <<endl;
    cout<< "  2. Print student information" <<endl;
    cout<< "Enter Your choice"<< endl;
    cin >>choice;
    return choice;
}




int main()
{
    Student s1;
    s1.initStudent();    
    int choice;
    while ((choice = menu()) != 0)
    {
        switch(choice)
        {
            case 1 :
                s1.acceptStudentFromConsole();
                break;
            case 2 :
                s1.printStudentOnConsole();
                break;
            
            default :
                cout << "Enter Valid Input "<< endl;
                break;
            
        }
    }
    cout<<" Thank you !! "<< endl;


    return 0;
}