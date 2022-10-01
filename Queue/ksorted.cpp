#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PAIR;

int main(){

    int k;
    cin>>k;

    vector<vector<int>> allValues(k);
    for(int i=0;i<k;i++){
        int size;
        cin>>size;
        allValues[i] = vector<int>(size);
        for(int k=0;k<size;k++){
            cin>>allValues[i][k];
        }
    }
    vector<int>indexTracker(k,0);
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;

    for(int i=0;i<k;i++){
        pq.push(make_pair(allValues[i][0],i));
    }

    vector<int>ans;

    while(!pq.empty()){

        PAIR x = pq.top();
        pq.pop();

        ans.push_back(x.first);

        if(indexTracker[x.second]+1 < allValues[x.second].size()){ //increment position validity check
            pq.push(make_pair(allValues[x.second][indexTracker[x.second]+1],x.second));
            //We are creating a pair:(increment position value,increment position array identity)
            //Then push in pq
        }
        indexTracker[x.second]+=1;
    }


    for(auto element:ans){
        cout<<element<<" ";
    }
        
    return 0;
}

/*
3 
3
1 4 7
2 
3 5
3
2 6 7 
*/