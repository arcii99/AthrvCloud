//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void print_board(int board[ROWS][COLS], int called_numbers[]) {
    printf("\nBINGO BOARD\n");
    printf("-------------------\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == -1)
                printf(" X ");
            else
                printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("-------------------\n");
    printf("Called Numbers: ");
    for(int i=0; i<75; i++) {
        if(called_numbers[i] != -1)
            printf("%d ", called_numbers[i]);
    }
    printf("\n");
}

int check_win(int board[ROWS][COLS]) {
    //check rows
    for(int i=0; i<ROWS; i++) {
        int count = 0;
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == -1)
                count++;
        }
        if(count == ROWS)
            return 1;
    }
    //check columns
    for(int i=0; i<COLS; i++) {
        int count = 0;
        for(int j=0; j<ROWS; j++) {
            if(board[j][i] == -1)
                count++;
        }
        if(count == COLS)
            return 1;
    }
    //check diagonals
    int count = 0;
    for(int i=0; i<ROWS; i++) {
        if(board[i][i] == -1)
            count++;
    }
    if(count == ROWS) return 1;

    count = 0;
    for(int i=0; i<ROWS; i++) {
        if(board[i][ROWS-i-1] == -1)
            count++;
    }
    if(count == ROWS) return 1;

    return 0;
}

int main() {
    int board[ROWS][COLS];
    int called_numbers[75];
    srand(time(NULL));

    //initialize board
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = 0;
        }
    }
    //initialize called_numbers
    for(int i=0; i<75; i++) {
        called_numbers[i] = -1;
    }

    while(1) {
        //print board
        print_board(board, called_numbers);

        //check win
        if(check_win(board)) {
            printf("\nBINGO!\n");
            break;
        }

        //generate random number
        int num = rand() % 75 + 1;
        int already_called = 0;
        for(int i=0; i<75; i++) {
            if(called_numbers[i] == num) {
                already_called = 1;
                break;
            }
        }
        if(!already_called) {
            //mark number on board
            for(int i=0; i<ROWS; i++) {
                for(int j=0; j<COLS; j++) {
                    if(board[i][j] == num)
                        board[i][j] = -1;
                }
            }
            //add called number to called_numbers array
            for(int i=0; i<75; i++) {
                if(called_numbers[i] == -1) {
                    called_numbers[i] = num;
                    break;
                }
            }
        }
    }

    return 0;
}