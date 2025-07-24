//FormAI DATASET v1.0 Category: Checkers Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 8
#define COLUMNS 8

bool is_valid(int x, int y) { // Function to check if selected move is valid
    if ((x < 0) || (x >= ROWS)) return false;
    if ((y < 0) || (y >= COLUMNS)) return false;
    if ((x+y) % 2 != 0) return false;
    return true;
}

void print_board(int board[ROWS][COLUMNS]) { // Function to print the board
    printf("\n\n   C H E C K E R S\n\n");
    printf("   0 1 2 3 4 5 6 7\n");
    printf("  =================\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d| ", i);
        for (int j = 0; j < COLUMNS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  =================\n");
}

bool can_jump(int board[ROWS][COLUMNS], int player, int x, int y) { // Function to check if a player can jump
    if (player == 1) {
        if (((x-2) >= 0) && ((y-2) >= 0) && (board[x-1][y-1] == 2) && (board[x-2][y-2] == 0)) return true;
        if (((x-2) >= 0) && ((y+2) < COLUMNS) && (board[x-1][y+1] == 2) && (board[x-2][y+2] == 0)) return true;
    } else if (player == 2) {
        if (((x+2) < ROWS) && ((y-2) >= 0) && (board[x+1][y-1] == 1) && (board[x+2][y-2] == 0)) return true;
        if (((x+2) < ROWS) && ((y+2) < COLUMNS) && (board[x+1][y+1] == 1) && (board[x+2][y+2] == 0)) return true;
    }
    return false;
}

bool can_move(int board[ROWS][COLUMNS], int player, int x, int y) { // Function to check if a player can move
    if (player == 1) {
        if (((x-1) >= 0) && ((y-1) >= 0) && (board[x-1][y-1] == 0)) return true;
        if (((x-1) >= 0) && ((y+1) < COLUMNS) && (board[x-1][y+1] == 0)) return true;
    } else if (player == 2) {
        if (((x+1) < ROWS) && ((y-1) >= 0) && (board[x+1][y-1] == 0)) return true;
        if (((x+1) < ROWS) && ((y+1) < COLUMNS) && (board[x+1][y+1] == 0)) return true;
    }
    return false;
}

void move_piece(int board[ROWS][COLUMNS], int player, int x, int y, int new_x, int new_y) { // Function to move a piece
    board[new_x][new_y] = player;
    board[x][y] = 0;
    if (player == 1 && new_x == 0) board[new_x][new_y] = 3;
    if (player == 2 && new_x == 7) board[new_x][new_y] = 4;
}

void jump_piece(int board[ROWS][COLUMNS], int player, int x, int y, int new_x, int new_y) { // Function to jump a piece
    board[new_x][new_y] = player;
    board[x][y] = 0;
    if (player == 1 && new_x == 0) board[new_x][new_y] = 3;
    if (player == 2 && new_x == 7) board[new_x][new_y] = 4;
    if (new_x > x && new_y > y) {
        board[new_x-1][new_y-1] = 0;
    } else if (new_x > x && new_y < y) {
        board[new_x-1][new_y+1] = 0;
    } else if (new_x < x && new_y > y) {
        board[new_x+1][new_y-1] = 0;
    } else if (new_x < x && new_y < y) {
        board[new_x+1][new_y+1] = 0;
    }
}

int main() {
    int board[ROWS][COLUMNS] = {
        {0, 2, 0, 2, 0, 2, 0, 2},
        {2, 0, 2, 0, 2, 0, 2, 0},
        {0, 2, 0, 2, 0, 2, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
    };
    int player = 1;
    int x, y, new_x, new_y;

    while (true) { // Main game loop
        print_board(board);

        printf("\nPlayer %d turn\n", player);
        printf("Enter the x and y coordinates of the piece you want to move: \n");
        scanf("%d %d", &x, &y);

        if (!is_valid(x, y)) {
            printf("Please enter valid coordinates (0-7)\n");
            continue;
        }
        if (board[x][y] == 0 || board[x][y] == 2 || board[x][y] == 4) {
            printf("Please select a valid piece\n");
            continue;
        }
        if (board[x][y] == player || board[x][y] == player + 2) {
            printf("Enter the x and y coordinates of where you want to move the piece: \n");
            scanf("%d %d", &new_x, &new_y);

            if (!is_valid(new_x, new_y)) {
                printf("Please enter valid coordinates (0-7)\n");
                continue;
            }
            if (board[new_x][new_y] != 0) {
                printf("That space is already occupied\n");
                continue;
            }

            int x_distance = abs(x - new_x);
            int y_distance = abs(y - new_y);

            if (x_distance == 2 && y_distance == 2) {
                if (!can_jump(board, player, x, y)) {
                    printf("You cannot make that jump\n");
                    continue;
                }
                jump_piece(board, player, x, y, new_x, new_y);
                if (player == 1 && board[new_x][new_y] == 4) {
                    printf("Player 1 wins!\n");
                    return 0;
                }
                if (player == 2 && board[new_x][new_y] == 3) {
                    printf("Player 2 wins!\n");
                    return 0;
                }
            } else if (x_distance == 1 && y_distance == 1) {
                if (!can_move(board, player, x, y)) {
                    printf("You cannot make that move\n");
                    continue;
                }
                move_piece(board, player, x, y, new_x, new_y);
            } else {
                printf("That is an invalid move\n");
                continue;
            }

            if (player == 1) player = 2;
            else player = 1;
        } else {
            printf("That is not your piece\n");
            continue;
        }
    }

    return 0;
}