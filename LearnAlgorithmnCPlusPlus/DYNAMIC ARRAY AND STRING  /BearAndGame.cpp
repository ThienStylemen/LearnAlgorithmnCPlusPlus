//
//  BearAndGame.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/25/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Bear and Game

 Bear Limak likes watching sports on TV. He is going to watch a game today. The game lasts
 90 minutes and there are no breaks.
 Each minute can be either interesting or boring. If

 15 consecutive minutes are boring then Limak immediately turns TV off. You know that there will be N interesting minutes T1, T2, ... ,TN. Your task is to calculate for how many minutes Limak will watch the game.

 Input

 The first line of the input contains one integer N (
 1 ≤ N ≤ 90) — the number of interesting minutes.

 The second line contains N integers T1,T2, ...,TN ()
 ​​  (1≤ T1 < T2 < ... TN ≤ 90) given in the increasing order.

 Output

 Print the number of minutes Limak will watch the game.
 
 3
 7 20 88

 35

 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {

    unsigned int n;
    cin >> n;
    vector<unsigned int> minutes;
    int temp;
    for(int i=0;i<n;i++){
        cin >> temp;
        minutes.push_back(temp);
    }
    if (minutes[0] > 15) {
        cout << 15;
        system("pause");
        return 0;
    }
    int ans =0;
    for(int i=0;i<minutes.size() -1;i++){
        if (minutes[i+1] - minutes[i] <15) {
            continue;}
        else{
            ans = minutes[i] +15;
            break;
        }
    }
    if (ans ==0){
        ans = minutes.back()+15;
    }
    if (ans >90) ans =90;
    cout << ans;
    system("pause");
    return 0;
    
}
