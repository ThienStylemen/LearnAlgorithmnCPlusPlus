//
//  Monk and Multiplication  Monk and Multiplication  Monk and Multiplication  Monk and Multiplication  Monk and Multiplication.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/28/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Monk and Multiplication

 The Monk learned about priority queues recently and asked his teacher for an interesting problem. So his teacher came up with a simple problem. He now has an integer array A. For each index i, he wants to find the product of the largest, second largest and the third largest integer in the range [1,i]. Note: Two numbers can be the same value-wise but they should be distinct index-wise.

 Input

 The first line contains an integer N, denoting the number of elements in the array
 A (1≤N≤100000). The next line contains N space separated integers, each denoting the ith integer of the array A (0≤A[i]≤1000000).

 Output

 Print the answer for each index in each line. If there is no second largest or third largest number in the array A upto that index, then print "-1", without the quotes.
 */

#include<iostream>
#include<vector>
using namespace std;
#include <queue>
int main(){
    unsigned long long t;
    cin >> t;
    priority_queue<long long> pq;
    vector<unsigned long long> arr(t);
    for(unsigned long long i=0;i<t;i++){
        cin >> arr[i];
        pq.push(arr[i]);
        if (pq.size() <3){
            cout << -1 << endl;
        }else{
            unsigned long long a = pq.top();
            pq.pop();
            unsigned long long b = pq.top();
            pq.pop();
            unsigned long long c = pq.top();
            
            pq.push(a);
            pq.push(b);
            
            cout << a*b*c << endl;
            
        }
    }
    system("pause");
    return 0;
}
