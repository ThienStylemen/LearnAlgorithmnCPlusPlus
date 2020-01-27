//
//  Breadth First Search: Shortest Reach.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/27/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Breadth First Search: Shortest Reach

 Consider an undirected graph consisting of N nodes where each node is labeled from 1 to N and the edge between any two nodes is always of length 6. We define node S to be the starting position for a BFS.

 Given Q queries in the form of a graph and some starting node, S, perform each query by calculating the shortest distance from starting node S to all the other nodes in the graph. Then print a single line of N−1 space-separated integers listing node S's shortest distance to each of the N−1 other nodes (ordered sequentially by node number); if S is disconnected from a node, print −1 as the distance to that node.

 Input

 The first line contains an integer, Q, denoting the number of queries. The subsequent lines describe each query in the following format:

 The first line contains two space-separated integers describing the respective values of N (the number of nodes) and M (the number of edges) in the graph.
 Each line i of the M subsequent lines contains two space-separated integers, u and v, describing an edge connecting node u to node v.
 The last line contains a single integer, S, denoting the index of the starting node.
 Constraints

 1≤Q≤10
 
 2≤N≤1000
 
 1≤M≤ N(N−1)/2
 ​​
 1≤u,v,S≤N
 Output

 For each of the Q queries, print a single line of N−1 space-separated integers denoting the shortest distances to each of the N−1 other nodes from starting position S. These distances should be listed sequentially by node number (i.e.,1,2,...N), but should not include node S. If some node is unreachable from S, print −1 as the distance to that node.
 
2
4 2
1 2
1 3
1
3 1
2 3
2

 6 6 -1
 -1 6
*/

#include<queue>
#include<iostream>
#include<vector>
using namespace std;
#define MAX 1005

int V,E;    // V so node, E so canh
bool visited[MAX];  // trang thai cua dinh, da tham hay chua
int distanc[MAX];
vector<int> graph[MAX];

void BFS(int start){
    queue<int> q;
    visited[start] =true;
    q.push(start);  // q ban dau chua start
    
    while (!q.empty()){ // lap toi khi empty
        int u= q.front();   // lay dinh ra xet
        q.pop();
        for(int i=0;i<graph[u].size();i++){     // duyet cac phan tu lien ke cua dinh dang xet
            int v= graph[u][i];
            if (!visited[v]){
                visited[v] =true;
                q.push(v); // q.push( graph[u][i] );
                //modify:
                distanc[v] = distanc[u] +1;
                /*
                    dist[ graph[u][i] ]                                            // graph[u][i]
                Gọi dist[v] lưu khoảng cách ngắn nhất từ đỉnh start đến đỉnh v.
                    // graph[u][i]                                    // q.front()
                Với đỉnh v có được thông qua duyệt các đỉnh kề của đỉnh u.
                                // dist[ graph[u][i] ] = dist[ q.front() ] + 1
                Như vậy dễ dàng nhận thấy dist[v] = dist[u] + 1, nghĩa là từ
                    S đến v ta mất một quãng đường bằng khoảng cách từ
                    S đến u và từ u đến v(chưa tính trọng số 6 của mỗi cạnh).
                */
            }
        }
    }
}

int main(){
    int u,v,s,Q;
    cin >> Q;
    while(Q--){
        cin >> V >> E;
        for(int i=0;i<MAX;i++){
            graph[i].clear();
            visited[i] = false;
            distanc[i] =0;
        }
        
        // buoc 0: chuyen danh sach cac canh ke vao mang graph
        for(int i=0;i<E;i++){
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cin >> s;
        BFS(s);
        
        for(int i=1;i<=V;i++){
            if (i==s) continue;
            cout << (visited[i] ? distanc[i]*6:-1) << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
