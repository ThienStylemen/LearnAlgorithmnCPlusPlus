//
//  Connect The Campus.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/6/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 
 Connect the Campus

 Many new buildings are under construction on the campus of the University of Waterloo. The university has hired bricklayers, electricians, plumbers, and a computer programmer. A computer programmer? Yes, you have been hired to ensure that each building is connected to every other building (directly or indirectly) through the campus network of communication cables.

 We will treat each building as a point specified by an x-coordinate and a y-coordinate. Each communication cable connects exactly two buildings, following a straight line between the buildings. Information travels along a cable in both directions. Cables can freely cross each other, but they are only connected together at their endpoints (at buildings).

 You have been given a campus map which shows the locations of all buildings and existing communication cables. You must not alter the existing cables. Determine where to install new communication cables so that all buildings are connected. Of course, the university wants you to minimize the amount of new cable that you use.

 Input

 The input file describes several test cases. The description of each test case is given below:

 The first line of each test case contains the number of buildings N(1≤N≤750). The buildings are labeled from 1 to N. The next N lines give the x and
 y
 y coordinates of the buildings. These coordinates are integers with absolute values at most
 1
 0
 0
 0
 0
 10000. No two buildings occupy the same point. After that there is a line containing the number of existing cables M(0≤M≤1000) followed by M lines describing the existing cables. Each cable is represented by two integers: the building numbers which are directly connected by the cable. There is at most one cable directly connecting each pair of buildings.

 Output

 For each set of input, output in a single line the total length of the new cables that you plan to use rounded to two decimal places.
 
 4
 103 104
 104 100
 104 103
 100 100
 1
 4 2
 4
 103 104
 104 100
 104 103
 100 100
 1
 4 2
 
 
 4.41
 4.41
 */


#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<iomanip>
#include<cmath>
#define MAX_E 1000 +5
#define MAX_V 751
using namespace std;
const int INF = 1e9;

double sqr(double x) {
    return x * x;
}

struct Point{
    int _x, _y;
    double cal_distance(const Point& other) {
        return sqrt ( sqr(this->_x - other._x) + sqr(this->_y - other._y) );
    }
};

vector< pair<int, double> > graph[MAX_V];
vector<double> dist(MAX_V, INF);
vector<int> path(MAX_V, -1);
bool visited[MAX_V];

int V,E;
vector<Point> v_P;

struct MIN_HEAP {
    bool operator() (const pair<int, double> &a, const pair<int, double> &b) const {
        return a.second > b.second;
    }
};

void Prims(int start) {
    //fill(visited, visited + V, false);
    priority_queue< pair<int, double>, vector<pair<int, double>>, MIN_HEAP > pq;
    pq.push(make_pair(start, 0));
    dist[start] = 0;
    while (!pq.empty()) {
        int u = pq.top().first;    // start for each step vertice;
        pq.pop();
        visited[u] = true;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            double w = graph[u][i].second;
            if (!visited[v] && dist[v] > w) {
                dist[v] = w;
                pq.push(make_pair(v, w));
                path[v] = u;
            }
        }
    }
}

void OutAns() {
    double ans = 0;
    for (int i = 1; i <= V; i++) {
        if (path[i] == -1)
            continue;
        ans += dist[i];
    }
    cout << fixed << setprecision(2)<< ans << endl;
}

void Reset() {
    for (int i = 1; i <= V; i++) {
        graph[i].clear();
        path[i] = -1;
        dist[i] = INF;
        visited[i] = false;
    }
    
}
int main() {
    
    while (cin >> V) {    // V=E

        /*fill(path.begin(), path.end(), -1);
        fill(dist.begin(), dist.end(), INF);*/
        E = V;
        int x, y;
        v_P.push_back(Point{0,0});
        for (int i = 1; i <= E; i++) {
            cin >> x >> y;
            Point A{ x, y };
            v_P.push_back(A);
        }
        int M;
        cin >> M;
        int start_cable, end_cable;

        for (int i = 1; i <= E; i++) {
            for (int j = 1; j <= E; j++) {
                if (i == j)
                    continue;
                graph[i].push_back(  make_pair( j, v_P[i].cal_distance(v_P[j]))  );
                graph[j].push_back(  make_pair( i, v_P[j].cal_distance(v_P[i]))  );
            }
        }
        while (M--) {
            cin >> start_cable >> end_cable;
            graph[start_cable].push_back(make_pair(end_cable, 0));
            graph[end_cable].push_back(make_pair(start_cable, 0));
        }
        Prims(1);
        OutAns();
        v_P.clear();
        Reset();
    }
    system("pause");
    return 0;
}



