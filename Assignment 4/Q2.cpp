// Implement following classes. Test all functionalities in main() of each created class. Note that
// employee is inherited into manager and salesman.

#include<iostream>
using namespace std;

class Employee
{
private :
    int id;
    float sal;

public:
    Employee()
    {
        this->id=0;
        this->sal=0;
    }

    Employee(int id,float sal)
    {
        this->id=id;
        this->sal=sal;
    }

    int getId()
    {
        return this->id;
    }

    int getSal()
    {
        return this->sal;
    }

    void setId(int id)
    {
        this->id=id;
    }

    void setSal(float sal)
    {
        this->sal=sal;
    }

    virtual void display()
    {
        cout<<"Employee ID : "<< this->id<<endl;
        cout<<"Salary : "<< this->sal<<endl;  
    }

    virtual void accept()
    {
        cout<<"Enter the Employee ID : "<<endl;
        cin>>this->id;
        cout<<"Enter the Salary : "<<endl;
        cin>>this->sal;
    }

};

class Manager : virtual public Employee
{
private :
    float bonus;

protected :
    void display_manager()
    {
        cout<<"Bonus : "<< this->bonus<<endl; 
    }

    void accept_manager()
    {
        cout<<"Enter the bonus : "<<endl;
        cin>>this->bonus;
    }

public :
    Manager()
    {
        this->bonus=0;
    }

    Manager(float bonus)
    {
        this->bonus=bonus;
    }

    int getBonus()
    {
        return this->bonus;
    }

    void setbonus(int bonus)
    {
        this->bonus=bonus;
    }

    void display()
    {
        Employee::display();
        this->display_manager();
 
    }

    void accept()
    {
        Employee::accept();
        this->accept_manager();

    }



};

class Salesman : virtual public Employee
{
private :
    float comm;

protected :
    void display_salesman()
    {
        cout<<"Commission : "<< this->comm<<endl; 
    }

    void accept_salesman()
    {
        cout<<"Enter the Commission : "<<endl;
        cin>>this->comm;
    }


public :
    Salesman()
    {
        this->comm=0;
    }

    Salesman(float comm)
    {
        this->comm=comm;
    }

    int getComm()
    {
        return this->comm;
    }

    void setComm(int comm)
    {
        this->comm=comm;
    }

    void display()
    {
        Employee::display();
        this->display_salesman();
 
    }

    void accept()
    {
        Employee::accept();
        this->accept_salesman();

    }



};

class SalesManager : public Manager,public Salesman
{
public :
    
    void display()
    {
        Employee::display();
        this->display_manager();
        this->accept_salesman();
    }

    void accept()
    {
        Employee::accept();
        this->accept_manager();
        this->accept_salesman();
    }

};

int main()
{
    Employee *e1 = new Manager;
    e1->accept();
    e1->display();

    Employee *e2 = new Salesman;
    e2->accept();
    e2->display();

    Employee *e3 = new SalesManager;
    e3->accept();
    e3->display();
}


