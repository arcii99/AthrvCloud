//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define TOTAL_MINES 10

int board[BOARD_SIZE][BOARD_SIZE];
int revealed_board[BOARD_SIZE][BOARD_SIZE];
int num_mines_found = 0;

void initialize_board() {
    int mines_placed = 0;
    srand(time(NULL));

    while (mines_placed < TOTAL_MINES) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;

        if (board[x][y] == 0) {
            board[x][y] = -1;
            mines_placed++;
        }
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != -1) {
                // Count the number of neighboring mines
                int count = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int nx = i + dx;
                        int ny = j + dy;
                        if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && board[nx][ny] == -1) {
                            count++;
                        }
                    }
                }

                board[i][j] = count;
            }
        }
    }
}

void print_board() {
    printf("   ");
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    printf("  +");
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("---");
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d|", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed_board[i][j]) {
                if (board[i][j] == -1) {
                    printf(" * ");
                } else {
                    printf(" %d ", board[i][j]);
                }
            } else {
                printf(" . ");
            }
        }
        printf("|\n");
    }

    printf("  +");
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("---");
    }
    printf("\n");
}

void reveal(int x, int y) {
    if (board[x][y] == -1) {
        printf("Game over! You hit a mine.\n");
        exit(0);
    } else if (revealed_board[x][y]) {
        return;
    } else {
        revealed_board[x][y] = 1;
        if (board[x][y] == 0) {
            // Recursively reveal neighboring cells
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE) {
                        reveal(nx, ny);
                    }
                }
            }
        } else {
            num_mines_found++;
        }

        if (num_mines_found == TOTAL_MINES) {
            printf("Congratulations! You won the game!\n");
            exit(0);
        }
    }
}

int main() {
    initialize_board();

    printf("Welcome to Minesweeper!\n");
    printf("=======================\n");
    printf("Rules:\n");
    printf("* You will be presented with a board of 10x10 cells.\n");
    printf("* You have to reveal all non-mine cells in order to win the game.\n");
    printf("* You can reveal a cell by typing its x and y coordinates.\n");
    printf("* Good luck!\n");
    printf("=======================\n");

    while (1) {
        print_board();
        int x, y;
        printf("Enter x and y: ");
        scanf("%d %d", &x, &y);

        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
            reveal(x, y);
        } else {
            printf("Invalid coordinates. Please try again.\n");
        }
    }

    return 0;
}