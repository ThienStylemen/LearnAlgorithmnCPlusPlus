//
//  DNA Prefix.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/5/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 DNA Prefix

 Given a set of N DNA samples, where each sample is a string containing characters from {A, C, G, T}, we are trying to find a subset of samples in the set, where the length of the longest common prefix multiplied by the number of samples in that subset is maximum.

 To be specific, let the samples be:

 ACGT
 ACGTGCGT
 ACCGTGC
 ACGCCGT

 If we take the subset {ACGT} the the result is 4 (4 * 1), if we take {ACGT, ACGTGCGT, ACGCCGT} then the result is 3 * 3 = 9 (since ACG is the common prefix), if we take {ACGT, ACGTGCGT, ACCGTGC, ACGCCGT} then the result is 2 * 4 = 8.

 Now your task is to report the maximum result we can get from the samples.

 Input

 Input starts with an integer T ( ≤ 10), denoting the number of test cases.

 Each case starts with a ine containing an integer N (1 ≤ N ≤ 50 000) denoting the number of DNA samples. Each of the next N lines contains a non empty string whose length is not greater than 50. And the strings contain characters from {A, C, G, T}.

 Output

 For each case, print the case number and the maximum result that can be obtained.

 Note

 Dataset is huge. Use faster I/O methods.
 
 3
 4
 ACGT
 ACGTGCGT
 ACCGTGC
 ACGCCGT
 3
 CGCGCGCGCGCGCCCCGCCCGCGC
 CGCGCGCGCGCGCCCCGCCCGCAC
 CGCGCGCGCGCGCCCCGCCCGCTC
 2
 CGCGCCGCGCGCGCGCGCGC
 GGCGCCGCGCGCGCGCGCTC
 
 
 Case 1: 9
 Case 2: 66
 Case 3: 20
 */
