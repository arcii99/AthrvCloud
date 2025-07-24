//FormAI DATASET v1.0 Category: Checkers Game ; Style: thoughtful
#include <stdio.h>

/* Global array containing game board */
int board[8][8] = {
    {0, -1, 0, -1, 0, -1, 0, -1},
    {-1, 0, -1, 0, -1, 0, -1, 0},
    {0, -1, 0, -1, 0, -1, 0, -1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0}
};

/* Function to check if a move is valid */
int is_valid_move(int x1, int y1, int x2, int y2, int player) {
    /* Check if there is a piece at the starting location */
    if (board[x1][y1] == 0 || board[x1][y1] * player < 0) {
        return 0;
    }
    /* Check if the ending location is on the board */
    if (x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7) {
        return 0;
    }
    /* Check if the ending location is empty */
    if (board[x2][y2] != 0) {
        return 0;
    }
    /* Check if the move is diagonal */
    if ((x2 - x1) * (x2 - x1) != (y2 - y1) * (y2 - y1)) {
        return 0;
    }
    /* Check if the move is in the correct direction */
    if (board[x1][y1] == 1 && x2 <= x1) {
        return 0;
    }
    if (board[x1][y1] == -1 && x2 >= x1) {
        return 0;
    }
    /* Check if the move is a capture */
    if (board[(x1 + x2) / 2][(y1 + y2) / 2] * player <= 0 
        || board[(x1 + x2) / 2][(y1 + y2) / 2] == 2) {
        return 0;
    }
    /* All checks passed, move is valid */
    return 1;
}

/* Function to print the current board */
void print_board() {
    printf("   0  1  2  3  4  5  6  7\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i);
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 0) {
                printf(".  ");
            }
            else if (board[i][j] == 1) {
                printf("O  ");
            }
            else if (board[i][j] == -1) {
                printf("X  ");
            }
            else {
                printf("K  ");
            }
        }
        printf("\n");
    }
}

/* Function to make a move */
void make_move(int x1, int y1, int x2, int y2, int player) {
    /* Check if move is a capture */
    if ((x2 - x1) * (x2 - x1) == 4) {
        board[(x1 + x2) / 2][(y1 + y2) / 2] = 0;
    }
    /* Check if move reaches other end of board */
    if (x2 == 0 || x2 == 7) {
        board[x2][y2] = player * 2;
    }
    else {
        board[x2][y2] = board[x1][y1];
    }
    board[x1][y1] = 0;
}

int main() {
    /* Initialize game variables */
    int player_turn = 1;
    int move_count = 0;
    int x1, y1, x2, y2;
    /* Game loop */
    while (1) {
        /* Print board */
        print_board();
        /* Prompt player for move */
        printf("Player %d: enter move (x1 y1 x2 y2): ", player_turn);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        /* Check if move is valid */
        if (is_valid_move(x1, y1, x2, y2, player_turn)) {
            /* Make the move */
            make_move(x1, y1, x2, y2, player_turn);
            /* Check if player has won */
            int has_won = 1;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (board[i][j] == player_turn * 2) {
                        has_won = 0;
                    }
                }
            }
            if (has_won) {
                printf("Player %d wins!\n", player_turn);
                break;
            }
            /* Switch player turn */
            move_count++;
            if (move_count % 2 == 0) {
                player_turn = -player_turn;
            }
        }
        else {
            printf("Invalid move, try again.\n");
        }
    }
    return 0;
}