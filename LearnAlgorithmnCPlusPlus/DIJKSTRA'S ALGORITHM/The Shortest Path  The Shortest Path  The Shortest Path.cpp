//
//  The Shortest Path  The Shortest Path  The Shortest Path.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/1/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 
 The Shortest Path

 You are given a list of cities. Each direct connection between two cities has its transportation cost (an integer bigger than 0). The goal is to find the paths of minimum cost between pairs of cities. Assume that the cost of each path (which is the sum of costs of all direct connections belongning to this path) is at most 200000. The name of a city is a string containing characters a,...,z and is at most 10 characters long.

 Input

 s [the number of tests ≤ 10]

 n [the number of cities ≤ 10 000]

 NAME [city name]

 p [the number of neighbours of city NAME]

 nr cost [nr - index of a city connected to NAME (the index of the first city is 1)]
        [cost - the transportation cost]
 r [the number of paths to find ≤ 100]

 NAME 1 NAME 2 [NAME 1 - source, NAME 2 - destination]

 [empty line separating the tests]

 Output

 cost [the minimum transportation cost from city NAME 1 to city NAME 2
 ​​  (one per line)]

 
 Vi du:
 1
 4
 gdansk
 2
 2 1
 3 3
 bydgoszcz
 3
 1 1
 3 1
 4 4
 torun
 3
 1 3
 2 1
 4 1
 warszawa
 2
 2 4
 3 1
 2
 gdansk warszawa
 bydgoszcz warszawa

 
 3
 2
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include<queue>
#include<map>

#define MAX 1005
const int INF= 1e9;

vector<vector<pair<int,int>>> graph;
vector<int> dist(MAX,INF);

void Dijkstra(int start){
    fill(dist.begin(), dist.end(), INF);
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(start, 0));
    dist[start] =0;
    while (!pq.empty()) {
        int u=pq.top().first;
        int w = pq.top().second;
        pq.pop();
        for(int i=0;i<graph[u].size();i++){
            pair<int, int> neighbor = graph[u][i];
            if (w + neighbor.second < dist[neighbor.first]){
                dist[neighbor.first] = w + neighbor.second;
                pq.push(pair<int,int> (neighbor.first, dist[neighbor.first]));
            }
        }
    }
    
    
}

int main(){
    graph = vector<vector<pair<int, int>>> (MAX+5, vector<pair<int,int>>() );
    int Test, cities;
    cin >> Test;
    while (Test--){
        cin >> cities;
        for(int i=0;i<=cities;i++){
            graph[i].clear();
        }
        map<string,int> map_cities;
        string name_temp;
        int number_neighbors, a, b;
        for(int i=1;i<=cities;i++){
            cin >> name_temp;
            map_cities[name_temp] =i;
            
            cin >> number_neighbors;
            while (number_neighbors--){
                cin >> a >> b;
                graph[i].push_back(pair<int,int>(a,b));
            }
        }
        
        int query;
        cin >> query;
        while (query--){
            string from, to;
            cin >> from >> to;
            Dijkstra(map_cities[from]);
            cout << dist[map_cities[to]] << endl;
        }
    }
    system("pause");
    return 0;
}
