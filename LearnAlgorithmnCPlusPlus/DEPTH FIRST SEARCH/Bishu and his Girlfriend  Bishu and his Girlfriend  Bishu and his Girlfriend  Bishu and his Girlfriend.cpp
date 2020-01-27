//
//  Bishu and his Girlfriend  Bishu and his Girlfriend  Bishu and his Girlfriend  Bishu and his Girlfriend.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/28/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
There are N countries 1,2,3,4....N and N−1 roads(i.e depicting a tree)

Bishu lives in the Country 1 so this can be considered as the root of the tree.

Now there are Q girls who lives in various countries (not equal to 1) .

All of them want to propose Bishu. But Bishu has some condition.

He will accept the proposal of the girl who lives at minimum distance from his country.

Now the distance between two countries is the number of roads between them.

If two or more girls are at the same minimum distance then he will accept the proposal of the girl who lives in a country with minimum id.

No two girls are at same country.

Input

First line consists of N, i.e number of countries.
Next N−1 lines follow the type u v which denotes there is a road between u and v.
Next line consists of Q Next Q lines consists of x where the girls live.

Contraints:

 2≤N≤1000

 1≤u,v≤N

 1≤Q≤(N−1)
Output

Print the id of the country of the girl who will be accepted.
 
 6
 1 2
 1 3
 1 4
 2 5
 2 6
 4
 5
 6
 3
 4
 
 3
 
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#define MAX 1001
int V,E;
vector<int>graph[MAX];
int girls[MAX];
int distan[MAX];

vector<bool> visted ={false};
void DFS(int src){
    stack<int> s;
    visted[src]=true;
    s.push(src);
    
    while(!s.empty()){
        int u = s.top();
        s.pop();
        
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            if (!visted[v]){
                s.push(v);
                distan[v] = distan[u] + 1;
                visted[v] = true;
            }
        }
    }
}

int main(){
    cin >> V;
    int u,v;
    E=V-1;
    for(int i=0;i<E;i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    DFS(1);
    
    int Q;
    cin >> Q;
    for(int i=0;i<Q;i++){
        cin >> girls[i];
    }
    
    int dist_max =V, chosen=1;
    for(int i=0;i<Q;i++){
        if ( distan[ girls[i] ] < dist_max || (distan[ girls[i] ] ==dist_max &&  girls[i] < chosen) ){
            chosen = girls[i];
            dist_max = distan[girls[i]];
        }
    }
    cout << chosen;
    system("pause");
    return 0;
    
}
