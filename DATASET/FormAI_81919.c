//FormAI DATASET v1.0 Category: Chess engine ; Style: Alan Touring
// C Chess Engine
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Chessboard array
char board[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

// Function to display the chessboard
void display_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("[%c] ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to move a piece on the chessboard
void move_piece(int x1, int y1, int x2, int y2) {
    char piece = tolower(board[x1][y1]);
    if (piece == 'p') { // Pawn move
        if ((x1 == 1 || x1 == 6) && abs(x2 - x1) == 2) { // Pawn's first move
            board[x2][y2] = piece;
            board[x1][y1] = ' ';
        } else if (x2 == 0 || x2 == 7) { // Pawn promotion
            printf("Pawn promotion!\nEnter choice from 'Q', 'R', 'N' or 'B': ");
            char choice;
            scanf("%c", &choice);
            board[x2][y2] = choice;
            board[x1][y1] = ' ';
        } else {
            board[x2][y2] = piece;
            board[x1][y1] = ' ';
        }
    } else if (piece == 'r') { // Rook move
        board[x2][y2] = piece;
        board[x1][y1] = ' ';
    } else if (piece == 'n') { // Knight move
        board[x2][y2] = piece;
        board[x1][y1] = ' ';
    } else if (piece == 'b') { // Bishop move
        board[x2][y2] = piece;
        board[x1][y1] = ' ';
    } else if (piece == 'q') { // Queen move
        board[x2][y2] = piece;
        board[x1][y1] = ' ';
    } else if (piece == 'k') { // King move
        board[x2][y2] = piece;
        board[x1][y1] = ' ';
    }
}

// Function to check if move is valid
int is_valid_move(int x1, int y1, int x2, int y2) {
    char piece = tolower(board[x1][y1]);
    if (piece == 'p') { // Pawn move
        if ((x1 == 1 || x1 == 6) && abs(x2 - x1) == 2) { // Pawn's first move
            if (board[x2][y2] == ' ') {
                return 1;
            } else {
                return 0;
            }
        } else if (x2 == x1 + 1 || x2 == x1 - 1) { // Pawn capture
            if (y2 == y1 + 1 || y2 == y1 - 1) {
                if (isupper(board[x2][y2]) && board[x2][y2] != 'K') {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        } else if (board[x2][y2] == ' ') { // Pawn move forward
            if (x2 == x1 + 1 || x2 == x1 - 1) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else if (piece == 'r') { // Rook move
        if (x1 == x2 || y1 == y2) {
            int increment;
            if (x1 == x2) {
                increment = (y2 - y1) / abs(y2 - y1);
                for (int j = y1 + increment; j != y2; j += increment) {
                    if (board[x1][j] != ' ') {
                        return 0;
                    }
                }
            } else {
                increment = (x2 - x1) / abs(x2 - x1);
                for (int i = x1 + increment; i != x2; i += increment) {
                    if (board[i][y1] != ' ') {
                        return 0;
                    }
                }
            }
            if (isupper(board[x2][y2])) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else if (piece == 'n') { // Knight move
        if ((abs(x2 - x1) == 2 && abs(y2 - y1) == 1) || (abs(x2 - x1) == 1 && abs(y2 - y1) == 2)) {
            if (isupper(board[x2][y2])) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else if (piece == 'b') { // Bishop move
        if (abs(x2 - x1) == abs(y2 - y1)) {
            int increment_x = (x2 - x1) / abs(x2 - x1);
            int increment_y = (y2 - y1) / abs(y2 - y1);
            for (int i = x1 + increment_x, j = y1 + increment_y; i != x2; i += increment_x, j += increment_y) {
                if (board[i][j] != ' ') {
                    return 0;
                }
            }
            if (isupper(board[x2][y2])) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else if (piece == 'q') { // Queen move
        if (x1 == x2 || y1 == y2) {
            int increment;
            if (x1 == x2) {
                increment = (y2 - y1) / abs(y2 - y1);
                for (int j = y1 + increment; j != y2; j += increment) {
                    if (board[x1][j] != ' ') {
                        return 0;
                    }
                }
            } else {
                increment = (x2 - x1) / abs(x2 - x1);
                for (int i = x1 + increment; i != x2; i += increment) {
                    if (board[i][y1] != ' ') {
                        return 0;
                    }
                }
            }
            if (isupper(board[x2][y2])) {
                return 1;
            } else {
                return 0;
            }
        } else if (abs(x2 - x1) == abs(y2 - y1)) {
            int increment_x = (x2 - x1) / abs(x2 - x1);
            int increment_y = (y2 - y1) / abs(y2 - y1);
            for (int i = x1 + increment_x, j = y1 + increment_y; i != x2; i += increment_x, j += increment_y) {
                if (board[i][j] != ' ') {
                    return 0;
                }
            }
            if (isupper(board[x2][y2])) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else if (piece == 'k') { // King move
        if (abs(x2 - x1) <= 1 && abs(y2 - y1) <= 1) {
            if (isupper(board[x2][y2])) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int main() {
    display_board();
    int x1, y1, x2, y2;
    printf("Enter the coordinates of the piece you want to move:");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the square you want to move that piece:");
    scanf("%d %d", &x2, &y2);
    while (!is_valid_move(x1, y1, x2, y2)) {
        printf("Invalid move!\nEnter the coordinates of the piece you want to move:");
        scanf("%d %d", &x1, &y1);
        printf("Enter the coordinates of the square you want to move that piece:");
        scanf("%d %d", &x2, &y2);
    }
    move_piece(x1, y1, x2, y2);
    display_board();
    return 0;
}