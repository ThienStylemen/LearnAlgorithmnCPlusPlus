//
//  Qheap1.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/28/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Qheap 1

 This question is designed to help you get a better understanding of basic heap operations. You will be given queries of 3 types:

 "1v" - Add an element to the heap.
 "2v" - Delete the element from the heap.
 "3" - Print the minimum of all the elements in the heap.
 NOTE: It is guaranteed that the element to be deleted will be there in the heap. Also, at any instant, only distinct elements will be in the heap.

 Input

 The first line contains the number of queries, Q (1≤Q≤10^5).
 Each of the next Q lines contains a single query of any one of the 3 above mentioned types ( −10^9≤v≤10^9).
 
 Output

 For each query of type 3, print the minimum value on a single line.
 
 5
 1 4
 1 9
 3
 2 4
 3
 
 4
 9

 */
#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> pq,pqRemove;
    int Q;
    cin >> Q;
    int type, value;
    while (Q--){
        cin >> type;
        if (type==1){
            cin >> value;
            pq.push(value);
        }
        else if (type==2){
            cin >> value;
            pqRemove.push(value);
        }else{
            // print out
            while ( !pqRemove.empty() && pqRemove.top() == pq.top() ){
                pq.pop();
                pqRemove.pop();
            }
            cout << pq.top() << endl;
        }
    }
    system("pause");
    return 0;
}
