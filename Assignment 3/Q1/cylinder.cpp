#include "cylinder.h"



    Cylinder::Cylinder():height(0),radius(0),volume(0)
    {
    }

    Cylinder::Cylinder(double radius, double height)
    {
        this->radius=radius;
        this->height=height;

    }
    double Cylinder::getRadius()
    {
        return this->radius;
    }
    void Cylinder::setRadius(double radius)
    {
        this->radius=radius;
    }

    double Cylinder::getHeight()
    {
        return this->height;
    }
    void Cylinder::setHeight(double height)
    {
        this->height=height;
    }

    double Cylinder::getVolume()
    {
        this->volume = Cylinder::pi * this->height * this->radius;
        return volume;
    }
    void Cylinder::printVolume()
    {
        this->volume = Cylinder::pi * this->height * this->radius;
        cout<< " The volume of the cylinder = "<< this->volume <<endl;
    }

const double Cylinder::pi=3.14;