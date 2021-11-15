//Nischal Pradyoth
//CS20B1109
#include <bits/stdc++.h>
using namespace std;
//This problem follows optimal substructure property because
//the optimal solution of this problem lies within its subproblems i.e there will be three cases for each item 1)not including
//2) including 1/2th of item 3)including the whole item. Therefore it is done by taking maximum of those three conditions
//the time complexity of this problem is clearly O(n*W) which is in polynomial time of n which is required 
class knapProblem
{
    public:

    int max(int a, int b)//function to return max of two numbers
    {
        return (a > b) ? a : b;
    }
    int knapSack(int W, int wt[], int val[], int n)//the dp function for calculating result in bottom up way
    {
        int i, w;
        vector<vector<int>> KnapArray(n + 1, vector<int>(W + 1));
        for(i = 0; i <= n; i++)
        {
            for(w = 0; w <= W; w++)
            {
                if (i == 0 || w == 0)//base cases
                    KnapArray[i][w] = 0;
                else if (wt[i - 1]<= w)//recursive solution in dp way.
                    KnapArray[i][w] =max( max(val[i - 1] +
                                    KnapArray[i - 1][w - wt[i - 1]],
                                    KnapArray[i - 1][w]),
                                    max((val[i-1]/2)+KnapArray[i-1][w-wt[i-1]/2],KnapArray[i-1][w]) );//taking max of 1/2 or 1
                else
                    KnapArray[i][w] = KnapArray[i - 1][w];
            }
        }
        return KnapArray[n][W];
    }
};
int main()
{
    int n,W;
    cout<<"Enter the number of objects:";
    cin>>n;
	int val[n],wt[n];
    for(int i=0;i<n;i++)//taking input
    {
        cout<<"Enter the weight and profit of the object:";
        cin>>wt[i]>>val[i];
    }
	cout<<"Enter the maximum weight:";
    cin>>W;
    knapProblem object;
	cout <<"The maximum profit obtained is:"<<object.knapSack(W, wt, val, n);//printing result
	
	return 0;
}