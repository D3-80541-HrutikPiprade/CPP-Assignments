// Q1. Write a menu driven program for Date in a C and CPP language.
// Declare a structure Date having data members day, month, year.
// Implement the following functions.
// void initDate(struct Date* ptrDate);
// void printDateOnConsole(struct Date* ptrDate);
// void acceptDateFromConsole(struct Date* ptrDate);

#include<iostream>
using namespace std;

struct Date
{
    //data member
    int day;
    int month;
    int year;

};

void initDate(struct Date* ptrDate)
{
    ptrDate->day=01;
    ptrDate->month=01;
    ptrDate->year=2023;
    return;
}

int menu()
{
    int choice;
    cout<< "  0. Exit" <<endl;
    cout<< "  1. Enter date" <<endl;
    cout<< "  2. Print date" <<endl;
    cout<< "Enter Your choice"<< endl;
    cin >>choice;
    return choice;

}

void printDateOnConsole(struct Date* ptrDate)
{
    cout<< "Date = " << ptrDate->day << " - " << ptrDate->month << " - " << ptrDate->year << endl;
    return;
}

void acceptDateFromConsole(struct Date* ptrDate)
{
    cout<< " Enter day, month and year : ";
    cin>> ptrDate->day >> ptrDate->month >> ptrDate->year ;
    return;
}

int main(){
    struct Date d1;
    initDate(&d1);
    int choice;
    while ((choice = menu()) != 0)
    {
        switch(choice)
        {
            case 1 :
                acceptDateFromConsole(&d1);
                break;
            case 2 :
                printDateOnConsole(&d1);
                break;
            default :
                cout << "Enter Valid Input "<< endl;
                break;
            
        }
    }
    cout<<" Thank you !! "<< endl;
    return 0;
}