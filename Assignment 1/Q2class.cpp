// Write a menu driven program for Date in a CPP language using
// structure and also using class.
// Date is having data members day, month, year. Implement the
// following functions.
// void initDate(struct Date* ptrDate);
// void printDateOnConsole(struct Date* ptrDate);
// void acceptDateFromConsole(struct Date* ptrDate);
// bool isLeapYear();


#include<iostream>
using namespace std;

class Date
{
private :
    //data member
    int day;
    int month;
    int year;

public :
void initDate()
{
    this->day=31;
    this->month=12;
    this->year=2023;

}

void printDateOnConsole()
{
    cout<< "Date = " << this->day << " : " << this->month << " : " << this->year << endl;
    return;
}

void acceptDateFromConsole()
{
    cout<< " Enter day, month and year : ";
    cin>> this->day >> this->month >> this->year ;
    return;
}

bool isLeapYear()
{
    if((this->year%4 ==0 && this->year%100 != 0) || this->year%400 ==0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }

}

};

int menu()
{
    int choice;
    cout<< "  0. Exit" <<endl;
    cout<< "  1. Enter date" <<endl;
    cout<< "  2. Print date" <<endl;
    cout<< "  3. Check leap year" <<endl;
    cout<< "Enter Your choice"<< endl;
    cin >>choice;
    return choice;

}

int main(){
    Date d1;
    d1.initDate();
    int choice;
    while ((choice = menu()) != 0)
    {
        switch(choice)
        {
            case 1 :
                d1.acceptDateFromConsole();
                break;
            case 2 :
                d1.printDateOnConsole();
                break;
            case 3 :
                if(d1.isLeapYear())
                    cout << "The Given year is a leap year "<< endl;
                else
                    cout << " The given year is NOT a leap year" << endl;
                break;
            default :
                cout << "Enter Valid Input "<< endl;
                break;
            
        }
    }
    cout<<" Thank you !! "<< endl;
    return 0;
}

