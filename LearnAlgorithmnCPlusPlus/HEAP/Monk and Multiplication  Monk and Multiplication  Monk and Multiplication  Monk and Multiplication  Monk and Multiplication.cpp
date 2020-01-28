//
//  Monk and Multiplication  Monk and Multiplication  Monk and Multiplication  Monk and Multiplication  Monk and Multiplication.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/28/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 
 */
#include<iostream>
#include<vector>
using namespace std;
//
//vector<int> h;
//void minHeap(int i) {
//    int smallest = i;
//    int left = 2 * i + 1;
//    int right = 2 * i + 2;
//    if (left < h.size() && h[left] < h[smallest])
//        smallest = left;
//    if (right < h.size() && h[right] < h[smallest])
//        smallest = right;
//    if (smallest != i) {
//        swap(h[smallest], h[i]);
//        minHeap(smallest);
//    }
//}
//void buildHeap(int n) {
//    for (int i = n / 2 - 1; i >= 0; i--)
//        minHeap(i);
//}
#include<queue>
int main(){

    unsigned long long t;
    cin >> t;
    priority_queue< unsigned long long> pq;
    
    vector< unsigned long long > arr(t);

    for (unsigned long long i = 0; i < t; i++) {
        cin >> arr[i];
        pq.push(arr[i]);

        if (pq.size() < 3)
            cout << -1 << endl;
        else {
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
