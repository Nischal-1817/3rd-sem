//Nischal Pradyoth
//CS20B1109
#include<iostream>
#include<vector>
using namespace std;
class greedyKnap
{
    private:
        int profit;
        vector<int>weightArray;//for taking weights 
        vector<float>counterArray;
    public:
        void add(int data2)//for adding the data
        {
            weightArray.push_back(data2);
        }
        void add2(int profit)//for adding the data
        {
            this->profit=profit;
        }
        void merge(int p, int q, int r)
        {
            int n1=q-p+1;
            int n2=r-q;
            int first[n1],second[n2];
            for(int i=0;i<n1;i++)
            {
                first[i]=weightArray[p+i];
            }
            for(int i=0;i<n2;i++)
            {
                second[i]=weightArray[q+1+i];
            }

            int i=0,j=0,k=p;
            while(i<n1&&j<n2)
            {
                if(first[i]<=second[j])
                {
                    weightArray[k]=first[i];
                    i++;
                }
                else
                {
                    weightArray[k]=second[j];
                    j++;
                }
                k++;
            }
            while(i<n1)
            {
                weightArray[k]=first[i];
                i++;
                k++;
            }
            while(j<n2)
            {
                weightArray[k]=second[j];
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
        void mergeCall()//function for sorting the weightArray
        {
            int low=0; int high=weightArray.size()-1;
            mergeSort(low,high);
        }
        void knapSack(int maxWeight)//function for calculating and displaying the results
        {
            int counter=0;
            for(int i=0;i<weightArray.size()&&counter!=maxWeight;i++)
            {
                    if(counter+weightArray[i]<=maxWeight)//checking whether it exceeds maxWeight or not
                    {
                        counter+=weightArray[i];
                        counterArray.push_back(1);
                    }
            }
            float profitCount=0;
            for(int i=0;i<counterArray.size();i++)
            {
                profitCount+=profit*counterArray[i];
                if(counterArray[i]>0)
                {
                        cout<<" 1 unit of object with weight "<<weightArray[i]<<" and profit "<<profit<<endl;
                }
            }
            cout<<'\n';
            cout<<"The maximum profit is:"<<profitCount<<endl;
        }
};
int main()
{
    greedyKnap object;
    int size,weight,profit,maxWeight,choice;
    cout<<"Enter the number of objects:";
    cin>>size;
    cout<<"Enter the profit of all objects(which is same):";
    cin>>profit;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter the weight of the object:";
        cin>>weight;
        object.add(weight);
    }
    object.add2(profit);
    cout<<"Enter the maximum weight of the basket:";
    cin>>maxWeight;
    object.mergeCall();
    cout<<"The result is:";
    object.knapSack(maxWeight);
    return 0;
}