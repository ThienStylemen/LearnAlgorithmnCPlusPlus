//
//  Guilty Prince.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/27/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Eng
 Guilty Prince

 Once there was a king named Akbar. He had a son named Shahjahan. For an unforgivable reason the king wanted him to leave the kingdom. Since he loved his son he decided his son would be banished in a new place. The prince became sad, but he followed his father's will. In the way he found that the place was a combination of land and water. Since he didn't know how to swim, he was only able to move on the land. He didn't know how many places might be his destination. So, he asked your help.

 For simplicity, you can consider the place as a rectangular grid consisting of some cells. A cell can be a land or can contain water. Each time the prince can move to a new cell from his current position if they share a side.

 Now write a program to find the number of cells (unit land) he could reach including the cell he was living.

 Input

 Input starts with an integer T(≤500), denoting the number of test cases.

 Each case starts with a line containing two positive integers W and H; W and H are the numbers of cells in the x and y directions, respectively. W and H are not more than 20.

 There will be H more lines in the data set, each of which includes W characters. Each character represents the status of a cell as follows.

 '.' - land
 '#' - water
 '@' - initial position of prince (appears exactly once in a dataset)
 Output

 For each case, print the case number and the number of cells he can reach from the initial position (including it).
 
 4
 6 9
 ....#.
 .....#
 ......
 ......
 ......
 ......
 ......
 #@...#
 .#..#.
 11 9
 .#.........
 .#.#######.
 .#.#.....#.
 .#.#.###.#.
 .#.#..@#.#.
 .#.#####.#.
 .#.......#.
 .#########.
 ...........
 11 6
 ..#..#..#..
 ..#..#..#..
 ..#..#..###
 ..#..#..#@.
 ..#..#..#..
 ..#..#..#..
 7 7
 ..#.#..
 ..#.#..
 ###.###
 ...@...
 ###.###
 ..#.#..
 ..#.#..
 
 Case 1: 45
 Case 2: 59
 Case 3: 6
 Case 4: 13

 */

#include<algorithm>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
#define MAX_ROW_COL 21

bool visited[MAX_ROW_COL][MAX_ROW_COL];
int num_row, num_col;
char map[MAX_ROW_COL][MAX_ROW_COL];

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

struct Cell {
    int row, col;
};
//
bool isCellValid(int r, int c) {
    if (r >= 0 && r < num_row && c >= 0 && c < num_col) {
        return true;
    }
    return false;
}
int GuiltyPrinceBFS(Cell start) {
    queue < Cell > q;
    visited[start.row][start.col] = true;
    q.push(start);
    int count = 1;
    while (!q.empty()) {
        Cell u = q.front();
        q.pop();
        // xet 4 huong
        for (int i = 0; i < 4; i++) {
            int r = u.row + dr[i];
            int c = u.col + dc[i];
            if (isCellValid(r, c) && !visited[r][c] && map[r][c] == '.' ) {
                count++;
                visited[r][c] = true;

                Cell temp;
                temp.row = r;
                temp.col = c;
                q.push( temp);
            }
        }
    }
    return count;
}

int main() {
    int Q;
    cin >> Q;
    Cell start;
    int k = 0;
    while(Q--) {
        k++;
        cin >> num_col >> num_row  ;
        for (int i = 0; i < num_row; i++) {
            for (int j = 0; j < num_col; j++) {
                cin >> map[i][j];
                visited[i][j] = false;
                if (map[i][j] == '@') {
                    start.row = i;
                    start.col = j;
                }
            }
        }
        cout <<"Case " << k << ": " << GuiltyPrinceBFS(start) << endl;
    }
    // chay BFS tu vi tri start
    system("pause");
    return 0;
}
