#ifndef VECTORFCI_H
#define VECTORFCI_H
#include <iostream>
using namespace std;
template <class T>
class VectorFCI
{
private :
    T* elements;
    int numberOfElements;
    int capacity;
public:
    /*constructor that initializes the class attributes ( capacity , size , vector)*/
    VectorFCI()
    {
        capacity=1;
        numberOfElements=0;
        elements = new T [capacity];
    }
    /* function that returns the size of the vector */
    int sizee()
    {
        return numberOfElements;
    }
    /* function that returns the vector capacity*/
    int capacityy()
    {
         return capacity;
    }
    /* function that returns whether the vector is empty or not */
    bool emptyy ()
    {
        if (numberOfElements != 0)
        {
            return false;
        }
        return true;
    }
    /* function that deletes last element in the vector */
    void pop__back ()
    {
        numberOfElements--;
    }
    /* operator overloading for indexing operator*/
    T&  operator [](int i)
    {

        return elements[i];
    }
    /*function that adds element at the end of the vector*/
    void push__back(T x)
    {
        if (numberOfElements==capacity)
        {
            reserve (); // calling reserve function which reserve new capacity if the vector is full
        }
        elements[numberOfElements]=x;  // hena eh l bye7sal ??????????????
        numberOfElements++;
    }
    /* function that returns a pointer to the first element in the vector */
    T* beginn()
    {
        return elements;
    }
    /* function that returns address of the first element in the vector */
    T& frontt( )
    {
        return elements[0];
    }
    /* function that returns address of the last element in the vector */
    T& backk( )
    {
        return elements[numberOfElements -1];
    }
    /* function that deletes all the elements in a vector */
    void clearr()
    {
        delete[] elements;
        numberOfElements = 0;
    }
    /*function that deletes element from a certain position */
    void erasee ( T* position)
    {
        T* temp;
        temp = new T[numberOfElements-1];
        bool indexFound=false;
        int positionIndex;
        for ( int i=0 ; i< numberOfElements ; i++) // for loop searches for the index of the element user want to erase
          {

              if (beginn()+i == position)
                {
                    indexFound=true;
                    positionIndex=i;
                }
          }
        bool reached = false;
        int newj=positionIndex;
        if (indexFound)
        {
            for (int j=0 ; j<numberOfElements-1 ; j++) // for loop copies all elements for a temp vector except
                                                      //the element user want to erase
            {
                if (j==positionIndex)
                    {
                        reached = true;
                    }
                if (reached)
                {
                    temp[j]=elements[newj+1];
                    newj++;
                }
                else
                {
                    temp[j]=elements[j];
                }
            }

            for ( int i=0 ; i<numberOfElements-1 ;i++)
            {
                elements[i]=temp[i];
            }
        }
        else
        {
            cout<<"element you want to erase is not in the vector"<<endl;
        }
        delete [] temp;
        numberOfElements--;
    }
/* function that insert element at a certain position inside the vector */
void insertt(T* position , T val)
 {
        T* temp;
        temp = new T[numberOfElements+1];
        bool indexFound=false;
        int positionIndex;
        for ( int i=0 ; i< numberOfElements ; i++)
          {

              if (beginn()+i == position)
                {
                    indexFound=true;
                    positionIndex=i;
                }
          }
              if (numberOfElements==capacity)
                {
                    reserve (); // calling reserve function which reserve new capacity if the vector is full
                }
        bool reached = false;
        int newj=positionIndex;
        if (indexFound)
        {
            for (int j=0 ; j<numberOfElements+1 ; j++)
            {
                if (j==positionIndex)
                    {
                        temp[j]=val;
                        reached = true;
                        continue;
                    }
                if (reached)
                {
                    temp[j]=elements[newj];
                    newj++;
                }
                else
                {
                    temp[j]=elements[j];
                }
            }
        numberOfElements++;
        }
        else
        {
            cout<<" you can't access that index , the size of the vector is only " << sizee() <<endl;
        }
        elements = temp;
 } /* function that expands the capacity of the vector to the double */
    void reserve ()
    {
        T* newVector;
        newVector = new T[capacity*2];

            for ( int i=0 ; i<capacity ; i++)
            {
                newVector[i]=elements[i];
            }
        delete[] elements;
        elements = newVector;
        capacity*=2;
    }
    // destructor
~VectorFCI()
{
    delete elements;
}
};
#endif // VECTORFCI_H
