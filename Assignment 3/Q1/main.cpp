#include "cylinder.h"

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