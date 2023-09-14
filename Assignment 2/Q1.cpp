// Q1. Write a menu driven program to calculate volume of the box.
// Provide necessary constructors.

#include<iostream>
using namespace std;

class Box
{
private :
    int len;
    int bre;
    int hei;

public :
    Box()
    {
        this->len=0;
        this->bre=0;
        this->hei=0;
    }

    Box(int len, int bre=0, int hei=0)
    {
        this->len=len;
        this->bre=bre;
        this->hei= hei;

    }

    void acceptDimension()
    {
        cout<<" Enter the length : "<<endl;
        cin>>this->len;

        cout<<" Enter the breadth : "<<endl;
        cin>>this->bre;

        cout<<" Enter the height : "<<endl;
        cin>>this->hei;


    }

    void printDmension()
    {
        cout<< "Length = "<< this->len << endl;
        cout<< "Breadth = "<< this->bre << endl;
        cout<< "Height = "<< this->hei << endl;
    }

    void volume()
    {
        cout<< " Volume of Box = " << this->len * this->bre * this->hei <<endl;

    }
};

int menu()
{
    int choice;
    cout<< "  0. Exit" <<endl;
    cout<< "  1. Enter Dimensions" <<endl;
    cout<< "  2. Print Dimensions" <<endl;
    cout<< "  3. Calculate volume" <<endl;
    cout<< "Enter Your choice"<< endl;
    cin >>choice;
    return choice;
}

int main()
{
    Box b;

    int choice;
    while ((choice = menu()) != 0)
    {
        switch(choice)
        {
            case 1 :
                b.acceptDimension();
                
                break;
            case 2 :
                b.printDmension();
                break;
            
            case 3 :
                b.volume();
            
            default :
                cout << "Enter Valid Input "<< endl;
                break;
            
        }
    }
    cout<<" Thank you !! "<< endl;

}