//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: interoperable
#include <stdio.h>
#define ROW 5
#define COL 5
 
int map[ROW][COL]={
 {0,0,0,0,0},
 {0,1,0,1,0},
 {0,1,0,1,0},
 {0,1,0,1,0},
 {0,0,0,0,0}
};
 
int visited[ROW][COL]= {0};
int solution[ROW][COL] = {0};
int flag = 0;
 
void printSolution(){
    printf("The maze solution is:\n");
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            printf("%d ",solution[i][j]);
        }
        printf("\n");
    }
}
 
void traverse(int row,int col){
    int row_mv[4] = {0,0,1,-1};
    int col_mv[4] = {1,-1,0,0};
    if(row==ROW-1 && col==COL-1){
        flag = 1;
        solution[row][col] = 1;
        return;
    }
    for(int i=0;i<4;i++){
        int new_row = row+row_mv[i];
        int new_col = col+col_mv[i];
        if(new_row >= 0 && new_row < ROW && new_col >=0 && new_col < COL){
            if(map[new_row][new_col] == 0 && visited[new_row][new_col] == 0){
                visited[new_row][new_col] = 1;
                solution[new_row][new_col] = 1;
                traverse(new_row,new_col);
                if(flag == 1){
                    return;
                }
                else{
                    solution[new_row][new_col] = 0;
                }
            }
        }
    }
}
 
int main(){
    printf("The maze is:\n");
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    visited[0][0] = 1;
    solution[0][0] = 1;
    traverse(0,0);
    if(flag == 1){
        printSolution();
    }
    else{
        printf("No path exists.\n");
    }
    return 0;
}