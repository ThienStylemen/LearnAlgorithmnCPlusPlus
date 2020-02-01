//
//  Sending Email.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/1/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//


#include <iostream>
#include <queue>
#define MAX 20005
using namespace std;
const int INF = 1e9;

vector<int>dist(MAX, INF);
vector<pair<int, int>> graph[MAX];

void Dijkstra(int start){
    fill(dist.begin(), dist.end(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start]=0;
    pq.push(make_pair(start, 0));
    
    while (!pq.empty()){
        int u = pq.top().first;
        int w = pq.top().second;
        pq.pop();
        
        for(int i=0;i<graph[u].size();i++){
            pair<int, int> neighbor = graph[u][i];
            if (w + neighbor.second < dist[neighbor.first]){
                dist[neighbor.first] = w + neighbor.second;
                pq.push(make_pair(neighbor.first,dist[neighbor.first]));
            }
        }
    }
}

int main(){
    int Test;
    cin >> Test;
    
    for (int tc=1;tc<=Test;tc++){
        int N, M, S, T;
        cin >> N >> M >>S >> T;
        int u,v,w;
        while(M--){
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }
        Dijkstra(S);
        
        if (dist[T] != INF)
        cout << "Case #" << tc<<": " << dist[T] << endl;
        else cout << "Case #" << tc << ": " << "unreachable" << endl;
        
        for(int i=0;i<N;i++){
            graph[i].clear();
        }
    }
    
    
    system("pause");
    return 0;
}
