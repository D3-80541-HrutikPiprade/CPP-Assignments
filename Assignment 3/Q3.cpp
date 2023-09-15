// Q3. Stack is a Last-In-First-Out data structure. Write a Stack class. It
// implements stack using Dynamically allocated array. Stack size
// should be passed in parameterized constructor. If size is not given,
// allocate stack of size 5. Provide member functions like push(), pop(),
// peek(), isEmpty(), isFull(), and print().

#include<iostream>
using namespace std;

class Stack
{

private : 
    int *stack;
    int limit;
    int top;

public :
    Stack(int size=5)
    {
        this->stack=new int[size];
        this->limit=size;
        this->top=-1;
    }

    bool isEmpty()
    {
        if(this->top==-1)
        {
            return true;
        }
        else
            return false;
    }

    bool isFull()
    {
        if(this->top==(limit-1))
            return true;
        else 
            return false;
    }

    void push()
    {
        if(isFull())
        {
            cout<<"Stack is full"<<endl;
        }
        else
        {
            int value;
            cout<< "Enter the value to push : "<< endl;
            cin>> value;
            this->top++;
            this->stack[this->top]=value;
        }
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<< "Stack is empty...Nothing to Pop..."<<endl;
        }
        else
        {
            cout<<" Poped element : " <<this->stack[this->top]<<endl;
            this->top--;

        }
    }

    void peek()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty..."<< endl;
        }
        else
        {
            cout<< "Peeked element : "<<this->stack[this->top]<<endl;
        }

    }

    void printStack()
    {   
        if(isEmpty())
            cout<<"Stack Empty..."<<endl;
        else
            for(int i = this->top;i>-1;i--)
                cout<<"Stack["<<i+1<<"] = "<<this->stack[i]<<endl;
    }


    ~Stack()
    {
        delete[] stack;
    }
    

};

int menu()
{
    int choice;
    cout<<"--------------------------"<<endl;
    cout<<" 0: EXIT"<<endl;
    cout<<" 1: PUSH element"<<endl;
    cout<<" 2: POP element"<<endl;
    cout<<" 3: PEEK element"<<endl;
    cout<<" 4: Print Stack"<<endl;
    cout<<"Enter your choice  - ";
    cin>>choice;
    cout<<"--------------------------"<<endl;
    return choice;
}
int main()
{
 
    int size,choice;

    cout<<"Enter the size of the stack - ";
    cin>>size;
    Stack s(size);
    while((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.printStack();
            break;
        default:
            cout<<"Enter Valid Choice...!"<<endl;
            break;
        }
    }

    cout<<"Thank You :) "<<endl;
    return 0;

    return 0;
}