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

struct Date
{
    //data member
    int day;
    int month;
    int year;

};

void initDate(struct Date* ptrDate)
{
    ptrDate->day=31;
    ptrDate->month=12;
    ptrDate->year=2023;
    
}

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
void printDateOnConsole(struct Date* ptrDate)
{
    cout<< "Date = " << ptrDate->day << " : " << ptrDate->month << " : " << ptrDate->year << endl;
    
}

void acceptDateFromConsole(struct Date* ptrDate)
{
    cout<< " Enter day, month and year : ";
    cin>> ptrDate->day >> ptrDate->month >> ptrDate->year ;
    
}

bool isLeapYear(struct Date* ptrDate)
{
    if((ptrDate->year%4 ==0 && ptrDate->year%100 != 0) || ptrDate->year%400 ==0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }

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
            case 3 :
                if(isLeapYear(&d1))
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