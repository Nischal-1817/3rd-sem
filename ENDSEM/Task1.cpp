//Nischal Pradyoth
//CS20B1109
#include<iostream>
#include<vector>
using namespace std;
class greedyKnap
{
    private:
        int weight;
        vector<int>profitArray;//for taking profits 
        vector<float>counterArray;
    public:
        void add(int data2)//for adding the data
        {
            profitArray.push_back(data2);
        }
        void add2(int weight)//for adding the data
        {
            this->weight=weight;
        }
        void merge(int p, int q, int r)
        {
            int n1=q-p+1;
            int n2=r-q;
            int first[n1],second[n2];
            for(int i=0;i<n1;i++)
            {
                first[i]=profitArray[p+i];
            }
            for(int i=0;i<n2;i++)
            {
                second[i]=profitArray[q+1+i];
            }

            int i=0,j=0,k=p;
            while(i<n1&&j<n2)
            {
                if(first[i]>second[j])
                {
                    profitArray[k]=first[i];
                    i++;
                }
                else
                {
                    profitArray[k]=second[j];
                    j++;
                }
                k++;
            }
            while(i<n1)
            {
                profitArray[k]=first[i];
                i++;
                k++;
            }
            while(j<n2)
            {
                profitArray[k]=second[j];
                j++;
                k++;
            }
        }
        void mergeSort(int low,int high)
        {
            if(low<high)
            {
                int mid=low+(high-low)/2;
                mergeSort(low,mid);
                mergeSort(mid+1,high);
                merge(low,mid,high);
            }
        }
        void mergeCall()//function for sorting the profitArray
        {
            int low=0; int high=profitArray.size()-1;
            mergeSort(low,high);
        }
        void knapSack(int maxWeight)//function for calculating and displaying the results
        {
            int counter=0;
            for(int i=0;i<profitArray.size()&&counter!=maxWeight;i++)
            {
                    if(counter+weight<=maxWeight)//checking whether it exceeds maxWeight or not
                    {
                        counter+=weight;
                        counterArray.push_back(1);
                    }
            }
            float profit=0;
            for(int i=0;i<counterArray.size();i++)
            {
                profit+=profitArray[i]*counterArray[i];
                if(counterArray[i]>0)
                {
                        cout<<" 1 unit of object with weight "<<weight<<" and profit "<<profitArray[i]<<endl;
                }
            }
            cout<<'\n';
            cout<<"The maximum profit is:"<<profit<<endl;
        }
};
int main()
{
    greedyKnap object;
    int size,weight,profit,maxWeight,choice;
    cout<<"Enter the number of objects:";
    cin>>size;
    cout<<"Enter the weight of all objects(which is same):";
    cin>>weight;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter the profit of the object:";
        cin>>profit;
        object.add(profit);
    }
    object.add2(weight);
    cout<<"Enter the maximum weight of the basket:";
    cin>>maxWeight;
    object.mergeCall();
    cout<<"The result is:";
    object.knapSack(maxWeight);
    return 0;
}