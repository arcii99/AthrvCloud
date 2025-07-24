//FormAI DATASET v1.0 Category: Memory Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define MAX_VALUE 5

int board[BOARD_SIZE][BOARD_SIZE];
int uncovered[BOARD_SIZE][BOARD_SIZE];

void init_board();
void print_board();
void uncover(int x, int y);
int check_win();

int main() {
    int x, y, matches = 0, max_matches = BOARD_SIZE * BOARD_SIZE / 2;
    srand(time(NULL));

    init_board();

    while (matches < max_matches) {
        print_board();

        // Get user input
        printf("Select a cell to uncover (row column): ");
        scanf("%d %d", &x, &y);

        if (x > BOARD_SIZE || y > BOARD_SIZE || uncovered[x][y]) {
            printf("Invalid selection, try again.\n");
            continue;
        }

        uncover(x, y);

        if (board[x][y] == -1) {
            printf("Game Over!\n");
            break;
        } else if (check_win()) {
            printf("You win!\n");
            break;
        }

        if (matches % 2 == 1 && board[x][y] != board[uncovered[x][y]][uncovered[y][x]]) {
            uncover(uncovered[x][y], uncovered[y][x]);
        } else {
            uncovered[x][y] = x;
            uncovered[y][x] = y;
        }
        
        matches++;
    }

    return 0;
}

void init_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = -1;
            uncovered[i][j] = 0;
        }
    }

    for (i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; i++) {
        int value = rand() % MAX_VALUE;
        int count = 0;

        while (count < 2) {
            int x = rand() % BOARD_SIZE;
            int y = rand() % BOARD_SIZE;

            if (board[x][y] == -1) {
                board[x][y] = value;
                count++;
            }
        }
    }
}

void print_board() {
    int i, j;
    printf("\n");
    printf("   ");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%2d", i);
    }

    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (uncovered[i][j]) {
                printf("%2d", board[i][j]);
            } else {
                printf(" *");
            }
        }
        printf("\n");
    }
}

void uncover(int x, int y) {
    uncovered[x][y] = 1;
}

int check_win() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (!uncovered[i][j]) {
                return 0;
            }
        }
    }

    return 1;
}