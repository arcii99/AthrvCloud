//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10

int board[ROWS][COLS];

void initialize_board() {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            board[i][j] = 0;
        }
    }
}

void print_board() {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int random_number(int min_num, int max_num) {
    int result = 0, low_num = 0, hi_num = 0;
    if (min_num < max_num) {
        low_num = min_num;
        hi_num = max_num + 1;
    } else {
        low_num = max_num + 1;
        hi_num = min_num;
    }
    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

void add_invader() {
    int row = random_number(0, ROWS-1);
    int col = random_number(0, COLS-1);
    board[row][col] = 1;
}

int get_input() {
    int input;
    printf("Enter a column number to shoot: ");
    scanf("%d", &input);
    return input;
}

void update_board(int col) {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if (board[i][j] == 1 && j == col) {
                board[i][j] = 0;
                printf("You hit an invader!\n");
            }
            if (board[i][j] == 1 && i == ROWS-1) {
                printf("Game Over!\n");
                exit(0);
            }
        }
    }
}

int main() {
    initialize_board();
    while(1) {
        print_board();
        add_invader();
        int col = get_input();
        update_board(col);
    }
    return 0;
}