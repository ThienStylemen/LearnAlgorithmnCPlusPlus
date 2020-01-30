//
//  Travelling Cost.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/30/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//


/*
 Travelling Cost

 The government of Spoj_land has selected number of locations in the city for road construction and numbered those locations as
 
 0,1,2,3,...,500.

 Now, they want to construct roads between various pairs of location (say A and B) and have fixed the cost for travelling between those pair of locations from either end as W unit.

 Now, Rohit being a curious boy wants to find the minimum cost for travelling from location U (source) to Q number of other locations (destination).

 Input

 First line contains N, the number of roads that government constructed.

 Next N line contains three integers A, B and W. A and B represent the locations between which the road was constructed and W is the fixed cost for travelling from A to B or from B to A.

 Next line contains an integer U from where Rohit wants to travel to other locations.

 Next line contains Q, the number of queries (finding cost) that he wants to perform.

 Next Q lines contain an integer V (destination) for which minimum cost is to be found from U.

 Constraints

 1≤N≤500
 
 0≤A,B≤500
 
 1≤W≤100
 
 0≤U,V≤500
 
 1≤Q≤500
 Output

 Print the required answer in each line.

 If he can't travel from location U to V by any means then, print 'NO PATH' without quotes.
 
 Ví dụ
 
 7
 0 1 4
 0 3 8
 1 4 1
 1 2 2
 4 2 3
 2 5 3
 3 4 2
 0
 4
 1
 4
 5
 7
 
 4
 5
 9
 NO PATH

 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 505
const int INF = 1e9;
vector< vector<pair<int,int>> > graph;
vector<int> dist(MAX,INF);
int path[MAX];

struct option{
    bool operator() (const pair<int, int> &a, const pair<int,int> &b){
        return a.first > b.first;   // sap xep cac object tang dan
    }
};

void Dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
    dist[start]=0;
    pq.push(make_pair(start, 0));
    while (!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        
        int u =top.first;
        int w = top.second;
        
        for(int i=0;i<graph[u].size();i++){
            pair<int, int> neighbor = graph[u][i];
            if (w +neighbor.second < dist[neighbor.first]){
                dist[neighbor.first] = w + neighbor.second;
                
                pq.push(pair<int,int> (neighbor.first, dist[neighbor.first]) );
                path[neighbor.first] = u;   // thien: neighbot.first - > u
            }
        }
    }
    
}

int main(){
    
    int n;
    cin >> n;
    //MAX+5 phan tu , moi gia tri la 1 vector<pair>
    graph=vector<vector<pair<int, int>>> (MAX+5, vector<pair<int, int>>());
    int d=0;
    int a, b;
    while (n--){
        cin >> a >> b >> d;
        graph[a].push_back(pair<int,int> (b,d));
        graph[b].push_back(pair<int,int> (a,d));
    }
    int startPeek;
    cin >> startPeek;
    int number_of_destination;
    cin >> number_of_destination;
    vector<int> arr(number_of_destination);
    
    Dijkstra(startPeek);
    
    for(int i=0;i<number_of_destination;i++){
        cin >> arr[i];
        int ans = dist[arr[i]];
        if (ans!= INF){
            cout << ans << endl;
        }else{
            cout << "NO PATH" << endl;
        }
    }
    
    
    system("pause");
    return 0;
}
