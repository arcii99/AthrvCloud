//FormAI DATASET v1.0 Category: Checkers Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int board[SIZE][SIZE] = {  // Initialize board
    {-1, 0,-1, 0,-1, 0,-1, 0},
    { 0,-1, 0,-1, 0,-1, 0,-1},
    {-1, 0,-1, 0,-1, 0,-1, 0},
    { 0,-1, 0,-1, 0,-1, 0,-1},
    {-1, 0,-1, 0,-1, 0,-1, 0},
    { 0,-1, 0,-1, 0,-1, 0,-1},
    {-1, 0,-1, 0,-1, 0,-1, 0},
    { 0,-1, 0,-1, 0,-1, 0,-1},
};

void print_board() {  // Print out current state of board
    printf("   0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == -1) {
                printf("B ");
            } else if (board[i][j] == 1) {
                printf("W ");
            } else if (board[i][j] == -2) {
                printf("b ");
            } else if (board[i][j] == 2) {
                printf("w ");
            } else {
                printf("- ");
            }
        }
        printf("%d\n", i);
    }
    printf("   0 1 2 3 4 5 6 7\n");
}

int valid_move(int start_x, int start_y, int end_x, int end_y, int player) {
    if (start_x < 0 || start_x >= SIZE || start_y < 0 || start_y >= SIZE ||
            end_x < 0 || end_x >= SIZE || end_y < 0 || end_y >= SIZE ||
            board[start_x][start_y] != player ||
            board[end_x][end_y] != 0) {
        return 0;
    }
    int dx = end_x - start_x;
    int dy = end_y - start_y;
    if (player == 1) {  // Check for valid white move
        if (dx == -1 && abs(dy) == 1 && board[end_x][end_y] == 0) {  // Regular move
            return 1;
        } else if (dx == -2 && abs(dy) == 2 && board[start_x-1][start_y+dy/2] == -1) {  // Capture move
            return 2;
        } else if (dx == -1 && abs(dy) == 1 && board[end_x][end_y] == -2) {  // King capture move
            return 3;
        }
    } else if (player == -1) {  // Check for valid black move
        if (dx == 1 && abs(dy) == 1 && board[end_x][end_y] == 0) {  // Regular move
            return 1;
        } else if (dx == 2 && abs(dy) == 2 && board[start_x+1][start_y+dy/2] == 1) {  // Capture move
            return 2;
        } else if (dx == 1 && abs(dy) == 1 && board[end_x][end_y] == 2) {  // King capture move
            return 3;
        }
    } else if (player == 2) {  // Check for valid white king move
        if (abs(dx) == 1 && abs(dy) == 1 && board[end_x][end_y] == 0) {  // Regular move
            return 1;
        } else if (abs(dx) == 2 && abs(dy) == 2 && board[start_x+dx/2][start_y+dy/2] == -1) {  // Capture move
            return 2;
        }
    } else if (player == -2) {  // Check for valid black king move
        if (abs(dx) == 1 && abs(dy) == 1 && board[end_x][end_y] == 0) {  // Regular move
            return 1;
        } else if (abs(dx) == 2 && abs(dy) == 2 && board[start_x+dx/2][start_y+dy/2] == 1) {  // Capture move
            return 2;
        }
    }
    return 0;
}

int make_move(int start_x, int start_y, int end_x, int end_y, int player) {
    int move_type = valid_move(start_x, start_y, end_x, end_y, player);
    if (move_type == 0) {
        return 0;
    }
    board[start_x][start_y] = 0;
    board[end_x][end_y] = player;
    if (player == 1 && end_x == 0) {  // White king promotion
        board[end_x][end_y] = 2;
    } else if (player == -1 && end_x == SIZE-1) {  // Black king promotion
        board[end_x][end_y] = -2;
    }
    if (move_type == 2 || move_type == 3) {  // Capture move
        int dx = end_x - start_x;
        int dy = end_y - start_y;
        board[start_x+dx/2][start_y+dy/2] = 0;
    }
    return 1;
}

int main() {
    int turn = 1;  // Start with white's turn
    print_board();
    int game_over = 0;
    while (!game_over) {
        printf("Player %d's turn.\n", turn);
        int start_x, start_y, end_x, end_y;
        printf("Enter start and end coordinates of the piece to move (in the format 'x y x y'): ");
        scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);
        if (make_move(start_x, start_y, end_x, end_y, turn)) {
            print_board();
            if (turn == 1) {
                turn = -1;
            } else {
                turn = 1;
            }
        } else {
            printf("Invalid move, try again.\n");
        }
        // Game over conditions
        int white_pieces = 0, black_pieces = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == 1 || board[i][j] == 2) {
                    white_pieces++;
                } else if (board[i][j] == -1 || board[i][j] == -2) {
                    black_pieces++;
                }
            }
        }
        if (white_pieces == 0) {
            printf("Black wins!\n");
            game_over = 1;
        } else if (black_pieces == 0) {
            printf("White wins!\n");
            game_over = 1;
        }
    }
    return 0;
}