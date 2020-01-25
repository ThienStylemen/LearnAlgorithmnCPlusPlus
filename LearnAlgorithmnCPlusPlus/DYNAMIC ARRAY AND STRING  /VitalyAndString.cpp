//
//  VitalyAndString.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/25/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Vitaly and Strings

 Vitaly is a diligent student who never missed a lesson in his five years of studying in the university. He always does his homework on time and passes his exams in time.

 During the last lesson the teacher has provided two strings S andT to Vitaly. The strings have the same length, they consist of lowercase English letters, string S is lexicographically smaller than string T. Vitaly wondered if there is such string that is lexicographically larger than string S and at the same is lexicographically smaller than string T. This string should also consist of lowercase English letters and have the length equal to the lengths of strings S and T.

 Let's help Vitaly solve this easy problem!

 Input

 The first line contains string S ( 1 ≤ ∣S∣ ≤ 100), consisting of lowercase English letters. Here, ∣S∣ denotes the length of the string. The second line contains string T ( ∣T∣ = ∣S∣), consisting of lowercase English letters.

 It is guaranteed that the lengths of strings S and T are the same and string S is lexicographically less than string T.

 Output

 If the string that meets the given requirements doesn't exist, print a single string "No such string" (without the quotes).

 If such string exists, print it. If there are multiple valid strings, you may print any of them.
 
 Note

 String
 S = S1S2...SN is said to be lexicographically smaller than T=T1T2...TN, if there exists such i, that S1=T1, S2=T2, ..., Ss-1 = Ti-1, Si <Ti
 */


/*
s < t
find p: s < p < t
p = s + 1, s + 2, .. s + x

a  -  z
0 .. 25

25 + 1 ==

0 ... 9
0 1

9 + 1=

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){
    string s, t;    //  find s<p<t
    cin >> s >> t;
    for(int i = s.length(); i>=0;i--){
        if (s[i] != 'z'){
            s[i]++;
            break;
        }else{
            s[i] = 'a';
        }
    }
    if (s!= t) cout << s;  // this is s-1;
    else cout << "No such string" << endl;
    system("pause");
    return 0;
}
