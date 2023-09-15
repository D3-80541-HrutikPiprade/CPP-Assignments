// Q2. Write a class for Time and provide the functionality
// Time()
// Time(int h,int m,int s)
// getHour()
// getMinute()
// getSeconds()
// printTime()
// setHour()
// setMinute()
// setSeconds()
// In main create array of objects of Time. Allocate the memory for the
// array and the object dynamically.

#include<iostream>
using namespace std;


class Time
{
private :
    int h;
    int m;
    int s;
public :
    Time()
    {
        this->h=0;
        this->m=0;
        this->s=0;
    }

    Time(int h,int m,int s)
    {
        this->h=h;
        this->m=m;
        this->s=s;
    }

    int getHour()
    {
        return this->h;
    }
    int getMinute()
    {
        return this->m;
    }
    int getSeconds()
    {
        return this->s;
    }
    void printTime()
    {
        cout<< " Time : "<< this->h <<" : " << this->m <<" : " << this->s <<endl;
    }
    void setHour(int h)
    {
        this->h=h;
    }
    void setMinute(int m)
    {
        this->m=m;
    }
    void setSeconds(int s)
    {
        this->s=s;
    }

};

int main()
{
    Time *arr = new Time[3];

    arr[0].setHour(4);
    arr[0].setMinute(35);
    arr[0].setSeconds(43);

    arr[0].printTime();

    arr[1].setHour(3);
    arr[1].setMinute(22);
    arr[1].setSeconds(10);

    arr[1].printTime();

    arr[2].setHour(12);
    arr[2].setMinute(30);
    arr[2].setSeconds(42);

    arr[2].printTime();


}