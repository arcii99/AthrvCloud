//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 8
#define COLUMNS 8

void print_board(int board[][COLUMNS], int bombs[][COLUMNS], int revealed[][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (revealed[i][j]) {
                printf("%d ", board[i][j]);
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

int count_adjacent_bombs(int x, int y, int bombs[][COLUMNS]) {
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLUMNS && bombs[i][j]) {
                count++;
            }
        }
    }
    return count;
}

void reveal_zeroes(int x, int y, int board[][COLUMNS], int bombs[][COLUMNS], int revealed[][COLUMNS]) {
    revealed[x][y] = 1;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLUMNS
                    && !bombs[i][j] && !revealed[i][j]) {
                int adjacent_bombs = count_adjacent_bombs(i, j, bombs);
                revealed[i][j] = 1;
                if (adjacent_bombs == 0) {
                    reveal_zeroes(i, j, board, bombs, revealed);
                }
            }
        }
    }
}

int main() {
    int board[ROWS][COLUMNS];
    int bombs[ROWS][COLUMNS];
    int revealed[ROWS][COLUMNS];
    srand(time(NULL));
    int num_bombs = 0;
    while (num_bombs < 10) {
        int x = rand() % ROWS;
        int y = rand() % COLUMNS;
        if (!bombs[x][y]) {
            bombs[x][y] = 1;
            num_bombs++;
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (bombs[i][j]) {
                board[i][j] = -1;
            } else {
                board[i][j] = count_adjacent_bombs(i, j, bombs);
            }
            revealed[i][j] = 0;
        }
    }
    while (1) {
        print_board(board, bombs, revealed);
        int x, y;
        printf("Enter row and column (e.g. 3 4) or -1 to quit: ");
        scanf("%d", &x);
        if (x == -1) {
            printf("Quitting...\n");
            break;
        }
        scanf("%d", &y);
        if (bombs[x][y]) {
            printf("You hit a bomb and lost!\n");
            print_board(board, bombs, bombs);
            break;
        }
        if (board[x][y] == 0) {
            reveal_zeroes(x, y, board, bombs, revealed);
        } else {
            revealed[x][y] = 1;
        }
        int num_revealed = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (revealed[i][j]) {
                    num_revealed++;
                }
            }
        }
        if (num_revealed == ROWS*COLUMNS - num_bombs) {
            printf("You won!\n");
            break;
        }
    }
    return 0;
}