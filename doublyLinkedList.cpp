#include<iostream>
using namespace std;

class doublyNode
{
public:
    int value;
    doublyNode* Next;
    doublyNode* Prev;

    doublyNode(int val)
    {
         value = val;
         Next = NULL;
         Prev = NULL;
    }
};

void display(doublyNode* head)
{
    while(head != NULL)
    {
        cout<<head->value;
        if(head->Next != NULL)
        {
            cout<<"-->";
        }
        head = head->Next;
    } 
    cout<<endl;   
}

void displayReverse(doublyNode* head)
{
    while(head->Next != NULL)
    {
        head = head->Next;
    }

    while(head != NULL)
    {
        cout<<head->value;
        if(head->Prev != NULL)
        {
            cout<<"-->";
        }
        head = head->Prev;
    } 
    cout<<endl; 
}

int len(doublyNode* head)
{
    int count = 0;
    while(head != NULL)
    {
        head = head->Next;
        count++;
    }

    return count;
}

void insertAtEnd(doublyNode *& head, int val)
{
    doublyNode *newNode = new doublyNode(val);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    doublyNode* temp = head;

    while(temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
    newNode->Prev =  temp;
}

void insertAtHead(doublyNode* &head, int val)
{
    doublyNode *newNode = new doublyNode(val);
    head->Prev = newNode;
    newNode->Next = head;   
    head = newNode;
}

int main()
{
    doublyNode* head = NULL;

    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,5);
    //insertAtEnd(head,2);
    //insertAtHead(head,3);
    //insertAtHead(head,10);
    //insertAtAnyPosition(head,5,3);
    //int listLen = len(head);
    //cout<<"The length of the list is "<<listLen<<endl;
    display(head);
    displayReverse(head);
    return 0;
}