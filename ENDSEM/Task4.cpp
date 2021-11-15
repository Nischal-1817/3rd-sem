//Nischal Pradyoth
//CS20B1109
#include <bits/stdc++.h>
using namespace std;
class knapSack
{
    public:
        void subsetsUtil(vector<int>& A, vector<vector<int> >& res,vector<int>& subset, int index)//recursive function
        {
            res.push_back(subset);
            for (int i = index; i < A.size(); i++) {
                subset.push_back(A[i]);//including the element

                subsetsUtil(A, res, subset, i + 1);//moving to next element

                subset.pop_back();//not including the element
            }
            return;
        }
        vector<vector<int> > subsets(vector<int>& A)
        {
            vector<int> subset;
            vector<vector<int> > res;

            int index = 0;//for index of current element
            subsetsUtil(A, res, subset, index);

            return res;//returning the vector 
        }
};
int main()
{
	int size,maxWeight,weight,profit,feasibleCount=0;
	cout<<"Enter the number of objects:";
	cin>>size;
	vector<int>weightArray;
	vector<int>profitArray;
	for(int i=0;i<size;i++)
	{
	    cout<<"Enter the weight and profit of the object:";//taking input
	    cin>>weight>>profit;
	    weightArray.push_back(weight); 
	    profitArray.push_back(profit);
	}
	cout<<"Enter the maximum weight:";
	cin>>maxWeight;
    knapSack object;
	vector<vector<int> > res = object.subsets(weightArray);

	for (int i = 0; i < res.size(); i++) {//printing subsets 
	    int sum=0;
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
            
		    sum+=res[i][j];
		}
		if(sum<=maxWeight)//checking whether it satisfies the given condition or not
		{
		    cout<<"- The weight sum is "<<sum;
		    feasibleCount++;
		}
		else 
		{
		    cout<<"- Not applicable";
		}
		cout << endl;
	}
    cout<<"The number of feasible solutions are:"<<feasibleCount<<endl;//printing the result
	return 0;
}