#include<iostream>
using namespace std;
/* 4. (Anish) Write a C++ program to create a Banking System. All the data members are declared private and member 
functions are defined under public.

1. Create new account: This creates a new account with the following data members: Account number,
 Account holder’s name, Account type [Savings / Current], Balance, Standing debt.
2. Display all account holder’s record: This displays account number, account holder’s name, account type of all account holders.
3. Declare a constructor that initialises the data members’ value to 0 or ‘\0’.
4. Declare a parameterized constructor that takes name, account number, account type, balance as parameters and
 set other values to 0. Use this pointer inside all constructors.

Write a menu driven program to add new accounts and delete existing accounts. Declare an array of objects and 
get the size of the array during runtime. 

Note: If an account has standing debt, the account cannot be closed (i.e.) removed. 

Maintain proper boundary conditions and follow best coding practices.

The menu is as follows:

1. Create Account
2. Delete Account
3. Display
4. Exit. */
//Note:Here we are taking all data members including account number to be greater than zero only but for account number it
// mustn't be 0 and name must not be empty
class Banking//Banking class 
{
    private://data members
        int accNo;
        string holderName;
        int accType;
        double balance;
        double standingDebt;
    public://member functions
        Banking()//Non-parameterized constructor for assigning all as 0 or "\0"
        {
            this->accNo=0;
            this->holderName='\0';
            this->accType=0;
            this->balance=0;
            this->standingDebt=0;
        }
        Banking(int number,string name,int type,double amount)//Parameterized constructor
        {
            this->accNo=number;
            this->holderName=name;
            this->accType=type;
            this->balance=amount;
            this->standingDebt=0;
        }
        //function for creating an account
        int createAccount(Banking obj[],string holderName,int accNo,int accType,double balance,double standingDebt,int customerCount)
        {
            for(int i=0;i<customerCount;i++)
            {if(obj[i].accNo==accNo){cout<<"This account number is already taken"<<endl; return -1;}}
            obj[customerCount].accNo=accNo;
            obj[customerCount].holderName=holderName;
            obj[customerCount].accType=accType;
            obj[customerCount].balance=balance;
            obj[customerCount].standingDebt=standingDebt;
            return 0;
        }
        int deleteAccount(Banking *obj,int number,int customerCount)//function for deleting an account
        {
            if(customerCount<=0){cout<<"Sorry there is no account to delete"<<endl; return -1;}//boundary condition
            for(int i=0;i<customerCount;i++)
            {
                if(obj[i].accNo==number)
                {
                    if(obj[i].standingDebt>0)//checking standing debt while deleting
                    {
                        cout<<"Sorry,this account cannot be closed as it has standingDebt"<<endl;
                        return -1;
                    }
                    else
                    {
                        for(int j=i;j<customerCount;j++)
                        {
                            obj[i].accNo=obj[i+1].accNo;
                            obj[i].accType=obj[i+1].accType;
                            obj[i].balance=obj[i+1].balance;
                            obj[i].holderName=obj[i+1].holderName;
                            obj[i].standingDebt=obj[i+1].standingDebt;
                        }
                        return 0;
                    }
                }
            }
            cout<<"Invalid account Number"<<endl;
            return -1;
        }
        void display(Banking obj[],int customerCount)//function for displaying all the customer's records
        {
            if(customerCount<=0){cout<<"There is no data"<<endl; return ;}//boundary condition
            cout<<"The details of all the customers are as follows:"<<endl;
            for(int i=0;i<customerCount;i++)
            {
                cout<<"Customer "<<i+1<<":"<<endl;
                cout<<"Holder name is:"<<obj[i].holderName<<endl;
                cout<<"account number is:"<<obj[i].accNo<<endl;
                if(obj[i].accType==1)
                {
                    cout<<"account type is:Savings"<<endl;
                }
                else
                {
                    cout<<"account type is:Current"<<endl;
                }
            }
        }
};
int main()//main function
{
    Banking obj[20];//Declaring array of objects
    int size,customerCount=0;
    cout<<"Enter the size of the array of objects(maximum is 20):";
    cin>>size;//Taking the size of array
    if(size<=0||size>20)
    {
        while(size<=0||size>20)
        {
            cout<<"Enter a valid size:";
            cin>>size;
        }
    }
    Banking head;
    int number; string name; int type; double amount; double debt;
    int choice;
    while(1)//printing menu
    {
        cout<<"1.Create Account"<<endl;
        cout<<"2.Delete Account"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        cin.ignore();
        switch(choice)
        {
            case 1://taking data for creating account
                cout<<"Enter your name:";
                getline(cin,name);
                cout<<"Enter your account Number:";
                cin>>number;
                cout<<"Enter your account type,if savings enter 1 else if current enter 0:";
                cin>>type;
                cout<<"Enter the balance amount:";
                cin>>amount;
                cout<<"Enter the standing Debt you have:";
                cin>>debt;
                if(name =="\0"||number<=0||type<0||type>1||amount<0||debt<0)//Checking details are correct or not
                {
                    cout<<"Invalid credentials,try again"<<endl;
                }
                else 
                {
                    if(customerCount>=size)//boundary condition
                    {
                        cout<<"Sorry this option is closed,due to size issue"<<endl;
                    }
                    else
                    {
                        int m=head.createAccount(obj,name,number,type,amount,debt,customerCount);
                        if(m==0){customerCount++;}
                    }
                }
                break;
            case 2:
                cout<<"Enter the account number of the account for which you want to close:";
                cin>>number;
                if(number<=0)
                {
                    cout<<"Invalid account number";
                }
                else
                {
                    int x=head.deleteAccount(obj,number,customerCount);
                    if(x==0){ customerCount--; }
                }
                break;
            case 3:
                head.display(obj,customerCount);
                break;
            case 4:
                return(0);
                break;
            default:
                cout<<"Enter a valid choice!"<<endl;
                break;
        }
    }
    return 0;
}//End of code