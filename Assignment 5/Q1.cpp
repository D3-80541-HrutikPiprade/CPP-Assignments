// Q1. Write a class Distance to hold feet and inches. Overload operator + as member function and ==
// operator as friend function. Also, overload ++ operator (to increment inches) as member function
// and -- operator as friend function. Overload << and >> operators to
// accept and display distance.

#include<iostream>
using namespace std;

class Distance
{
private :
    int feet;
    int inches;
public :
    Distance()
    {
        this->feet=0;
        this->inches=0;
    }

    Distance(int feet, int inches)
    {
        this->feet=feet;
        this->inches=inches;
    }

    void accept()
    {
        cout<<"Enter the feet : "<<endl;
        cin>>this->feet;
        cout<<"Enter the inches : "<<endl;
        cin>>this->inches;
    }
    void display()
    {
        cout<<"--------------------------------"<<endl;
        cout<<"Feet : "<< this->feet<<endl;
        cout<<"Inches : "<< this->inches<<endl;
        cout<<"--------------------------------"<<endl;
    }
    Distance operator+(Distance &other)
    {
        Distance d;
        d.feet = this->feet + other.feet;
        d.inches = this->inches + other.inches;
        if(d.inches>12)
        {
            d.feet+= d.inches /12;
            d.inches = d.inches %12 ;
        }
        return d;
    }

    void operator++()
    {
        this->feet;
        this->inches++;
        if(this->inches>12)
        {
            this->feet+= this->inches /12;
            this->inches = this->inches %12 ;
        }
        if(this->inches==12)
        {
            this->feet= this->feet + 1;
            this->inches =0;
        }  
    }

    void operator--()
    {
        if(this->inches==0)
        {
            this->feet--;
            this->inches=11;
        }
        else
        {
            this->inches--;
        }
    
        if(this->inches>12)
        {
            this->feet-= this->inches /12;
            this->inches = this->inches %12 ;
        }  
        if(this->inches==12)
        {
            this->feet= this->feet + 1;
            this->inches =0;
        }  
        
    }
        friend bool operator==(Distance &d1,Distance &d2);
    };

    bool operator==(Distance &d1,Distance &d2)
    {
        if(d1.feet==d2.feet && d1.inches==d2.inches)
        {
            return true;
        }
        else 
            return false;

    }


int main()
{
    Distance d1;
    d1.accept();
    ++d1;
    d1.display();

    Distance d2;
    d2.accept();
    if(d1==d2)
    {
        cout<< " d1 and d2 distance is equal..!!"<<endl;
    }
    else 
        cout<< " d1 and d2 distance is NOT equal..!!"<<endl;

    --d2;
    d2.display();
    
    return 0;
}