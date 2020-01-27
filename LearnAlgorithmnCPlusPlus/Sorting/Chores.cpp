//
//  Chores.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/27/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Chores

 Petya and Vasya are brothers. Today is a special day for them as their parents left them home alone and commissioned them to do n chores. Each chore is characterized by a single parameter — its complexity. The complexity of the i^th chore equals hi.
 
 As Petya is older, he wants to take the chores with complexity larger than some value x(hi>x) to leave to Vasya the chores with complexity less than or equal to x(hi ≤x). The brothers have already decided that Petya will do exactly a chores and Vasya will do exactly b chores (a+b=n).

 In how many ways can they choose an integer x so that Petya got exactly a chores and Vasya got exactly b chores?

 Input

 The first input line contains three integers n,a and b(2≤n≤2000;a,b≥1;a+b=n) — the total number of chores, the number of Petya's chores and the number of Vasya's chores.

 The next line contains a sequence of integers h1,h2,...,hn (1≤h​i≤10^9), hi is the complexity of the i^th chore. The numbers in the given sequence are not necessarily different.

 All numbers on the lines are separated by single spaces.

 Output

 Print the required number of ways to choose an integer value of x. If there are no such ways, print 0.
 
 
 5 2 3
 6 2 3 100 1
 
 3
 */
#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

int main(){
    int n,b,a;
    cin >> n >> a >> b;
    vector<int>arr;
    int temp;
    for(int i=0;i<n;i++){
        cin >> temp;
        arr.push_back(temp);
    }
    
    sort(arr.begin(),arr.end());
    
    int ans1 = arr[arr.size()-a];
    int ans2 = arr[b-1];
    cout << ans1 - ans2;
    
    system("pause");
    return 0;
}






