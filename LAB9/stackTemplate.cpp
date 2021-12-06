#include<iostream>
using namespace std;
template<typename T>//creating template T
class stack//stack class
{
    private://data members
        int size,top=-1;
        T *arr;
        bool isFull()//function for checking whether the stack is full or not
        {
            if(top==size-1)
            {return 1;}
            return 0;
        }
        bool isEmpty()//function for checking whether the stack is empty or not
        {
            if(top==-1)
            {
                return 1;
            }
            return 0;
        }
    public://member functions
        stack(int size)//constructor for initializing the size and creating dynamic array
        {
            this->size=size;
            arr=new T[size];
        }
        void push(T data)//function to push an element into stack
        {
            if(!isFull())
            {
                top++;
                arr[top]=data;
            }
            else
            {
                cout<<"Stack is full"<<endl;
            }
        }
        T peek()//function to return the top most element in stack
        {
            if(!isEmpty())
            {
                cout<<"The topmost element is:"<<arr[top]<<endl;
                return arr[top];
            }
            else
            {
                cout<<"Stack is empty"<<endl;
            }
        }
        T pop()//function to remove the topmost element from stack
        {
            if(!isEmpty())
            {    T value=arr[top];
                top--;
                cout<<"The popped element is:"<<value<<endl;
                return value;
            }
            else 
            {
                cout<<"Stack is empty"<<endl;
            }
        }
        void display()//displaying the elements in the stack starting from top
        {
            if(!isEmpty())
            {
                cout<<"The stack is:";
                for(int i=top;i>=0;i--)
                {
                    cout<<arr[i]<<" ";
                }
            }
            else 
            {
                cout<<"Stack is empty"<<endl;
            }
        }
        ~stack()//destructor for de-allocating the memory
        {
            delete[] arr;
        }
};
int main()//main function
{
    int size,choice,choice1;
    int data;char data2;
    cout<<"Enter the size of the stack:";//taking the size of the stack
    cin>>size;
    if(size<=0)//boundary condition
    {
        while(size<=0)
        {
            cout<<"Enter a valid size:";
            cin>>size;
        }
    }
    cout<<"Enter what type of stack you want to create"<<endl;
    cout<<"If int enter 1, if char enter 2:";//taking choice of the type of stack
    cin>>choice;
    if(choice>2||choice<1)
    {
        while(choice>2||choice<1)
        {
            cout<<"Enter a valid choice:";
            cin>>choice;
        }
    }
    stack<int>array1(size);
    stack<char>array2(size);
    
    while(1)
    {//printing menu
        cout<<"1.Push into stack"<<endl;
        cout<<"2.Pop from stack"<<endl;
        cout<<"3.Peek"<<endl;
        cout<<"4.Display"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice1;
        if(choice==1)//for integer stack
       { 
           switch(choice1)
            {
                case 1:
                    cout<<"Enter the data you want to push:";
                    cin>>data;
                    array1.push(data);
                    break;
                case 2:
                    array1.pop();
                    break;
                case 3:
                    array1.peek();
                    break;
                case 4:
                    array1.display();
                    break;
                case 5:
                    return(0);
                default:
                    cout<<"Enter a valid choice"<<endl;
            }
       }
       else//for character stack
       {
           switch(choice1)
            {
                case 1:
                    cout<<"Enter the data you want to push:";
                    cin>>data2;
                    array2.push(data2);
                    break;
                case 2:
                    array2.pop();
                    break;
                case 3:
                    array2.peek();
                    break;
                case 4:
                    array2.display();
                    break;
                case 5:
                    return(0);
                default:
                    cout<<"Enter a valid choice"<<endl;
            }
       }
    }
    return 0;
}//End of main function