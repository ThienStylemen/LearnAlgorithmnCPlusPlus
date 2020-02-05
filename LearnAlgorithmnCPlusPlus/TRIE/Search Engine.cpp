//
//  Search Engine.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/5/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Search Engine

 Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.

 Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.

 Input

 First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.

 Next q lines follow, each line having a string t, which needs to be completed.

 Constraints

 1≤n,weight,len(s),len(t)≤10^6
 
 1≤q≤10^5
 ​​ 
 total length of all strings in database entries ≤10^​6
 ​​ 

 total length of all query strings ≤10^6
 ​​ 

 Output

 q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.
 
 
 2 1
 hackerearth 10
 hackerrank 9
 hacker
 
 10
 */

#include<iostream>
#include<string>
using namespace std;
#define MAX 26
#include<string>
#include<algorithm>

struct Node {
    int _trend;
    Node *child[MAX];
    // int countWord; ko can coundword;
};

struct Node* newNode() {
    Node *node = new Node;
    node->_trend = -1 ;
    //node->countWord = 0;
    for (int i = 0; i < MAX; i++) {
        node->child[i] = nullptr;
    }
    return node;
}

void addWord(Node* root, string s, int trend) {
    int ch;
    Node* temp = root;
    for (int i = 0; i < s.size(); i++) {
        ch = s[i] - 'a';
        if (!temp->child[ch]) {
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
        temp->_trend = max(trend, temp->_trend);
    }
    //temp->countWord++;
}
int findWord(Node* root, string s) {
    int ch;
    struct Node* temp = root;
    for (int i = 0; i < s.size(); i++) {
        int ch = s[i] - 'a';
        if (temp->child[ch] == NULL) return -1;
        temp = temp->child[ch];
    }
    //return temp->countWord > 0;
    return temp->_trend;
}
int main() {
    int Test, query;
    cin >> Test >> query;
    string s;
    int trend;
    Node *head = newNode();
    while (Test--) {
        cin >> s >> trend;
        addWord(head, s, trend);
    }
    string s_find;
    
    for (int i = 0; i < query; i++) {
        cin >> s_find;
        cout << findWord(head, s_find) << endl;
    }

    //delete[] head->child;
    delete[] head;
    system("pause");
    return 0;
}

