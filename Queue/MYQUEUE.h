#include<iostream>
#include<stdlib.h>

using namespace std;

template <typename N> class Node{

public:
    N value;
    Node* next;

    public:

    Node(N val){
        value = val;
        next = NULL;
    } 
};

template<typename Q> class Queue{
    Node<Q>* front;
    Node<Q>* rear;

    public:

    Queue(){
        front = NULL;
        rear = NULL;
    }
    //enqueue --> push(val)

    void push(Q val){

        Node<Q>* newNode = new Node <Q> (val);
        if(front == NULL)
        {
            front = newNode;
            rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = rear->next;
    }

    Q pop (){

        Q chk;
        if(rear == NULL){
            cout<<"Queue underflow"<<endl;
            return chk;
        }
        Node<Q>* delNode;
        delNode = front;
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
        chk = delNode ->value;
        delete delNode;
        return chk;
    }

    Q Front(){

        Q chk;
        chk = front->value;
        return chk;
    }

    Q Back(){
        Q chk;
        chk = rear->value;
        return chk;
    }

    bool empty(){
        if(front == NULL && rear == NULL)
            return true;
        else
            return false;
    }


};
