//FormAI DATASET v1.0 Category: Checkers Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

void initialize_board(int board[BOARD_SIZE][BOARD_SIZE]);
void print_board(int board[BOARD_SIZE][BOARD_SIZE]);
int valid_move(int board[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2, int player);
int perform_move(int board[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2, int player);
int game_over(int board[BOARD_SIZE][BOARD_SIZE]);

int main(void) 
{
    int board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    print_board(board);
    int player = 1;
    int x1, y1, x2, y2;
    while (!game_over(board)) {
        printf("Player %d: enter move (from_row from_col to_row to_col): ", player);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (valid_move(board, x1, y1, x2, y2, player)) {
            perform_move(board, x1, y1, x2, y2, player);
            print_board(board);
            player = (player == 1) ? 2 : 1;
        } else {
            printf("Invalid move, try again\n");
        }
    }
    printf("Game over!\n");
}

void initialize_board(int board[BOARD_SIZE][BOARD_SIZE]) 
{
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0 && i < 3) {
                board[i][j] = 2;
            } else if ((i + j) % 2 == 0 && i > 4) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) 
{
    int i, j;
    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf(" %d ", i);
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("[%d]", board[i][j]);
        }
        printf("\n");
    }
}

int valid_move(int board[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2, int player) 
{
    if (x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE || x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
        return 0;
    }
    if (x1 == x2 && y1 == y2) {
        return 0;
    }
    if (board[x1][y1] == 0 || board[x2][y2] != 0) {
        return 0;
    }
    if (board[x1][y1] == 1 && player == 2) {
        return 0;
    }
    if (board[x1][y1] == 2 && player == 1) {
        return 0;
    }
    if (board[x1][y1] == 1 && x2 >= x1) {
        return 0;
    }
    if (board[x1][y1] == 2 && x2 <= x1) {
        return 0;
    }
    if (abs(x1 - x2) != abs(y1 - y2)) {
        return 0;
    }
    if (abs(x1 - x2) > 2 || abs(y1 - y2) > 2) {
        return 0;
    }
    if (abs(x1 - x2) == 2 && abs(y1 - y2) == 2) {
        if (board[(x1 + x2) / 2][(y1 + y2) / 2] == 0) {
            return 0;
        }
        if (board[(x1 + x2) / 2][(y1 + y2) / 2] == player) {
            return 0;
        }
    }
    return 1;
}

int perform_move(int board[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2, int player) 
{
    if (abs(x1 - x2) == 2 && abs(y1 - y2) == 2) {
        board[(x1 + x2) / 2][(y1 + y2) / 2] = 0;
    }
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = 0;
}

int game_over(int board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    int player1_pieces = 0;
    int player2_pieces = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 1) {
                player1_pieces++;
            } else if (board[i][j] == 2) {
                player2_pieces++;
            }
        }
    }
    if (player1_pieces == 0 || player2_pieces == 0) {
        return 1;
    } else {
        return 0;
    }
}