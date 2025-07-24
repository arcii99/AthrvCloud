//FormAI DATASET v1.0 Category: Game ; Style: dynamic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

typedef enum {EMPTY, SHIP, HIT, MISS} state_t;

bool is_valid_ship_location(state_t board[ROW][COL], int row, int col, int size, bool is_horizontal) {
    if (is_horizontal) {
        if (col + size > COL) {
            return false;
        }
        for (int i = col; i < col + size; i++) {
            if (board[row][i] != EMPTY) {
                return false;
            }
        }
    } else {
        if (row + size > ROW) {
            return false;
        }
        for (int i = row; i < row + size; i++) {
            if (board[i][col] != EMPTY) {
                return false;
            }
        }
    }
    return true;
}

void place_ship(state_t board[ROW][COL], int size) {
    bool is_horizontal = (rand() % 2 == 0) ? true : false;
    int row, col;
    do {
        if (is_horizontal) {
            row = rand() % ROW;
            col = rand() % (COL - size);
        } else {
            row = rand() % (ROW - size);
            col = rand() % COL;
        }
    } while (!is_valid_ship_location(board, row, col, size, is_horizontal));
    for (int i = 0; i < size; i++) {
        if (is_horizontal) {
            board[row][col + i] = SHIP;
        } else {
            board[row + i][col] = SHIP;
        }
    }
}

void init_board(state_t board[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            board[i][j] = EMPTY;
        }
    }
    srand(time(NULL));
    place_ship(board, 5);   // place battleship of size 5
    place_ship(board, 4);   // place cruiser of size 4
    place_ship(board, 3);   // place destroyer of size 3
    place_ship(board, 3);   // place submarine of size 3
    place_ship(board, 2);   // place patrol boat of size 2
}

void print_board(state_t board[ROW][COL], bool show_ship) {
    printf("  ");
    for (int i = 0; i < COL; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < ROW; i++) {
        printf("%c ", i + 'A');
        for (int j = 0; j < COL; j++) {
            if (show_ship) {
                if (board[i][j] == SHIP) {
                    printf("O ");
                } else if (board[i][j] == HIT) {
                    printf("X ");
                } else if (board[i][j] == MISS) {
                    printf(". ");
                } else {
                    printf("  ");
                }
            } else {
                if (board[i][j] == HIT || board[i][j] == MISS) {
                    printf("%c ", board[i][j]);
                } else {
                    printf("  ");
                }
            }
        }
        printf("\n");
    }
}

bool is_win(state_t board[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (board[i][j] == SHIP) {
                return false;
            }
        }
    }
    return true;
}

void play_game(state_t board[ROW][COL]) {
    int row, col;
    do {
        print_board(board, false);
        printf("Enter row and column (e.g. A5): ");
        char input[10];
        scanf("%s", input);
        row = input[0] - 'A';
        col = input[1] - '0';
        if (board[row][col] == HIT || board[row][col] == MISS) {
            printf("You have already guessed that spot\n");
        }
    } while (board[row][col] == HIT || board[row][col] == MISS);
    if (board[row][col] == SHIP) {
        board[row][col] = HIT;
        printf("Hit!");
    } else {
        board[row][col] = MISS;
        printf("Miss!");
    }
}

int main(void) {
    state_t board[ROW][COL];
    init_board(board);
    while (!is_win(board)) {
        play_game(board);
    }
    print_board(board, true);
    printf("Congratulations! You won!\n");
    return 0;
}