#include<iostream>
#include"/Users/rahimhossain/Documents/codes/Data Structure and Algo/MYSTACK.h"

using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    Stack<int> st,min;

    int minimum = INT8_MAX;

    for(int i=0;i<n;i++)
    {
        if(arr[i] <= minimum)
        {
            minimum = arr[i];
            st.push(arr[i]);
            min.push(arr[i]);
        }
        else
        {
            st.push(arr[i]);
        }
    }

    while(!st.empty())
    {
        if(st.TOP() == min.TOP())
        {
            cout<<min.pop()<<" ";
            st.pop();
        }

        else
        {
            cout<<min.TOP()<<" ";
            st.pop();
        }

    }

return 0;

}