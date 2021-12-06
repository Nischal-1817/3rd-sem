//CS20B1109
//header file for accessing all the functions and creation
#include<iostream>
using namespace std;
//students class for creation of report card
class students
{
    private://making data members private
        int rollNo;
        string studentName;
        int subject1,subject2,subject3,subject4,subject5;
    public: //member functions 
        
        students()//Non-parameterized constructor
        {
            rollNo=0;
            subject1=subject2=subject3=subject4=subject5=0;
            studentName=" ";
        }
        students(int roll,string name)//parameterized constructor
        {
            rollNo=roll;
            subject1=subject2=subject3=subject4=subject5=0;
            studentName=name;
        }
        //function for adding the student details
        void createReport(int roll,string student_Name,int score[],int size)
        {
           rollNo=roll;
           studentName=student_Name;
           subject1=score[0];
           subject2=score[1];
           subject3=score[2];
           subject4=score[3];
           subject5=score[4];
        }
        void displayAll()//function for displaying the student details
        {
            cout<<"Roll Number is:"<<rollNo<<endl;
            cout<<"Name is:"<<studentName<<endl;
            cout<<"Marks in the 5 subjects are:"<<endl;
            cout<<"Subject1:"<<subject1<<endl;
            cout<<"Subject2:"<<subject2<<endl;
            cout<<"Subject3:"<<subject3<<endl;
            cout<<"Subject4:"<<subject4<<endl;
            cout<<"Subject5:"<<subject5<<endl;
        }
    
};