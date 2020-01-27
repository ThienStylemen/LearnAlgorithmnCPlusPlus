//
//  Throwing Cards Away I.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/27/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//


/*
 Throwing Cards Away I

 Given is an ordered deck of N cards numbered 1 to N with card 1 at the top and card N at the bottom. The following operation is performed as long as there are at least two cards in the deck:

 Throw away the top card and move the card that is now on the top of the deck to the bottom of the deck.
 
 Your task is to find the sequence of discarded cards and the last, remaining card.

 Input

 Each line of input (except the last) contains a number N≤50. The last line contains ‘0’ and this line should not be processed.

 Output

 For each number from the input produce two lines of output. The first line presents the sequence of discarded cards, the second line reports the last remaining card. No line will have leading or trailing spaces. See the sample for the expected format.
 
 7
 19
 10
 6
 0
 
 Discarded cards: 1, 3, 5, 7, 4, 2
 Remaining card: 6
 Discarded cards: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 4, 8, 12, 16, 2, 10, 18, 14
 Remaining card: 6
 Discarded cards: 1, 3, 5, 7, 9, 2, 6, 10, 8
 Remaining card: 4
 Discarded cards: 1, 3, 5, 2, 6
 Remaining card: 4

 */
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int n;
    queue<int> deck;
    vector<int> discarded_cards;
    while (true){
        cin >> n;
        if (n==0) break;
        for(int i=0;i<n;i++){
            deck.push(i);
        }
        
        while (deck.size()>=2){
            /*
              Khi số lượng lá bài trong queue còn ít nhất hai lá:
             Lấy lá bài trên đầu queue ra.
             Lấy lá bài mới trên đầu queue ra và đưa lại vào cuối queue.
             */
            discarded_cards.push_back(deck.front());
            deck.pop();
            
            deck.push(deck.front());
            deck.pop();
        }
        cout << "Discarded_cards: ";
        for(int i=0;i<n-1;i++){
            if (i!=0){
                cout << ",";
            }
            cout <<" "<< discarded_cards[i];
        }
        cout << endl;
        cout << "Remaining cards: " << deck.front() << endl;
        deck.pop();
        discarded_cards.clear();
        
    }
    
    
    system("pause");
    return 0;
}
