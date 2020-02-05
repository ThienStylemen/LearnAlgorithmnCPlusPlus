//
//  Ekko.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/5/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Eko

 Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.

 Mirko's machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Mirko then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

 Mirko is ecologically minded, so he doesn't want to cut off more wood than necessary. That's why he wants to set his sawblade as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.

 Input

 The first line of input contains two space-separated positive integers, N (the number of trees, 1≤N≤1000000) and M (Mirko's required wood amount, 1≤M≤2000000000).

 The second line of input contains N space-separated positive integers less than 1000000000, the heights of each tree (in metres). The sum of all heights will exceed M, thus Mirko will always be able to obtain the required amount of wood.

 Output

 The first and only line of output must contain the required height setting.
 
 
 4 7
 20 15 10 17
 
 15
 
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int>trees(N);
    for(int i=0;i<N;i++){
        cin >> trees[i];
    }
    int h_min=0;
    int h_max=1e9;
    int res;
    // binary search -> no need to sort
    while( h_min <= h_max){
        long long sum=0;
        int h_mid = h_min + (h_max-h_min)/2;
        for(int i=0;i<trees.size();i++){
            sum += max(0,trees[i]-h_mid);
        }
        if (sum>=M){
            res = h_mid;
            h_min = h_mid +1;
        }else{
            h_max = h_mid -1;
        }
    }
    cout << res;

    system("pause");
    return 0;
}

/* solution time limit exceeded on test 29
 
 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;
 #define INF 1e9;

 int main() {
     unsigned long N, M;
     cin >> N >> M;
     unsigned long sum_trees=0;
     vector<unsigned long> trees(N);
     for (unsigned long i = 0; i < N; i++) {
         cin >> trees[i];
         //sum_trees += trees[i];
     }
     sort(trees.begin(), trees.end(), greater<int>());
     unsigned long cut =0;
     unsigned long i = 0;
     for (i = 0; i < N-1; i++) {
         cut += (trees[i] - trees[i + 1]) * (i+1) ;
         if (cut >= M) {
             break;
         }
     }
     //cout << i << endl;
     //cout << cut << endl;
     unsigned long height = trees[i + 1 ];
     if (cut == M) cout << trees[i+1] << endl;
     else {
         while (cut - (i + 1) >= M) {
             cut -= (i + 1);

             height += 1;
             //cout <<"cut:" << cut <<"\t" << height << endl;
             //if (cut - (i + 1) <= M)
             //    break;
         }
         cout << height ;
     }
     //cout << trees[i + 1] << endl;
     
     system("pause");
     return 0;
 }
 */

/*
 solution error on test 49
 
 
 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;
 #define INF 1e9;

 int main() {
     int N, M;
     cin >> N >> M;
     int sum_trees=0;
     vector<int> trees(N);
     for (int i = 0; i < N; i++) {
         cin >> trees[i];
         sum_trees += trees[i];
     }
     sort(trees.begin(), trees.end(), greater<int>());
     int cut =0;
     int i = 0;
     for (i = 0; i < N-1; i++) {
         cut += (trees[i] - trees[i + 1]) * (i+1) ;
         if (cut >= M) {
             break;
         }
     }
     //cout << i << endl;
     //cout << cut << endl;
     int height = trees[i + 1 ];
     if (cut == M) cout << trees[i+1] << endl;
     else {
         while (cut - (i + 1) >= M) {
             cut -= (i + 1);

             height += 1;
             //cout <<"cut:" << cut <<"\t" << height << endl;
             //if (cut - (i + 1) <= M)
             //    break;
         }
         cout << height ;
     }
     //cout << trees[i + 1] << endl;
     
     system("pause");
     return 0;
 }
 */
