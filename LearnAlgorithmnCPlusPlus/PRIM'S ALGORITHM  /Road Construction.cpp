//
//  Road Construction.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/6/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//


/*
 Road Construction

 There are several cities in the country, and some of them are connected by bidirectional roads. Unfortunately, some of the roads are damaged and cannot be used right now. Your goal is to rebuild enough of the damaged roads that there is a functional path between every pair of cities.

 You are given the description of roads. Damaged roads are formatted as " city1 city​2 cost" and non-damaged roads are formatted as " city1 city​2 0". In this notation city1 and city​2
 ​​  are the case-sensitive names of the two cities directly connected by that road. If the road is damaged, cost represents the price of rebuilding that road. Every city in the country will appear at least once in roads. And there can be multiple roads between same pair of cities.

 Your task is to find the minimum cost of the roads that must be rebuilt to achieve your goal. If it is impossible to do so, print Impossible.

 Input

 Input starts with an integer T (≤ 50), denoting the number of test cases. Each case begins with a blank line and an integer m(1≤m≤50) denoting the number of roads. Then there will be m lines, each containing the description of a road. No names will contain more than 50 characters. The road costs will lie in the range [0,1000].

 Output

 For each case of input you have to print the case number and the desired result.

 2

 12
 Dhaka Sylhet 0
 Ctg Dhaka 0
 Sylhet Chandpur 9
 Ctg Barisal 9
 Ctg Rajshahi 9
 Dhaka Sylhet 9
 Ctg Rajshahi 3
 Sylhet Chandpur 5
 Khulna Rangpur 7
 Chandpur Rangpur 7
 Dhaka Rajshahi 6
 Dhaka Rajshahi 7

 2
 Rajshahi Khulna 4
 Kushtia Bhola 1
 
 Case 1: 31
 Case 2: Impossible
 
 */
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<map>
#define MAX 105
const int INF = 1e7;
using namespace std;

map<string, int> map_road;
int Edge;
vector<pair<int, int>> graph[MAX];
//vector<int> path(MAX, -1);

vector<int> dist(MAX, INF);
vector<bool> visited(MAX, false);
struct MIN_HEAP {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};
void Prim(int start) {
    fill(visited.begin() + 1, visited.end(), false);
    fill(dist.begin() + 1, dist.end(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, MIN_HEAP> pq;
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
                //path[v] = u;
            }
        }
    }
}
void outAns() {
    int ans = 0;
    for (int i = 1; i <= map_road.size(); i++) {
        ans += dist[i];
    }
    if (ans >= INF)
        cout << "Impossible";
    else
        cout << ans;
    /* Ta sẽ không thể tạo được thành một cây khung nếu tồn tại một vị trí i nào đó mà disti=inf.
    Do đó, kết quả xuất ra là Impossible nếu như tồn tại i mà dist[i]=inf.
    Ngược lại, ta xuất ra tổng trọng số của các cạnh trong cây khung nhỏ nhất.
    */
}

int main() {
    int T;
    cin >> T;
    string start_place, destination;
    int w;    // V chay tu 1
    for (int tc = 1; tc <= T; tc++) {
        int V = 0;
        map_road.clear();
        cin >> Edge;
        while (Edge--) {
            cin >> start_place >> destination >> w;
            if (map_road.find(start_place) == map_road.end())
                map_road[start_place] = ++V;

            if (map_road.find(destination) == map_road.end())
                map_road[destination] = ++V;

            graph[map_road[start_place]].push_back(make_pair(map_road[destination], w));
            graph[map_road[destination]].push_back(make_pair(map_road[start_place], w));
        }
        Prim(1);
        cout << "Case " << tc << ": "; outAns(); cout << endl;
        for (int i = 1; i <= map_road.size(); i++) {
            graph[i].clear();
        }
    }

    system("pause");
    return 0;
}
