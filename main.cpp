// Name: Hagar Muhammad Abdelzaher
// ID: 20180324
// date: December 2019

#include <iostream>
#include<VectorFCI.h>
#include <cstring>
using namespace std;
class Course {
private:
    string courseName;
    string courseCode;
    char   courseGrade;
    float  coursePoint;
    int    courseYear;
    int    courseSemester;

public:
    Course(){};
    Course (string Cname , string Ccode , char Cgrade , float Cpoint , int Cyear , int Csemester)
    {
        courseName=Cname;
        courseCode=Ccode;
        courseGrade=Cgrade;
        coursePoint=Cpoint;
        courseYear=Cyear;
        courseSemester=Csemester;
    }
    void printCourseInfo()
    {
        cout<<"Course Name : " << courseName <<endl;
        cout<<"Course Code : " << courseCode <<endl;
        cout<<"Course Grade : " << courseGrade <<endl;
        cout<<"Course Points : " << coursePoint <<endl;
        cout<<"Course Year: " << courseYear <<endl;
        cout<<"Course Semester : " << courseSemester <<endl;
    }
    /*Operator overloading for cin operator to enter details of a course*/
    friend istream & operator >> (istream & in , Course &c)
 {
     cout<<"please enter course name" <<endl;
     in>>c.courseName;
     cout<<"please enter course code " <<endl;
     in>>c.courseCode;
     cout<<"please enter course grade " <<endl;
     in>>c.courseGrade;
     cout<<"please enter course points " <<endl;
     in>>c.coursePoint;
     cout<<"please enter course year" <<endl;
     in>>c.courseYear;
     cout<<" please enter course semester"<<endl;
     in>>c.courseSemester;

     return in;
 }
/* operator overloading for cout operator to print course details*/
 friend ostream & operator << (ostream &out , Course &c)
 {
    out<<"Course Name : " << c.courseName <<endl;
    out<<"Course Code : " << c.courseCode <<endl;
    out<<"Course Grade : " << c.courseGrade <<endl;
    out<<"Course Points : " << c.coursePoint <<endl;
    out<<"Course Year: " << c.courseYear <<endl;
    out<<"Course Semester : " <<c.courseSemester <<endl;

    return out;
 }
};


class Student
{
private:
    string sname;
    string sdepartment;
    int sid;
    VectorFCI <Course> FCIVectorOfCourses;
public:
    Student(){};
    Student (string name , string dep , int id , VectorFCI <Course> coursesVec)
    {
        sname=name;
        sdepartment=dep;
        sid=id;
        FCIVectorOfCourses = coursesVec;

    }
    /* function that print the details of the course*/
    void printStudentInfo()
    {
        cout<<"Student Name: " <<sname<<endl;
        cout<<"Student ID : " <<sid <<endl;
        cout<<"Student department : "<< sdepartment <<endl;
    }

/*Operator overloading for cin operator to enter attributes of a student*/
    friend istream & operator >> (istream & in , Student &s)
    {   int x;
        cout<<"Enter student name: " <<endl;
        in>>s.sname;
        cout<<"Enter student department:" <<endl;
        in>>s.sdepartment;
        cout<<"Enter student id: " <<endl;
        in>>s.sid;
        cout<<"please enter number of courses of student " << s.sname <<endl;
        cin>>x;
        for (int i=0 ; i<x ; i++ )
        {
            cout<<"please enter course # "<< i << "info"<<endl;
            Course c;
            cin>>c;
           s.FCIVectorOfCourses.push__back(c);
        }

        return in;
    }
    /* operator overloading for cout operator to print student details*/
    friend ostream & operator << (ostream & out , Student &s)
    {
        out<<"Student Name: " <<s.sname<<endl;
        out<<"Student ID : " <<s.sid <<endl;
        out<<"Student department : "<< s.sdepartment <<endl;
        out<<"Student courses details :"<<endl;
        for (int i=0 ; i<s.FCIVectorOfCourses.sizee() ; i++)
        {
            out<<s.FCIVectorOfCourses[i]<<endl;
        }
        return out;
    }

};
template <class T>
/* Function that allows the user to enter the operation he wants to do on the vector */
void ChooseOperation ( VectorFCI <T> tempVector); // prototype only in order to the function choose to be able to see the vectors created inside it
/* Functions that displays the main menu to the user to create a new vector of the type he chooses*/
void mainMenu()
{
    int choice;
    string type;
    beginning:
    cout<<"Insert type of vector you would like to create:\n 1. list of integer\n 2. list of character\n 3. list of string \n 4. list of float \n 5. list of students \n 6. Exit"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1: // if the user wants to create a vector of integers
       {
           VectorFCI <int> V;
           type = "integers";
           cout<<" A vector of " << type << " was created successfully" <<endl;
           ChooseOperation(V);
           break;
       }
    case 2: // if the user wants to create a vector of characters
       {
           VectorFCI <char> V;
           type = "Characters";
           cout<<" A vector of " << type << " was created successfully" <<endl;
           ChooseOperation(V);
           break;
       }
    case 3:
        {
           VectorFCI <string> V;
           type = "strings";
           cout<<" A vector of " << type << " was created successfully" <<endl;
           ChooseOperation(V);
           break;
        }
    case 4: // if the user wants to create a vector of float numbers
        {
           VectorFCI <float> V;
           type = "float ";
           cout<<" A vector of " << type << " was created successfully" <<endl;
           ChooseOperation(V);
           break;
        }
    case 5: // if the user wants to create a vector of students
        {
          VectorFCI <Student> V;
           type = "students";
           cout<<" A vector of " << type << " was created successfully" <<endl;
           ChooseOperation(V);
           break;
        }
    case 6: // if the user wants to terminate from the program
        {
            exit(0);
        }
    default:// if the user didn't enter one of the previous cases then he entered an invalid input
        {
            cout<<"Invalid input , please try again"<<endl;
            goto beginning; // go back to the beginning and try entering your choice again
        }
    }
}
template <class T>
/*  A void function that allows the user to choose what operation to be done on the vector he created  */
/* it takes the vector created un the mainMenu function as a parameter  */
void ChooseOperation ( VectorFCI <T> tempVector)
{
    bool again = true;
    while (again) // while loop that ends when the user doesn't want to perform another operations
         {
           chooseAgain:
           cout<<" What kind of operation would you like to perform?"<<endl;
           cout<<"1. Add element.\n2. Remove last element.\n3. Insert element at certain position.\n4. Erase element from a certain position.\n5. Clear.\n6. Display first element.\n7. Display last element.\n8. Display element at certain position.\n9. Display vector size.\n10. Display vector capacity.\n11. Is empty? \n12. Print vector elements \n"<<endl;
           int choice2;
           cin>>choice2;
           switch (choice2)
           {
           case 1 : // when the user wants to add elements in the vector
            {
                int siz;
                cout<<"enter number of elements you want to add" <<endl;
                cin>>siz;
                cout<<"Please insert elements you want to add "<<endl;
                for (int i=0 ; i<siz ; i++)
                {
                    T x;
                    cin>>x;
                    tempVector.push__back(x);
                }
                break;
            }
           case 2: // when the user wants to erase last elements in the vector
             {
                tempVector.pop__back();
                cout<<"last element erased successfully"<<endl;
                break;
            }
           case 3: // when the user wants to insert elements at certain position inside the vector
            {
                int ind ;
                T val;
                cout<<"please enter the index you want to add this value at" <<endl;
                cin>>ind;
                cout<<"please enter the value you want to add"<<endl;
                cin>>val;
                tempVector.insertt(&tempVector[ind-1] , val);
                break;
            }
           case 4: // when the user wants to erase element from a certain position inside the vector
            {
                int x;
                cout<<"please insert index of the element you want to erase "<<endl;
                cin>>x;
                tempVector.erasee(&tempVector[x-1]);
                break;
            }
           case 5: // when the user wants to delete all elements inside the vector
            {
                tempVector.clearr();
                break;
            }
           case 6: // when the user wants to display the first element in the vector
            {
                cout<<tempVector.frontt()<<endl;
                break;
            }
           case 7: // when the user wants to display last element in the vector
            {
                cout<<tempVector.backk()<<endl;
                break;
            }
           case 8: // when the user wants to display certain element in the vector
            {
                cout<<" enter position of the element you want to show " <<endl;
                int i;
                cin>>i;
                if (i<0 || i>tempVector.sizee())
                {
                    cout<< " index you entered is out of range" <<endl;
                }
                else
                {
                    cout<< tempVector[i-1]<<endl;
                }
                break;
            }
           case 9: // when the user wants to display the number of elements inside the vector
            {
                cout<<tempVector.sizee()<<endl;
                break;
            }
           case 10: // when the user wants to display the capacity that the vector can hold
            {
                cout<<tempVector.capacityy()<<endl;
                break;
            }
           case 11: // displays whether the vector is empty or not
            {
               cout<<tempVector.emptyy()<<endl;
               break;
            }
           case 12: // displays all the vector elements
            {
                if(tempVector.emptyy())
                {
                    cout<<" The vector is empty , please add elements before printing" <<endl; // no elements to show
                }
                else
                {
                     for (int i=0 ; i<tempVector.sizee() ; i++)
                        {
                            cout<<tempVector[i]<<endl;
                        }
                }
                break;
            }
           default: // if the user enters a choice other than the above 12 choice
            {
                cout<<"Invalid input , please try again" <<endl;
                goto chooseAgain; // go to the beginning and choose again
            }

         }
            char anotherOperation;
            yesOrNo:
            cout<<"do you want to perform another operation? [Y/N]" <<endl;
            cin>>anotherOperation;
            if(tolower(anotherOperation)=='n' ) // if the user doesn't want to perform operations
            {
                again=false;
                mainMenu(); // go the main menu again
            }
            else if (tolower(anotherOperation)=='y')
            {
                again=true;
            }
            else
            {
                cout<<"Invalid input , please try again "<<endl; // if the user enters any thing other than y or n
                goto yesOrNo; // try choosing again
            }
           }
}
int main()
{
   mainMenu(); // calling of the main menu function
}

