// Q3. Modify Matrix class from previous assignment to implement copy constructor and overload =
// operator.


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
    Matrix()
    {
        this->row=0;
        this->col=0;
        this->matrix =NULL;

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

    Matrix(Matrix &m)     // copy constructor
    {
        this->row = m.row;
        this->col = m.col;
        this->matrix = new int *[m.row];
        for(int i=0;i<m.row;i++)
        {
            matrix[i]=new int[m.col];
        }
        for(int i=0; i<m.row; i++)
            for(int j = 0;j<m.col; j++)
                this->matrix[i][j]=m.matrix[i][j];
    }

    void operator=(Matrix &m)
    {

        for(int i=0; i<this->row;i++)
            delete matrix[i];
        delete[] matrix;

        this->row = m.row;
        this->col = m.col;

        this->matrix = new int *[m.row];
        for(int i=0;i<m.row;i++)
        {
            matrix[i]=new int[m.col];
        }
        for(int i=0; i<m.row; i++)
            for(int j = 0;j<m.col; j++)
                this->matrix[i][j]=m.matrix[i][j];

    }
    ~Matrix()
    {
        if(matrix!=NULL)
        {
            for(int i=0;i<this->row;i++)
                delete matrix[i];
                delete [] matrix;
        }
    }
};

int main()
{

    Matrix m1(3,3);
    m1.accept();
    Matrix m2=m1; //copy constructor;
    m2.print();

    Matrix m3(2,2);
    m3.accept();
    Matrix m4;
    m4=m3;
    m4.print();

    return 0;
}