//FormAI DATASET v1.0 Category: Checkers Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

//initializing the board
int board[SIZE][SIZE] = {
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {2, 0, 2, 0, 2, 0, 2, 0},
    {0, 2, 0, 2, 0, 2, 0, 2},
    {2, 0, 2, 0, 2, 0, 2, 0}
};

void print_board(int board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int x, int y, int new_x, int new_y, int player) {
    if (new_x < 0 || new_x >= SIZE || new_y < 0 || new_y >= SIZE) {
        return 0;
    }
    if (board[new_x][new_y] != 0) {
        return 0;
    }
    if (player == 1 && board[x][y] != 1 && board[x][y] != 3) {
        return 0;
    }
    if (player == 2 && board[x][y] != 2 && board[x][y] != 4) {
        return 0;
    }
    if (abs(x - new_x) == 1 && abs(y - new_y) == 1 && abs(board[x][y]) == 1) {
        return 1;
    }
    if (abs(x - new_x) == 2 && abs(y - new_y) == 2) {
        int mid_x = (x + new_x) / 2;
        int mid_y = (y + new_y) / 2;
        if ((board[mid_x][mid_y] == 2 || board[mid_x][mid_y] == 4) && player == 1) {
            board[mid_x][mid_y] = 0;
            return 1;
        }
        if ((board[mid_x][mid_y] == 1 || board[mid_x][mid_y] == 3) && player == 2) {
            board[mid_x][mid_y] = 0;
            return 1;
        }
    }
    if (abs(x - new_x) == 2 && abs(y - new_y) == 2 && abs(board[x][y]) == 3) {
        int mid_x = (x + new_x) / 2;
        int mid_y = (y + new_y) / 2;
        board[mid_x][mid_y] = 0;
        return 1;
    }
    return 0;
}

int can_move(int x, int y, int player) {
    if (player == 1 && (board[x][y] == 1 || board[x][y] == 3)) {
        if (is_valid(x, y, x - 1, y - 1, player)) return 1;
        if (is_valid(x, y, x - 1, y + 1, player)) return 1;
        if (is_valid(x, y, x - 2, y - 2, player)) return 1;
        if (is_valid(x, y, x - 2, y + 2, player)) return 1;
    }
    if (player == 2 && (board[x][y] == 2 || board[x][y] == 4)) {
        if (is_valid(x, y, x + 1, y - 1, player)) return 1;
        if (is_valid(x, y, x + 1, y + 1, player)) return 1;
        if (is_valid(x, y, x + 2, y - 2, player)) return 1;
        if (is_valid(x, y, x + 2, y + 2, player)) return 1;
    }
    return 0;
}

int move(int x, int y, int new_x, int new_y, int player) {
    if (!is_valid(x, y, new_x, new_y, player)) {
        return 0;
    }
    int piece = board[x][y];
    board[x][y] = 0;
    board[new_x][new_y] = piece;
    if (player == 1 && new_x == 0 && abs(piece) == 1) {
        board[new_x][new_y] *= 3;
    }
    if (player == 2 && new_x == SIZE - 1 && abs(piece) == 2) {
        board[new_x][new_y] *= 4;
    }
    return 1;
}

int check_game_over(int player) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] != 0 && abs(board[i][j]) % 2 == player - 1) {
                if (can_move(i, j, player)) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    int player = 1;
    while (1) {
        print_board(board);
        if (check_game_over(player)) {
            printf("Game over! Player %d wins!\n", player == 1 ? 2 : 1);
            break;
        }
        int x, y, new_x, new_y;
        printf("Player %d enter move: ", player);
        scanf("%d %d %d %d", &x, &y, &new_x, &new_y);
        if (move(x, y, new_x, new_y, player)) {
            player = player == 1 ? 2 : 1;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
    return 0;
}