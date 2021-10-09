//CS20B1109
//Nischal Pradyoth
#include<iostream>
#include<math.h>
using namespace std;
//This code is designed for unsigned representation only
class binaryMultiply//class for binary multiplication
{
    private:
        int m,n;
    public:
        binaryMultiply(int m,int n)//constructor for assigning the numbers and calling multiply function
        {
            this->m=m;
            this->n=n;
            multiply();
        }
        void multiply()//function for binary multiplication bitwise and printing results
        {
            int *arr1=new int[32];
            int *arr2=new int[32];
            arr1=decimalBinary(arr1,m);//getting binary representation of the numbers
            arr2=decimalBinary(arr2,n);
            cout<<"m=";//printing the binary representation of the numbers
            for(int i=0;i<32;i++)
            {
                cout<<arr1[i];
            }
            cout<<'\n';
            cout<<"n=";
            for(int i=0;i<32;i++)
            {
                cout<<arr2[i];
            }
            cout<<'\n';
            int arr3[32];
            for(int i=0;i<32;i++)//just creating a copy of 1st number
            {
                arr3[i]=arr1[i];
            }
             int carry1=0,carry2=0,p,g,sum=0;
            for(int i=1;i<n;i++)//here we are adding the number 'm' by itself until 'n' times  
            {
                for(int j=31;j>=0;j--)//adding binary numbers
                {//designing like carry look ahead adder circuit
                    p=arr1[j]^arr3[j];
                    g=arr1[j]&arr3[j];
                    carry2=g+(p&carry1);
                    arr1[j]=p^carry1;
                    carry1=carry2;
                }
            } 
            cout<<"after multiplying:";//printing the binary representation after multiplying
            for(int i=0;i<32;i++)
            {
                cout<<arr1[i];
            }
            cout<<'\n';
            for(int i=0;i<32;i++)//calculating the result
            {
                int x=arr1[i]*pow(2,31-i);
                sum+=x;
            }
            cout<<"The result is:"<<sum;//printing result
            
        }
        int* decimalBinary(int *arr,int n)//function for binary representation
        {
            int i,a,temp,x;
            int b=1;
            for(i=0;i<32;i++)
            {
                arr[i]=0;
            }
            for(i=0;b>0;i++)
            {
                a=n%2;
                b=n/2;
                n=b;
                arr[i]=a;
            }
            for(i=0;i<16;i++)
            {
                temp=arr[i];
                arr[i]=arr[31-i];
                arr[31-i]=temp;
            }
            return arr;
        }
};
int main()//Main function
{
    int m,n;
    cout<<"Enter the two numbers you want to multiply:";
    cin>>m>>n;//taking input
    binaryMultiply obj(m,n);
    return 0;
}//End of main function