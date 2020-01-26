//
//  GeorgeAndRound.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/26/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//
/*
 George and Round

 George decided to prepare a Codesecrof round, so he has prepared M problems for the round. Let's number the problems with integers 1 through M. George estimates the i-th problem's complexity by integer Bi. To make the round good, he needs to put at least  N problems there. Besides, he needs to have at least one problem with complexity exactly A1, at least one with complexity exactly A2, ...,  and at least one with complexity exactly AN. Of course, the round can also have problems with other complexities.

 George has a poor imagination. It's easier for him to make some already prepared problem simpler than to come up with a new one and prepare it. George is magnificent at simplifying problems. He can simplify any already prepared problem with complexity C to any positive integer complexity (C≥D), by changing limits on the input data.

 However, nothing is so simple. George understood that even if he simplifies some problems, he can run out of problems for a good round. That's why he decided to find out the minimum number of problems he needs to come up with in addition to the M he's prepared in order to make a good round. Note that George can come up with a new problem of any complexity.

 Input

 The first line contains two integers N and M (1≤N,M≤3000) — the minimal number of problems in a good round and the number of problems George's prepared. The second line contains space-separated integers A1,A2,...,AN (1≤A1<A2<...<AN≤10^6) — the requirements for the complexity of the problems in a good round. The third line contains space-separated integers B1,B2,...,BM(1≤B1≤B2≤...≤<10^6) — the complexities of the problems prepared by George.

 Output

 Print a single integer — the answer to the problem.
 */

/*
 Bước 1: Bỏ độ khó được quy định trong kỳ thi vào mảng A, độ khó của các bài đã được George chuẩn bị vào mảng B.

 Bước 2: Sử dụng hai biến i, j chạy song song trên hai mảng, biến count để đếm số lượng đề bài đã chuẩn bị được cho kì thi.

 Biến i chạy trên mảng A, biến j chạy trên mảng B.
 Nếu Ai ≤ Bj nghĩa là bài đã chuẩn bị thứ j có thể sử dụng làm đề bài thứ i trong kỳ thi, ta tăng biến i,j,count lên 1 đơn vị để tìm bài tập cho đề bài i+1

 Ngược lại, nếu Ai > ta tăng biến j lên 1 đơn vị để tiếp tục tìm kiếm bài có độ khó ≤ Ai (j+1) trở về sau.
 Bước 3: In ra đáp án của bài toán: n−count (với count là số đề bài đã chuẩn bị được cho kì thi).
 
 3 5
 1 2 3
 1 2 2 3 3
 
 0
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include<algorithm>

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    
    int count =0;
    // elements in preapare array if it higher than a[i], can be use for a[i+1],
    for(int i=0, j=0; i<n && j<m;j++){
        if (b[j] >= a[i]){
            i++;
            count++;
        }
    }
    cout << n - count;
    system("pause");
    return 0;
}
