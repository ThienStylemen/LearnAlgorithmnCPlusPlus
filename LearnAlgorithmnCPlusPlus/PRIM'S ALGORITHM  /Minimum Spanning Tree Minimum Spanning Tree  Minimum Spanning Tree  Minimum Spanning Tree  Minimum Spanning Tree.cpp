//
//  Minimum Spanning Tree Minimum Spanning Tree  Minimum Spanning Tree  Minimum Spanning Tree  Minimum Spanning Tree.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/6/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Minimum Spanning Tree

 Find the minimum spanning tree of the graph.

 Input

 On the first line there will be two integers N - the number of nodes and M - the number of edges. (1≤N≤10000),(1≤M≤100000) M lines follow with three integers i j k on each line representing an edge between node i and j with weight k. The IDs of the nodes are between 1 and n inclusive. The weight of each edge will be ≤1000000.

 Output

 Single number representing the total weight of the minimum spanning tree on this graph. There will be only one possible MST.

 4 5
 1 2 10
 2 3 15
 1 3 5
 4 2 2
 4 3 40
 
 17
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define MAX_E 100000 +5
#define MAX_V 10000+5
const int INF = 1e9;

vector<pair<int, int>> graph[MAX_E];
vector<int> dist(MAX_V, INF);
int V, E;
vector<int> path(MAX_V, -1);
bool visited[MAX_V];
struct MIN_HEAP{
    bool operator() (const pair<int,int> &a, const pair<int, int>&b){
        return a.second > b.second;
    }
};

void Prims(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, MIN_HEAP> pq;
    pq.push(make_pair(start, 0));
    dist[start] =0;
    
    while(!pq.empty()){
        int u =pq.top().first; // start for each step vertice;
        pq.pop();
        visited[u] =true;
        
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if (!visited[v] && dist[v] > w){
                dist[v]= w;
                pq.push(make_pair(v, w));
                path[v] =u;
            }
        }
    }
}

void OutAns(){
    long long ans =0;
    for(int i=1;i<=V;i++){
        if (path[i] == -1) continue;
        ans += dist[i];
    }
    cout << ans << endl;
}

int main(){
    cin >> V >> E;
    fill(path.begin(), path.end(), -1);
    int u, v;
    long long w;
    for(int i=0;i<E;i++){
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    Prims(1);
    OutAns();
    system("pause");
    return 0;
    
}
