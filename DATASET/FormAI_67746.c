//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int board[ROWS][COLS];

void init_board() {
    //Initialize board with random numbers
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = rand() % 10;
        }
    }
}

void print_board() {
    //Print the current state of the board
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win() {
    //Check if the game has been won
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void shift_left() {
    //Shift all numbers to the left
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(j == 0) {
                continue;
            }
            if(board[i][j-1] == 0) {
                board[i][j-1] = board[i][j];
                board[i][j] = 0;
            }
            else if(board[i][j-1] == board[i][j]) {
                board[i][j-1] *= 2;
                board[i][j] = 0;
            }
        }
    }
}

void shift_right() {
    //Shift all numbers to the right
    for(int i=0; i<ROWS; i++) {
        for(int j=COLS-1; j>=0; j--) {
            if(j == COLS - 1) {
                continue;
            }
            if(board[i][j+1] == 0) {
                board[i][j+1] = board[i][j];
                board[i][j] = 0;
            }
            else if(board[i][j+1] == board[i][j]) {
                board[i][j+1] *= 2;
                board[i][j] = 0;
            }
        }
    }
}

void shift_up() {
    //Shift all numbers up
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(i == 0) {
                continue;
            }
            if(board[i-1][j] == 0) {
                board[i-1][j] = board[i][j];
                board[i][j] = 0;
            }
            else if(board[i-1][j] == board[i][j]) {
                board[i-1][j] *= 2;
                board[i][j] = 0;
            }
        }
    }
}

void shift_down() {
    //Shift all numbers down
    for(int i=ROWS-1; i>=0; i--) {
        for(int j=0; j<COLS; j++) {
            if(i == ROWS - 1) {
                continue;
            }
            if(board[i+1][j] == 0) {
                board[i+1][j] = board[i][j];
                board[i][j] = 0;
            }
            else if(board[i+1][j] == board[i][j]) {
                board[i+1][j] *= 2;
                board[i][j] = 0;
            }
        }
    }
}

int main() {
    init_board();
    while(1) {
        print_board();
        if(check_win()) {
            printf("Congratulations! You win!\n");
            break;
        }
        char move = getchar();
        getchar(); //Consume newline character
        switch(move) {
            case 'a':
                shift_left();
                break;
            case 'd':
                shift_right();
                break;
            case 'w':
                shift_up();
                break;
            case 's':
                shift_down();
                break;
            default:
                printf("Invalid move\n");
        }
    }
    return 0;
}