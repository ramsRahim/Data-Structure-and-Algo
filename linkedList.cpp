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

int findMid(Node *head)
{
    if(head == NULL)
    {
        return -1;
    }
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->Next != NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
    }

    return slow->value;
}

void makeCycle(Node *&head, int pos)
{
    int count=1;
    Node *temp = head;
    Node *startNode;

    while(temp->Next != NULL)
    {
        if(count==pos)
        {
            startNode = temp;
        }
        temp = temp->Next;
        count++;
    }

    temp->Next = startNode;
}

bool detectCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->Next != NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;

        //Cycle check
        if(slow == fast)
        {
            return true;
        }
    }

    return false;
}

void removeCycle(Node* &head)
{
    bool cycleStatus = detectCycle(head);
    if(cycleStatus == false)
    {
        return;
    }
    else
    {
        Node* slow = head;
        Node* fast = head;

        // Step 1: fast = slow
        do{
            slow = slow->Next;
            fast = fast->Next->Next;
        }while(slow!=fast);
        
        //Step 2: Re Initialization
        fast = head;

        // Step 3: fast->Next = slow->Next
        while(fast->Next!=slow->Next)
        {
            slow = slow->Next;
            fast = fast->Next;
        }

        //Step 4:
        slow->Next = NULL;
    }
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

void insertAfterValueUnique(Node *&head,int srchval, int val)
{
    int position = searchByValueUnique(head,srchval);
    insertAtAnyPosition(head,position+1,val);
}

void insertAfterValueDuplicate(Node *&head,int srchval, int val)
{
    Test t = searchByValueDuplicate(head,srchval);

    for(int i=1 ; i<t.position[0];i++)
    {
        insertAtAnyPosition(head,t.position[i]+i,val);
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
    head = temp->Next;
    delete temp;
}

void deletionAtTail(Node *&head)
{
    if(head == NULL || head->Next == NULL)
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
    while(temp->Next->Next!= NULL)
    {
            temp = temp->Next;
    }
    temp->Next = NULL;
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

void deletionBySpecificValueDuplicate(Node *&head,int srchval)
{
      Test t = searchByValueDuplicate(head,srchval);
      for(int i=1 ; i<t.position[0];i++)
        {  
            t.position[i] -= i-1;
        } 
      for (int i=1 ; i<t.position[0];i++)
        {
            deletionAtSpecific(head,t.position[i]);
        }
        
}

Node* reverseNonRecursive(Node *&head)
{
    Node* prev = NULL;
    Node* current = head;

    if(head == NULL)
    {
        return head;
    }

    Node* next = head->Next;

    while (1)
    {
        current->Next = prev;
        prev = current;
        current=next;
        if(current == NULL)
        {
            break;
        }
        next = next->Next;
    }
    
    return prev;
}

Node* revereseRecursive(Node *&head)
{
    //Base call
    if(head == NULL || head->Next == NULL)
        {
            if(head == NULL) cout<<"The list is empty"<<endl;
            return head;
        }

    //Recursive call
    Node* newHead = revereseRecursive(head->Next);
    head->Next->Next = head;
    head->Next = NULL;

    return newHead;
}

int main()
{
    Node* head = NULL;

    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,5);
    insertAtEnd(head,10);
    //insertAtEnd(head,23);
    //insertAtHead(head,3);
    //insertAtHead(head,10);
    //insertAtAnyPosition(head,5,3);
    //int listLen = len(head);
    //cout<<"The length of the list is "<<listLen<<endl;
    display(head);
    //int position=searchByValueUnique(head,3);
    //cout<<"the value is in "<<position<<" position"<<endl;
    //Test T = searchByValueDuplicate(head,3);
    //for (int i = 1; i < T.position[0]; i++)
    //{
    //    cout<<T.position[i]<<" ";
    //}
    //cout<<endl;
    //insertAfterValueUnique(head,3,6);
    //insertAfterValueDuplicate(head,3,6);
    //deletionAtHead(head);
    //deletionAtTail(head);
    //deletionAtSpecific(head,3);
    //deletionBySpecificValueDuplicate(head,2);
    //head = reverseNonRecursive(head);
    //head = revereseRecursive(head);
    makeCycle(head,2);
    //int mid = findMid(head);
    //cout<<mid<<endl;
    bool cycleStatus = detectCycle(head);
    if(cycleStatus == true)
    {
        cout<<"Cycle exists"<<endl;
    }
    else
    {
        cout<<"Cycle doesn't exist"<<endl;
    }
    removeCycle(head);
    display(head);
    return 0;
}