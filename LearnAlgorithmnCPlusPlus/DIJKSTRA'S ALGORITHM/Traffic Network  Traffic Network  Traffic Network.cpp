//
//  Traffic Network  Traffic Network  Traffic Network.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/1/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//


/*
 Traffic Network

 The city traffic network consists of N nodes numbered from 1 to N and M one-way roads connecting pairs of nodes. In order to reduce the length of the shortest path between two different critical nodes S and T, a list of K two-way roads are proposed as candidates to be constructed. Your task is to write a program to choose one two-way road from the proposed list in order to minimize the resulting shortest path between S and T.

 Input

 The input file consists of several data sets. The first line of the input file contains the number of data sets which is a positive integer and is not bigger than 20. The following lines describe the data sets.

 For each data set, the first line contains five positive integers N (N≤10000), M (M≤100000), K (K<300), S (1≤S≤N), T (1≤T≤N) separated by space. The i-th line of the following M lines contains three integers di, ci, li separated by space, representing the length li (0<l​i≤1000) of the i-th one-way road connecting node di to ci. The j-th line of the next K lines contains three positive integers uj, vj and qj (qj ≤1000) separated by space, representing the j-th proposed two-way road of length qj connecting node uj to vj.

 Output

 For each data set, write on one line the smallest possible length of the shortest path after building the chosen one two-way road from the proposed list. In case, there does not exist a path from S to T, write −1.
 
 */

#include<iostream>
#include<vector>
#include<queue>

#define MAX 10005
const int INF = 1e9;

using namespace std;

vector<vector<pair<int, int>>> graphS;
vector<vector<pair<int, int>>> graphT;

vector<int> distS(MAX,INF);
vector<int> distT(MAX,INF);

void Dijkstra(int start, vector<int> &dist, vector<vector<pair<int,int>>> &graph){
    fill(dist.begin(), dist.end(), INF);
    dist[start]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(start, 0));
    
    while (!pq.empty()){
        int u = pq.top().first;
        int w = pq.top().second;
        pq.pop();
        for(int i=0;i<graph[u].size();i++){
            pair<int, int> neighbor = graph[u][i];
            if (w + neighbor.second < dist[neighbor.first]){
                dist[neighbor.first] = w + neighbor.second;
                pq.push(make_pair(neighbor.first, dist[neighbor.first]));
            }
        }
        
    }
}

int main(){
    graphS = vector<vector<pair<int, int>>> (MAX+5, vector<pair<int, int>>());
    graphT = vector<vector<pair<int, int>>> (MAX+5, vector<pair<int, int>>());
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int Test_case;
    int N, M, K, S, T;
    
    cin >> Test_case;
    while(Test_case--){
        cin >> N >> M >> K >> S >> T;
        for(int i=1;i<=N;i++){
            graphS[i].clear();
            graphT[i].clear();
        }
        
        int u,v,d;
        for(int i=0;i<M;i++){
            cin >> u >> v >> d;
            graphS[u].push_back(make_pair(v, d));
            // something openmind vcl here
            graphT[v].push_back(make_pair(u, d));
        }
        
        Dijkstra(S, distS, graphS);
        Dijkstra(T, distT, graphT);
        
        int res = distS[T]; // weight from S to T in one-way;
        
        for(int i=0;i<K;i++){
            cin >> u >> v >> d;    // u<----d----> v
            int a = distS[u] + d + distT[v];    // two possible ways
            int b = distS[v] + d + distT[u];
            res = min(res, min(a,b));
        }
        cout <<( res != INF ? res : -1) << endl;
    }
    
    system("pause");
    return 0;
}
