#include<iostream>
#include<vector>
using namespace std;
class sorting//sorting class
{
    private://taking a vector for taking input
        vector<int>sortingArray;
    public:
        void addElement(int data)//pushing back the input data
        {
            sortingArray.push_back(data);
        }
        void display()//function for displaying the array
        {
            cout<<"the array is:";
            for(int i=0;i<sortingArray.size();i++)
            {
                cout<<sortingArray[i]<<" ";
            }
            cout<<'\n';
        }
        void swap(int i,int j)//function for swapping two elements
        {
            int temp=sortingArray[i];
            sortingArray[i]=sortingArray[j];
            sortingArray[j]=temp;
        }
        void quickSort(int low,int high)//function for making recursive call
        {
            if(low<high)//the bottom out condition
            {
                int left,right;//the two pivots
                left=division(low,high,&right);
                quickSort(low,left-1);
                quickSort(left+1,right-1);
                quickSort(right+1,high);
            }
        }
        int division(int low,int high,int* right)//function for sorting
        {
            if(sortingArray[low]>sortingArray[high])//checking which pivot is greater
            {
                swap(low,high);
            }

            int index1=low+1,index2=high-1,index3=low+1;
            int lvalue=sortingArray[low],rvalue=sortingArray[high];//assigning the pivots
            while(index3<=index2)
            {
                if(sortingArray[index3]<lvalue)//swapping the elements which are less than left pivot
                {
                    swap(index3,index1);
                    index1++;
                }
                else if(sortingArray[index3]>=rvalue)//swapping the elements which are greater than right pivot
                {
                    while(sortingArray[index2]>rvalue&&index3<index2)
                    {
                        index2--;
                    }
                    swap(index3,index2);
                    index2--;
                    if(sortingArray[index3]<lvalue)//again checking pivots
                    {
                        swap(index3,index1);
                        index1++;
                    }
                }
                index3++;
            }
            index1--; index2++;
            swap(low,index1); swap(high,index2);
            *right=index2;//updating the pivots values
            return index1;
        }

};
int main()//Main function
{
    int size,data;
    sorting array;
    cout<<"Enter the size of the array:";
    cin>>size;//taking size of the array
    for(int i=0;i<size;i++)
    {//asking for elements
        cout<<"Enter the element:";
        cin>>data;
        array.addElement(data);
    }
    cout<<"Before Quicksorting ";
    array.display();
    array.quickSort(0,size-1);
    cout<<"After Quicksorting ";
    array.display();
    return 0;
}//End of main function