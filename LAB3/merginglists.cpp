#include<bits/stdc++.h>
using namespace std;
//class for linked list which is mainly for member functions
/*
Note: No need of a separate header file.	
Given two sorted lists, merge them so as to produce a combined sorted list (without using extra space). 
The data members and the member function isEmpty() are private and the other member functions are public. 
The list stores integer data. Use new and delete keywords to dynamically allocate and deallocate memory whenever needed.
 Hint: use objects as function arguments and return type from a function or call an object by reference.
Examples: 
 
Input : head1: 5->7->9
        head2: 4->6->8 
Output : 4->5->6->7->8->9
Explanation: The output list is in sorted order.

Input : head1: 1->3->5->7
        head2: 2->4
Output : 1->2->3->4->5->7
Explanation: The output list is in sorted order.

The options for the list are
Insert
Delete
Display
Merge
Exit

When 1. Insert option is selected, request the user at which linked list should you insert the new element in the 
sorted order in the corresponding list.
 When 2. Delete option is selected, request the user at which linked list should you delete at what position and
  delete the node present in the corresponding list.

When 3. Display option is selected, request the user which linked list should you display and print the elements 
in the corresponding list.

When 4. Merge option is selected, you can merge the contents of list2 to list1 or create a list 3 and merge
 the contents of list1 and list2 in the sorted order.

When 5. Exit option is selected, stop the program.
*/
class linkedList
{
    private:
        //Inner class for each node so that it is easy to create a object without member functions
        class Node
        {
            public:
                int data;
                Node *next;
                Node()
                {
                    next=NULL;
                }
        };
        static int objectCount;//just taking objectCount so as to show that there is no extra space 
        Node *head=NULL;//creating a head pointer for a particular object(linked list)
        bool isempty()//function to check whether the linked list is empty or not
        {
            if(head==NULL)
            {
                return true;
            }
            return false;
        }
    public:
        void addNode(int value)//member function to add new node into linked list in a sorted way
        {
            Node *temp=new Node();
                temp->data=value;
            if(isempty())
            {
                head=temp;
            }
            else
            {
                Node* ptr=head;
                if(value < ptr->data)
                {
                     temp->next = head;
                     head = temp;
                }
                else
                {
                    while(ptr->next != NULL && ptr->next->data<value)
                    {    ptr=ptr->next; }
            
                       temp->next=ptr->next;
                       ptr->next=temp;
                }
            }
        }
        void display()//member function to display a linked list 
        {
            Node* temp=head;
            if(isempty())
            {
                cout<<"Linked list is empty!"<<endl;
            }
            else
            {
                cout<<"Linked list is:";
                while(temp!=NULL)
                {
                    cout<<temp->data<<"->";
                    temp=temp->next;
                }   
                cout<<endl;
            }
        }
        void Delete(int position)//member function to delete a node from a linked list 
        {//Remember that if a linked list is 1->2->NULL then the position of '1' is 0
            if(isempty())
            {
                cout<<"Linked list is empty!"<<endl;
            }
            else
            {
            if(position==0)
            {
                Node *ptr=head;
                cout<<"Element delted is:"<<ptr->data<<endl;
                head=head->next;
                delete(ptr);
            }
            else
            {
                Node *ptr,*temp;
                ptr=head;
                while(position>1)
                {
                    position--;
                if(ptr->next==NULL||ptr==NULL)
                {
                    cout<<"There is no Element to delete at that position"<<endl;
                    return ;
                }
                    ptr=ptr->next;
                }
                if(ptr->next==NULL||ptr==NULL)
                {
                    cout<<"There is no Element to delete at that position"<<endl;
                    return ;
                }
                else
                {
                    cout<<"Element delted is:"<<ptr->next->data<<endl;
                    temp=ptr->next;
                    ptr->next=ptr->next->next;
                    delete(temp);
                }
            }
            }
        }
        void mergeLists(linkedList &list2)//member function for merging two linked lists 
        {//here we are basically adding nodes from linked list2 and adding in list1 in a sorted way(simultaneously deleting in list2)
            Node *remover;
            if(isempty()&&list2.isempty())
            {
                cout<<"Both the linked lists are empty"<<endl;
            }
            else
            {
            while(list2.head!=NULL)
            {
                int value=list2.head->data; 
                Node* ptr=head;
                Node *temp=new Node();
                temp->data=value;
                if(isempty())
                {
                head=temp;
                }
                else
                {
                if(value < ptr->data)
                {
                     temp->next = head;
                     head = temp;
                }
                else
                {
                    while(ptr->next != NULL && ptr->next->data<value)
                    {    ptr=ptr->next; }
            
                       temp->next=ptr->next;
                       ptr->next=temp;
                }
                }
                remover=list2.head;
                list2.head=list2.head->next;
                delete(remover);
            }
            cout<<"After merging ";
            display();
            }
        }
        ~linkedList()//destructor for deallocating the memory
        {
            objectCount++;
            cout<<"Linked list"<<objectCount<<" is deleted"<<endl;
            Node *temp=head;
            Node *remover;
            while(temp!=NULL)
            {
                remover=temp;
                temp=temp->next;
                delete(remover);
            }
        }
            
};
int linkedList::objectCount=0;
//main function 
int main()
{
    linkedList list1,list2;
    int choice,data,position,num;
    while(1)
    {
        //printing menu
        cout<<"1.Insert"<<endl;
        cout<<"2.Delete"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Merge"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter to which linkedList you want to insert(1/2):";
                cin>>num;
                if(num==1)
                {
                    cout<<"Enter the number you want to insert to list1:";
                    cin>>data;
                    list1.addNode(data);
                }
                else if(num==2)
                {
                    cout<<"Enter the number you want to insert to list2:";
                    cin>>data;
                    list2.addNode(data);
                }
                else
                {
                    cout<<"Not a valid choice"<<endl;
                }
                break;
            case 2:
                cout<<"Enter from which linkedList you want to delete(1/2):";
                cin>>num;
                if(num==1)
                {
                     cout<<"Enter the position to delete:";
                    cin>>position;
                    list1.Delete(position);
                }
                else if(num==2)
                {
                    cout<<"Enter the position to delete:";
                    cin>>position;
                    list2.Delete(position);
                }
                else
                {
                    cout<<"Not a valid choice"<<endl;
                }
                
                break;
            case 3:
                cout<<"Enter which linkedList you want to see(1/2):";
                cin>>num;
                if(num==1)
                {
                    list1.display();
                }
                else if(num==2)
                {
                    list2.display();
                }
                else
                {
                    cout<<"Not a valid choice"<<endl;
                }
                break;
            case 4:
                list1.mergeLists(list2);
                break;
            case 5:
                return (1);
                break;
            default:
                cout<<"Enter a valid choice"<<endl;
                break;
        }
    }
    
    return 0;
}