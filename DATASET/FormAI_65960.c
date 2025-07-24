//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_MINES 10

void init_board(int board[][BOARD_SIZE], int hidden[][BOARD_SIZE]) {
    srand(time(NULL));

    // Initialize board to have all 0's
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // Randomly place mines on the board
    int count = 0;
    while (count < NUM_MINES) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;

        if (board[x][y] == 0) {
            board[x][y] = -1;
            count++;
        }
    }

    // Calculate number of adjacent mines for each cell
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == -1) {
                continue;
            }

            int num_adjacent_mines = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i + k < 0 || i + k >= BOARD_SIZE || j + l < 0 || j + l >= BOARD_SIZE) {
                        continue;
                    }

                    if (board[i + k][j + l] == -1) {
                        num_adjacent_mines++;
                    }
                }
            }

            board[i][j] = num_adjacent_mines;
            hidden[i][j] = 1;
        }
    }
}

void print_board(int board[][BOARD_SIZE], int hidden[][BOARD_SIZE]) {
    printf("\n");
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }

    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);

        for (int j = 0; j < BOARD_SIZE; j++) {
            if (hidden[i][j]) {
                printf("# ");
            } else if (board[i][j] == -1) {
                printf("* ");
            } else {
                printf("%d ", board[i][j]);
            }
        }

        printf("\n");
    }

    printf("\n");
}

void reveal_cell(int board[][BOARD_SIZE], int hidden[][BOARD_SIZE], int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE || !hidden[x][y]) {
        return;
    }

    hidden[x][y] = 0;

    if (board[x][y] == -1) {
        return;
    }

    if (board[x][y] == 0) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                reveal_cell(board, hidden, x + i, y + j);
            }
        }
    }
}

int check_win(int hidden[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (hidden[i][j]) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int hidden[BOARD_SIZE][BOARD_SIZE];

    init_board(board, hidden);
    print_board(board, hidden);

    while (1) {
        int x, y;

        printf("Enter row and column to reveal: ");
        scanf("%d %d", &x, &y);

        reveal_cell(board, hidden, x, y);
        print_board(board, hidden);

        if (board[x][y] == -1) {
            printf("You have hit a mine. Game over!\n");
            break;
        }

        if (check_win(hidden)) {
            printf("Congratulations, you have won!\n");
            break;
        }
    }

    return 0;
}