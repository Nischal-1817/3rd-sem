#include <iostream>
#include <vector>
#include<climits>

using namespace std;

class OptimalBinarySearch{
private:
    vector <int> keys;
    vector <int> freq;
public:
    void add(int b, int c){
        keys.push_back(b);
        freq.push_back(c);
    }

    int optimalSearchTree(int n){
        /* Create an auxiliary 2D matrix to store results
        of subproblems */
        int cost[n][n];

        /* cost[i][j] = Optimal cost of binary search tree
        that can be formed from keys[i] to keys[j].
        cost[0][n-1] will store the resultant cost */

        // For keys single key, cost is equal to frequency of the key
        for (int i = 0; i < n; i++)
            cost[i][i] = freq[i];
        for (int L = 2; L <= n; L++)
        {
            // i is row number in cost[][]
            for (int i = 0; i <= n-L+1; i++)
            {
                // Get column number j from row number i and
                // chain length L
                int j = i+L-1;
                cost[i][j] = INT_MAX;

                // Try making all keys in interval keys[i..j] as root
                for (int r = i; r <= j; r++)
                {
                // c = cost when keys[r] becomes root of this subtree
                int c = ((r > i)? cost[i][r-1]:0) +
                        ((r < j)? cost[r+1][j]:0) +
                        sum(i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
                }
            }
	    }
	return cost[0][n-1];
    }

    int sum(int i, int j){
        int s = 0;
        for (int k = i; k <= j; k++)
        s += freq[k];
        return s;
    }

};

int main()
{
	OptimalBinarySearch obj;
    int size,x,y;
    cout<<"Enter the number of keys: ";
    cin>>size;
    cout<<"Enter the keys and their frequency:\n";
    for(int i=0;i<size;i++){
        cin>>x;
        cin>>y;
        obj.add(x,y);
    }
	cout << "Cost of Optimal BST is " << obj.optimalSearchTree(size);
	return 0;
}
