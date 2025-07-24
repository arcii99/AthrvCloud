//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 5
#define COLS 5

int board[ROWS][COLS];
int score;

void init_board(){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            board[i][j] = rand()%100;
        }
    }
}

void print_board(){
    printf("---------THE BOARD---------\n");
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
    printf("---------------------------\n");
}

void play(){
    int choice = 0;
    int row, col;
    printf("Enter the row and column of the element you want to remove: ");
    scanf("%d%d", &row, &col);
    if(row >= ROWS || col >= COLS){
        printf("Enter valid row and column!\n");
        play();
        return;
    }
    score += board[row][col];
    board[row][col] = -1;
    printf("Score: %d\n\n", score);
}

int main(){
    srand(time(NULL));
    init_board();
    print_board();
    while(1){
        play();
        print_board();
    }
}