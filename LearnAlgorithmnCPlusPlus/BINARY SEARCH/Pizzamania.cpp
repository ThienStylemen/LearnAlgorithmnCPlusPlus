//
//  Pizzamania.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/4/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Pizzamania

 Singham and his friends are fond of pizza. But this time they short of money. So they decided to help each other. They all decided to bring pizza in pairs. Our task is to find the total number of pairs possible which can buy pizza, given the cost of pizza. As pizza boy dont have any cash for change, if the pair adds upto more money than required, than also they are unable to buy the pizza. Each friend is guaranteed to have distinct amount of money. As it is Singham's world, money can also be negative ;).

 Input

 The first line consist of t (1≤t≤100) test cases. In the following 2×t lines, for each test case first there is n and m, where n (1≤n≤100000) is number of Singham's friend and m is the price of pizza. The next line consist of n integers, seperated by space, which is the money each friend have.

 The value of m and money is within the limits of int in C, C++.

 Output

 A single integer representing the number of pairs which can eat pizza.

 2
 4 12
 9 -3 4 3
 5 -9
 -7 3 -2 8 7

 1
 1
 
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int test_case;
    cin >> test_case;
    while(test_case--){
        /* In the following 2×t lines, for each test case first there is n and m,
        where
        */
        int n, m; //n ( 1≤n≤100000) is number of Singham's friend and m is the price of pizza
        cin >> n >> m;
        vector<int> friends(n);
        for(unsigned int i=0;i<n;i++){
            cin >> friends[i];
        }
        if (n==1){
            cout << 0;
            continue;
        }
        sort(friends.begin(), friends.end());
        int count =0;
        for(unsigned int i=0;i<n;i++){
            if (binary_search(friends.begin() +i, friends.end(), m-friends[i])){
                count++;
            }
        }
        cout << count << endl;
    }
    system("pause");
    return 0;
}
