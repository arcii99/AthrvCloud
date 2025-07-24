//FormAI DATASET v1.0 Category: Checkers Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];

// Initialize board with starting pieces
void init_board()
{
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3)
                    board[i][j] = 1;
                else if (i > 4)
                    board[i][j] = 2;
            }
        }
    }
}

// Print the current state of the board
void print_board()
{
    int i, j;

    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d", i);
    }
    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                printf(" ");
            } else if (board[i][j] == 1) {
                printf("o");
            } else if (board[i][j] == 2) {
                printf("x");
            }
        }
        printf("|%d\n", i);
    }

    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d", i);
    }
    printf("\n");
}

// Check if a move is valid
int valid_move(int player, int x1, int y1, int x2, int y2)
{
    if (x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE ||
        x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE)
        return 0;
    if (board[y1][x1] != player)
        return 0;
    if (board[y2][x2] != 0)
        return 0;
    if (abs(x2 - x1) != 1 || abs(y2 - y1) != 1)
        return 0;
    if (player == 1 && y2 > y1)
        return 0;
    if (player == 2 && y2 < y1)
        return 0;
    return 1;
}

// Evaluate a capture move
int evaluate_capture(int player, int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int cx = x2 + dx;
    int cy = y2 + dy;
    if (cx < 0 || cx >= BOARD_SIZE || cy < 0 || cy >= BOARD_SIZE)
        return 0;
    if (board[cy][cx] == player || board[cy][cx] == 0)
        return 0;
    return 1;
}

// Check if a capture move is valid
int valid_capture(int player, int x1, int y1, int x2, int y2)
{
    if (!valid_move(player, x1, y1, x2, y2))
        return 0;
    return evaluate_capture(player, x1, y1, x2, y2);
}

// Apply a move to the board
void apply_move(int player, int x1, int y1, int x2, int y2)
{
    board[y1][x1] = 0;
    board[y2][x2] = player;
    if (evaluate_capture(player, x1, y1, x2, y2)) {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int cx = x2 + dx;
        int cy = y2 + dy;
        board[cy][cx] = 0;
    }
}

// Check if a player has any valid moves left
int has_valid_moves(int player)
{
    int i, j, x, y;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                for (y = i - 2; y <= i + 2; y++) {
                    for (x = j - 2; x <= j + 2; x++) {
                        if (valid_capture(player, j, i, x, y))
                            return 1;
                    }
                }
            }
        }
    }

    return 0;
}

// Get user input for a move
void get_move(int player, int *x1, int *y1, int *x2, int *y2)
{
    if (player == 1)
        printf("Player 1 (o), enter move: ");
    else
        printf("Player 2 (x), enter move: ");
    scanf("%d%d%d%d", x1, y1, x2, y2);
}

// Main function
int main()
{
    int player = 1;
    int x1, y1, x2, y2;

    init_board();

    while (1) {
        print_board();

        if (!has_valid_moves(player)) {
            printf("Player %d has no valid moves left\n", player);
            break;
        }

        get_move(player, &x1, &y1, &x2, &y2);

        if (valid_capture(player, x1, y1, x2, y2)) {
            apply_move(player, x1, y1, x2, y2);
        } else if (valid_move(player, x1, y1, x2, y2)) {
            apply_move(player, x1, y1, x2, y2);
        } else {
            printf("Invalid move\n");
            continue;
        }

        if (player == 1)
            player = 2;
        else
            player = 1;
    }

    printf("Game over\n");
    print_board();

    return 0;
}