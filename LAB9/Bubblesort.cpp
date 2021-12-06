#include<iostream>
using namespace std;
template<typename T>//creating a template T
void bubbleSort(T arr[],int size)//Bubble sort template function i.e it can sort any data type
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]>arr[j])
            {
                T temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"The array after sorting is:";
    for(int i=0;i<size;i++)//Displaying the array after sorting 
    {
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}
int main()//Main function
{
    int size,choice;
    cout<<"Enter the size of the array:";//taking size
    cin>>size;
    if(size<=0)//boundary condition
    {
        while(size<=0)
        {
            cout<<"Enter a valid size:";
            cin>>size;
        }
    }
    int arr[size]; float arr2[size]; char arr3[size];
    cout<<"Enter the type of array you want to sort"<<endl;//printing menu
    cout<<"1.Integer"<<endl;
    cout<<"2.Float"<<endl;
    cout<<"3.Character"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter your choice:";
    cin>>choice;
    if(choice<1||choice>4)//boundary condition
    {
        while(choice<1||choice>4)
        {
            cout<<"Enter a valid choice:";
            cin>>choice;
        }
    }
    switch (choice)//Taking inputs and calling bubble sort function
    {
        case 1:
            for(int i=0;i<size;i++)
            {
                cout<<"Enter the elements:";
                cin>>arr[i];
            }
            bubbleSort(arr,size);
            break;
        case 2:
            for(int i=0;i<size;i++)
            {
                cout<<"Enter the elements:";
                cin>>arr2[i];
            }
            bubbleSort(arr2,size);
            break;
        case 3:
            for(int i=0;i<size;i++)
            {
                cout<<"Enter the elements:";
                cin>>arr3[i];
            }
            bubbleSort(arr3,size);
            break;
        case 4:
            return(0);
        default:
            break;
    }
    
    return 0;
}//End of main function