// Q1. Write a class to find volume of a Cylinder by using following
// members. (volume of Cylinder=3.14 * radius * radius *height) ( use
// modular approach)
// Class having following member functions:
// Cylinder()
// Cylinder(double radius, double height)
// getRadius()
// setRadius()
// getHeight()
// setHeight()
// getVolume()
// printVolume()
// Initialize members using constructor member initializer list.

#include<iostream>
using namespace std;

class Cylinder
{
private:
    double radius;
    double height;
    double volume;
    static const double pi;

public :

    Cylinder():height(0),radius(0),volume(0)
    {
    }

    Cylinder(double radius, double height)
    {
        this->radius=radius;
        this->height=height;

    }
    double getRadius()
    {
        return this->radius;
    }
    void setRadius(double radius)
    {
        this->radius=radius;
    }

    double getHeight()
    {
        return this->height;
    }
    void setHeight(double height)
    {
        this->height=height;
    }

    double  getVolume()
    {
        this->volume = Cylinder::pi * this->height * this->radius;
        return volume;
    }
    void printVolume()
    {   
        this->volume = this->getVolume();
        cout<< " The volume of the cylinder = "<< this->volume <<endl;
    }
};
const double Cylinder::pi=3.14;


int main()
{

    Cylinder c1;
    //c1.printVolume();
    double radius,height;
    cout<< "Enter the radius of Cylinder :";
    cin>>radius;
    c1.setRadius(radius);
    cout<< "Enter the height of Cylinder :";
    cin >> height;
    c1.setHeight(height);
    c1.printVolume();

    Cylinder c2(3,5);
    c2.printVolume();


}