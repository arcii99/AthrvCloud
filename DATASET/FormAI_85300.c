//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define MAX_NUM 25

void init_board(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void print_board(int board[SIZE][SIZE]) {
    printf("Bingo Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

bool is_game_over(int board[SIZE][SIZE]) {
    bool is_full = true;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                is_full = false;
                break;
            }
        }
    }
    return is_full;
}

bool is_bingo(int board[SIZE][SIZE]) {
    bool bingo = false;
    int i, j, count;

    for (i = 0; i < SIZE; i++) {
        count = 0;
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 0)
                count++;
        }
        if (count == SIZE)
            bingo = true;
    }

    for (j = 0; j < SIZE; j++) {
        count = 0;
        for (i = 0; i < SIZE; i++) {
            if (board[i][j] == 0)
                count++;
        }
        if (count == SIZE)
            bingo = true;
    }

    count = 0;
    for (i = 0, j = 0; i < SIZE && j < SIZE; i++, j++) {
        if (board[i][j] == 0)
            count++;
    }
    if (count == SIZE)
        bingo = true;

    count = 0;
    for (i = 0, j = SIZE - 1; i < SIZE && j >= 0; i++, j--) {
        if (board[i][j] == 0)
            count++;
    }
    if (count == SIZE)
        bingo = true;
    
    return bingo;
}

int main() {
    int board[SIZE][SIZE], num, row, col;
    bool already_called[MAX_NUM + 1] = {false};
    srand(time(NULL));
  
    init_board(board);
    while (true) {
        num = rand() % MAX_NUM + 1;
        if (!already_called[num]) {
            already_called[num] = true;
            printf("Number called: %d\n", num);
            for (row = 0; row < SIZE; row++) {
                for (col = 0; col < SIZE; col++) {
                    if (board[row][col] == num) {
                        board[row][col] = 0;
                        break;
                    }
                }
            }
            if (is_bingo(board)) {
                printf("Bingo!\n");
                break;
            }
            if (is_game_over(board)) {
                printf("Game over: All numbers called!\n");
                break;
            }
        }
    }
    print_board(board);
    return 0;
}