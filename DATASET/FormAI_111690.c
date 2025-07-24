//FormAI DATASET v1.0 Category: Checkers Game ; Style: dynamic
#include <stdio.h>
#include <stdbool.h>

#define ROWS 8
#define COLUMNS 8

// The following code defines the board array and initializes it
char board[ROWS][COLUMNS] = {
    {'-', 'B', '-', 'B', '-', 'B', '-', 'B'},
    {'B', '-', 'B', '-', 'B', '-', 'B', '-'},
    {'-', 'B', '-', 'B', '-', 'B', '-', 'B'},
    {'-', '-', '-', '-', '-', '-', '-', '-'},
    {'-', '-', '-', '-', '-', '-', '-', '-'},
    {'R', '-', 'R', '-', 'R', '-', 'R', '-'},
    {'-', 'R', '-', 'R', '-', 'R', '-', 'R'},
    {'R', '-', 'R', '-', 'R', '-', 'R', '-'}
};

// The following function prints the current state of the board
void print_board() {
    printf("    A   B   C   D   E   F   G   H\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < COLUMNS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("| %d\n", i+1);
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
    printf("    A   B   C   D   E   F   G   H\n");
}

// The following function checks if a move is valid and returns true or false accordingly
bool is_valid_move(int from_row, int from_col, int to_row, int to_col, char player) {
    if (to_row < 0 || to_row >= ROWS || to_col < 0 || to_col >= COLUMNS) {
        return false;
    }
    if (board[to_row][to_col] != '-') {
        return false;
    }
    if (player == 'R') {
        if (from_row - to_row == 1 && abs(from_col - to_col) == 1) {
            return true;
        } else if (from_row - to_row == 2 && abs(from_col - to_col) == 2 
                   && board[(from_row + to_row)/2][(from_col + to_col)/2] == 'B') {
            board[(from_row + to_row)/2][(from_col + to_col)/2] = '-';
            return true;
        } else {
            return false;
        }
    } else {
        if (to_row - from_row == 1 && abs(from_col - to_col) == 1) {
            return true;
        } else if (to_row - from_row == 2 && abs(from_col - to_col) == 2 
                   && board[(from_row + to_row)/2][(from_col + to_col)/2] == 'R') {
            board[(from_row + to_row)/2][(from_col + to_col)/2] = '-';
            return true;
        } else {
            return false;
        }
    }
}

// The following function makes a move for a player
void make_move(int from_row, int from_col, int to_row, int to_col, char player) {
    board[to_row][to_col] = player;
    board[from_row][from_col] = '-';
    if (player == 'R' && to_row == 0) {
        board[to_row][to_col] = 'r';
    } else if (player == 'B' && to_row == 7) {
        board[to_row][to_col] = 'b';
    }
}

// The following function checks if a player has won the game
char check_win() {
    bool red_left = false;
    bool black_left = false;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == 'R' || board[i][j] == 'r') {
                red_left = true;
            }
            if (board[i][j] == 'B' || board[i][j] == 'b') {
                black_left = true;
            }
        }
    }
    if (!red_left) {
        return 'B';
    } else if (!black_left) {
        return 'R';
    } else {
        return '-';
    }
}

int main() {
    char player = 'R';
    char result = '-';
    int from_row = -1, from_col = -1, to_row = -1, to_col = -1;
    printf("Welcome to Checkers Game!\n");
    printf("To make a move, enter the coordinates of the piece you want to move (row, column),\n");
    printf("followed by the coordinates of the square you want to move it to (row, column).\n");
    printf("For example, to move the piece at row 3, column C to row 4, column D, enter: 3 C 4 D\n");
    while (result == '-') {
        print_board();
        printf("Player %c's turn.\n", player);
        printf("Enter move: ");
        scanf("%d %c %d %c", &from_row, &from_col, &to_row, &to_col);
        from_col -= 'A';
        to_col -= 'A';
        from_row--;
        to_row--;
        if (is_valid_move(from_row, from_col, to_row, to_col, player)) {
            make_move(from_row, from_col, to_row, to_col, player);
            result = check_win();
            if (result == '-') {
                player = (player == 'R') ? 'B' : 'R';
            }
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
    print_board();
    printf("Player %c wins!\n", result);
    return 0;
}