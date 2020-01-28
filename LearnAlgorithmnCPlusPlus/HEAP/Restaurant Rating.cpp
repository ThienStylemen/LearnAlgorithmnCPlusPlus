//
//  Restaurant Rating.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/28/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Restaurant Rating

 Chef has opened up a new restaurant. Like every other restaurant, critics critique this place. The Chef wants to gather as much positive publicity as he can. Also, he is very aware of the fact that people generally do not tend to go through all the reviews. So he picks out the positive reviews and posts it on the website of the restaurant. A review is represented by an integer which is the overall rating of the restaurant as calculated by that particular review. A review is considered to be positive if it is among the top one-third of the total reviews when they are sorted by their rating. For example, suppose the ratings given by
 8 different reviews are as follows: 2 8 3 1 6 4 5 7

 Then the top one-third reviews will be 8 and 7. Note that we considered one-third to be 8/3=2 top reviews according to integer division. (see Notes)

 So here is what the Chef wants from you: Given the reviews(ratings) by different critics, the Chef needs you to tell him what is the minimum rating that his website will be displaying. For example in the above case, the minimum rating that will be displayed is 7. Also, different critics keep reviewing the restaurant continuosly. So the new reviews keep coming in. The Chef wants your website ratings to be up-to-date. So you should keep updating the ratings there. At any point of time, the Chef might want to know the minimum rating being displayed. You'll have to answer that query. An interesting thing to note here is that a review might be in the website for some time and get knocked out later because of new better reviews and vice-versa.

 Notes: To be precise, the number of reviews displayed website will be floor(n/3), where n denotes the current number of all reviews.

 Input

 First line of the input file consists of a single integer N (1≤N≤250000), the number of operations to follow. The next N lines contain one operation each on a single line. An operation can be of 2 types:
 1 x : Add a review with rating 'x' to the exisiting list of reviews ( x is an integer, 1≤x≤1000000000)
 2 : Report the current minimum rating on the website
 Output

 For every test case, output a single integer each for every operation of type 2 mentioned above. If no review qualifies as a positive review, print "No reviews yet".
 
 10
 1 1
 1 7
 2
 1 9
 1 21
 1 8
 1 5
 2
 1 9
 2
 
 No reviews yet
 9
 9
 
 */

#include<queue>
#include<iostream>
using namespace std;
priority_queue<int,vector<int>,greater<int>> min_top3;
priority_queue<int> pq;
int main(){
    int n,x;
    cin >> n;
    int option, n_review=0;
    while (n--){
        cin >> option;
        if(option==1){
            n_review++;
            cin >> x;
            
            if (!min_top3.empty() && x > min_top3.top()){
                pq.push(min_top3.top());
                min_top3.pop(); // vi < x
                min_top3.push(x);
            }else{
                pq.push(x);
            }
            
            if (n_review %3==0){
                min_top3.push(pq.top());
                pq.pop();
            }
            
        }else{
            if (min_top3.empty()){
                cout << "No reviews yet" << endl;
            }else {
                cout << min_top3.top() << endl;
            }
        }
    }
    system("pause");
    return 0;
}
