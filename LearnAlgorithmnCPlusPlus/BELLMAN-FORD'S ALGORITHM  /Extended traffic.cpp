//
//  Extended traffic.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/4/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Extended traffic

 Dhaka city is getting crowded and noisy day by day. Certain roads always remain blocked in congestion. In order to convince people avoid shortest routes, and hence the crowded roads, to reach destination, the city authority has made a new plan. Each junction of the city is marked with a positive integer (≤20) denoting the busyness of the junction. Whenever someone goes from one junction (the source junction) to another (the destination junction), the city authority gets the amount (busyness of destination - busyness of source)^3
 ​​  (that means the cube of the difference) from the traveler. The authority has appointed you to find out the minimum total amount that can be earned when someone intelligent goes from a certain junction (the zero point) to several others.

 Input

 Input starts with an integer T(≤50), denoting the number of test cases.

 Each case contains a blank line and an integer (1<n≤200) denoting the number of junctions. The next line contains n integers denoting the busyness of the junctions from 1 to n respectively. The next line contains an integer m, the number of roads in the city. Each of the next m lines (one for each road) contains two junction-numbers (source, destination) that the corresponding road connects (all roads are unidirectional). The next line contains the integer q, the number of queries. The next q lines each contain a destination junction-number. There can be at most one direct road from a junction to another junction.

 Output

 For each case, print the case number in a single line. Then print q lines, one for each query, each containing the minimum total earning when one travels from junction 1 (the zero point) to the given junction. However, for the queries that gives total earning less than 3, or if the destination is not reachable from the zero point, then print a ?

 2

 5
 6 7 8 9 10
 6
 1 2
 2 3
 3 4
 1 5
 5 4
 4 5
 2
 4
 5

 2
 10 10
 1
 1 2
 1
 2
 
 
 
 Case 1:
 3
 4
 Case 2:
 ?
 
 */
#include <vector>
#include <iostream>
#include<cmath>
using namespace std;
#define MAX  205
#define MAX_E 205*204
const int INF =1e9;

struct Edge{
    int source;
    int target;
    int weight;
};

int n,m;
int dist[MAX];
int states[MAX];
//vector<int> path(MAX, -1);
Edge graph[MAX_E];

void BellmanFord(int start){
    fill(dist, dist+ (n+1), INF);
    int u,v,w;
    dist[start]=0;
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<m;j++){
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;
            if (dist[u] != INF && dist[u] + w < dist[v]){
                dist[v] = dist[u] +w;
            }
        }
    }
}

int main(){
    int Time;
    cin >> Time;
    for(int time=1;time<=Time;time++){
        cin >> n;    // n la dinh, m la canh
        for(int i=1;i<=n;i++){
            cin >> states[i];
        }
        cin >> m;
        int u,v;
        for(int i=0;i<m;i++){
            cin >> u >> v;
            graph[i] = Edge{u,v, int(pow(states[v]- states[u], 3))};
        }
        BellmanFord(1);
        int number_destination, destination;
        cin >> number_destination;
        cout << "Case " << time << ":" << endl;
        for (int i = 0; i < number_destination; i++) {
            cin >> destination;
            if (dist[destination] < 3 || dist[destination] == INF)
                cout << "?" << endl;
            else
                cout << dist[destination] << endl;
        }
    }
    system("pause");
    return 0;
}
