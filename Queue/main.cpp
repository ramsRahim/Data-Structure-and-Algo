#include<iostream>
#include"MYQUEUE.h"

using namespace std;

typedef pair <int, int> mytype;

int main()
{
    Queue<mytype> q;
    int n;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        int c1,c2;
        cin>>c1>>c2;
        q.push(make_pair(c1,c2));
    }
    //cout<<q.Back()<<endl; 
    //cout<<q.Front()<<endl;
    while(!q.empty())
    {
        mytype chk;
        chk = q.pop();
        cout<<chk.first<<"|"<<chk.second<<endl;
    }

    return 0;
}