//CS20B1109
//Nischal pradyoth
//menu driven program for circularqueue 
/*
Write a C++ program to implement a queueor a circular queue ADT as a header file using class. 
Create a class for a queue with the following operations, enqueue, dequeue, display, peek, isFull, 
and isEmpty functions. Declare the enqueue and dequeue member functions inside the queue class and 
write their definitions outside the queue class using scope resolution operator. Define the remaining 
functions inside the queue class. The data members(variables declared inside the function) should use 
"Private" access specifier and member functions (function declared and defined withing the scope of a class) 
should use "Public" access specifier. Assume the queue stores integers and can store a maximum of  5 integers. 
Note: Should use cin and cout for getting and displaying values. Import the created queue header file into a "printer.cpp" file.
 The printer.cpp has the following menus,

1. Add to Print Queue
2. Current Job
3. Execute a Job
4. Display Jobs
5. Exit

Option 1 gets an integer job ID and stores it into the queue.
 2 prints the job ID that will be executed next (Value present at the front of the queue). 
 3 removes the currently executed job ID from the queue and prints a message that The job <<Insert job ID>> has been completed. 
 4 Displays all the jobs pending in the queue pool.
  5 quits from the program. Any other option should prompt the user to enter a valid option. 
  Write appropriate boundary conditions, design functions, and comment properly.
*/
#include "queueclas"
#include <iostream>
using namespace std;
int main()
{
    queue q1;
    int choice,id,number,num;
    while(1)
    {
        //printing the menu
        cout<<"\n 1.Add to PrintQueue \n 2.Current Job\n 3.Execute a Job\n 4.Display Jobs\n 5.Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the JobID";
                cin>>id;
                q1.enqueue(id);
                break;
            case 2:
                 number=q1.peek();
                if(number==-1)
                { cout<<"queue is empty"<<endl; }
                else
                {cout<<number<<endl; }
                break;
            case 3:
                num=q1.deque();
                if(num==-1)
                { cout<<"queue is empty"<<endl; }
                else
                {cout<<"The Job "<<num<<" has been completed"; }
                break;
            case 4:
                q1.display();
                break;
            case 5:
                exit(1);
            default:
             cout<<"Enter a valid option"<<endl;
        }
    }
    return 0;
}