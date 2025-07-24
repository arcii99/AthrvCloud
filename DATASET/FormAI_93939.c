//FormAI DATASET v1.0 Category: Checkers Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define DIM 8

// Set up the initial checkerboard
char board[DIM][DIM] = {
    {'-', 'w', '-', 'w', '-', 'w', '-', 'w'},
    {'w', '-', 'w', '-', 'w', '-', 'w', '-'},
    {'-', 'w', '-', 'w', '-', 'w', '-', 'w'},
    {'-', '-', '-', '-', '-', '-', '-', '-'},
    {'-', '-', '-', '-', '-', '-', '-', '-'},
    {'r', '-', 'r', '-', 'r', '-', 'r', '-'},
    {'-', 'r', '-', 'r', '-', 'r', '-', 'r'},
    {'r', '-', 'r', '-', 'r', '-', 'r', '-'},
};

// Draw the current state of the board
void draw_board() {
    printf("\n   0 1 2 3 4 5 6 7\n");
    printf("  +----------------+\n");
    for (int i = 0; i < DIM; i++) {
        printf("%d | ", i);
        for (int j = 0; j < DIM; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  +----------------+\n");
}

// Check if the move is valid
int is_valid_move(int x, int y, int new_x, int new_y, char player) {
    // Check if move is within the bounds of the board
    if (new_x < 0 || new_x >= DIM || new_y < 0 || new_y >= DIM) {
        return 0;
    }

    // Check if move is diagonal
    if ((new_x - x) != (new_y - y) && (new_x - x) != -(new_y - y)) {
        return 0;
    }

    // Check if destination is empty
    if (board[new_x][new_y] != '-') {
        return 0;
    }

    // Check if player is moving their own piece
    if (player == 'r' && board[x][y] != 'r' && board[x][y] != 'R') {
        return 0;
    } else if (player == 'w' && board[x][y] != 'w' && board[x][y] != 'W') {
        return 0;
    }

    // Check if move is a jump
    if (abs(new_x - x) == 2) {
        int middle_x = (new_x + x) / 2;
        int middle_y = (new_y + y) / 2;
        if (player == 'r' && board[middle_x][middle_y] != 'w' && board[middle_x][middle_y] != 'W') {
            return 0;
        } else if (player == 'w' && board[middle_x][middle_y] != 'r' && board[middle_x][middle_y] != 'R') {
            return 0;
        }
    }

    return 1;
}

// Check if the player can make any jumps
int can_jump(int x, int y, char player) {
    if (player == 'r') {
        if (is_valid_move(x, y, x+2, y+2, 'r') || is_valid_move(x, y, x+2, y-2, 'r')) {
            return 1;
        }
    } else if (player == 'w') {
        if (is_valid_move(x, y, x-2, y+2, 'w') || is_valid_move(x, y, x-2, y-2, 'w')) {
            return 1;
        }
    }
    return 0;
}

// Check if the player has any valid moves
int can_move(char player) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            if (player == 'r' && (board[i][j] == 'r' || board[i][j] == 'R')) {
                if (is_valid_move(i, j, i+1, j+1, player) || is_valid_move(i, j, i+1, j-1, player) || can_jump(i, j, player)) {
                    return 1;
                }
            } else if (player == 'w' && (board[i][j] == 'w' || board[i][j] == 'W')) {
                if (is_valid_move(i, j, i-1, j+1, player) || is_valid_move(i, j, i-1, j-1, player) || can_jump(i, j, player)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Check if the game is over
int is_game_over() {
    return (!can_move('r') || !can_move('w'));
}

// Make a move
void make_move(int x, int y, int new_x, int new_y, char player) {
    board[new_x][new_y] = board[x][y];
    board[x][y] = '-';
    if (player == 'r' && new_x == DIM-1 && board[new_x][new_y] == 'r') {
        board[new_x][new_y] = 'R';
    } else if (player == 'w' && new_x == 0 && board[new_x][new_y] == 'w') {
        board[new_x][new_y] = 'W';
    }
    if (abs(new_x - x) == 2) {
        int middle_x = (new_x + x) / 2;
        int middle_y = (new_y + y) / 2;
        board[middle_x][middle_y] = '-';
    }
}

// Main game loop
int main() {
    int x, y, new_x, new_y;
    char player = 'r';
    while (!is_game_over()) {
        draw_board();
        printf("%c's turn\n", player);
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &x, &y);
        printf("Enter the row and column of where you want to move the piece: ");
        scanf("%d %d", &new_x, &new_y);
        if (is_valid_move(x, y, new_x, new_y, player)) {
            make_move(x, y, new_x, new_y, player);
            if (can_jump(new_x, new_y, player)) {
                x = new_x;
                y = new_y;
                continue;
            }
            if (player == 'r') {
                player = 'w';
            } else {
                player = 'r';
            }
        } else {
            printf("Invalid move!\n");
        }
    }
    draw_board();
    printf("%c wins!\n", player == 'r' ? 'w' : 'r');
    return 0;
}