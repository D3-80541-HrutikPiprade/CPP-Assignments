// Q2. Create a user defined class “Fraction” with data members numerator and denominator. Provide
// constructors, getter/setters and methods like lowestForm() and decimalValue(). The
// setDenominator() method should throw exception if value is zero. Overload operators +, -, *, /, =,
// ==, !=, <, >.

#include<iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction()
    {
        this->numerator=0;
        this->denominator=0;
    }

    Fraction(int numerator,int denominator)
    {
        this->numerator=numerator;
        this->denominator=denominator;
    }

    void accept()
    {
        cout<<"Enter the numerator : ";
        cin>>this->numerator;

        cout<<"Enter the denominator : ";
        cin>>this->denominator;

    }

    void display()
    {
        cout<<"-------------------------"<<endl;
        cout<< "Numerator : "<<this->numerator<<endl;
        cout<< "Denominator : "<<this->denominator<<endl;
        cout<<"-------------------------"<<endl;

    }

    int getNumerator()
    {
        return this->numerator;
    }

    int getDenominator()
    {
        return this->denominator;
    }

    void setNumerator(int numerator)
    {
        this->numerator=numerator;
    }

    void setDenominator(int denominator)
    {
        this->denominator=denominator;
    }

    float decimalValue()
    {
        return (float)numerator/(float)denominator;
    }
    
    int findGCD(int numerator, int denominator)
    {
        if(denominator == 0)
            return numerator;
        return findGCD(denominator,numerator % denominator);
    }

    void lowestForm()
    {
        int temp;
        temp = findGCD(this->numerator,this->denominator);
        this->numerator/=temp;
        this->denominator/=temp;
    }

    Fraction operator+(Fraction &other)
    {
        Fraction temp;
        temp.numerator=(this->numerator*other.denominator)+(other.denominator*this->numerator);
        temp.denominator= this->numerator * this->denominator;
        temp.lowestForm();
        return temp;
    }

    Fraction operator-(Fraction &other)
    {
        Fraction temp;
        temp.numerator=(this->numerator*other.denominator)-(other.denominator*this->numerator);
        temp.denominator= this->numerator * this->denominator;
        temp.lowestForm();
        return temp;
    }

    Fraction operator*(Fraction &other)
    {
        Fraction temp;
        temp.numerator= (this->numerator*other.numerator);
        temp.denominator= this->denominator*other.denominator;
        temp.lowestForm();
        return temp;
    }

    Fraction operator/(Fraction &other)
    {
        Fraction temp;
        temp.numerator=this->numerator/other.numerator;
        temp.denominator=this->denominator/other.denominator;
        temp.lowestForm();
        return temp;
    }

    void operator=(Fraction &other)
    {
        this->numerator=other.numerator;
        this->denominator=other.denominator;
        
    }

    bool operator==(Fraction &other)
    {
        this->lowestForm();
        other.lowestForm();

        if((this->numerator==other.numerator) && (this->denominator==other.numerator))
            return true;
        else
            return false; 
    }

    bool operator!=(Fraction &other)
    {
        this->lowestForm();
        other.lowestForm();

        if((this->numerator!=other.numerator) && (this->denominator!=other.numerator))
            return true;
        else
            return false; 
    }

    bool operator<(Fraction &other)
    {
        float frac1=this->decimalValue();
        float frac2=other.decimalValue();

        if(frac1<frac2)
            return true;
        else
            return false;
    }

    bool operator>(Fraction &other)
    {
        float frac1=this->decimalValue();
        float frac2=other.decimalValue();

        if(frac1>frac2)
            return true;
        else
            return false;
    }


};

int main()
{
    Fraction f1;
    f1.accept();
    Fraction f2;
    f2.accept();

    Fraction f3=f1+f2;
    f3.display();

    Fraction f4= f1-f2;
    f4.display();

    Fraction f5=f1*f2;
    f5.display();

    Fraction f6=f1/f2;
    f6.display();

    if(f1==f2)
    {
        cout<<"Fraction 1 is equal to fraction f2"<<endl;
    }
    else
    {
        cout<<"Fraction 1 is NOT equal to fraction f2"<<endl;
    }

    if(f1>f2)
    {
        cout<<"Fraction F1 is greater than fraction f2"<<endl;
    }
    else if(f1<f2)
    {
        cout<<"Fraction F2 is greater than fraction F1"<<endl;
    }

    return 0;

}