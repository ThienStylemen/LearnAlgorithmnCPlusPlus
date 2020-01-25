//
//  Array.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/26/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Array

 You've got an array A,  consisting of N integers: A1,A2,...AN. Your task is to find a minimal by inclusion segment [L,R]
 (1≤L≤R≤N) such, that among numbers AL,AL+1,...AR there are exactly K distinct numbers.

 Segment [L,R] (1≤L≤R≤N; L, R  are integers ) of length M=R−L+1, satisfying the given property, is called minimal by inclusion, if there is no segment [X,Y] satisfying the property and less then M in length, such that 1≤L≤X≤Y≤R≤N. Note that the segment [L,R] doesn't have to be minimal in length among all segments, satisfying the given property

 Input

 The first line contains two space-separated integers: N and K  (1≤N, K ≤ 10^5)
 The second line contains N space-separated integers A1,A2,...,AN — elements of the array  (1≤Ai ≤10^5)
 
 Output

 Print a space-separated pair of integers L and R  (1≤L≤R≤N) such, that the segment [L,R] is the answer to the problem. If the sought segment does not exist, print " -1 -1 " without the quotes. If there are multiple correct answers, print any of them.
 
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include<algorithm>

int cnt[100000+1];

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a;
    int temp;
    for(int i=0;i<n;i++){
        cin >> temp;
        a.push_back(temp);
    }
    
    int right =0;
    int unique =0;
    
    for (int i=0;i<100000+1;i++){
        if (cnt[a[i]] ==0){  //  unique numbers
            unique++;
        }
        cnt[a[i]]++;
        if (unique==k){
            right = i;
            break;
        }
    }
    if (unique <k){
        cout << -1 << " " << -1;
        system("pause");
        return 0;
    }
    int left=0;
    for (int i=0;i<100000+1;i++){  // tim doan ngan nhat
        cnt[a[i]]--;
        if (cnt[a[i]]==0){   // vi tri ngan nhat;
            
            left =i;
            break;
        }
    }
    cout << left+1 << " " << right +1;
    
    
    system("pause");
    return 0;
}
