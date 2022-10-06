#include<bits/stdc++.h>

using namespace std;

typedef pair <int,int> edgeWeightPair;
class Graph{
    int v;
    list <edgeWeightPair> *adj;
public:
    Graph(int v){
        this->v = v;
        adj = new list<edgeWeightPair> [v];
    }

    void addEdge(int u,int v,int w){
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    void printNeighbour(int chk){
        for(auto i = adj[chk].begin(); i!=adj[chk].end();i++){
            cout<<"( " << (*i).first <<", "<<(*i).second<<" )";
            
        }
    }
};

int main(){
    int V,E;

    cin>>V>>E;

    Graph g(V);

    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    
    for(int i=0;i<V;i++){
        g.printNeighbour(i);
        cout<<endl;
    }

    return 0;
}

/*
7 10
0 1 7
0 2 1
0 5 3
1 3 11
2 3 3
3 6 1
6 5 2
6 4 4
5 4 4
2 5 8
*/