#include<iostream>
using namespace std;
int main()
{
    //step1 --> Max
    //step2 --> count[Max+1]
    //step3 --> Frequency
    //step4 --> Cumulative sum
    //step5 --> sorting

    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    //step1
    int MAX = arr[0];
    for(int i=1;i<n;i++)
    {
        MAX = max(MAX,arr[i]);
    }
    //cout<<MAX<<endl;

    //step2
    int count[MAX+1];
    for(int i=0;i<=MAX;i++)
    {
        count[i]=0;
    }

    //step3
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }

    //step4
    for(int i=1;i<=MAX;i++)
    {
        count[i]+=count[i-1];
    }

    //step5
    int final[n];
    for(int i=n-1;i>=0;i--)
    {   
        count[arr[i]]--;
        int k = count[arr[i]];
        final[k] = arr[i];
    }

    for(int i=0;i<n;i++)
    {
        cout<<final[i]<<" ";
    }
    cout<<endl;
}