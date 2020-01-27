//
//  Validate The Maze  Validate The Maze  Validate The Maze.cpp
//  LearnAlgorithmnCPlusPlus
//
//  Created by NguyenTanThien on 1/27/20.
//  Copyright © 2020 NguyenTanThien. All rights reserved.
//

/*
 Validate The Maze

 There are many algorithms to generate maze (Maze Generation Algorithm). After generating the maze we’ve to validate whether it’s a valid maze or not. A valid maze has exactly one entry point and exactly one exit point (exactly 2 openings in the edges) and there must be atleast one path from the entry point to exit point.

 Given a maze, just find whether the maze is " valid" or "invalid".

 Input

 The first line consists of an integer T, the number of test cases. Then for each test case, the first line consists of two integers M and N, the number of rows and columns in the maze. Then contains the description of the matrix M of order. M[i][j]= '#' represents a wall and M[i][j]= '.' represents a space.

 Constraints:

 1≤T≤10000

 1≤M≤20

 1≤N≤20
 Output

 For each test case find whether the maze is " valid" or " invalid".
 
 6
 4 4
 ####
 #...
 #.##
 #.##
 5 5
 #.###
 #..##
 ##..#
 #.#.#
 ###.#
 1 1
 .
 5 1
 #
 #
 .
 .
 #
 2 2
 #.
 .#
 3 4
 #..#
 #.##
 #.##
 
 valid
 valid
 invalid
 valid
 invalid
 invalid

 
 */

#include<algorithm>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
#define MAX 21
string maze[MAX];
struct Cell{
    int row,col;
};

int num_row, num_col;
bool isValid(int r, int c){
    return r>=0 && r <num_row && c >=0 && c<num_col;
}

const int dr[]={0,0,1,-1};
const int dc[]={1,-1,0,0};
bool visited[MAX][MAX];
bool BFS(Cell start, Cell end){
    queue<Cell> q;
    visited[start.row][start.col] = true;
    q.push(start);
    while (!q.empty()){
        Cell u = q.front();
        q.pop();
        
        // chay toi khi nao gap cell end thi return true
        if (u.row ==end.row && u.col== end.col){
            return true;
        }
        
        //BFS binh thuong thi khong co vong lap nay nhung vi minh dang xet 4 dinh o xung quanh (4 huong nen lap 4 lan)
        for(int i=0;i<4;i++){
            int r = u.row +dr[i];
            int c = u.col +dc[i];
            if (!visited[r][c] && maze[r][c]=='.' && isValid(r, c)){
                visited[r][c] = true;
                q.push({r,c});
            }
        }
    }
    return false;
}
int main(){
    int Q;
    cin >> Q;
    while (Q--){
        cin >> num_row >> num_col;
        for(int i=0;i<num_row;i++){
            cin >> maze[i];
        }
        vector<Cell> entrance;
        for(int i=0;i<num_row;i++){
            for(int j=0;j<num_col;j++){
                visited[i][j] = false;
                if (maze[i][j]=='.' && (i==0 || i== num_row-1 || j==0 || j== num_col-1)){
                    entrance.push_back({i,j});
                }
            }
        }
        if(entrance.size()!=2){
            cout << "invalid" << endl;
        }
        else {
            Cell start1=entrance[0];
            Cell start2=entrance[1];
            if (BFS(start1, start2)){
                cout << "valid" <<endl;
            }else{
                cout << "invalid" << endl;
            }
        }
    }
    system("pause");
    return 0;
}


