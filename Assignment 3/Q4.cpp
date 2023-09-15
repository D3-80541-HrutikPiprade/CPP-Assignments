// Q4. Write a Matrix class. Allocate memory dynamically in
// parameterized constructor. Also write parameter-less constructor.
// Write accept() and print() functions. Also provide add(), subtract(),
// multiply() and transpose() function.

#include<iostream>
using namespace std;

class Matrix
{
private :
    int row;
    int col;
    int **matrix;
    

public :
    Matrix(int row,int col)
    {
        this->row=row;
        this->col=col;
        this->matrix = new int *[row];
        for(int i=0;i<row;i++)
        {
            matrix[i]=new int[col];
        }
        for(int i=0; i<this->row; i++)
            for(int j = 0;j<this->col; j++)
                matrix[i][j]=0;
    }


    void accept()
    {
        cout<<"Enter elements of  Matrix :- "<<endl;
        for(int i=0; i<this->row; i++)
            for(int j = 0;j<this->col; j++)
                cin>>matrix[i][j];
    }

    void print()
    {
        //cout<<"Matrix :- "<<endl;
        for(int i=0; i<this->row; i++)
        {
            for(int j = 0;j<this->col; j++)
                cout<<matrix[i][j]<<" ";
            
            cout<<endl;
        }
    }

    friend void add(Matrix &a,Matrix &b,Matrix &r);
    friend void subtract(Matrix &a,Matrix &b,Matrix &r);
    friend void multiply(Matrix &a,Matrix &b,Matrix &r);
    friend void transpose(Matrix &a,Matrix &r);

};

void add(Matrix &a,Matrix &b,Matrix &r)
{
    for(int i=0; i<r.row; i++)
        {
            for(int j = 0;j<r.col; j++)
            {
                r.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
            }
        }
}

void subtract(Matrix &a,Matrix &b,Matrix &r)
{
    for(int i=0; i<r.row; i++)
        {
            for(int j = 0;j<r.col; j++)
            {
                r.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
            }
        }
}

void multiply(Matrix &a,Matrix &b,Matrix &r)
{
    if(a.row == b.col) //row of 1st matrix should be equal to col of 2nd matrix for multiplication.
        {
            for(int i=0; i<r.row; i++)
            {
                for(int j = 0;j<r.col; j++)
                {
                    r.matrix[i][j] = 0;

                    for(int k = 0; k<r.col;k++)
                        r.matrix[i][k]+= a.matrix[i][k] * b.matrix[k][j];
                }
            }
        }
        else
        {
            cout<<"Cannot multiply matrix (row of mtraix 1 is not equal to column of matrix 2)"<<endl;
        }
}


void transpose(Matrix &a,Matrix &r)
{
    for(int i=0; i<a.row; i++)
        {
            for(int j = 0;j<a.col; j++)
            {
                r.matrix[i][j] = a.matrix[j][i];
            }
        }
}



int main()
{

    Matrix m1(3,3);
    Matrix m2(3,3);
    Matrix result(3,3);
    m1.accept();
    m2.accept();
    add(m1,m2,result);
    cout<<"The addition of matrix is : "<< endl;
    result.print();

    subtract(m1,m2,result);
    cout<<"The subtraction of matrix is : "<< endl;
    result.print();

    multiply(m1,m2,result);
    cout<<"The multiplication of matrix is : "<< endl;
    result.print();

    transpose(m1,result);
    cout<<"The transpose of matrix is : "<< endl;
    result.print();

    return 0;
}