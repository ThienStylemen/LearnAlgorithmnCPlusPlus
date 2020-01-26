//
//  Books.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/26/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 
 Books

 When Valera has got some free time, he goes to the library to read some books. Today he's got T free minutes to read. That's why Valera took N books in the library and for each book he estimated the time he is going to need to read it. Let's number the books by integers from 1 to N. Valera needs Ai minutes to read the i-th book.

 Valera decided to choose an arbitrary book with number i and read the books one by one, starting from this book. In other words, he will first read book number i, then book number i+1, then book number i+2 and so on. He continues the process until he either runs out of the free time or finishes reading the N-th book. Valera reads each book up to the end, that is, he doesn't start reading the book if he doesn't have enough free time to finish reading it.

 Print the maximum number of books Valera can read.

 Input

 The first line contains two integers  N and T (1≤N≤10^5 ;1≤T≤10^9) — the number of books and the number of free minutes Valera's got. The second line contains a sequence of N integers A1,A2,...,AN (1≤A​i ≤10^4), where number Ai shows the number of minutes that the boy needs to read the i-th book.

 Output

 Print a single integer — the maximum number of books Valera can read.
 
 4 5
 3 1 2 1
 
 3
 */


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    int read=0;
    int max_book =0;
    int j=0;
    
    for(int i=0;i<n;i++){
        while(t < a[i] ){
            read--;
            t+= a[j];
            j++;        // hoac la t+= a[j++];
        }
        t -= a[i];
        read++;
        max_book = max(max_book, read);
    }
    cout << max_book;
    
    system("pause");
    return 0;
}
