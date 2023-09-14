// Imagine a tollbooth at a bridge. Cars passing by the booth are
// expected to pay a fifty-cent toll. Mostly they do, but sometimes a car
// goes by without paying.
// The tollbooth keeps track of the number of cars that have gone by
// and of the total amount of money collected. Model this tollbooth
// with a class called tollbooth.
// The two data items are a type unsigned int to hold the total number
// of cars, and a type double to hold the total amount of money
// collected.
// A constructor initializes all data members to 0.
// A member function called payingCar() increments the car total and
// adds 0.50 to the cash total. Another function, called nopayCar()
// increments the car total but adds nothing to the cash total.
// Finally, a member function called printOnConsole() displays the two
// totals and number of paying as well as non paying cars total.

#include<iostream>
using namespace std;

class Tollbooth
{
private :
    unsigned int paidcar;
    unsigned int unpaidcar;
    double amount;

public :
    Tollbooth()
    {
        this->paidcar=0;
        this->unpaidcar=0;
        this->amount=0.00;
    }

    Tollbooth(unsigned int paidcar, unsigned int unpaidcar, double amount)
    {
        this->paidcar = paidcar;
        this->unpaidcar= unpaidcar;
        this->amount= amount;
    }

    void payingCar()
    {
        this->paidcar++;
        this->amount=this->amount + 0.50;
    }

    void nopaycar()
    {
        this->unpaidcar++;
    }

    void printOnConsole()
    {
        cout<< "Total paid cars = "<< this->paidcar << endl;
        cout<< "Total unpaid cars = "<< this->unpaidcar << endl;

        cout<< "Total cars = "<< this->paidcar + this->unpaidcar << endl;
        cout<< "Total amount = " << this->amount << endl;
    }
};

int menu()
{
    int choice;
    cout<< "---------------------------------------------"<<endl;
    cout<< "0. EXIT"<< endl;
    cout<< "1. Paid car passes..."<< endl;
    cout<< "2. Unpaid car passes..."<< endl;
    cout<< "3. Display details of  total car and amount "<<endl;
    cout<< "Enter your choice : ";
    cin>>choice;
    cout<< "---------------------------------------------"<<endl;

    return choice;
}
int main()
{
    Tollbooth t1;

    
    int choice;
    while((choice=menu())!=0)
    {
    switch (choice)
    {
    case 1 :
        t1.payingCar();
        break;
    case 2 :
        t1.nopaycar();
        break;
    case 3 :
        t1.printOnConsole();
        break;

    default:
        cout<<"Invalid Input...!!!"<<endl;
        break;
    }
    }
printf("Thank you...!");
    return 0;
}