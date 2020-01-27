//
//  Transform the Expression.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/27/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//
/*
 Transform the Expression

 Transform the algebraic expression with brackets into RPN form (Reverse Polish Notation . Two-argument operators: +, −, ∗, /, ^ (priority from the lowest to the highest), brackets (). Operands: only letters: a,b,...,z. Assume that there is only one RPN form (no expressions like a*b*c)
 
 Input

 T [ the number of expressions ≤ 100]
 expression [ength ≤400]
 [other expressions]

 Note: Text grouped in [ ] does not appear in the input file.

 Output

 The expressions in RPN form, one per line.

 3
 (a+(b*c))
 ((a+b)*(z+x))
 ((a+t)*((b+(a+c))^(c+d)))
 
 abc*+
 ab+zx+*
 at+bac++cd+^*

 */

#include<iostream>
#include<stack>
using namespace std;
#include<algorithm>
#include<string>
void transform(string expression){
    stack<char> stk;
    
    for(char symbol:expression){
        if (isalpha(symbol))   //abcd
            cout << symbol;
        else if (symbol==')'){
            cout << stk.top();
            stk.pop();
        }
        else if (symbol!='('){  // operator
            stk.push(symbol);
        }
    }
    cout << endl;
}
int main(){
    int t;
    string s;
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> s;
        transform(s);
        
    }
    system("pause");
    return 0;
}

