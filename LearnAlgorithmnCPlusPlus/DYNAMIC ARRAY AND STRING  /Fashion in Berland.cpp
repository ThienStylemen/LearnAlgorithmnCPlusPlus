//
//  Fashion in Berland.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/25/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 
 Fashion in Berland

 According to rules of the Berland fashion, a jacket should be fastened by all the buttons except only one, but not necessarily it should be the last one. Also if the jacket has only one button, it should be fastened, so the jacket will not swinging open.

 You are given a jacket with N buttons. Determine if it is fastened in a right way.
 
 Input

 The first line contains integer N (
 1 ≤ N ≤ 1000) — the number of buttons on the jacket.
 
 The second line contains N integers Ai (0 ≤ Ai ≤ 1). The number
 Ai =0 if the i-th button is not fastened. Otherwise Ai = 1
 
 Output

 In the only line print the word "YES" if the jacket is fastened in a right way. Otherwise print the word "NO".
 3
 1 0 1

 YES
 */


#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> rule;
    int temp;
    if ( n==1){
        cin >> temp;
        if (temp ==1)cout << "YES";
        else cout << "NO";
        system("pause");
        return 0;
    }
    for (int i=0;i<n;i++){
        cin >> temp;
        rule.push_back(temp);
    }
    int count =0;
    for (int i=0;i<rule.size();i++){
        if (rule[i] ==1) count ++;
    }
    if (count == n-1) cout << "YES";
    else cout << "NO";
    system("pause");
    return 0;
}
