//
//  SortTheArray.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/27/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//


/*
 Sort the Array

 Being a programmer, you like arrays a lot. For your birthday, your friends have given you an array a consisting of n distinct integers.

 Unfortunately, the size of a is too small. You want a bigger array! Your friends agree to give you a bigger array, but only if you are able to answer the following question correctly: is it possible to sort the array a (in increasing order) by reversing exactly one segment of a? See definitions of segment and reversing in the notes.

 Note

 A segment [l,r] of array a is the sequence al,al+1,...,ar.
 If you have an array a of size n and you reverse its segment [l,r], the array will become:
a1,a2,...,al-2,al-1,ar,ar-1,...,al+1,al,ar+1,ar+2,...,an-1,an.
 
 Input

 The first line of the input contains an integer n(1≤n≤10^5) — the size of array a.

 The second line contains n distinct space-separated integers: a1,a2,...,an (1≤ai ≤10 ^9).

 Output

 Print yes or no, depending on the answer.

 If your answer is yes, then also print two space-separated integers denoting start and end (start must not be greater than end) indices of the segment to be reversed. If there are multiple ways of selecting these indices, print 1 1.
 
 3
 3 2 1
 
 yes
 1 3
 */
#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

int main(){
    int n;
    cin >> n;
    vector<int> a(n), sorted_a(n);
    
    for(int i=0;i<n;i++){
        cin >> a[i];
        sorted_a[i]=a[i];
    }
    
    sort(sorted_a.begin(),sorted_a.end());
    
    int l=0, r=0;
    
    for(int i=n-1;i>=0;i--){
        if (a[i] != sorted_a[i]){
            r=i;
            break;
        }
    }
    for (int i=0;i<n;i++){
        if (a[i]!=sorted_a[i]){
            l=i;
            break;
        }
    }
    
    for(int i=l,j=r;i<j;i++,j--){
        swap(a[i],a[j]);
    }
    
    if (a!=sorted_a){
        cout << "no";
        return 0;
    }
    
    cout << "yes" << endl;
    cout << l + 1 << " " << r + 1;
    
    system("pause");
    return 0;
}
