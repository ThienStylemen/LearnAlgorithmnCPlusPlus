//
//  The Last Shot.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/28/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 
 THE LAST SHOT

 Tony Stark is on the mission to save the world from Loki's army so he spread N bombs in the enemy region. He spread the bombs in such a way that a bomb can be in range of another bomb i.e say bomb B1 is in range of bomb B2, when bomb B2 explodes it will trigger bomb B1 and it also get explode but vice-versa might not be true because the bombs are of different of range. As he is running out of energy so he left with one shot To trigger the bomb. Now he ask Jarvis to find most appropriate bomb which he can trigger to make maximum impact.

 Impact is basically number of bombs get explode.

 Can you help Jarvis to do so?

 Input

 First line contains two integer N and M denoting number of bombs and number of relation between the bombs.
 1≤n≤10000

 1≤m≤10000

 Next M lines contain two integer A and B denoting bomb B is in range of bomb A.

 1≤A≤N

 1≤B≤N

 Output

 A single line containing MAXIMUM IMPACT.
 
 4 3
 1 2
 2 4
 1 3
 
 4

 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#include<stack>
#define MAX 10005
vector<int> graph[MAX];
int N;
int DFS(int start){
    vector<bool> visted(N+1,false);
    stack<int> s;
    s.push(start);
    visted[start] = true;
    int boom =0;
    
    while (!s.empty()){
        int u = s.top();
        s.pop();
        boom++;
        for(int i=0;i<graph[u].size();i++){
            int v =graph[u][i];
            if (!visted[v]){
                s.push(v);
                visted[v] = true;
            }
        }
    }
    return boom;
    
}

int main(){
    int M;
    cin >> N >> M;
    int u,v;
    while (M--){
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int max_boom =0;
    for(int i=1;i<=N;i++){
        max_boom = max(DFS(i),max_boom);
    }
    cout << max_boom << endl;

    system("pause");
    return 0;
}
