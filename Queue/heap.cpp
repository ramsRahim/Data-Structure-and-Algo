#include<bits/stdc++.h>

using namespace std;

void heapify(int array[] , int n, int current){
    
    int largest = current;
    int leftChild = 2*current + 1;
    int rightChild = 2*current +2;

    if(leftChild< n && array[leftChild]<array[largest]){
        largest = leftChild;
    }

    if(rightChild<n && array[rightChild]<array[largest]){
        largest = rightChild;
    }

    if(largest!=current){
        //cout<<array[current]<<" "<<array[largest]<<" "<<largest<<endl;
        swap(array[current],array[largest]);
        heapify(array,n,largest);
    }
}

void printArray(int array[], int size){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i] << " ";
    }
    cout<<endl;
}

void heapSort(int array[],int size){
    for(int i =size-1; i>=0;i--){
        swap(array[0],array[i]);
        heapify(array,i,0);
        cout<<"heap"<<endl;
        printArray(array,size);
    }
}

int main(){

    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }

    cout<<"Before Heapify";
    printArray(array,n);
    //Heapify
    int nonLeafStart = (n/2)-1;

    for(int i=nonLeafStart;i>=0;i--){
        heapify(array,n,i);
    }

    cout<<"After heapify";
    printArray(array,n);

    heapSort(array,n);
    cout<<"After the heap sort";
    printArray(array,n);
    
    return 0;
}

/* 
9
2 10 1 5 4 8 3 8 7 
*/