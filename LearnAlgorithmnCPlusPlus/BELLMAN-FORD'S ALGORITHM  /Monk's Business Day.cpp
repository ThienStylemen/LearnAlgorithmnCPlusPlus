//
//  Monk's Business Day.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/4/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Monk's Business Day

 Monk visits Biksy, the largest trading market in the land. Biksy has traders from all over the world.

 There are a total of N items indexed from 1 to N, that are traded in the market by a total of M dealers. Each trader is characterized by three integers, say i,j,C, meaning that the trader will take i^th item from you and give you j^th
 ​​  item and C units of money. A negative value of C signifies that, in order to get j^th
 ​​  item from the trader, you will have to give i^th
 ​​  item and C units of money. Note that there can be multiple dealers who deal with the same pair of items and some crazy dealers might trade the same item as well i.e. (i=j).

 Monk visits Biksy having the item number 1. He collects the data of all the traders and wants to know if there is way by which he can become infinity rich if he acts smart! i.e. if there are a series of profits, repeating which, will always increase the number of units of money with him! Help Monk find the answer to this question. Note that Monk can go to any dealer any number of times.

 Input

 First line contains an integer T. T test cases follow.

 First line of each test case contains two space-separated integers N,M

 Next M lines contain three space-separated integers i, j and C, the characteristics of the traders.

 Constraints:

 1≤T≤10
 
 1≤N≤100
 
 1≤M≤1000
 
 1≤i,j≤N
 
 −1000≤C≤1000
 Output

 Print "Yes" (without the quotes) if such a way exists, "No" (without the quotes) otherwise.

 Print the answer to each test case in a new line.
 
 inputcopy
 2
 5 6
 1 2 2
 2 3 -1
 3 4 -7
 4 5 0
 2 3 -7
 3 5 6
 5 8
 1 5 10
 2 3 -6
 5 2 5
 4 5 9
 1 5 1
 2 4 -10
 2 3 -2
 4 1 1
 outputcopy
 No
 Yes
 
 */
#include <vector>
#include <iostream>
#include<cmath>
using namespace std;
#define MAX_V 105
#define MAX_E 1005
const int INF = 1e9;
struct Edge{
    int source, target, weight;
};
struct Graph {
    int V, E;
    Edge* edge;
};
Graph* createGraph(int V, int E) {
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

bool BellmanFord(Graph* graph, int start) {
    int dist[MAX_V];
    fill(dist, dist + graph->V + 1, INF);
    dist[start] = 0;
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->E; j++) {
            int u = graph->edge[j].source;
            int v = graph->edge[j].target;
            int weight = graph->edge[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                /*
                Khi (i == n-1) tức là lần duyệt thêm bình thường em hay thấy đó.
                Khi nhảy vào đó rồi tức là dist vẫn tiếp tục thay đổi giá trị thêm nữa
                thì nghĩa là có chu trình.
                Còn chu trình đó là dương tại vì nhảy vào đó giá trị của dist
                tăng (chú ý dấu < trong dk if nhé). Còn nếu dấu là > thì nghĩa là chu trình âm.
                */
                if (i == graph->V - 1 ) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int Time;
    int V, E;
    int u, v, w;
    cin >> Time;
    while (Time--) {
        cin >> V >> E;
        Graph* graph = createGraph(V, E);
        for (int i = 0; i < graph->E; i++) {
            cin >> u >> v >> w;
            graph->edge[i].source = u;
            graph->edge[i].target = v;
            graph->edge[i].weight = -w;
            /*
            Với thuật toán Bellman-Ford dùng để xác định sự tồn tại của chu trình âm,
            ta chỉ cần đổi dấu của trọng số là có thể xác định được chu trình dương.
            */
        }
        cout << (BellmanFord(graph, 1) ?  "Yes" : "No") << endl;
        delete[] graph->edge;
        delete graph;
    }

    system("pause");
    return 0;
}
