// Q3. Write a class to store Account information of Bank customer byusing following class diagram.
// Use enum to store information of account type. Create an array of 5 Accounts in main() and accept
// their details from user. Write Menu driven program to deposit/withdraw amount from the account.
// After each transaction display updated account balance. Provide appropriate getters/setters with
// necessary validations. Throw exceptions for invalid values. Also implement an exception class
// InsufficientFunds. In withdraw() member function, if sufficient balance is not available
// in account, throw this exception.


#include<iostream>
using namespace std;
enum accountType
{
    SAVING,
    CURRENT,
    DMAT
};

string arr[3]={"SAVING","CURRENT", "DMAT"};

class InsufficientFunds
{
private:
    int accid;
    double curr_balance;
    double withdraw_amount;

public:
    InsufficientFunds(int id,double balance,double withdraw_amount)
    {
        this->accid=id;
        this->curr_balance=balance;
        this->withdraw_amount=withdraw_amount;

    }

    void display()
    {
        cout<<"Transaction Failed! Insufficient balance !!"<<endl;
        cout<<"Your account balance : "<< this->curr_balance <<endl;
    }



};
class Account
{
private:
    int id;
    accountType type;
    double balance;

public:
    Account()
    {
        this->id=0;
        this->type=SAVING;
        this->balance=0;
    }

    Account(int id,accountType type,double balance)
    {
        this->id=id;
        this->type=type;
        this->balance=balance;
    }

    static Account accept()
    {
        int id, type;
        double balance;
        cout<<"Enter Id : ";
        cin>>id;
        if(id<0)
            throw 2;
        cout<<"  1. SAVING"<<endl;
        cout<<"  2. CURRENT"<<endl;
        cout<<"  3. DMAT"<<endl;
        cout<<"Enter Account type : ";
        cin>>type;
        if(type<1 || type>3)
            throw 'a';
        cout<<"Enter opening balance : ";
        cin>>balance;
        if(balance<0)
            throw 1.2f;
        return Account(id,accountType(type),balance);   

    }

    void display()
    {
        cout<<"================================"<<endl;
        cout<< "Account id : "<< this->id<<endl;
        cout<< "Account type : "<< arr[this->type-1]<<endl;
        cout<< "Balance : "<< this->balance<<endl;
        cout<<"================================"<<endl;

    }

    void setId(int id)
    {
        this->id=id;
    }

    void setType(accountType type)
    {
        this->type=type;
    }

    int getId()
    {
        return this->id;
    }

    accountType getType()
    {
        return this->type;
    }

    double getBalance()
    {
        return this->balance;
    }

    void deposit(double amount)
    {
        if(amount<1)
            throw 2.1;
        this->balance+=amount;
    }


    void withdraw(double amount)
    {
        if(this->balance<amount)
            throw InsufficientFunds(this->id,this->balance,amount);
        else
        {
            this->balance-=amount;
            cout<<"Transaction Sucessfull..!!"<<endl;
            cout<<"Updated Balance : " << this->balance<<endl;
        }
    }   
    
};

int menu()
{
    int choice;
    cout<<"-------------------------------------"<<endl;
    cout<<" 0. EXIT"<<endl;
    cout<<" 1. Display Account details"<<endl;
    cout<<" 2. Deposit Amount"<<endl;
    cout<<" 3. Withdraw Amount"<<endl;
    cout<< "Enter your choice : "<<endl;
    cin>>choice;
    cout<<"-------------------------------------"<<endl;
        return choice;

}

int main()
{
    Account acc[5];
    for(int i=0; i<5;i++)
    {
        try
        {
            acc[i] = Account::accept();
        }
        catch(int error)
        {
            cout<<"Invalid account id !!"<<endl;
            i--;
        }
        catch(char error)
        {
            cout<<"Invalid account type !!"<<endl;
            i--;
        }
        catch(float error)
        {
            cout<<"Invalid amount!! Cannot be less than zero!"<<endl;
            i--;
        }
    }

    int accno,choice,index,amount,flag=1;
    do
    {
    cout<<"Enter the Account id to do transaction : ";
    cin>>accno;
    for(int i=0;i<5;i++)
    {
        if(acc[i].getId()==accno)
        {
            index=i;
            break;
        }
    }
    while((choice=menu())!=0)
    {
        switch (choice)
        {
        case 1:
            acc[index].display();
            break;
        case 2:
            cout<<"Enter the Amount to deposit : ";
            cin>>amount;
            try
            {
            acc[index].deposit(amount);
            }
            catch(double error)
            {
                cout<<"The amount to be deposit should be greater than Rs. 1 "<<endl;
            }
            break;
        case 3:
            cout<<"Enter the Amount to Withdraw : ";
            cin>>amount;
            try
            {
                acc[index].withdraw(amount);
            }
            catch(InsufficientFunds error)
            {
                error.display();
            }
            break;
        default:
            break;
        }
    }
        cout<<"Do Transaction in another account ?"<<endl;
        cout<<"1. yes"<<endl;
        cout<<"2. No"<<endl;
        cin>>flag;
    }while(flag!=2);

}