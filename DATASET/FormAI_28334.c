//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define BOARD_SIZE 5
#define MAX_NUM 75

int is_duplicate(int num, int *board, int current_ball) {
    for (int i = 0; i < current_ball; i++) {
        if (num == board[i]) {
            return 1;
        }
    }
    return 0;
}

void print_board(int *board, int current_ball) {
    for (int i = 0; i < current_ball; i++) {
        printf("%d ", board[i]);
        if ((i+1) % BOARD_SIZE == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // set random seed
    int *board = (int*) malloc(BOARD_SIZE * BOARD_SIZE * sizeof(int));
    int current_ball = 0;
    while (current_ball < BOARD_SIZE * BOARD_SIZE) {
        int new_ball = rand() % MAX_NUM + 1; // generate a random number between 1-75
        if (!is_duplicate(new_ball, board, current_ball)) { // check for duplicates
            board[current_ball++] = new_ball;
            print_board(board, current_ball); // print the board after each new ball
        }
    }
    free(board); // free memory
    return 0;
}