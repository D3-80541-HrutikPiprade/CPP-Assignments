// Q1. Using the Q2 from assignment 4.
// Create an array of 10 employees.
// Provide menu driven code for the functionalities:
// 1. Accept Employee
// 2. Display the count of all employees with respect to
// designation
// 3. Display All Managers
// 4. Display All SalesMan
// 5. Display All SalesManager

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
    
    virtual ~Employee()
    {
        
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
        cout<<"-----------------------------------"<<endl;
        Employee::display();
        this->display_manager();
        cout<<"-----------------------------------"<<endl;
 
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
        cout<<"-----------------------------------"<<endl;
        Employee::display();
        this->display_salesman();
        cout<<"-----------------------------------"<<endl;

 
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
        cout<<"-----------------------------------"<<endl;
        Employee::display();
        this->display_manager();
        this->display_salesman();
        cout<<"-----------------------------------"<<endl;
    }

    void accept()
    {
        Employee::accept();
        this->accept_manager();
        this->accept_salesman();
    }

};
void displayCount(Employee *eptr[],int index)
{
    int manager=0,salesman=0,salesmanager=0;
    for(int i=0; i<index;i++)
    {
        if(typeid(*eptr[i])==typeid(Manager))
        {
            manager++;
        }
        else if(typeid(*eptr[i])==typeid(Salesman))
        {
            salesman++;
        }
        else if(typeid(*eptr[i])==typeid(SalesManager))
        {
            salesmanager++;
        }
    }
    cout<<"-----------------------------------"<<endl;
    cout<<"Count of All Employees :"<<endl;
    cout<<" No. of Manager = "<< manager<<endl;
    cout<<" No. of Salesman = "<< salesman<<endl;
    cout<<" No. of SalesManager = "<< salesmanager<<endl;
    cout<<"-----------------------------------"<<endl;


}

void displayAllManager(Employee *eptr[],int index)
{
    for(int i=0; i<index;i++)
    {
        if(typeid(*eptr[i])==typeid(Manager))
        {
            eptr[i]->display();
        }
    }
}

void displayAllSalesman(Employee *eptr[],int index)
{
    for(int i=0; i<index;i++)
    {
        if(typeid(*eptr[i])==typeid(Salesman))
        {
            eptr[i]->display();
        }
    }
}

void displayAllSalesManager(Employee *eptr[],int index)
{
    for(int i=0; i<index;i++)
    {
        if(typeid(*eptr[i])==typeid(SalesManager))
        {
            eptr[i]->display();
        }
    }
}

int menu()
{
    int choice;
    cout<<" 0. Exit"<<endl;
    cout<<" 1. Enter Manager"<<endl;
    cout<<" 2. Enter Salesman"<<endl;
    cout<<" 3. Enter SalesManager"<<endl;
    cout<<" 4. Display the count of all employees"<<endl;
    cout<<" 5. Display All Managers"<<endl;
    cout<<" 6. Display All SalesMan"<<endl;
    cout<<" 7. Display All SalesManager"<<endl;
    cout<<" Enter your choice : ";
    cin>>choice;
    return choice;

}

int main()
{
    Employee *eptr[10] ={NULL} ;
    int choice,index=0;
    while((choice=menu())!=0)
    {
        switch (choice)
        {
        case 1:
            eptr[index]=new Manager();
            eptr[index]->accept();
            index++;
            break;
        case 2:
            eptr[index]=new Salesman();
            eptr[index]->accept();
            index++;
            break;
        case 3:
            eptr[index]=new SalesManager();
            eptr[index]->accept();
            index++;
            break;
        case 4:
            displayCount(eptr,index);
            break;
        case 5:
            displayAllManager(eptr,index);
            break;
        case 6:
            displayAllSalesman(eptr,index);
            break;
        case 7:
            displayAllSalesManager(eptr,index);
            break;
        default:
            cout<<"Enter valid choice !!"<<endl;
            break;
        }

    }

    for(int i=0;i<10;i++)
    {
        if(eptr[i]!=NULL)
        {
            delete eptr[i];
            eptr[i]=NULL;
        }
    }
}

