//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#define ROW 10
#define COL 15
#define UNVISITED -1
#define OBSTACLE 1
#define VISITED 2
#define PATH 3
#define START_ROW 3
#define START_COL 3
#define GOAL_ROW 8
#define GOAL_COL 12

void init_map(int map[ROW][COL]){
    int i,j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            if(i==0 || i==ROW-1 || j==0 || j==COL-1 || (i==3 && j>=4)){
                map[i][j]=OBSTACLE;
            }else{
                map[i][j]=UNVISITED;
            }
        }
    }
    map[START_ROW][START_COL]=VISITED;                                         map[START_ROW][START_COL+1]=PATH;
    map[START_ROW][START_COL+2]=VISITED;                                       map[START_ROW][START_COL+3]=VISITED;                                    
    map[GOAL_ROW][GOAL_COL]=VISITED;                                           map[GOAL_ROW-1][GOAL_COL]=PATH;
    map[GOAL_ROW-2][GOAL_COL]=VISITED;                                         map[GOAL_ROW-3][GOAL_COL]=VISITED;
}

void print_map(int map[ROW][COL]){
    int i,j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            switch(map[i][j]){
                case UNVISITED:
                    printf(" ");
                    break;
                case VISITED:
                    printf(".");
                    break;
                case OBSTACLE:
                    printf("X");
                    break;
                case PATH:
                    printf("*");
                    break;
            }
        }
        printf("\n");
    }
}

int main(){
    int map[ROW][COL];
    init_map(map);
    printf("=======MAP==========\n");
    print_map(map);
    printf("====================\n");
    int curr_row=START_ROW, curr_col=START_COL+2;
    int target_row=GOAL_ROW-2, target_col=GOAL_COL;
    while(1){
        if(curr_row==target_row && curr_col==target_col){
            break;
        }
        int next_row, next_col;
        if(curr_row<target_row){
            next_row=curr_row+1;
        }else if(curr_row>target_row){
            next_row=curr_row-1;
        }else{
            next_row=curr_row;
        }
        if(curr_col<target_col){
            next_col=curr_col+1;
        }else if(curr_col>target_col){
            next_col=curr_col-1;
        }else{
            next_col=curr_col;
        }
        if(map[next_row][next_col]==UNVISITED){
            map[next_row][next_col]=VISITED;
            map[curr_row][curr_col+1]=PATH;
            curr_row=next_row;
            curr_col=next_col;
        }
        printf("=======MAP==========\n");
        print_map(map);
        printf("====================\n");
        printf("Press enter to continue...");
        getchar();
    }
    printf("Path found!\n");
    print_map(map);
    return 0;
}