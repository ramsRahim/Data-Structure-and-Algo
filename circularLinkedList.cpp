#include<iostream>
using namespace std;

class Node
{
public:
    int value;
    Node* Next;

    Node(int val)
    {
         value = val;
         Next = NULL;
    }
};

void display(Node* head)
{
    Node* temp = head;
    do
    {
        cout<<temp->value;
        if(temp->Next != head)
        {
            cout<<"->";
        }
        temp = temp->Next;
    }while(temp!= head); 
    cout<<endl; 
}  

int len(Node* head)
{
    int count = 0;
    Node *temp = head;
    do
    {
        temp = temp->Next;
        count++;
    }while(temp != head);
    
    return count;
}

void insertAtTail(Node* &head,int val)
{
    Node *newNode = new Node(val);

    if(head == NULL)
    {
        head = newNode;
        newNode->Next = head;
        return;
    }

    Node* temp = head;

    while(temp->Next != head)
    {
        temp = temp->Next;
    }
    newNode->Next = head;
    temp->Next = newNode;
}

void insertAtHead(Node* &head, int val)
{
    Node *newNode = new Node(val);
    newNode->Next = head;  
    Node *temp = head;
    if(head == NULL)
    {
        head = newNode;
        newNode->Next = head;
        return;
    }
    while(temp->Next != head)
    {
        temp = temp->Next;
    }
    temp->Next = newNode; 
    head = newNode;
}

void insertAtSpecificPosition(Node* &head,int position,int val)
{
    Node *newNode = new Node(val);
    int count = 1;

    Node* temp = head;
    while(1)
    {
        count++;
        temp = temp->Next;
        if(count == position-1)
        {
            newNode->Next = temp->Next;
            temp->Next = newNode;
            break;
        }
    }
}

void deletionAtHead(Node *&head)
{
    if(head == NULL)
    {
        cout<<"The list is empty";
        return;
    }
    Node* temp = head;
    Node* prevHead = head;
    while(temp->Next != prevHead)
    {
        temp = temp->Next;
    }
    temp->Next = prevHead->Next;
    head = prevHead->Next;
    delete prevHead;
}

void deletionAtTail(Node *&head)
{
    if(head == NULL || head->Next == head)
    {
        if(head == NULL)
        {
            cout<<"The list is empty"<<endl;
            return;
        }
        else
        {
            deletionAtHead(head);
            return;
        }
       
    }

    Node* temp = head;
    while(temp->Next->Next!= head)
    {
            temp = temp->Next;
    }
    temp->Next = head;
    delete temp->Next;  
}

void deletionAtSpecific(Node *&head , int pos)
{
    Node* temp = head;
    int count =1;
    if(pos-1 == 0)
    {
        deletionAtHead(head);
    }
    else if (temp == NULL)
    {
        cout<<"The list is empty"<<endl;
    }
    
    else if(pos>len(head))
    {
        cout<<"The given position is out of range"<<endl;
    }
    else
    {
        while (count < pos-1)
        {
            temp = temp->Next;
            count++;
        }
        Node *delNode = temp->Next;
        temp->Next = delNode->Next;
        delete delNode;
    }
    
}

int main()
{
    Node* head = NULL;

    //insertAtTail(head,1);
    //insertAtTail(head,2);
    //insertAtTail(head,5);
    //insertAtTail(head,10);
    insertAtHead(head,-1);
    display(head);

    deletionAtHead(head);
    display(head);

    //int length = len(head);
    //cout<<length<<endl;

    return 0;
}


