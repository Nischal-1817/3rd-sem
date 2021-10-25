#include<iostream>
#include<vector>
using namespace std;
class matrixGreedy
{
    private:
        vector<int>matrixArray;
        vector<int>columnOrder;
        vector<int>rowOrder;
        vector<int>checked;
    public:
        void add(int data)
        {
            matrixArray.push_back(data);
        }
        void display()
        {
            cout<<"The matrices are:";
            for(int i=0;i<matrixArray.size()-1;i++)
            {
                cout<<matrixArray[i]<<"x"<<matrixArray[i+1]<<", ";
            }
            cout<<'\n';
            cout<<"The row order are:";
            for(int i=0;i<rowOrder.size();i+=2)
            {
                cout<<rowOrder[i]<<"x"<<rowOrder[i+1]<<",";
            }
            cout<<'\n';
            cout<<"The column order are:";
            for(int i=0;i<columnOrder.size();i+=2)
            {
                cout<<columnOrder[i]<<"x"<<columnOrder[i+1]<<",";
            }
            cout<<"\n";
        }
        bool check(int data)
        {
            for(int i=0;i<checked.size();i++)
            {
                if(data==checked[i])
                return 0;
            }
            return 1;
        }
        void creation()
        {
            int max=-1,max_index;
            for(int j=0;j<matrixArray.size();j++)
            {
                max=-1;
                for(int i=0;i<matrixArray.size();i++)
                {
                    if(max<matrixArray[i])
                    {
                        if(check(matrixArray[i])==1)
                        {max_index=i;
                        max=matrixArray[i];}  
                    } 
                }
                checked.push_back(matrixArray[max_index]);
                        if(max_index!=matrixArray.size()-1)//row
                        {
                            rowOrder.push_back(matrixArray[max_index]);
                            rowOrder.push_back(matrixArray[max_index+1]);
                        }
                        if(max_index!=0)//column
                        {
                            columnOrder.push_back(matrixArray[max_index-1]);
                            columnOrder.push_back(matrixArray[max_index]);
                        }
            }
        }
        void computation()
        {
            int sum=0;
            int ptr=columnOrder.size()-1;
            int m,n,x,y;
            while(rowOrder.size()!=0&&columnOrder.size()!=0&&ptr>0)
            {
                 x=columnOrder[ptr];
                 y=columnOrder[ptr-1];
                for(int i=rowOrder.size()-1;i>=0;i-=2)
                {
                    if(y==rowOrder[i])
                    {
                        n=rowOrder[i]; m=rowOrder[i-1];
                        sum+=(x*y*m);
                        columnOrder.erase(columnOrder.begin()+ptr);  columnOrder.erase(columnOrder.begin()+ptr-1);
                        for(int j=0;j<columnOrder.size();j+=2)
                        {
                            if(m==columnOrder[j]&&n==columnOrder[j+1])
                            {
                                columnOrder.erase(columnOrder.begin()+j); columnOrder.erase(columnOrder.begin()+j);
                            }
                        }
                        rowOrder.erase(rowOrder.begin()+i); rowOrder.erase(rowOrder.begin()+i-1);
                        for(int j=0;j<rowOrder.size();j+=2)
                        {
                            if(x==rowOrder[j+1]&&y==rowOrder[j])
                            {
                                rowOrder.erase(rowOrder.begin()+j); rowOrder.erase(rowOrder.begin()+j);
                            }
                        }
                        columnOrder.push_back(m); columnOrder.push_back(x);
                    }
                }
                ptr-=2;
            }
            cout<<"The minimum number of computations required are:"<<sum<<endl;
        }
};
int main()
{
    matrixGreedy obj;
    int size,data;
    cout<<"Enter the number of matrices:";
    cin>>size;
    for(int i=0;i<size+1;i++)
    {
        cout<<"Enter the order:";
        cin>>data;
        obj.add(data);
    }
    obj.creation();
    obj.display();
    obj.computation();
    obj.display();
    return 0;
}