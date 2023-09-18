// Q1. Write a user defined function factorial() that calculates factorial of given number and it throws
// exception if number entered by user is negative.

#include<iostream>
using namespace std;

void factorial()
{
    int num,fact=1;
    cout<<"Enter the number : ";
    cin>>num;
    int n=num;
    if(num<0)
        throw 1;
    for(int i=0;i<n;i++)
    {
        fact*=num;
        --num;
    }
    cout<<"The factorial of number is : "<< fact <<endl;


}
int main()
{

    try
    {
        factorial();
    }
    catch(int error)
    {
        cout<<"ERROR-Enter a positive value"<<endl;
        try
        {
            factorial();
        }
        catch(int error)
        {
            cout<<"ERROR - You have entered negative value"<<endl;
        }
        

    }

}