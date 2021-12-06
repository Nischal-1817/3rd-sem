//CS20B1109
//Menu driven program for reportcard
/* Here for creation of record we are taking input
from the user in the main function itself and passing by value to the header file
*/
/*
Write a C++ header program(abstraction) to create a StudentReportCard System( use classes - encapsulation). 
Note: All the data members are declared private (secure data members) and member functions are defined under public.
Create student report card record: This feature creates a new student record containing his marks. 
For this, the information to be provided are the name and roll no. of the student, and the marks obtained by him/her 
in 5 subjects Any five subjects.

Display all student’s report card records: This feature displays the roll no. and name of all the students, 
the marks obtained by them in 5 subjects.

Declare a constructor that initializes the data members’ value to 0.

Declare a parameterized constructor that takes a name and roll number as parameters and assigns all other marks to 0.

Now, write a C++ Menu driven program to utilize the student report card system. Get details for 5 students. 
Let the 5 objects be stu1, stu2, stu3, stu4, and stu5. Let stu1, stu2, and stu3 be initialized by default constructors and 
stu4 and stu5 be initialized by parameterized constructors.  Maintain proper boundary conditions, follow coding best practices,
 declare and define functions following coding practices.

Eg: From the Menu program, for display, call like,
stu1.displayRecord();
stu2.displayRecord();
stu3.displayRecord();
stu4.displayRecord() ..
For creation, call from the main function like
stu1.create(name, roll no, mark1, mark2, mark3, mark4, mark5);
stu2.create(name, roll no, mark1, mark2, mark3, mark4, mark5); ..
Note: The above variable names and passing of parameters are just examples. 
*/
#include "reportcard.hpp"
#include<iostream>
#define size 5
using namespace std;
int main()
{
    students stu1,stu2,stu3,stu4(21,"Ram"),stu5(22,"Laxman");//declaring students as 2 ways
    int choice,roll,score[size],i,student_mark,studentCount=0,flag;//declaring variables
    string student_Name;
    while(1)
    {
      //Printing menu
        cout<<"1.Creating student reportcard record"<<endl;
        cout<<"2.Display all student's records"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Enter your choice";
        cin>>choice;
        switch(choice)
        {
            case 1:
              if(studentCount<5)//As the limit of intake is only 5 students
              {cout<<"Enter student roll number:"; 
              cin>>roll;
              if(roll<0)//Taking valid roll number as less than 0 is not valid
              {
                while (roll<0)
                {
                  cout<<"Enter valid roll number:"<<endl;
                  cin>>roll;
                }
                
              }
              cin.ignore();
              cout<<"Enter student name:"; getline(cin,student_Name);//for name with spaces
              cout<<"Enter marks for 5 subjects"<<endl;
              i=0;
              while(i<5)//for taking marks as an array
              {
                  cout<<"Enter score of subject"<<i+1<<":";
                  cin>>student_mark;
                  if(student_mark<0||student_mark>100)//boundary condition for student marks
                  {
                      cout<<"Enter correct score"<<endl;
                      i--;
                  }
                  else
                  {
                      score[i]=student_mark;
                  }
                  i++;
              }
              switch(studentCount)//for adding student details according to studentCount
              {
                  case 0:
                    stu1.createReport(roll,student_Name,score,size);
                    break;
                  case 1:
                    stu2.createReport(roll,student_Name,score,size);
                    break;
                  case 2:
                    stu3.createReport(roll,student_Name,score,size);
                    break;
                  case 3:
                    stu4.createReport(roll,student_Name,score,size);
                    break;
                  case 4:
                    stu5.createReport(roll,student_Name,score,size);
                    break;
                   default:
                     break;
              }
              studentCount++;}
              else
              {
                  cout<<"Sorry report closed(no more entries)!"<<endl;
              }
              break;
            case 2:
                flag=1;
                if(studentCount<5)
                {
                    cout<<"You added less than 5 students! Are you sure to continue!"<<endl;
                    cout<<"If so enter 1 else 0:";
                    cin>>flag;
                }

                if(flag==1)
                {cout<<"The records of all students are:"<<endl;//displaying all students details
                stu1.displayAll();
                stu2.displayAll();
                stu3.displayAll();
                stu4.displayAll();
                stu5.displayAll();}
              break;
            case 3:
               exit(1);//exit 
            default:
              cout<<"Enter a valid choice"<<endl;
              break;
        }
    }
    return 0;
}