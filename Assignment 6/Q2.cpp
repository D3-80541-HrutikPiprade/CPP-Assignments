// Q2. Implement following classes. Test all functionalities in main(). Insted of char[] use string
// datatype


#include<iostream>
using namespace std;

class Date
{
private :
    int day;
    int month;
    int year;
public:
    Date()
    {
        this->day=1;
        this->month=1;
        this->year=2023;
    }

    Date(int day, int month, int yy)
    {
        this->day=day;
        this->month=month;
        this->year=yy;
    }

    int getDay()
    {
        return this->day;
    }

    int getMonth()
    {
        return this->month;
    }

    int getYear()
    {
        return this->year;
    }

    void setDay(int day)
    {
        this->day=day;
    }

    void setMonth(int month)
    {
        this->month=month;
    }

    void setYear(int year)
    {
        this->year=year;
    }

    void accept()
    {
        cout<<"Enter day : ";
        cin>>this->day;

        cout<<"Enter month : ";
        cin>>this->month;

        cout<<"Enter year : ";
        cin>>this->year;
    }

    void display()
    {
        cout<<"Date : "<< this->day << " - "<<this->month << " - " << this->year<<endl;
    }

    bool isLeapYear()
    {
        if((this->year%100!=0&&this->year%4 == 0)|| (this->year %400==0))
        {
            return true;
        }
        else false;
    }
};


class Employee
{
private :
    int id;
    float sal;
    string dept;
    Date doj;

public :
    Employee()
    {
        this->id =0;
        this->sal=0;
        this->dept="";
    }
    Employee(int id,float sal,string dept, int day, int month , int year) : doj(day,month,year)
    {
        this->id=id;
        this->sal=sal;
        this->dept=dept;

    }

    int getId()
    {
        return this->id;
    }

    int getSal()
    {
        return this->sal;
    }

    string getDept()
    {
        return this->dept;
    }

    Date getDoj()
    {
        return this->doj;
    }

    void setId(int id)
    {
        this->id =id;
    }

        void setSal(int id)
    {
        this->id =id;
    }

    void setDept(string dept)
    {
        this->dept =dept;
    }

    void setDoj(Date doj)
    {
        this->doj=doj;
    }

    void accept()
    {
        cout<< "Enter the Employee Id : ";
        cin>>this->id;
        cout<< "Enter the Salary : ";
        cin>>this->sal;
        cout<< "Enter the Department : ";
        cin>>this->dept;        
        cout<<"Enter the date of Joining :"<<endl;
        this->doj.accept();
    }

    void display()
    {
        cout<< "Employee Id : "<< this->id<<endl;
        cout<< "Salary : "<< this->sal<<endl;
        cout<< "Department : "<< this->dept<<endl;
        cout<<" Date of joining : "<<endl;
        this->doj.display();
    }

};

class Person
{
private:
    string name;
    string addr;
    Date dob;

public:
    Person()
    {
        this->name="";
        this->addr="";
    }
    Person(string name, string addr,int day,int month,int year):dob(day,month,year)
    {
        this->name=name;
        this->addr;
    }

    string getName()
    {
        return this->name;
    }
  

    string getAddress()
    {
        return this->addr;
    }

    Date getDob()
    {
        return this->dob;
    }

    void setName(string name)
    {
        this->name =name;
    }

    void setAddr(string addr)
    {
        this->addr =addr;
    }

    void setDob(Date dob)
    {
        this->dob=dob;
    }
    
    void accept()
    {
        cout<< "Enter your name : ";
        cin>> this->name;
        cout<< "Enter address : ";
        cin>> this->addr;
        cout<< "Enter date of birth : "<<endl;
        dob.accept();

    }

    void display()
    {
        cout<< "Name : "<< this->name<<endl;
        cout<< "Address : "<< this->addr<<endl;
        cout<< "Date of birth : ";
        dob.display();        
    }
};

int main()
{
    Employee e;
    e.accept();
    e.display();

    Person p;
    p.accept();
    p.display();

    Person p1("hrutik","Pune",30,04,2000);
    p1.display();
    
    
    return 0;
}