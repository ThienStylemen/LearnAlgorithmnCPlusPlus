//
//  Printer Queue  Printer Queue  Printer Queue  Printer Queue (UnAccepted).cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 2/1/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

// Thien: Wrong answer on test 2
/*
 Printer Queue

 The only printer in the computer science students’ union is experiencing an extremely heavy workload. Sometimes there are a hundred jobs in the printer queue and you may have to wait for hours to get a single page of output.

 Because some jobs are more important than others, the Hacker General has invented and implemented a simple priority system for the print job queue. Now, each job is assigned a priority between 1 and 9 (with 9 being the highest priority, and 1 being the lowest), and the printer operates as follows.



 The first job J in queue is taken from the queue.
 If there is some job in the queue with a higher priority than job J , then move J to the end of the queue without printing it.
 Otherwise, print job J (and do not put it back in the queue).
 In this way, all those important muﬃn recipes that the Hacker General is printing get printed very quickly. Of course, those annoying term papers that others are printing may have to wait for quite some time to get printed, but that’s life.

 Your problem with the new policy is that it has become quite tricky to determine when your print job will actually be completed. You decide to write a program to figure this out. The program will be given the current queue (as a list of priorities) as well as the position of your job in the queue, and must then calculate how long it will take until your job is printed, assuming that no additional jobs will be added to the queue. To simplify matters, we assume that printing a job always takes exactly one minute, and that adding and removing jobs from the queue is instantaneous.

 Input

 One line with a positive integer: the number of test cases (at most 100). Then for each test case:

 One line with two integers n and m, where n is the number of jobs in the queue (1 ≤ n ≤ 100) and m is the position of your job (0 ≤ m ≤ n – 1). The first position in the queue is number 0, the second is number 1, and so on.
 One line with n integers in the range 1 to 9, giving the priorities of the jobs in the queue. The first integer gives the priority of the first job, the second integer the priority of the second job, and so on.
 Output

 For each test case, print one line with a single integer; the number of minutes until your job is completely printed, assuming that no additional print jobs will arrive.

 3
 1 0
 5
 4 2
 1 2 3 4
 6 0
 1 1 9 1 1 1
 
 1
 2
 5


 */


#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct job {
    int number;
    int priority;
};
struct MAX_HEAP {
    bool operator() (const job &a, const job &b) {
        return a.priority < b.priority;
    }
};
int main() {
    int cases;
    cin >> cases;
    queue<job> q;
    priority_queue<job,vector<job>, MAX_HEAP> pq;    // max heap;


    while (cases--) {
        int n, m;
        cin >> n >> m;
        // n is the number of jobs in the queue(1
        // and m is the position of your job
        int temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;    // muc do uu tien

            pq.push(job{i,temp});
            q.push(job{ i ,temp });
        }
        int count = 0;
        
        while (true) {
            if (q.front().priority < pq.top().priority) {
                q.push(q.front());
                q.pop();
            }
            else {
                count++;    // print
                if (m == q.front().number) {
                    cout << count << endl;
                    break;
                }
                pq.pop();
                q.pop();
            }

        }
    }

    system("pause");
    return 0;
}
