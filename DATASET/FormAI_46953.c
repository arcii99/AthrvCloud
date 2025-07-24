//FormAI DATASET v1.0 Category: Chess engine ; Style: mathematical
#include <stdio.h>
char board[8][8] = {
   { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' },
   { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
   { ' ', '.', ' ', '.', ' ', '.', ' ', '.' },
   { '.', ' ', '.', ' ', '.', ' ', '.', ' ' },
   { ' ', '.', ' ', '.', ' ', '.', ' ', '.' },
   { '.', ' ', '.', ' ', '.', ' ', '.', ' ' },
   { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
   { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' }
}; // initial board setup

int is_valid_move(int x_s, int y_s, int x_d, int y_d)
{
    // check if move is valid according to chess game logic
    char piece = board[y_s][x_s];

    if (piece == 'P' && y_s == 1 && y_d == 3 && x_s == x_d) {
        return 1;
    } else if (piece == 'p' && y_s == 6 && y_d == 4 && x_s == x_d) {
        return 1;
    } else if (piece == 'P' && y_s + 1 == y_d && x_s == x_d && board[y_d][x_d] == ' ') {
        return 1;
    } else if (piece == 'p' && y_s - 1 == y_d && x_s == x_d && board[y_d][x_d] == ' ') {
        return 1;
    } else if (piece == 'P' && y_s + 1 == y_d && (x_s == x_d - 1 || x_s == x_d + 1) && board[y_d][x_d] != ' ') {
        return 1;
    } else if (piece == 'p' && y_s - 1 == y_d && (x_s == x_d - 1 || x_s == x_d + 1) && board[y_d][x_d] != ' ') {
        return 1;
    } else if (piece == 'R' && (x_s == x_d || y_s == y_d)) {
        int dx = x_s < x_d ? 1 : -1;
        int dy = y_s < y_d ? 1 : -1;
        while (x_s != x_d || y_s != y_d) {
            x_s += dx; y_s += dy;
            if (board[y_s][x_s] != ' ' && (x_s != x_d || y_s != y_d)) {
                return 0;
            }
        }
        return 1;
    } else if (piece == 'r' && (x_s == x_d || y_s == y_d)) {
        int dx = x_s < x_d ? 1 : -1;
        int dy = y_s < y_d ? 1 : -1;
        while (x_s != x_d || y_s != y_d) {
            x_s += dx; y_s += dy;
            if (board[y_s][x_s] != ' ' && (x_s != x_d || y_s != y_d)) {
                return 0;
            }
        }
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    // sample move
    int x_s = 4, y_s = 0; // initial position of king
    int x_d = 4, y_d = 1; // destination position of king

    if (is_valid_move(x_s, y_s, x_d, y_d)) {
        // move piece to destination
        board[y_d][x_d] = board[y_s][x_s];
        board[y_s][x_s] = ' ';
    }

    return 0;
}