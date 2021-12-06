//CS20B1109
//Nischal Pradyoth
#include<iostream>
using namespace std;
//NOTE:Here the positions are taken as "If the linked list 1->2->3" then the positions of 1,2,3 are 1,2,3 respectively
/*
Write a C++ program using classes to implement a single linked list. 
The data members are private and member functions are public. Overload the insert and delete functions. 
If the insert function passes only the head pointer and the number to be inserted, then, insert at the end of the list. 
If the insert function passes head pointer, number to be inserted, and position to insert the element,
 overload the insert function and insert the number at the specified position. Similarly, overload the delete function. 
 If the delete function passes only the head pointer, then, delete the element at the end of the list and return 
 the deleted element.  If the delete function passes the head pointer, and position to delete the element, 
 overload the delete function. Display function prints all the elements in the list. Maintain proper boundary conditions 
 and design a menu driven program.
*/
class Node//Class Node 
{
    private:
        int data;
        Node *next;//Keeping data members private
    public:
        Node()//Function for creating new node 
        {
            next=NULL;
        }
        void insert(Node **head,int value)//Insert function for inserting at the end
        {
            Node *ptr=new Node();
            ptr->data=value;
            if(*head==NULL)//Checking empty or not
            {
                *head=ptr;
            }
            else 
            {
                Node *temp=*head;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=ptr;
            }
        }
        void insert(Node **head,int value,int position)//Insert function for inserting at a position
        {
            Node *ptr=new Node();
            ptr->data=value;
            if(*head==NULL)//Checking empty or not
            {
                *head=ptr;
            }
            else 
            {
                Node *temp=*head;
                if(position==1)
                {
                    ptr->next=*head;
                    *head=ptr;
                }
                else
                {
                    position--;
                    while(temp->next!=NULL&&position!=1)
                    {
                        temp=temp->next;
                        position--;
                    }
                    if(temp->next==NULL&&position>1)//Boundary condition
                    {
                        cout<<"Invalid position"<<endl;
                    }
                    else
                    {
                        ptr->next=temp->next;
                        temp->next=ptr;
                    }
                }
            }
        }
        void display(Node **head)//Display function to display the linked list's elements
        {
            if(*head==NULL)//Boundary condition
            {
                cout<<"The linked list is empty"<<endl;
            }
            else 
            {
                cout<<"The elements in the list are:";
                Node *temp=*head;
                while (temp!=NULL)
                {
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
                cout<<endl;
            }
            
        }
        void Delete(Node **head)//Delete function to delete element at end
        {
            if(*head==NULL)//Boundary condition
            {
                cout<<"The linked list is empty"<<endl;
            }
            else 
            {
                Node *temp=*head;
                if(temp->next==NULL)//For deleting head if head is only present
                {
                    cout<<"Deleted element is:"<<temp->data<<endl;
                    *head=NULL;
                    delete(temp);
                }
                else
                {
                    while(temp->next->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    Node *remover=temp->next;
                    cout<<"Deleted element is:"<<remover->data<<endl;
                    temp->next=NULL;
                    delete(remover);
                }   
            }
        }
        void Delete(Node **head,int position)//Delete function to delete at a certain position
        {
            if(*head==NULL)//Boundary condition
            {
                cout<<"The linked list is empty"<<endl;
            }
            else 
            {
                Node *temp=*head;
                if(position==1)//For deleting head
                {
                    cout<<"Deleted element is:"<<temp->data<<endl;
                    *head=temp->next;
                    delete(temp);
                    return ;
                }
                position--;
                if(temp->next==NULL&&position>=1)//Checking if position is greater than size or not
                {
                    cout<<"Not a valid choice"<<endl;
                    return ;
                }
                while(temp->next->next!=NULL&&position>1)
                {
                    temp=temp->next;
                    position--;
                }
                if(temp->next->next==NULL&&position>1)//Checking if posititon is greater than size or not
                {
                    cout<<"Not a valid choice"<<endl;
                    return ;
                }
                Node *remover=temp->next;
                cout<<"Deleted element is:"<<remover->data<<endl;
                temp->next=remover->next;
                delete(remover);
            }
        }
        void destruction(Node **head)//Function to de-allocate the memory of linked list
        {
            Node *ptr=*head;
            Node *remover;
            while(ptr!=NULL)
            {
                remover=ptr;
                ptr=ptr->next;
                delete(remover);
            }
        }
};
int main()//Main function begins
{
    Node list1;
    Node *head=NULL;//Creating head pointer
    int choice,data,position;
    while(1)
    {//Printing menu
        cout<<"1.Insert"<<endl;
        cout<<"2.Insert at a position"<<endl;
        cout<<"3.Delete"<<endl;
        cout<<"4.Delete at a position"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the number you want to insert:";
                cin>>data;
                list1.insert(&head,data);
                break;
            case 2:
                cout<<"Enter the number you want to insert and position :";
                cin>>data>>position;
                if(position<=0){cout<<"Not a valid choice"<<endl; break; }//Checking position
                list1.insert(&head,data,position);
                break;
            case 3:
                list1.Delete(&head);
                break;
            case 4:
                cout<<"Enter the position of the element you want to delete:";
                cin>>position;
                if(position<=0){cout<<"Not a valid choice"<<endl; break; }//Checking position
                list1.Delete(&head,position);
                break;
            case 5:
                list1.display(&head);
                break;
            case 6:
                list1.destruction(&head);
                return 1;
                break;
            default:
                cout<<"Enter a valid choice"<<endl;
                break;
        }
    }
    return 0;
}