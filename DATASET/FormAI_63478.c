//FormAI DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

typedef struct {
    int row;
    int col;
} Position;

void create_board(int board[][BOARD_SIZE]) {
    int i, j;
    int num_pairs = BOARD_SIZE * BOARD_SIZE / 2;
    int nums[num_pairs];

    // generate random pairs of numbers
    for (i = 0; i < num_pairs; i++) {
        nums[i] = i + 1;
    }

    // shuffle numbers
    for (i = num_pairs - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // place numbers on board in pairs
    int k = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = nums[k];
            k = (k + 1) % num_pairs;
        }
    }
}

void print_board(int board[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("[%2d]", board[i][j]);
        }
        printf("\n");
    }
}

void get_position(Position *pos) {
    printf("Enter row and column (e.g. 0 2): ");
    scanf("%d%d", &pos->row, &pos->col);
}

void reveal(int board[][BOARD_SIZE], Position pos) {
    if (board[pos.row][pos.col] == 0) {
        printf("Already revealed!\n");
        return;
    }
    printf("%d\n", board[pos.row][pos.col]);
    board[pos.row][pos.col] = 0;
}

int check_win(int board[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));

    int board[BOARD_SIZE][BOARD_SIZE];
    create_board(board);

    int found_pairs = 0;

    while (!check_win(board)) {
        printf("Pairs found: %d\n", found_pairs);
        print_board(board);
        
        Position pos1, pos2;
        printf("First position\n");
        get_position(&pos1);
        reveal(board, pos1);
        print_board(board);

        printf("Second position\n");
        get_position(&pos2);
        reveal(board, pos2);
        print_board(board);

        if (board[pos1.row][pos1.col] == board[pos2.row][pos2.col]) {
            printf("Found a pair!\n");
            found_pairs++;
        }
        else {
            printf("Not a pair, try again!\n");
            board[pos1.row][pos1.col] = board[pos2.row][pos2.col];
        }
    }

    printf("Congratulations, you won!\n");
    return 0;
}