//
//  Find The Median.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/2/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Find The Median

 Given a list of numbers, can you find the median?

 Input

 There will be two lines of input:

 n – the size of the array
 ar – n numbers that makes up the array
 1 ≤ n ≤ 1000001
 n is odd
 -100000 ≤ x ≤ 100000, x ∈ ar
 Output

 Output one integer, the median.
 
 7
 0 1 2 4 6 5 3
 
 3
 
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    cout << a[n/2];
    system("pause");
    return 0;
}

