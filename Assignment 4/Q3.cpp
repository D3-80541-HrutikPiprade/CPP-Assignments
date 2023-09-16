// Q3. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
// holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
// Assuming that each user purchase 3 products (either book or tape), calculate final
// bill. The program should be menu driven and should not cause
// memory leakage.


#include<iostream>
using namespace std;



class Book
{
private :
    int id;
    string title;
    string author;
    double price;
public :
    Book()
    {
        this->id=0;
        this->title="";
        this->author="";
        this->price=0;
    }
    void accept()
    {
        cout<<"Enter the Book ID : ";
        cin>>this->id;
        cout<<"Enter the title : ";
        cin>>this->title;
        cout<<"Enter the author : ";
        cin>>this->author;
        cout<<"Enter the price: ";
        cin>>this->price;
    }

    void display()
    {
        cout<< "Book ID : "<< this->id<<endl;
        cout<< "Title : "<< this->title<<endl;
        cout<< "author : "<< this->author<<endl;
        cout<< "Price : "<< this->price<<endl;
    }

    double getPrice()
    {
        return this->price;
    }

};

class Tape
{
private :
    int id;
    string title;
    string artist;
    double price;
public :
    Tape()
    {
        this->id=0;
        this->title="";
        this->artist="";
        this->price=0;
    }

    void accept()
    {
        cout<<"Enter the Tape ID : ";
        cin>>this->id;
        cout<<"Enter the title : ";
        cin>>this->title;
        cout<<"Enter the Artist : ";
        cin>>this->artist;
        cout<<"Enter the price: ";
        cin>>this->price;
    }

    void display()
    {
        cout<< "Tape ID : "<< this->id<<endl;
        cout<< "Title : "<< this->title<<endl;
        cout<< "Artist : "<< this->artist<<endl;
        cout<< "Price : "<< this->price<<endl;
    }

    double getPrice()
    {
        return this->price;
    }


};

class Shop
{
    double bill;
    Book *bptr;
    Tape *tptr;
    int b;
    int t;

public :
    Shop()
    {
        this->bill=0;
        this->bptr=NULL;
        this->tptr=NULL;
        this->b=0;
        this->t=0;
    }
    void addBook()
    {
        
        cout<<"Enter the number of books : ";
        cin>>b;
        if(b<=3)
        {
            bptr=new Book[b];
            for(int i=0 ;i<b ;i++)
            {
                this->bptr[i].accept();

            }
        }
        else
        {
            cout<<"Enter maximun 3 BOOKS"<<endl;
            cout<<"---------------------"<<endl;
        }
    }

    void addTape()
    {
        
        cout<<"Enter the number of Tape : ";
        cin>>t;
        if(t<=3)
        {
            tptr=new Tape[t];
            for(int i=0 ;i<t;i++)
            {
                this->tptr[i].accept();

            }

        }
        else
        {
        
            cout<<"Enter maximun 3 TAPE"<<endl;
            cout<<"---------------------"<<endl;
        }
    }

    

    void calculateFinalBill()
    {
    
        for(int i=0 ;i<b;i++)
        {
            bill+=(this->bptr[i].getPrice())*0.90;
        }
        
        for(int i=0 ;i<t;i++)
        {
            bill+=(this->tptr[i].getPrice())*0.95;
        }

        cout<<"-------------------------------------------"<<endl;
        cout<< "Billing Amount after Discount = "<< this->bill << endl;
        cout<<"-------------------------------------------"<<endl;
        

    }

    ~Shop()
    {
        if(bptr!=NULL)
        {
            delete[] bptr;
        }

        if(tptr!=NULL)
        {
            delete[] tptr;
        }
    }

};

int menu()
{
    int choice;
    cout<< "  0. Exit" <<endl;
    cout<< "  1. BOOK" <<endl;
    cout<< "  2. TAPE" <<endl;
    cout<< "  3. FINAL BILL" <<endl;
    cout<< "Enter Your choice"<< endl;
    cin >>choice;
    return choice;

}

int main()
{
    Shop s;
    int choice;
    int b=0,t=0;
    while ((choice = menu()) != 0)
    {
        switch(choice)
        {
            case 1 :
                s.addBook();
                break;
            case 2 :
                s.addTape();
                break;
            case 3:
                s.calculateFinalBill();
                break;
            default :
                cout << "Enter Valid Input "<< endl;
                break;
            
        }
    }
    cout<<" Thank you..!! "<< endl;
}