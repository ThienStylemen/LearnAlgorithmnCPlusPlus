//
//  Distinct Count.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/5/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 ViEng
 Distinct Count

 Given an array A of N integers, classify it as being Good, Bad or Average. It is called Good, if it contains exactly X distinct integers, Bad if it contains less than X distinct integers and Average if it contains more than X distinct integers.

 Input

 First line consists of a single integer T denoting the number of test cases.

 First line of each test case consists of two space separated integers denoting N and X.

 Second line of each test case consists of N space separated integers denoting the array elements.

 Constraints
 1≤T≤50
 
 1≤X,N≤13000
 
 1≤Ai ≤10^9
 ​​ 
 Output

 Print the required answer for each test case on a new line.

 4
 4 1
 1 4 2 5
 4 2
 4 2 1 5
 4 3
 5 2 4 1
 4 4
 1 2 4 5
 
 
 Average
 Average
 Average
 Good

 */
#include<iostream>
#include<vector>
using namespace std;
#include <set>

int main(){
    int T;
    cin >> T;
    int N,X;
    set<int> s;
    while(T--){
        cin >> N >> X;
        for(int i=0;i<N;i++){
            int temp;
            cin >> temp;
            s.insert(temp);
        }
        if (s.size()==X) cout << "Good" << endl;
        else if (s.size() >X) cout <<"Avarage" << endl;
        else cout << "Bad" <<endl;
        s.clear();
    }
    system("pause");
    return 0;
}
