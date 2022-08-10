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

struct Test
{
    int position[1000];
};

void display(Node* head)
{
    while(head != NULL)
    {
        cout<<head->value;
        if(head->Next != NULL)
        {
            cout<<"->";
        }
        head = head->Next;
    } 
    cout<<endl;    
}
int len(Node* head)
{
    int count = 0;
    while(head != NULL)
    {
        head = head->Next;
        count++;
    }

    return count;
}

int searchByValueUnique(Node* head, int val)
{
    int count =1;

    if(head == NULL)
        {
            return -1;
        }  

    while(head->value != val)
    {
       if(head->Next == NULL)
        {
            return -1;
        }  
        head = head->Next;
        count++;
    }

    return count;
}

Test searchByValueDuplicate(Node* head, int val)
{
    int count = 1;
    Test t;
    int k=1;
    while(head != NULL)
    {
        if(head->value == val)
        {
            //cout<<count<<" ";
            t.position[k]=count;
            k++;
        }
        head = head->Next;
        count++;
    }

    t.position[0]=k;
    return t;
}

void insertAtEnd(Node* &head,int val)
{
    Node *newNode = new Node(val);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void insertAtHead(Node* &head, int val)
{
    Node *newNode = new Node(val);
    newNode->Next = head;   
    head = newNode;
}

void insertAtAnyPosition(Node* &head,int position,int val)
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
            newNode->Next =  temp->Next;
            temp->Next = newNode;
            break;
        }
    }
}

int main()
{
    Node* head = NULL;

    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,5);
    insertAtHead(head,3);
    insertAtHead(head,10);
    insertAtAnyPosition(head,5,3);
    int listLen = len(head);
    cout<<"The length of the list is "<<listLen<<endl;
    display(head);
    int position=searchByValueUnique(head,3);
    cout<<"the value is in "<<position<<" position"<<endl;
    Test T = searchByValueDuplicate(head,3);
    for (int i = 1; i < T.position[0]; i++)
    {
        cout<<T.position[i]<<" ";
    }
    cout<<endl;
    return 0;
}