#include<iostream>
using namespace std;
class binaryMultiply
{
    private:
        int m,n;
    public:
        binaryMultiply(int m,int n)
        {
            this->m=m;
            this->n=n;
        }
};
int main()
{
    int m,n;
    cout<<"Enter the two numbers you want to multiply:";
    cin>>m>>n;
    binaryMultiply obj(m,n);
    return 0;
}