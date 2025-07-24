//FormAI DATASET v1.0 Category: Chess engine ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 8

char board[N][N];   //chess board
int movement[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};   //all possible movement of the knight
int visited[N][N];   //visited array to mark visited positions
int count_visited=0;   //counter to count total visited positions
int final_destination[2];   //final destination row and column

void init_board(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j]='-';
            visited[i][j]=0;
        }
    }
}

void print_board(){
    printf("  ");
    for(int i=0;i<N;i++){
        printf("%d ", i);
    }
    printf("\n");
    for(int i=0;i<N;i++){
        printf("%d ", i);
        for(int j=0;j<N;j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int i, int j){
    if(i<0 || i>=N || j<0 || j>=N){
        return 0;
    }
    if(visited[i][j]==1){
        return 0;
    }
    return 1;
}

int knight_tour(int row, int col, int move_no){
    if(move_no==N*N){   //all positions visited
        if(row==final_destination[0] && col==final_destination[1]){
            return 1;
        }
        return 0;
    }
    for(int i=0;i<8;i++){
        int next_row=row+movement[i][0];
        int next_col=col+movement[i][1];
        if(is_valid_move(next_row,next_col)==1){
            visited[next_row][next_col]=1;
            board[next_row][next_col]=move_no+1+'0';
            count_visited++;
            if(knight_tour(next_row,next_col,move_no+1)==1){
                return 1;
            }
            visited[next_row][next_col]=0;
            board[next_row][next_col]='-';
            count_visited--;
        }
    }
    return 0;
}

int main(){
    srand(time(0));
    init_board();
    //pick a random starting position
    int start_row=rand()%N;
    int start_col=rand()%N;
    printf("Starting position: (%d,%d)\n", start_row, start_col);
    visited[start_row][start_col]=1;
    board[start_row][start_col]='1';
    count_visited=1;
    //pick a random final destination
    final_destination[0]=rand()%N;
    final_destination[1]=rand()%N;
    printf("Final destination: (%d,%d)\n", final_destination[0], final_destination[1]);
    if(knight_tour(start_row,start_col,1)==1){
        printf("Knight successfully visited all positions!\n");
    }
    else{
        printf("Knight was unable to visit all positions.\n");
    }
    printf("Total positions visited: %d\n", count_visited);
    print_board();
    return 0;
}