//
//  Wormholes.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/4/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Wormholes

 In the year 2163, wormholes were discovered. A wormhole is a subspace tunnel through space and time connecting two star systems. Wormholes have a few peculiar properties:

 Wormholes are one-way only.
 The time it takes to travel through a wormhole is negligible.
 A wormhole has two end points, each situated in a star system.
 A star system may have more than one wormhole end point within its boundaries.
 For some unknown reason, starting from our solar system, it is always possible to end up in any star system by following a sequence of wormholes (maybe Earth is the centre of the universe).
 Between any pair of star systems, there is at most one wormhole in either direction.
 There are no wormholes with both end points in the same star system. All wormholes have a constant time difference between their end points. For example, a specific wormhole may cause the person travelling through it to end up 15 years in the future. Another wormhole may cause the person to end up 42 years in the past.
 A brilliant physicist, living on earth, wants to use wormholes to study the Big Bang. Since warp drive has not been invented yet, it is not possible for her to travel from one star system to another one directly. This can be done using wormholes, of course.

 The scientist wants to reach a cycle of wormholes somewhere in the universe that causes her to end up in the past. By travelling along this cycle a lot of times, the scientist is able to go back as far in time as necessary to reach the beginning of the universe and see the Big Bang with her own eyes. Write a program to find out whether such a cycle exists.

 Input

 The input starts with a line containing the number of cases c to be analysed. Each case starts with a line with two numbers n and m. These indicate the number of star systems (1≤n≤1000) and the number of wormholes (0≤m≤2000). The star systems are numbered from 0 (our solar system) through n−1 . For each wormhole a line containing three integer numbers x,y and t is given. These numbers indicate that this wormhole allows someone to travel from the star system numbered x to the star system numbered y, thereby ending up (−1000≤t≤1000) years in the future.

 Output

 The output consists of c lines, one line for each case, containing the word possible if it is indeed possible to go back in time indefinitely, or not possible if this is not possible with the given set of star systems and wormholes.

 2
 3 3
 0 1 1000
 1 2 15
 2 1 -42
 4 4
 0 1 10
 1 2 20
 2 3 30
 3 0 -60
 
 possible
 not possible
 */
#include <vector>
#include <iostream>
using namespace std;
#define MAX 105
const int INF = 1e9;
struct Edge {
    int source;
    int target;
    int weight;
};
int n, m;

vector<int> dist(MAX, INF);
//vector<int> path(MAX, -1);
vector<Edge> graph;

bool BellmanFord(int start) {
    int u, v, w;
    dist[start] = 0;
    for (int i = 1; i <= n-1; i++) {
        for (int j = 0; j < m; j++) {
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;
            if (dist[u] != INF && ( dist[u] + w < dist[v]) ) {
                dist[v] = dist[u] + w;
                //path[v] = u;
            }
        }
    }
    // kiem tra chu trinh am
    for (int i = 0; i < m; i++) {
        u = graph[i].source;
        v = graph[i].target;
        w = graph[i].weight;

        if ( (dist[u] + w < dist[v]) && dist[u] != INF)
            return false;
    }
    return true;
}
int main() {
    int Time;
    cin >> Time;
    while (Time--){
        int s, v, u, w;
        cin >> n >> m;
        // n so dinh, m so canh
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graph.push_back(Edge{ u,v,w });
        }
        s = 0;
        bool res = BellmanFord(s);
        if (!res) cout << "possible" << endl;
        else cout << "not possible" << endl;
        graph.clear();
    }

    system("pause");
    return 0;
}
