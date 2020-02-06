//
//  Cobbled streets  Cobbled streets  Cobbled streets.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/6/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

#include <stdio.h>

/*
 Cobbled streets

 The municipal chronicals of an unbelievable lordly major town in a land far, far away tell the following story:

 Once upon a time the new crowned king Günther decided to visit all towns in his kingdom. The people of the unbelievable lordly major town expected that king Günther would like to see some of the most famous buildings in their town. For the lordly citizens it seemed neccessary that all streets in the town that the king would have to use had to be cobbled with stone. Unfortunately the unbelievable lordly major town had not much money at that time as they used most of their savings to erect the highest cathedral the world had ever seen.

 Roumours were afloat that the real reason for their thriftiness was not that the town treasury was empty but that many people believed that king Günther came to the throne by deceiving his father king Erwin and that in his youth he made a pact with the devil. But anyway, the citizens of the unbelievable lordly major town decided to pave only as much streets as were absolutely necessary to reach every major building.

 Can you help the citizens of the unbelievable lordly major town to find out which streets should be paved?

 It might be usefull to know that all major buildings are either at the end of a street or at an intersection. In addition to that you can assume that all buildings are connected by the given streets.

 Input

 
 t [number of testcases (1≤t≤100)] p [price to pave one furlong of street (positive integer)] n [number of main buildings in the town (1≤n≤1000)] m [number of streets in the town (1≤m≤300000)] a b c [street from building a to building b with length c (lengths are given in furlong and the buildings are numbered from 1 to n)]
 Output

 For each testcase output the price of the cheapest possibility to reach all main buildings in the city on paved streets. You can assume that the result will be smaller than 2^32.
 
 1
 2
 5
 7
 1 2 1
 2 3 2
 2 4 6
 5 2 1
 5 1 3
 4 5 2
 3 4 3
 
 12
 */
#include<iostream>
#include<vector>
#include<queue>
#define MAX_V 1000+2
#define MAX_E 300000+2
const int INF = 1e9;
using namespace std;
vector<pair<int, int> > graph[MAX_V];
vector<int> dist(MAX_V, INF);
vector<int> path(MAX_V, -1);
bool visited[MAX_V];
struct MIN_HEAP {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        return a.second > b.second;
    }
};
int V, Edge;
void Prim(int start) {
    fill(visited, visited + V + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, MIN_HEAP > pq;
    pq.push(make_pair(start, 0));
    dist[start] = 0;
    while (!pq.empty()) {
        int u = pq.top().first;
        pq.pop();
        visited[u] = true;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if (!visited[v] && dist[v] > w) {
                dist[v] = w;
                pq.push(make_pair(v, w));
                path[v] = u;
            }
        }
    }
}

long long ansOut() {
    long long ans = 0;
    for (int i = 1; i <= V; i++) {
        if (path[i] == -1)
            continue;
        ans += dist[i];
    }
    return ans;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        fill(dist.begin(), dist.end(), INF);
        fill(path.begin(), path.end(), -1);
        int Price;
        cin >> Price >> V >> Edge;
        int u, v, w;
        while (Edge--) {
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }
        Prim(1);
        cout << Price * ansOut() << endl;
        for (int i = 1; i <= V; i++) {
            graph[i].clear();
        }
    }
    system("pause");
    return 0;
}
