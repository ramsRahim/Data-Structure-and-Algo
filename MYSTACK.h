#include<iostream>

using namespace std;

class Node{

public:
    int value;
    Node* Next;
    Node* Prev;

    Node(int val)
    {
        value = val;
        Next = NULL;
        Prev = NULL;
    }
};

class Stack{

    Node* head;
    Node* top;
    int Count =0;
public:
    Stack(){
        head = NULL;
        top = NULL;
    }

    //PUSH
    void push(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL){
            head = top = newNode;
            Count ++;
            return;
        }

        top->Next = newNode;
        newNode->Prev = top;
        top = newNode;
        Count ++;
       
    }
    //POP
    int pop(){
        Node* delNode;
        delNode = top;
        int val;
        //there is no element is the Stack
        if(head == NULL)
        {
            cout<< "Stack Underflow"<<endl;
            return -1;
        }
        if(top == head) //there is only one element
        {
            head = top = NULL;
        }
        else // there are more than one elements
        {
            top = delNode->Prev;
            top->Next = NULL;
        }

        val = delNode->value;
        delete delNode;
        Count--;
        return val;
    }

    //EMPTY
    bool empty(){
        if(head == NULL){
            return true;
        }
        else return false;
    }
    //SIZE
    int size(){
        return Count;
    }
    //TOp
    int TOP()
    {
        if(top == NULL){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        else return top->value;
    }

};
