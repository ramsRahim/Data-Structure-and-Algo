#include<iostream>

using namespace std;

template<typename N> class Node{

public:
    N value;
    Node* Next;
    Node* Prev;

    Node(N val)
    {
        value = val;
        Next = NULL;
        Prev = NULL;
    }
};

template<typename S> class Stack{

    Node<S>* head;
    Node<S>* top;
    int Count =0;
public:
    Stack(){
        head = NULL;
        top = NULL;
    }

    //PUSH
    void push(S val)
    {
        Node<S>* newNode = new Node<S>(val);
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
    S pop(){
        Node<S>* delNode;
        delNode = top;
        S val;
        //there is no element is the Stack
        if(head == NULL)
        {
            cout<< "Stack Underflow"<<endl;
            return val;
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
    S TOP()
    {
        S chk;
        if(top == NULL){
            cout<<"Stack Underflow"<<endl;
            return chk;
        }
        else return top->value;
    }

};
