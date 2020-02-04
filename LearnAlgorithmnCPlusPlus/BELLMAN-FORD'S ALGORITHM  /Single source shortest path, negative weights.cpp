//
//  Single source shortest path, negative weights.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/4/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//


/*
 
 Single source shortest path, negative weights

 Input

 The input consists of several test cases. Each test case starts with a line with four non-negative integers, 1≤n≤1000, 0≤m≤5000, 1≤q≤100 and 0≤s<n, separated by single spaces, where n is the numbers of nodes in the graph, m the number of edges, q the number of queries and s the index of the starting node. Nodes are numbered from 0 to n−1. Then follow m lines, each line consisting of three (space-separated) integers u,v and w indicating that there is an edge from u to v in the graph with weight −2000≤w≤2000. Then follow q lines of queries, each consisting of a single non-negative integer, asking for the minimum distance from node s to the node number given on the query line.

 Input will be terminated by a line containing four zeros, this line should not be processed.

 Output

 For each query, output a single line containing the minimum distance from node s to the node specified in the query, the word Impossible if there is no path from s to that node, or -Infinity if there are arbitrarily short paths from s to that node. Print a blank line after each test case.

 5 4 3 0
 0 1 999
 1 2 -2
 2 1 1
 0 3 2
 1
 3
 4
 2 1 1 0
 0 1 -100
 1
 0 0 0 0
 
 -Infinity
 2
 Impossible
 
 */

#include <vector>
#include <iostream>
#include<cmath>
using namespace std;
#define MAX_V 1005
const int INF = 1e9+5;
struct Edge{
    int source, target, weight;
};

struct Graph{
    int V, E;
    Edge* edge;
};

Graph* createGraph(int V, int E){
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

vector<int> dist(MAX_V);
/*
Nếu khoảng cách từ đỉnh nguồn s tới đỉnh i có giá trị là dương vô cực,
nghĩa là không tồn tại đường đi từ s→i.
Ngược lại, nếu khoảng cách này khác dương vô cực có thể xảy ra
2 trường hợp:
Đó là trọng số nhỏ nhất đi từ s→i.
Đỉnh i thuộc chu trình âm nên khảng cách này là không xác định.
*/
void BellmanFord(Graph* graph, int start){
    fill(dist.begin(),dist.end(),INF);
    dist[start]=0;
    int u,v,w;
    for(int i=1;i<=graph->V-1;i++){
        for(int j=0;j<graph->E;j++){
            int u = graph->edge[j].source;
            int v = graph->edge[j].target;
            int w = graph->edge[j].weight;
            if (dist[u] != INF && dist[u] +w < dist[v]){
                dist[v] = dist[u] +w;
            }
        }
    }
    /* Ta biết rằng thuật toán Bellman-Ford truyền thống chỉ cho phép ta pháp hiện có tồn tại
        chu trình âm bất kỳ trong đồ thị chứ không chỉ rõ các đỉnh thuộc các chu trình âm trong đồ thị đó.
        → Chạy Bellman-Ford lần hai, nếu lại tìm được một khoảng cách từ
        s→ v tốt hơn thì chắc chắn v thuộc chu trình âm. Ta gán khoảng cách là âm vô cực.
    */
    for(int i=1;i<=graph->V-1;i++){
        for(int j=0;j<graph->E;j++){
            int u = graph->edge[j].source;
            int v = graph->edge[j].target;
            int w = graph->edge[j].weight;
            if (dist[u] != INF && dist[u] + w < dist[v]){
                dist[v] = -INF;
            }
        }
    }
}
int main(){
    int n,m,s,t;
    while (cin >> n >> m >> s >> t, n!=0){
        int u,v,w;
        Graph* graph = createGraph(n, m);
        for(int i=0;i<graph->E;i++){
            cin >> u >> v >> w;
            graph->edge[i].source =u;
            graph->edge[i].target =v;
            graph->edge[i].weight = w;
        }
        BellmanFord(graph, t);
        int destination;
        while (s--){
            cin >> destination;
            if (dist[destination] == INF)
                cout << "Impossible" << endl;
            else if (dist[destination] == -INF)
                cout << "-Infinity" << endl;
            else
                cout << dist[destination] << endl;
        }
        cout << endl;
        delete[] graph->edge;
        delete graph;
    }
    system("pause");
    return 0;
}
