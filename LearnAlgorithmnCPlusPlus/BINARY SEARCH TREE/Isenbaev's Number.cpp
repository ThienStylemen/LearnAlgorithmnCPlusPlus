//
//  Isenbaev's Number.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/5/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//


/*
    

 Vladislav Isenbaev is a two-time champion of Ural, vice champion of TopCoder Open 2009, and absolute champion of ACM ICPC 2009. In the time you will spend reading this problem statement Vladislav would have solved a problem. Maybe, even two…

 Since Vladislav Isenbaev graduated from the Specialized Educational and Scientific Center at Ural State University, many of the former and present contestants at USU have known him for quite a few years. Some of them are proud to say that they either played in the same team with him or played in the same team with one of his teammates…

 Let us define Isenbaev's number as follows. This number for Vladislav himself is 0. For people who played in the same team with him, the number is 1. For people who weren't his teammates but played in the same team with one or more of his teammates, the number is 2, and so on. Your task is to automate the process of calculating Isenbaev's numbers so that each contestant at USU would know their proximity to the ACM ICPC champion.

 Input

 The first line contains the number of teams n (1≤n≤100). In each of the following n lines you are given the names of the three members of the corresponding team. The names are separated with a space. Each name is a nonempty line consisting of English letters, and its length is at most 20 symbols. The first letter of a name is capital and the other letters are lowercase.

 Output

 For each contestant mentioned in the input data output a line with their name and Isenbaev's number. If the number is undefined, output “undefined” instead of it. The contestants must be ordered lexicographically.

 7
 Isenbaev Oparin Toropov
 Ayzenshteyn Oparin Samsonov
 Ayzenshteyn Chevdar Samsonov
 Fominykh Isenbaev Oparin
 Dublennykh Fominykh Ivankov
 Burmistrov Dublennykh Kurpilyanskiy
 Cormen Leiserson Rivest
 
 Ayzenshteyn 2
 Burmistrov 3
 Chevdar 3
 Cormen undefined
 Dublennykh 2
 Fominykh 1
 Isenbaev 0
 Ivankov 2
 Kurpilyanskiy 3
 Leiserson undefined
 Oparin 1
 Rivest undefined
 Samsonov 2
 Toropov 1

 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define MAX 1001
#include<queue>
#include <map>

map<string,int> player;
vector<int>graph[MAX];  // run BFS

void BFS(vector<bool>visited, vector<int>&dist){
    queue<int>q;
    visited[ player["Isenbaev"] ] = true;
    q.push(player["Isenbaev"] );
    dist[player["Isenbaev"] ] =0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            if (!visited[v]){
                q.push(v);
                visited[v]=true;
                dist[v] = dist[u] +1;
            }
        }
    }
}

int main(){
    int Test;
    cin >> Test;
    string s1,s2,s3;
    int V=0;
    while(Test--){
        cin >> s1 >> s2 >> s3;
        if (player.find(s1) == player.end()) player[s1]= V++;
        if (player.find(s2) == player.end()) player[s2]= V++;
        if (player.find(s3) == player.end()) player[s3]= V++;
        
        int a = player[s1], b=player[s2], c=player[s3];
        graph[a].push_back(b); graph[a].push_back(c);
        graph[b].push_back(a); graph[a].push_back(c);
        graph[c].push_back(a); graph[a].push_back(b);
        
    }
    vector<bool> visited(player.size(), false);
    vector<int> dist(player.size(), -1);
    BFS(visited, dist);
    
    for(map<string,int>::iterator it = player.begin(); it != player.end();it++){
        cout << it->first << " ";
        if (dist[it->second] != -1){
            cout << dist[it->second] << endl;
        }
        else cout << "undefined" << endl;
    }
    
    system("pause");
    return 0;
}
