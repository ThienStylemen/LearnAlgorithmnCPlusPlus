//
//  Soldier and Bananas.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/2/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Soldier and Bananas

 A soldier wants to buy w bananas in the shop. He has to pay k dollars for the first banana, 2k dollars for the second one and so on (in other words, he has to pay i·k dollars for the i-th banana).

 He has n dollars. How many dollars does he have to borrow from his friend soldier to buy w bananas?

 Input

 The first line contains three positive integers k, n,w (1 ≤  k, w ≤  1000, 0 ≤ n ≤ 10^9), the cost of the first banana, initial number of dollars the soldier has and number of bananas he wants.

 Output

 Output one integer — the amount of dollars that the soldier must borrow from his friend. If he doesn't have to borrow money, output 0.
 
 3 17 4
 
 13
 */
#include<iostream>
using namespace std;

int main(){
    int k;  // first bananas
    int n;  // he has
    int w;  //bananas have to buy
    cin >> k >> n >> w;
    int ans=0;
    for (int i=1;i< w+1;i++){
        ans = ans +k*i;
    }
    if (ans>n){
        cout << ans -n;
    }
    else cout << 0;
    system("pause");
    return 0;
}
