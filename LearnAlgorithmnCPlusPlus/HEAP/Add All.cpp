//
//  Add All.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/28/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 
 Add All

 Yup!! The problem name reflects your task; just add a set of numbers. But you may feel yourselves condescended, to write a C/C++ program just to add a set of numbers. Such a problem will simply question your erudition. So, lets add some flavor of ingenuity to it. Addition operation requires cost now, and the cost is the summation of those two to be added. So, to add 1 and 0
 10, you need a cost of 11. If you want to add 1,2 and 3. There are several ways

 
 Input is terminated by a case where the value of N is zero. This case should not be processed.

 Output

 For each case print the minimum total cost of addition in a single line.

 3
 1 2 3
 4
 1 2 3 4
 0
 
 9
 19

 */
#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int> > pq;
    int n=1;
    while(n!=0){
        cin >>n;
        if (n==0) break;
        int value;
        for(int i=0;i<n;i++){
            cin >> value;
            pq.push(value);
        }
        long long ans =0;
        while (pq.size() !=1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ans += a+b;
            pq.push(a+b);
        }
        cout << ans << endl;
        pq.pop();
    }
    system("pause");
    return 0;
}
