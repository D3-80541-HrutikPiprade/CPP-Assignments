// Q4. Create a class Array. User will provide the size and type of array he wants to create.
// Write a template class for same. It should provide functunalities like addElement(int element),
// displayElement(int index), deleteElement(int index). Also provides mutators and inspectors.

#include<iostream>
using namespace std;
class Array
{
private :
    int size;
    int* ptr;
    int index;
public :
    Array(int size)
    {
        this->size=size;
        this->ptr= new int[this->size];
        this->index=0;
    }

    void addElement(int element)
    {
        if(this->index<this->size)
        {
            this->ptr[this->index]=element;
            index++;
        }
        else
            cout<<"Array is Full !! Cannot add element !!"<<endl;
        
    }

    void displayElement(int index)
    {
        if(index>-1 && index<this->index)
        {
            cout<<"Element [" << index << "] : "<<this->ptr[index]<< endl;
        }
        else
        {
            cout<<"No element exit!!"<<endl;
        }
    }

    int getLength()
    {
        return this->index;
    }

    void displayAll()
    {
        for(int i=0;i<index;i++)
        {
            displayElement(i);
        }
    }

    void deleteAt(int ind)
    {
        int temp;
        for(int i=0;i<size;i++)
        {
            if(i==ind)
            {
                for(int j=ind;j<this->index-1;j++)
                {
                    ptr[j]=ptr[j+1];
                }
                this->index--;
                this->size--;
                break;
                
            }
        }
    }

};

int menu()
{
    int choice;
    cout<<"-------------------------------------"<<endl; 
    cout<<"0. EXIT"<<endl;
    cout<<"1. Add Element"<<endl;
    cout<<"2. Delete Element"<<endl;
    cout<<"3. Display Element "<<endl;
    cout<<"4. Display All Elements"<<endl;
    cout<<"Enter the choice : ";
    cin>>choice;
    cout<<"-------------------------------------"<<endl;
    return choice;
}
int main()
{
    int size,choice,ele;
    cout<<"Enter the Size of array : "<<endl;
    cin>>size;
    Array arr(size);

    while((choice=menu())!=0)
    {
        switch (choice)
        {
        case 1:
            cout<<"Enter the element to add"<<endl;
            cin>>ele;
            arr.addElement(ele);
            break;
        case 2:
            cout<<"Enter the index to delete : "<<endl;
            cin>>ele;
            arr.deleteAt(ele);
            break;
        case 3:
            cout<<"Enter the index to display"<<endl;
            cin>>ele;
            arr.displayElement(ele);
            break;
        case 4:
            arr.displayAll();
            break;
        default:
            cout<<"Enter the valid choice !!"<<endl;
            break;
        }
    }




    return 0;
}