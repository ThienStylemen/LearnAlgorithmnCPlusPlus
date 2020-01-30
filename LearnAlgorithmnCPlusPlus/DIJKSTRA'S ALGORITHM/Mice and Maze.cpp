//
//  Mice and Maze.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/30/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Mice and Maze

 A set of laboratory mice is being trained to escape a maze. The maze is made up of cells, and each cell is connected to some other cells. However, there are obstacles in the passage between cells and therefore there is a time penalty to overcome the passage Also, some passages allow mice to go one-way, but not the other way round.

 Suppose that all mice are now trained and, when placed in an arbitrary cell in the maze, take a path that leads them to the exit cell in minimum time.

 We are going to conduct the following experiment: a mouse is placed in each cell of the maze and a count-down timer is started. When the timer stops we count the number of mice out of the maze.

 Input

 The maze cells are numbered

 1,2,3,...,N, where
 N is the total number of cells. You can assume that
 
 N≤100

 The first three input lines contain
 
 N, the number of cells in the maze,
 
 E, the number of the exit cell, and the starting value
 
 T for the count-down timer (in some arbitrary time unit).

 The fourth line contains the number
 
 M of connections in the maze, and is followed by
 
 M lines, each specifying a connection with three integer numbers: two cell numbers a and b (in the range
 
 1,2,3,...,N) and the number of time units it takes to travel from
 
 a to b.

 Notice that each connection is one-way, i.e., the mice can't travel from a to b unless there is another line specifying that passage. Notice also that the time required to travel in each direction might be different.

 Output

 The output consists of a single line with the number of mice that reached the exit cell E in at most T time units.

 Ví dụ
 
 */

#include<iostream>
#include<vector>
#include<queue>
#define MAX 105

using namespace std;
const int INF = 1e9;
vector<vector<pair<int,int>>> graph;
vector<int> dist(MAX,INF);


void Dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(start, 0) );
    dist[start] =0;
    
    while(!pq.empty()){
        int u = pq.top().first;
        int w = pq.top().second;
        pq.pop();
        for(int i=0; i<graph[u].size();i++){
            pair<int, int> neighbor = graph[u][i];
            if (w + neighbor.second < dist[neighbor.first]){
                dist[neighbor.first] = w + neighbor.second;
                pq.push(pair<int,int> (neighbor.first, dist[neighbor.first]) );
            }
            
        }
        
    }
}

int main(){
    int mice, out, time, n;
    cin >> mice >> out >> time >> n;
    int a,b,c;
    graph = vector<vector<pair<int,int>>> (MAX, vector<pair<int,int>>());
    while (n--){
        cin >> a >> b >> c;
        graph[b].push_back(pair<int,int> (a,c));
    }
    
    Dijkstra(out);
    
    int count =0;
    for(int i=1;i<=mice;i++){
        if (dist[i] <= time){
            count++;
        }
    }
    cout << count;
    system("pause");
    return 0;
}
