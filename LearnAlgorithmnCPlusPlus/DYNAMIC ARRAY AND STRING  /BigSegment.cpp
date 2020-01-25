//
//  BigSegment.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/25/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Big Segment
 
 A coordinate line hasN segments, the i-th segment starts at the position Li and ends at the position Ri. We will denote such a segment as [Li, Ri].

 You have suggested that one of the defined segments covers all others. In other words, there is such segment in the given set, which contains all other ones. Now you want to test your assumption. Find in the given set the segment which covers all other segments, and print its number. If such a segment doesn't exist, print -1.

 Formally we will assume that segment [a,b] covers segment [c,d], if they meet this condition
 a  ≤ c  ≤ d ≤ b
 
 Input

 The first line contains integer N (1≤N≤10^5 ) — the number of segments. Next N lines contain the descriptions of the segments. The i-th line contains two space-separated integers
 Li, Ri ( 1 ≤ Li ≤ Ri ≤ 10^9 ) — the borders of the i-th segment.

 It is guaranteed that no two segments coincide.

 Output

 Print a single integer — the number of the segment that covers all other segments in the set. If there's no solution, print −1.

 The segments are numbered starting from 1 in the order in which they appear in the input.
 
 3
 3 3
 4 4
 5 5

 -1

 
 */

#include <iostream>
#include <vector>
using namespace std;
struct Point {
    int x;
    int y;
    void inputPoint();
};

void Point::inputPoint(){
    cin >> x;
    cin >> y;
    this->x = x;
    this->y = y;
}

int main(){
    int n;
    cin >> n;
    vector<Point> vP;
    Point temp;
    for(int i=0;i<n;i++){
        temp.inputPoint();
        vP.push_back(temp);
    }
    
    int min_x = vP[0].x;
    int max_y = vP[0].y;
    
    for (int i =0;i< vP.size(); i++){
        if (max_y <= vP[i].y){
            max_y = vP[i].y;
        }
        if (min_x >=vP[i].x){
            min_x = vP[i].x;
        }
    }
    int index=-1;
    for (int i=0;i<vP.size();i++){
        if (vP[i].x == min_x && vP[i].y == max_y){
            index =i;
            break;
        }
    }
    if (index == -1) cout << -1;
    else cout << index +1;
    
    system("pause");
    return 0;
    
}
