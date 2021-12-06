#include<iostream>
using namespace std;
/* 25. (Vishnu)

Write a class template for different sorting operations. It should have data member array(size 10) and setinput, 
selection, insertion, bubble and display member functions. Create three objects of templates with data types integer,
float and string. Data members and member functions should be public.

Note : Maintain proper boundary conditions and follow best coding practice. All boundary conditions should be handled
through exception handling. Use this pointer inside the class.

The program should be menu driven. The menu is as follows,
1. Set input.
2. Selection sort.
3. Insertion sort.
4. Bubble sort.
5. Display.
6. Exit.

For set input ask data type and get 10 values and assign it to the array of corresponding object.
For 2 to 5 in menu ask the data type and do the operations on appropriate objects. Do not use STL. */


//Note: Here for string I have taken the data without spaces and sorting is done in non-decreasing order.
//Here I used exception handling for a case i.e whether data is present or not for doing certain operation
//for sorting of string it is done on basis of ascii values

#define size 10//defining size as 10
template<typename T>//creating a template
class sorting//sorting class template  
{
    public://all data members and member functions are private
        T arr[size]; bool allot=0;//here declaring "allot" variable for checking whether data is present or not.
        
        void setInput(T arr[])//function for settting input of "arr"
        {
            for(int i=0;i<size;i++)
            {
                this->arr[i]=arr[i];//use of this pointer
            }
            allot=1;//updating
        }

        void display()//function to display the array data
        {
            try {//try catch block 
                if(allot){
                cout<<"The array is:";
                for(int i=0;i<size;i++)
                {
                    cout<<this->arr[i]<<"  ";//use of this pointer
                } 
                cout<<"\n"; }
                else {throw 0;}
            }
            catch(int x){
                cout<<"No data to display"<<endl;
            }
        }

        void bubble()//function for sorting the array using bubble sort
        {//for this at each iteration we check each element pair-wise and update respectively
            try{
                if(allot){//algorithm
                    for(int i=0;i<size;i++)
                    {
                        for(int j=i+1;j<size;j++)
                        {
                            if(arr[i]>arr[j])
                            {
                                T temp=arr[i]; arr[i]=arr[j]; arr[j]=temp;//swapping 'i' & 'j' 
                            }
                        }
                    }
                }
                else {throw 0;}
            }
            catch(int x){
                cout<<"No data to sort"<<endl;
            }
        }

        void selection()//function for sorting the array using selection sort
        {//for this at 'i'th iteration we find the 'i'th minimum and place at arr[i] position
            try{
                if(allot){//algorithm
                    T min,temp; int min_index;
                    for(int i=0;i<size;i++)
                    {
                        min=arr[i]; min_index=i;
                        for(int j=i;j<size;j++)
                        {
                            if(min>arr[j])
                            {
                                min=arr[j];
                                min_index=j;
                            }
                        }
                        temp=arr[i]; arr[i]=arr[min_index]; arr[min_index]=temp;//swapping 'i' & 'min_index' 
                    }
                }
                else {throw 0;}
            }
            catch(int x){
                cout<<"No data to sort"<<endl;
            }
        }

        void insertion()//function for sorting the array using insertion sort
        {//Here at 'i'th iteration, the first 'i-1' elements are sorted, then we check for right position of 'i'th element
            try{
                if(allot){//algorithm
                      T temp;
                    for(int i=0;i<size;i++)
                    {
                        if(i>0)
                        {
                            if(arr[i]<arr[i-1])
                            {
                                temp=arr[i]; arr[i]=arr[i-1]; arr[i-1]=temp;
                                for(int j=i-1;(j>0)&&(arr[j]<arr[j-1]);j--)
                                {
                                    temp=arr[j]; arr[j]=arr[j-1]; arr[j-1]=temp;
                                }
                            }
                        }
                    }
                }
                else {throw 0;}
            }
            catch(int x){
                cout<<"No data to sort"<<endl;
            }
        }


};
int main()//main function
{
    sorting<int>array1; sorting<float>array2; sorting<string>array3;//creating objects of type "int,float,string"
    int data[10]; float data2[10]; string data3[10];
    int choice,flag;
    while(true)
    {//printing menu
        cout<<"1.Set input"<<endl;
        cout<<"2.Selection sort"<<endl;
        cout<<"3.Inserion sort"<<endl;
        cout<<"4.Bubble sort"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        if(choice>=1&&choice<=5)//for choice of data type 
        {
            cout<<"Enter the data type(int =1,float =2,string =3):";
            cin>>flag;
        }
        switch(choice)//switch-case for the menu
        {
            case 1:
                switch(flag)//switch-case for the data-type
                {
                    case 1:
                        cout<<"Enter the data for 10 values:";
                        for(int i=0;i<10;i++)
                        {
                            cin>>data[i];
                        }
                        array1.setInput(data);
                        break;
                    case 2:
                        cout<<"Enter the data for 10 values:";        
                        for(int i=0;i<10;i++)
                        {
                            cin>>data2[i];
                        }
                        array2.setInput(data2);
                        break;
                    case 3:
                        cout<<"Enter the data for 10 values:";            
                        for(int i=0;i<10;i++)
                        {
                            cin>>data3[i];
                        }
                        array3.setInput(data3);
                        break;
                    default:
                        cout<<"Enter a valid choice"<<endl;
                        break;
                }
                break;
            case 2:
                switch(flag)
                {
                    case 1:
                        array1.selection();
                        break;
                    case 2:
                        array2.selection();
                        break;
                    case 3:
                        array3.selection();
                        break;
                    default:
                        cout<<"Enter a valid choice"<<endl;
                        break;
                }
                break;
            case 3:
                switch(flag)
                {
                    case 1:
                        array1.insertion();
                        break;
                    case 2:
                        array2.insertion();
                        break;
                    case 3:
                        array3.insertion();
                        break;
                    default:
                        cout<<"Enter a valid choice"<<endl;
                        break;
                }
                break;
            case 4:
                switch(flag)
                {
                    case 1:
                        array1.bubble();
                        break;
                    case 2:
                        array2.bubble();
                        break;
                    case 3:
                        array3.bubble();
                        break;
                    default:
                        cout<<"Enter a valid choice"<<endl;
                        break;
                }
                break;
            case 5:
                switch(flag)
                {
                    case 1:
                        array1.display();
                        break;
                    case 2:
                        array2.display();
                        break;
                    case 3:
                        array3.display();
                        break;
                    default:
                        cout<<"Enter a valid choice"<<endl;
                        break;
                }
                break;
            case 6:
                return 0;//exiting 
            default:
                cout<<"Enter a valid choice"<<endl;
                break;
        }
    }
    return 0;
}//End of main function