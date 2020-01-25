//
//  Array2BachHigherThanArray1Begin.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/25/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Arrays
 You are given two arrays A and B consisting of integers, sorted in non-decreasing order. Check whether it is possible to choose K numbers in array A and choose M numbers in array B so that any number chosen in the first array is strictly less than any number chosen in the second array.

 Input

 The first line contains two integers NA,NB ( 1 ≤ NA, NB ≤ 10^5 ), separated by a space — the sizes of arrays A and B correspondingly.

 The second line contains two integers K and M (1 ≤ K ≤ NA, 1 ≤ M ≤ NB), separated by a space.

 The third line contains NA numbers A1,A2,...ANa ( -10^9 ≤ A1 ≤ A2 ≤ ... ≤ANa ≤ 10^9), separated by spaces — elements of array A.

 The third line contains NB numbers B1,B2...BNb ( -10^9 ≤ B1 ≤ B2 ≤ ... ≤BNb ≤ 10^9), separated by spaces — elements of array B.
 Output

 Print "YES" (without the quotes), if you can choose K in array A and M numbers in array B so that any number chosen in array A was strictly less than any number chosen in array
 B. Otherwise, print "NO" (without the quotes).

 */


#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n1,n2;
    cin >> n1 >> n2;
    int k,m;
    cin >> k >> m;
    vector<int> v1;
    vector<int> v2;
    int temp;
    for (int i=0; i<n1; i++){
        cin >> temp;
        v1.push_back(temp);
    }
    
    for (int i=0; i<n2; i++){
        cin >> temp;
        v2.push_back(temp);
    }
    // already sorted;
    if (v1[k-1] < v2[ (int) v2.size() - m]) cout << "YES";
    else cout << "NO";
    
    system("pause");
    return 0;
    
}
