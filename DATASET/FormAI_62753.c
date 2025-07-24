//FormAI DATASET v1.0 Category: Game of Life ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 60

void init_board(int board[][COLS]){
    srand(time(NULL));
    int i, j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[][COLS]){
    int i, j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            if(board[i][j] == 1){
                printf("O ");
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int board[][COLS], int row, int col){
    int count = 0;
    int i, j;
    for(i = -1; i <= 1; i++){
        for(j = -1; j <= 1; j++){
            if(i == 0 && j == 0){
                continue;
            }
            int r = row + i;
            int c = col + j;
            if(r < 0 || r >= ROWS || c < 0 || c >= COLS){
                continue;
            }
            if(board[r][c] == 1){
                count++;
            }
        }
    }
    return count;
}

void update_board(int board[][COLS]){
    int new_board[ROWS][COLS];
    int i, j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            int neighbors = count_neighbors(board, i, j);
            if(board[i][j] == 1){
                if(neighbors < 2 || neighbors > 3){
                    new_board[i][j] = 0;
                }
                else{
                    new_board[i][j] = 1;
                }
            }
            else{
                if(neighbors == 3){
                    new_board[i][j] = 1;
                }
                else{
                    new_board[i][j] = 0;
                }
            }
        }
    }
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            board[i][j] = new_board[i][j];
        }
    }
}

int main(){
    printf("Welcome to the cheery Game of Life! Let's get started!\n");

    int board[ROWS][COLS];

    init_board(board);

    while(1){
        printf("Current board:\n");
        print_board(board);
        update_board(board);
        printf("Press Enter to continue or type 'quit' to end the game.\n");
        char c = getchar();
        if(c == 'q' || c == 'Q'){
            break;
        }
    }

    printf("Thanks for playing! Have a great day!\n");

    return 0;
}