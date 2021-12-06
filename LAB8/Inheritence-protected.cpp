//CS20B1109
//Nischal Pradyoth
//Note: We are asking interest or transactionfee only at starting as it is being common for all, if we want to change we can change by option 
// And except option 1 to perform any other option I have kept the boundary condition as to add an account
/*
Create an inheritance hierarchy that a bank might use to represent customers’ bank accounts. 
All customers at this bank can deposit (i.e., credit) money into their accounts and withdraw (i.e., debit) 
money from their accounts. More specific types of accounts also exist. Savings accounts, for instance, 
earn interest on the money they hold. Checking accounts, on the other hand, charge a fee per transaction (i.e., credit or debit).
reate an inheritance hierarchy containing base class Account and derived classes SavingsAccount and CheckingAccount 
that inherit from class Account. Base class Account should include one data member of type double to represent the 
account balance and one data member of type int that represents the account number. The account number should be unique 
and must be provided by the user. The class should provide a constructor that receives an initial balance and uses it to 
initialize the data member. The constructor should validate the initial balance to ensure that it’s greater than or equal to 0.0.
If not, the balance should be set to 0.0 and the constructor should display an error message, indicating that the initial balance 
was invalid. The class should have necessary member functions. Member function credit should add an amount to the current balance.
 Member function debit should withdraw money from the Account and ensure that the debit amount does not exceed the Account’s 
 balance. If it does, the balance should be left unchanged and the function should print the message "Debit amount exceeded 
 account balance." Member function getBalance should return the current balance. Member function creates an account number and 
 it should be a unique account number for each user. 

Derived class SavingsAccount should inherit the functionality of an Account, but also include a data member of 
type double indicating the interest rate (percentage) assigned to the Account. SavingsAccount ’s constructor should 
receive the initial balance, as well as an initial value for the SavingsAccount ’s interest rate. SavingsAccount should 
provide a public member function calculateInterest that returns a double indicating the amount of interest earned by an account. 
Member function calculateInterest should determine this amount by multiplying the interest rate by the account balance.
 [Note: SavingsAccount should inherit member functions credit and debit as is without redefining them.]

Derived class CheckingAccount should inherit from base class Account and include an additional data member of type 
double that represents the fee charged per transaction. CheckingAccount’s constructor should receive the initial balance, 
as well as a parameter indicating a fee amount. Class CheckingAccount should redefine member functions credit and debit so
 that they subtract the fee from the account balance whenever either transaction is performed successfully. CheckingAccount ’s 
 versions of these functions should invoke the base-class Account version to perform the updates to an account balance. 
 CheckingAccount ’s debit function should charge a fee only if money is actually withdrawn (i.e., the debit amount does not 
 exceed the account balance). [Hint: Define Account’s debit function so that it returns a bool indicating whether money
  was withdrawn. Then use the return value to determine whether a fee should be charged.] 

The data about the customers are stored in a separate singly linked list for SavingsAccount and CheckingAccount fashion.
 Use public inheritance for both derived classes. Maintain proper boundary conditions.

After defining the classes in this hierarchy, write a menu-driven program with the following options, 

1. Open Account (Savings or Checking Account)
2. Credit (Savings or Checking Account)
3. Debit (Savings or Checking Account)
4. Change/Update Interest rate (Savings Account)
5. Calculate Interest (Savings Account - Print)
6. Calculate and Update Interest (Savings Account - Credit)
7. Change/Update Fee Amount (Checking Account)
8. Print Checking Fee (Checking Account)
9. Transact and Update (Checking Account - Debit)
10. Exit
*/
#include<iostream>
using namespace std;
class account//account class
{
    public: //data members
        double accBalance;
        int accNumber;
    public://member functions
        account(double accBalance=0)//Constructor for assigning Balance
        {
            if(accBalance<0)
            {
                this->accBalance=0;
                cout<<"Invalid Balance"<<endl;
            }
            else 
            {
                this->accBalance=accBalance;
            }
        }
        bool credit(double amount)//function to credit amount with boundary condition
        {
            if(amount<0)
            {
                cout<<"Invalid Credit"<<endl;
                return false;
            }
            else
            {
            accBalance+=amount;
            return true;
            }
        }
        bool debit(double amount)//function to debit amount with boundary condition
        {
            if(amount>accBalance)
            {
                cout<<"Debit amount exceeded account Balance"<<endl;
                return false;
            }
            else if(amount<0)
            {
                cout<<"Invalid Debit amount"<<endl;
                return false;
            }
            else
            {
                accBalance-=amount;
                return true;
            }
        }
        double getBalance()//function to get Balance 
        {
            return accBalance;
        }
};
class Savings: public account//Savings class which is publicly inherited from account class
{
    private://data members
        double interest;
    public:
        Savings *next;
        Savings(double rate=0)//Constructor to allocate balance and interest as 0 default
        {
            if(rate<0)
            {
                cout<<"Invalid entry"<<endl;
                 interest=0;
            }
            else
            {
                interest=rate;
            }
        }
        void create(Savings **head,int number,double Balance,double rate)//Function to add an account 
        {
            if(number<0||Balance<0||rate<0)
            {
                cout<<"Invalid credentials"<<endl;
                return ;
            }
            else
            {
                Savings *ptr=new Savings();
                ptr->accNumber=number;
                ptr->accBalance=Balance; 
                ptr->interest=rate;
                ptr->next=NULL;
                if(*head==NULL)
                {
                    *head=ptr;
                }
                else
                {
                    Savings *ptr1=*head;
                    while(ptr1->next!=NULL)
                    {
                        ptr1=ptr1->next;
                    }
                    ptr1->next=ptr;
                }
            }
        }
        void interestFunction(Savings **head,double rate,int choice)//Function for interest calculator,updater,printer
        {
            Savings *ptr=*head;
            if(choice==0)
            {
                while(ptr!=NULL)
                {
                    ptr->interest=rate;
                    ptr=ptr->next;
                }
            }
            else
            {   
                while (ptr!=NULL&&ptr->accNumber!=rate)
                {
                    ptr=ptr->next;
                }
                if(ptr==NULL)//boundary condition
                { cout<<"INVALID ACCOUNT NUMBER"<<endl; return ;}
                    double balance=ptr->getBalance();
                    cout<<"The interest amount is:"<<(balance*ptr->interest)/100<<endl;
                if(choice!=1)
                {
                    bool x=ptr->credit((balance*ptr->interest)/100);
                    if(x==true){cout<<"After updation of interest,the balance is: "<<ptr->getBalance()<<endl;}
                }
            }
        }
};
class Checking: public account//Checking class which publicly inherits from account class
{
    private://Data members
        double feeCharged;
        Checking *next;
    public:
        Checking(double fee=0)//Constructor for assigning Balance and fee Charge
        {
            if(fee<0)
            {
                cout<<"Invalid entry"<<endl;
                feeCharged=0;
            }
            else
            {
            feeCharged=fee;
            }
        }
        void create(Checking **head,int number,double Balance,double fee)//Function to add a Checking account
        {
            if(number<0||Balance<0||fee<0)
            {
                cout<<"Invalid Credentials"<<endl;
                return ;
            }
            else
            {
                Checking *ptr=new Checking();
                ptr->accNumber=number;
                ptr->accBalance=Balance;
                ptr->feeCharged=fee;
                ptr->next=NULL;
                if(*head==NULL)
                {
                    *head=ptr;
                }
                else
                {
                    Checking *ptr2=*head;
                    while(ptr2->next!=NULL)
                    {
                        ptr2=ptr2->next;
                    }
                    ptr2->next=ptr;
                }
            }
        }
        void Credit(Checking **head,int number,double amount)//Function to credit amount 
        {
            Checking *ptr=*head;
                while (ptr!=NULL&&ptr->accNumber!=number)
                {
                    ptr=ptr->next;
                }
                if(ptr==NULL)
                { cout<<"INVALID ACCOUNT NUMBER"<<endl; return ;}
                else 
                {
                bool x=ptr->credit(amount);
                if(x==true){cout<<"The balance after crediting "<< amount<<"is:"<<ptr->getBalance()<<endl;}
                
                if(x==true)//Checking whether to emit transaction fee or not
                {
                    if(ptr->accBalance>=ptr->feeCharged)
                    {ptr->debit(ptr->feeCharged);
                    cout<<"After emitting the transaction fee, your balance is:"<<ptr->getBalance()<<endl;}
                }
                }
        }
        void Debit(Checking **head,int number,double amount)//Function to debit amount
        {
            Checking *ptr=*head;
            while (ptr!=NULL&&ptr->accNumber!=number)
            {
                ptr=ptr->next;
            }
            if(ptr==NULL)
            { cout<<"INVALID ACCOUNT NUMBER"<<endl; return ;}
            
            bool x=ptr->debit(amount);
            if(x==true){cout<<"The balance after debiting "<< amount<<"is:"<<ptr->getBalance()<<endl;}
            
            if(x==true)//Checking whether to emit transaction fee or not
            {
                if(ptr->accBalance>=ptr->feeCharged)
                {
                    ptr->debit(feeCharged);
                    cout<<"After emitting the transaction fee,your balance is:"<<ptr->getBalance()<<endl; 
                }
            }
        }
        double feeFunction(Checking **head,double fee,int choice)//Function for fee Charge updater,printer
        {
            Checking *ptr=*head;
            if(choice==0)
            {
                while(ptr!=NULL)
                {
                    ptr->feeCharged=fee;
                    ptr=ptr->next;
                }
            }
            else if(choice==1)
            {
                if(ptr!=NULL)
                {   return ptr->feeCharged; }
                else 
                { return 0; }
            }
        }
};
int main()//Main function
{
    int choice,accType,number,countSaving=0,countChecking=0;
    double balance,rate,fee=0,amount,x;
    Savings list1;//Linked list for Savings account details
    Savings *head1=NULL;
    Checking list2;//Linked list for Checking account details
    Checking *head2=NULL;
    while(1)
    {//printing menu
        cout<<"1.Open Account"<<endl;
        cout<<"2.Credit"<<endl;
        cout<<"3.Debit"<<endl;
        cout<<"4.Change/Update Interest rate"<<endl;
        cout<<"5.Calculate Interest "<<endl;
        cout<<"6.Calculate and update interest"<<endl;
        cout<<"7.Change/Update fee amount"<<endl;
        cout<<"8.Print Checking fee"<<endl;
        cout<<"9.Transact and check out"<<endl;
        cout<<"10.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"If Savings account enter 1 else 2:";
            cin>>accType;
            if(accType==1)
            {
                if(countSaving==0)
                {
                    cout<<"Enter the account number,balance,interest:";
                    cin>>number>>balance>>rate;
                    list1.create(&head1,number,balance,rate);
                    if(number>0&&balance>0&&rate>0)
                    {countSaving++;}
                }
                else 
                {
                    cout<<"[NOTE:NO INTEREST RATE]Enter the account number,balance:";
                    cin>>number>>balance;
                    list1.create(&head1,number,balance,rate);
                }
            }
            else if(accType==2)
            {
                if(countChecking==0)
                {
                    cout<<"Enter the account number,balance,charging fee:";
                    cin>>number>>balance>>fee;
                    list2.create(&head2,number,balance,fee);
                    if(number>0&&balance>0&&rate>0)
                    {countChecking++;}
                }
                else 
                {
                    cout<<"[NOTE:NO TRANSACTION FEE]Enter the account number,balance:";
                    cin>>number>>balance;
                    list2.create(&head2,number,balance,fee);
                }
            }
            else 
            {
                cout<<"Enter a valid choice "<<endl;
            }
            break;
        case 2:
            cout<<"If Savings account enter 1 else 2:";
            cin>>accType;
            if(accType==1)
            {
                if(countSaving>0)
                {cout<<"Enter the account number to which you want to credit:";
                cin>>number;
                cout<<"Enter the amount you want to credit:";
                cin>>amount;
                Savings *ptr=head1;
                while (ptr!=NULL&&ptr->accNumber!=number)
                {
                    ptr=ptr->next;
                }
                if(ptr==NULL)//boundary condition
                { cout<<"INVALID ACCOUNT NUMBER"<<endl; break;}
                bool x=ptr->credit(amount);
                if(x==true){cout<<"After crediting "<<amount<<",the balance is: "<<ptr->getBalance()<<endl;}}
                else 
                {
                    cout<<"Add an account to credit amount"<<endl;
                }
            }
            else if(accType==2)
            {
                if(countChecking>0)
                {cout<<"Enter the account number to which you want to credit:";
                cin>>number;
                cout<<"Enter the amount you want to credit:";
                cin>>amount;
                list2.Credit(&head2,number,amount);}
                else 
                {
                    cout<<"Add an account to credit amount"<<endl;
                }
            }
            else 
            {
                cout<<"Enter a valid choice"<<endl;
            }
            break;
        case 3:
            cout<<"If Savings account enter 1 else 2:";
            cin>>accType;
            if(accType==1)
            {
                if(countSaving>0)
                {cout<<"Enter the account number from which you want to debit:";
                cin>>number;
                cout<<"Enter the amount you want to debit:";
                cin>>amount;
                Savings *ptr=head1;
                while (ptr!=NULL&&ptr->accNumber!=number)
                {
                    ptr=ptr->next;
                }
                if(ptr==NULL)//boundary condition
                { cout<<"INVALID ACCOUNT NUMBER"<<endl; break;}
                bool x=ptr->debit(amount);
                if(x==true){cout<<"After Debiting "<<amount<<",the balance is: "<<ptr->getBalance()<<endl;}}
                else 
                {
                    cout<<"Add an account to debit amount"<<endl;
                }
            }
            else if(accType==2)
            {
                if(countChecking>0)
                {cout<<"Enter the account number from which you want to debit:";
                cin>>number;
                cout<<"Enter the amount you want to debit:";
                cin>>amount;
                list2.Debit(&head2,number,amount);}
                else
                {
                    cout<<"Add an account to debit amount"<<endl;
                }
            }
            else 
            {
                cout<<"Enter a valid choice"<<endl;
            }
            break;
        case 4:
            if(countSaving>0)
            {cout<<"Enter the new interest rate:";
            cin>>rate;
            list1.interestFunction(&head1,rate,0);}
            else 
            {
                cout<<"To change the interest rate add an account"<<endl;
            }
            break;
        case 5:
            if(countSaving>0)
            {cout<<"Enter the account number for which you want to find the interest:";
            cin>>number;
            list1.interestFunction(&head1,number,1);}
            else 
            {
                cout<<"Add an account to Calculate the interest amount"<<endl;
            }
            break;
        case 6:
            if(countSaving>0)
            {cout<<"Enter the account number for which you want to find the interest:";
            cin>>number;
            list1.interestFunction(&head1,number,2);}
            else 
            {
                cout<<"Add an account to Update the interest amount"<<endl;
            }
            break;
        case 7:
            if(countChecking>0)
            {
                cout<<"Enter the new transaction fee:";
                cin>>fee;
                list2.feeFunction(&head2,fee,0);
            }
            else 
            {
                cout<<"To change the transaction fee add an account"<<endl;
            }
            break;
        case 8:
            if(countChecking>0)
            {
                x=list2.feeFunction(&head2,fee,1);
                cout<<"The current fee charge per transaction is:"<<x<<endl;
            }
            else
            {
                cout<<"As no account is added,the default transaction fee is 0"<<endl;
            }
            break;
        case 9:
            if(countChecking>0)
            {
                cout<<"Enter the account number from which you want to debit:";
                cin>>number;
                cout<<"Enter the amount you want to debit:";
                cin>>amount;
                x=list2.feeFunction(&head2,fee,1);
                list2.Debit(&head2,number,amount);
            }
            else 
            {
                cout<<"Add an account to debit"<<endl;
            }
            break;
        case 10:
            return (1);
            break;
        default:
            cout<<"Enter a valid choice"<<endl;
            break;
        }
    }
    return 0;
}//End of Main function and program