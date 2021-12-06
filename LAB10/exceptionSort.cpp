#include<iostream>
using namespace std;
template<typename T>//creating a template
void selectionSort(T* arr,int size)//function template 
{
    T min,temp; int minIndex;
    for(int i=0;i<size;i++)//sorting algorithm
    {
        min=arr[i]; minIndex=i;
        for(int j=i;j<size;j++)
        {
            if(min>arr[j])
            {
                min=arr[j];
                minIndex=j;
            }
        }
        T temp=arr[i]; arr[i]=arr[minIndex]; arr[minIndex]=temp;//swapping
    }
}
int main()//main function
{
    int data; char data2; float data3;
    int size,choice,choice2,flag=0;
    cout<<"Enter the choice of the data type"<<endl;
    cout<<"If int enter 1 else if char enter 2 else if float enter 3:";//taking input for datatype
    cin>>choice2;
    while(choice2<=0||choice2>3)//boundary condition for data type
    {
        try
        {
            if(choice2<=0||choice2>3)
            throw 0;
        }
        catch(int x)
        {
            cout<<"Enter a valid choice:";
            cin>>choice2;
        }
    }
    cout<<"Enter the size of the array:";//taking size of the array
    cin>>size;
    while(size<=0)//boundary condition for size
    {
        try
        {
            if(size<=0)
            throw 0;
        }
        catch(int x)
        {
            cout<<"Enter a valid size:";
            cin>>size;
        }
    }
    int arr[size]; char arr2[size]; float arr3[size];
    while(1)
    {//printing menu
        cout<<"1.Get Values"<<endl;
        cout<<"2.Sort"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice2)//switch-case for each datatype
        {
            case 1:
                switch(choice)//switch-case for menu
                {
                    case 1:
                        flag++;
                        for(int i=0;i<size;i++)
                        {
                            cout<<"Enter the data:";
                            cin>>arr[i];
                        }
                        break;
                    case 2:
                        try //boundary condition for no data
                        {
                            if(flag==0)
                            throw 0;
                            else 
                            selectionSort(arr,size);
                        }
                        catch(...)
                        {
                            cout<<"Please enter data first to sort"<<endl;
                        }
                        break;
                    case 3:
                        try//boundary condition for no data
                        {
                            if(flag==0)
                            throw 0;
                            else 
                            {
                               cout<<"The array is:";
                                for(int i=0;i<size;i++)
                                {
                                    cout<<arr[i]<<" ";
                                }
                                cout<<'\n'; 
                            }
                        }
                        catch(...)
                        {
                            cout<<"Please enter data first to display"<<endl;
                        }
                        break;
                    case 4:
                        return 0;
                    default:
                        cout<<"Enter a valid choice"<<endl;
                }
                break;
            case 2:
                switch(choice)
                {
                    case 1:
                        flag++;
                        for(int i=0;i<size;i++)
                        {
                            cout<<"Enter the data:";
                            cin>>arr2[i];
                        }
                        break;
                    case 2:
                        try//boundary condition for no data
                        {
                            if(flag==0)
                            throw 0;
                            else 
                            selectionSort(arr2,size);
                        }
                        catch(...)
                        {
                            cout<<"Please enter data first to sort"<<endl;
                        }
                        break;
                    case 3:
                        try//boundary condition for no data
                        {
                            if(flag==0)
                            throw 0;
                            else 
                            {
                               cout<<"The array is:";
                                for(int i=0;i<size;i++)
                                {
                                    cout<<arr2[i]<<" ";
                                }
                                cout<<'\n'; 
                            }
                        }
                        catch(...)
                        {
                            cout<<"Please enter data first to display"<<endl;
                        }
                        break;
                    case 4:
                        return 0;
                    default:
                        cout<<"Enter a valid choice"<<endl;
                }
                break;
            case 3:
                switch(choice)
                {
                    case 1:
                        flag++;
                        for(int i=0;i<size;i++)
                        {
                            cout<<"Enter the data:";
                            cin>>arr3[i];
                        }
                        break;
                    case 2:
                        try//boundary condition for no data
                        {
                            if(flag==0)
                            throw 0;
                            else 
                            selectionSort(arr3,size);
                        }
                        catch(...)
                        {
                            cout<<"Please enter data first to sort"<<endl;
                        }
                        break;
                    case 3:
                        try//boundary condition for no data
                        {
                            if(flag==0)
                            throw 0;
                            else 
                            {
                               cout<<"The array is:";
                                for(int i=0;i<size;i++)
                                {
                                    cout<<arr3[i]<<" ";
                                }
                                cout<<'\n'; 
                            }
                        }
                        catch(...)
                        {
                            cout<<"Please enter data first to display"<<endl;
                        }
                        break;
                    case 4:
                        return 0;
                    default:
                        cout<<"Enter a valid choice"<<endl;
                }
                break;
            default:
                cout<<"Not a valid choice"<<endl;
        }
    }
    return 0;
}