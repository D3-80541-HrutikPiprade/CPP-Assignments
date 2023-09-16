// Q1. Write a menu driven program for Student management. In main(), create Array of Objects and
// provide facility for accept, print, search and sort.
// For student accept name, gender, rollNumber and marks of three subjects from user and print name,
// rollNumber, gender and percentage.
// Provide global functions void sortRecords(Studuent[] arr) and int searchRecords(Student[] arr) for
// sorting and searching array.
// Search function returns index of found Student, otherwise returns -1.

#include<iostream>
using namespace std;

class Student 
{
private :
    string name;
    char gender;
    int rollNumber;
    float sub1;
    float sub2;
    float sub3;

public :
    Student()
    {
        this->name="";
        this->gender='-';
        this->rollNumber=0;
        this->sub1=0;
        this->sub2=0;
        this->sub3=0;

    }
 
    Student(string name,char gender,int rollNumber,float sub1,float sub2,float sub3)
    {
        this->name=name;
        this->gender=gender;
        this->rollNumber=rollNumber;
        this->sub1=sub1;
        this->sub2=sub2;
        this->sub3=sub3;
    }

    void acceptData()
    {
        cout<<"Enter name of student : ";
        cin>>this->name;
        cout<<"Enter gender (M/F) :";
        cin>>this->gender;
        cout<<"Enter Roll number : ";
        cin>>this->rollNumber;
        cout<<"Enter marks of Subject 1 : ";
        cin>>this->sub1;
        cout<<"Enter marks of Subject 2 : ";
        cin>>this->sub2;
        cout<<"Enter marks of Subject 3 : ";
        cin>>this->sub3;       
    }

    void printData()
    {
        cout<<"---------------------------------"<<endl;
        cout<< "Name : "<< this->name<<endl;
        cout<< "Gender : "<< this->gender<<endl;
        cout<< "Roll Number : "<< this->rollNumber<<endl;
        cout<< "Percentage : "<< (this->sub1 + this->sub2 + this->sub3)/3 <<endl;
        cout<<"---------------------------------"<<endl;

    }

    friend int searchRecords(Student arr[], int size);
    friend void sortRecords(Student arr[], int size);
    
};

void sortRecords(Student arr[], int size)
{
    Student temp;
    for(int i=0;i< size;i++)
    {
        for(int j=0; j<size-i;j++)
        {
            if(arr[j].rollNumber> arr[j+1].rollNumber)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

}

int searchRecords(Student arr[],int size)
{
    int roll=0;
    cout<<"Enter the roll No. to search : ";
    cin>>roll;
    int i;
    for( i=0;i<size;i++)
    {
        if(arr[i].rollNumber==roll)
        {
            return i;
        }
    }
    return -1;

}

enum Emenu
{
    EXIT,
    ACCEPT,
    PRINT,
    SEARCH,
    SORT
};

Emenu menu()
{
    int choice;
    cout<< "  0. Exit" <<endl;
    cout<< "  1. Accept" <<endl;
    cout<< "  2. Print" <<endl;
    cout<< "  3. Search" <<endl;
    cout<< "  4. Sort" <<endl;
    cout<< "Enter Your choice"<< endl;
    cin >>choice;
    return Emenu(choice);

}



int main()
{

    int size,index=0;
    cout<<"Enter the number of Studnets : ";
    cin>>size;

    Student arr[size];

    Emenu choice;

    while ((choice = menu()) != EXIT)
    {
        switch(choice)
        {
            case  ACCEPT:
                if(index<size)
                {
                    arr[index].acceptData();
                    index++;
                }
             
                break;
            case PRINT:
                for(int i=0; i<index; i++)
                {
                    arr[i].printData();
                }
                break;

            case SEARCH:
                int ind = searchRecords(arr,index);
                if(ind!=-1)
                {
                    cout<<"Student is found at index : "<< ind<<endl;
                }
                else
                    cout<<"Student not found !! "<<endl;
                break;
            case SORT:
                sortRecords(arr,index);
                break;
            default :
                cout << "Enter Valid Input "<< endl;
                break;
            
        }
    }
    cout<<" Thank you !! "<< endl;



}