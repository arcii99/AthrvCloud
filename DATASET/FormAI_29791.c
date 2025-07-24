//FormAI DATASET v1.0 Category: Checkers Game ; Style: beginner-friendly
#include <stdio.h>

// Global Variables

#define ROW 8
#define COL 8

char board[ROW][COL] = {
    {'#', ' ', '#', ' ', '#', ' ', '#', ' '},
    {' ', '#', ' ', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', ' '},
    {' ', '#', ' ', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', ' '},
    {' ', '#', ' ', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', ' '},
    {' ', '#', ' ', '#', ' ', '#', ' ', '#'}
};

int turn = 0; // 0 means 'O', 1 means 'X'

int main() {
    printf("Welcome to Checkers Game in C!\n");
    printf("================================\n\n");
    printf("Player 1: O\n");
    printf("Player 2: X\n\n");
    printf("Game starts!\n\n");
    print_board();

    int move_valid = 1;
    while (!check_win() && move_valid) { // game loop
        int from_row = -1, from_col = -1, to_row = -1, to_col = -1;
        printf("Player %d turn:\n", turn + 1);
        printf("Enter row and column to move from (e.g. 2 3): ");
        scanf("%d %d", &from_row, &from_col);
        printf("Enter row and column to move to (e.g. 3 4): ");
        scanf("%d %d", &to_row, &to_col);

        move_valid = make_move(from_row, from_col, to_row, to_col);
        if (!move_valid) {
            printf("\nInvalid move! Please try again.\n\n");
        } else {
            turn = 1 - turn; // switch turn
            print_board();
            printf("\n");
        }
    }

    if (turn == 0) {
        printf("Player 2 (X) wins!\n");
    } else {
        printf("Player 1 (O) wins!\n");
    }

    return 0;

}

int check_win() {
    int count_X = 0, count_O = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (board[i][j] == 'X') {
                count_X += 1;
            } else if (board[i][j] == 'O') {
                count_O += 1;
            }
        }
    }
    return count_X == 0 || count_O == 0;
}

int make_move(int from_row, int from_col, int to_row, int to_col) {
    if (out_of_bounds(from_row, from_col) || out_of_bounds(to_row, to_col)) {
        return 0;
    }
    if (board[from_row][from_col] == ' ') {
        return 0;
    }
    if ((turn == 0 && board[from_row][from_col] == 'X') || (turn == 1 && board[from_row][from_col] == 'O')) {
        return 0;
    }
    if (board[to_row][to_col] != ' ') {
        return 0;
    }
    int dx = (from_row < to_row) ? 1 : -1;
    int dy = (from_col < to_col) ? 1 : -1;
    if (abs(from_row - to_row) == 2 && abs(from_col - to_col) == 2) { // check for a jump move
        if (turn == 0 && board[from_row+dx][from_col+dy] == 'X') {
            board[from_row][from_col] = ' ';
            board[from_row+dx][from_col+dy] = ' ';
            board[to_row][to_col] = 'O';
            return 1;
        }
        if (turn == 1 && board[from_row+dx][from_col+dy] == 'O') {
            board[from_row][from_col] = ' ';
            board[from_row+dx][from_col+dy] = ' ';
            board[to_row][to_col] = 'X';
            return 1;
        }
        return 0;
    } else if (abs(from_row - to_row) == 1 && abs(from_col - to_col) == 1) { // check for a normal move
        if (turn == 0 && from_row - to_row == 1 && board[to_row][to_col] == ' ') { // white can only move up
            board[from_row][from_col] = ' ';
            board[to_row][to_col] = 'O';
            if (to_row == 0) { // check if 'O' reaches the first row and becomes a king
                board[to_row][to_col] = 'o';
            }
            return 1;
        } else if (turn == 1 && from_row - to_row == -1 && board[to_row][to_col] == ' ') { // black can only move down
            board[from_row][from_col] = ' ';
            board[to_row][to_col] = 'X';
            if (to_row == ROW-1) { // check if 'X' reaches the last row and becomes a king
                board[to_row][to_col] = 'x';
            }
            return 1;
        }
        return 0;
    }
    return 0;
}

void print_board() {
    printf("\n     0    1    2    3    4    5    6    7  \n");
    printf("  ========================================\n");
    for (int i = 0; i < ROW; i++) {
        printf("%d ", i);
        for (int j = 0; j < COL; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printf("  ========================================\n");
    }
}

int out_of_bounds(int row, int col) {
    return row < 0 || row >= ROW || col < 0 || col >= COL;
}