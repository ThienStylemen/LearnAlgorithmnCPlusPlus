//
//  Pangram.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/1/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//


/*
 Pangram

 A word or a sentence in some language is called a pangram if all the characters of the alphabet of this language appear in it at least once. Pangrams are often used to demonstrate fonts in printing or test the output devices.

 You are given a string consisting of lowercase and uppercase Latin letters. Check whether this string is a pangram. We say that the string contains a letter of the Latin alphabet if this letter occurs in the string in uppercase or lowercase.

 Input

 The first line contains a single integer n (1 ≤ n ≤ 100) — the number of characters in the string. The second line contains the string. The string consists only of uppercase and lowercase Latin letters.

 Output

 Output "YES", if the string is a pangram and "NO" otherwise.

 12
 toosmallword
 
 NO

 35
 TheQuickBrownFoxJumpsOverTheLazyDog
 YES

 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    bool cnt[124]= {false};
    int n;
    cin >> n;
    string str;
    cin >> str;
    
    for(int i=0;i<n;i++){
        cnt[ (int)str[i]] = true;
    }
    
    for(int i=65; i< 123; i++){
        if (i >=91 && i <= 96){
            continue;
        }
        if (i>=65 && i <= 90 && !cnt[i] && !cnt[i+32]){
            cout << "NO";
            system("pause");
            return 0;
        }
        if (i>96 && !cnt[i] && cnt[i-32]){
            cout << "NO";
            system("pause");
            return 0;
        }
    }
    cout << "YES";
    system("pause");
    return 0;
}
