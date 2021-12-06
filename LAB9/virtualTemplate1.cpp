//CS20B1109
//Nischal Pradyoth
#include<iostream>
using namespace std;
template<typename T>//A template for rollnumber
class person//person class
{
    protected://Declaring data members under protected
        string name;
        T rollNumber;
    public:
        person(T rollNumber,string name="\0")//Parameterized default constructor
        {
            this->name=name;
            this->rollNumber=rollNumber;
        }
        person()
        {
        }
        void display()//Function to display the details of person
        {
            cout<<"The person details are:"<<endl;
            cout<<"Name:"<<name<<endl;
            cout<<"Roll No.:"<<rollNumber<<endl;
        }
};
template<typename T>
class student:protected person<T>//student class inherited from person
{
    protected:
        string course1,course2,course3;
    public:
        student(string course1="\0",string course2="\0",string course3="\0",string rollNumber="\0",string name="\0")//paramaterized constructor
        {
            this->course1=course1;
            this->course2=course2;
            this->course3=course3;
        }
        void display2()//display function
        {
            cout<<"The course details are:"<<endl;
            cout<<"course1:"<<course1<<endl;
            cout<<"course2:"<<course2<<endl;
            cout<<"course3:"<<course3<<endl;
        }
};
template<typename T>
class researchStudent:protected person<T>//research student class inherited from person 
{
    protected:
        string course1,researchArea;
    public:
        researchStudent(string course1="\0",string researchArea="\0",int rollNumber=0,string name="\0")//parameterized constructor
        {
            this->course1=course1;
            this->researchArea=researchArea;
        }
        void display3()//display function
        {
            cout<<"The research area details are:"<<endl;
            cout<<"course1:"<<course1<<endl;
            cout<<"Research Area:"<<researchArea<<endl;
        }
};
template<typename T>
class TA:protected researchStudent<int>,protected student<string>//TA class inherited from both student and researchstudent class
{
    protected:
        string courseAssigned; int role;
    public:
        TA *next;//One constructor for student class
        TA(string courseAssigned,string course1,string course2,string course3,string rollNumber1,string name)
        {
            this->courseAssigned=courseAssigned;
            this->role=1;
            student<string>::course1=course1;
            student<string>::course2=course2;
            student<string>::course3=course3;
            student<string>::rollNumber=rollNumber1;
            student<string>::name=name;
        }//one constructor for research student class
        TA(string courseAssigned,string course1,string researchArea,int rollNumber2,string name)
        {
            this->courseAssigned=courseAssigned;
            this->role=2;
            researchStudent<int>::course1=course1;
            researchStudent<int>::researchArea=researchArea;
            researchStudent<int>::rollNumber=rollNumber2;
            researchStudent<int>::name=name;
        }
        void display4()//display funtion for displaying the details of TA
        {
            cout<<"The course assigned is:"<<courseAssigned<<endl;
            cout<<"The role is:"<<role<<endl;
        }
        void check(int flag,int choice,TA<string> *head)
        {
                TA<string> *ptr=head;
                while(ptr!=NULL)
                {
                        cout<<"Name:"<<ptr->student<string>::name<<endl;
                        cout<<"Rollnumber:"<<ptr->student<string>::rollNumber<<endl;
                    if(choice==2){ptr->student<string>::display2();}
                    else if(choice==3){ cout<<"Invalid"<<endl; }
                    else if(choice==4){ptr->display4(); }
                    ptr=ptr->next;
                }
        }
        void check2(int flag,int choice,TA<int> *head2)
        {
                TA<int> *ptr2=head2;
                while(ptr2!=NULL)
                {
                    /*cout<<"Name:"<<ptr2->researchStudent<int>::name<<endl;
                    cout<<"Rollnumber:"<<ptr2->researchStudent<int>::rollNumber<<endl;
                    if(choice==3){ptr2->researchStudent<int>::display3();}*/
                    if(choice==2){ cout<<"Invalid"<<endl; }
                    else if(choice==4){ptr2->display4(); }
                    ptr2=ptr2->next;
                }
        }
}; 
int main()//Main function
{
    int choice,role,flag;
    string researchArea;int rollNumber2;string name;
    string courseAssigned,course1,course2,course3,rollNumber1;
    TA<string> *head;
    TA<int> *head2;
    while(1)
    {//printing menu
        cout<<"1.Set person Details"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"     a. Person"<<endl;
        cout<<"     b. Student"<<endl;
        cout<<"     c. Research Student"<<endl;
        cout<<"     d. Teaching Assistant"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the role of the TA,if student enter 1 else 2:";
                cin>>role;
                if(role==1)
                {//taking required input
                    cout<<"Enter the required details"<<endl;
                    cin.ignore();
                    cout<<"Name:"; getline(cin,name);
                    cout<<"Roll number:"; cin>>rollNumber1; cin.ignore();
                    cout<<"Course Assigned:"; getline(cin,courseAssigned);
                    cout<<"Course 1:"; getline(cin,course1); 
                    cout<<"Course 2:"; getline(cin,course2); 
                    cout<<"Course 3:"; getline(cin,course3); 
                    if(courseAssigned!=course1&&courseAssigned!=course2&&courseAssigned!=course3)
                    {TA<string> obj(courseAssigned,course1,course2,course3,rollNumber1,name);
                    if(head==NULL)
                    {
                        head=&obj;
                        head->next=NULL;
                        cout<<"True"<<endl;
                    }
                    else
                    {
                        TA<string> *ptr=head;
                        while(ptr->next!=NULL){ ptr=ptr->next; }
                        TA<string> *ptr2=&obj;
                        ptr->next=ptr2;
                        ptr2->next=NULL;
                    }}
                    else {cout<<"Invalid credentials"<<endl; }
                }
                else if(role==2)
                {//taking required input
                    cout<<"Enter the required details"<<endl; cin.ignore();
                    cout<<"Name:"; getline(cin,name); 
                    cout<<"Roll number:"; cin>>rollNumber2; cin.ignore();
                    cout<<"Course Assigned:"; getline(cin,courseAssigned);
                    cout<<"Course 1:"; getline(cin,course1); 
                    cout<<"Research Area:"; getline(cin,researchArea); 
                    if(courseAssigned!=course1)
                    {TA<int> obj2(courseAssigned,course1,researchArea,rollNumber2,name);
                    if(head2==NULL)
                    {
                        head2=&obj2;
                        head2->next=NULL;
                        cout<<"True"<<endl;
                    }
                    else
                    {
                        TA<int> *ptr=head2;
                        while(ptr->next!=NULL){ ptr=ptr->next; }
                        TA<int> *ptr2=&obj2;
                        ptr->next=ptr2;
                        ptr2->next=NULL;
                    }}
                    else { cout<<"Invalid Credentials"<<endl; }
                }
                else 
                {cout<<"Invalid input"<<endl;}
                break;
            case 2:
                cout<<"     1. Person"<<endl;
                cout<<"     2. Student"<<endl;
                cout<<"     3. Research Student"<<endl;
                cout<<"     4. Teaching Assistant"<<endl;
                cout<<"Enter your choice:";
                cin>>choice;
                cout<<"Enter 1 if he is a student else 2 if a researchStudent:";
                cin>>flag;
                if(flag==1)
                {head->check(flag,choice,head);}
                else if(flag==2)
                {head->check2(flag,choice,head2);}
                break;
            case 3:
                return 0;
            default:
                cout<<"Enter a valid choice"<<endl;
                break;
        }
    }
    return 0;
}