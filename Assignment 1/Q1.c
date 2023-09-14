// Q1. Write a menu driven program for Date in a C and CPP language.
// Declare a structure Date having data members day, month, year.
// Implement the following functions.
// void initDate(struct Date* ptrDate);
// void printDateOnConsole(struct Date* ptrDate);
// void acceptDateFromConsole(struct Date* ptrDate);

#include<stdio.h>

struct Date
{
    int day;
    int month;
    int year;

};

void initDate(struct Date* ptrDate);
int menu();
void printDateOnConsole(struct Date* ptrDate);
void acceptDateFromConsole(struct Date* ptrDate);

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
                printf("\n Enter Valid Input \n");
                break;
            
        }
    }
    printf("\n Thank you !! \n");
    return 0;
}

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
    printf("\n  0. Exit \n  1. Enter date \n  2. Print date \nEnter the choice : ");
    scanf("%d",&choice);
    return choice;

}

void printDateOnConsole(struct Date* ptrDate)
{
    printf("\n Date = %d - %d - %d \n",ptrDate->day,ptrDate->month,ptrDate->year);
    return;
}

void acceptDateFromConsole(struct Date* ptrDate)
{
    printf("\nEnter day, month and year : ");
    scanf("%d%d%d",&ptrDate->day,&ptrDate->month,&ptrDate->year);
    return;
}