//FormAI DATASET v1.0 Category: Chess engine ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
char board[BOARD_SIZE][BOARD_SIZE];
int whiteKing[] = {7, 4};
int blackKing[] = {0, 4};

// Check if a given position is within limits of the board
int isValid(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

// Generate initial chess board
void generateBoard() {
    char tempBoard[BOARD_SIZE][BOARD_SIZE] = {
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
            {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
            {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
            {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };
  
    memcpy(board, tempBoard, sizeof(tempBoard));
}

// Check if a given square is under attack by opposite team's pieces
int isUnderAttack(int x, int y, char side) {
    int dx[] = {0, 0, -1, 1, 1, -1, 1, -1};
    int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};
    char oppositeKing = (side == 'w') ? 'b' : 'w';

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isValid(nx, ny)) {
            if (board[nx][ny] == oppositeKing && i < 4) {
                return 1;  // Knight attack can't be blocked
            }

            // Check for diagonal and straight attack
            if ((dx[i] && dy[i]) || i > 3) {
                while (isValid(nx, ny) && board[nx][ny] == ' ') {
                    nx += dx[i];
                    ny += dy[i];
                }

                if (isValid(nx, ny) && board[nx][ny] == oppositeKing) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

// Check if a given move is valid or not
int isMoveValid(int startX, int startY, int endX, int endY) {
    if (!isValid(startX, startY) || !isValid(endX, endY)) {
        return 0;
    }

    if (startX == endX && startY == endY) {
        return 0;
    }

    char piece = board[startX][startY];

    if (piece == ' ' || (board[endX][endY] != ' ' && piece == board[endX][endY])) {
        return 0;
    }

    int dx = abs(endY - startY);
    int dy = abs(endX - startX);

    if (piece == 'P') {
        if (startX == 6 && startX - endX == 2 && startY == endY && board[startX-1][startY] == ' ') {
            return 1;
        }

        if (startX - endX == 1 && abs(startY - endY) == 1 && board[endX][endY] != ' ') {
            return 1;
        }

        return dx == 0 && (startX - endX == 1 || (startX == 6 && startX - endX == 2)) && board[endX][endY] == ' ';
    }

    if (piece == 'p') {
        if (startX == 1 && endX - startX == 2 && startY == endY && board[startX+1][startY] == ' ') {
            return 1;
        }

        if (endX - startX == 1 && abs(startY - endY) == 1 && board[endX][endY] != ' ') {
            return 1;
        }

        return dx == 0 && (endX - startX == 1 || (startX == 1 && endX - startX == 2)) && board[endX][endY] == ' ';
    }

    if (piece == 'R' || piece == 'r') {
        if (dx && dy) {
            return 0;
        }

        int nx = startX;
        int ny = startY;
        int steps = (dx ? dx : dy) - 1;
        int stepX = (endX > startX) ? 1 : ((endX < startX) ? -1 : 0);
        int stepY = (endY > startY) ? 1 : ((endY < startY) ? -1 : 0);

        while (steps--) {
            nx += stepX;
            ny += stepY;

            if (board[nx][ny] != ' ') {
                return 0;
            }
        }

        return 1;
    }

    if (piece == 'N' || piece == 'n') {
        return dx && dy && dx + dy == 3;
    }

    if (piece == 'B' || piece == 'b') {
        if (dx != dy) {
            return 0;
        }

        int nx = startX;
        int ny = startY;
        int steps = dx - 1;
        int stepX = (endX > startX) ? 1 : -1;
        int stepY = (endY > startY) ? 1 : -1;

        while (steps--) {
            nx += stepX;
            ny += stepY;

            if (board[nx][ny] != ' ') {
                return 0;
            }
        }

        return 1;
    }

    if (piece == 'Q' || piece == 'q') {
        if (dx != dy && (dx && dy)) {
            return 0;
        }

        int nx = startX;
        int ny = startY;
        int steps = (dx ? dx : dy) - 1;
        int stepX = (endX > startX) ? 1 : ((endX < startX) ? -1 : 0);
        int stepY = (endY > startY) ? 1 : ((endY < startY) ? -1 : 0);

        while (steps--) {
            nx += stepX;
            ny += stepY;

            if (board[nx][ny] != ' ') {
                return 0;
            }
        }

        return 1;
    }

    if (piece == 'K' || piece == 'k') {
        if (dx <= 1 && dy <= 1) {
            return 1;
        }

        if (dx + dy == 2) {
            return 1;
        }

        // Castling
        if (piece == 'K' && startX == 7 && startY == 4 && endX == 7 && (endY == 6 || endY == 2)) {
            if (board[7][7] == 'R' && board[7][5] == ' ' && board[7][6] == ' '
                && !isUnderAttack(7, 5, 'b') && !isUnderAttack(7, 6, 'b')) {
                return 2;
            }
            else if (board[7][0] == 'R' && board[7][1] == ' ' && board[7][2] == ' ' && board[7][3] == ' '
                    && !isUnderAttack(7, 1, 'b') && !isUnderAttack(7, 2, 'b') && !isUnderAttack(7, 3, 'b')) {
                return 2;
            }
        }

        if (piece == 'k' && startX == 0 && startY == 4 && endX == 0 && (endY == 6 || endY == 2)) {
            if (board[0][7] == 'r' && board[0][5] == ' ' && board[0][6] == ' '
                && !isUnderAttack(0, 5, 'w') && !isUnderAttack(0, 6, 'w')) {
                return 2;
            }
            else if (board[0][0] == 'r' && board[0][1] == ' ' && board[0][2] == ' ' && board[0][3] == ' '
                    && !isUnderAttack(0, 1, 'w') && !isUnderAttack(0, 2, 'w') && !isUnderAttack(0, 3, 'w')) {
                return 2;
            }
        }

        return 0;
    }
}

// Move a piece from start position to end position
int makeMove(int startX, int startY, int endX, int endY) {
    int code = isMoveValid(startX, startY, endX, endY);

    if (code == 0) {
        return 0;
    }

    char piece = board[startX][startY];
    char oppositeKing = (piece == 'w') ? 'b' : 'w';
    int pawnToQueen = 0;

    if (piece == 'P' && endX == 0) {
        pawnToQueen = 1;
        piece = 'Q';
    }

    if (piece == 'p' && endX == 7) {
        pawnToQueen = 1;
        piece = 'q';
    }

    if (piece == 'K') {
        whiteKing[0] = endX;
        whiteKing[1] = endY;

        if (code == 2) {
            if (endY == 6) {
                board[7][5] = 'R';
                board[7][7] = ' ';
            }
            else {
                board[7][3] = 'R';
                board[7][0] = ' ';
            }
        }
    }

    if (piece == 'k') {
        blackKing[0] = endX;
        blackKing[1] = endY;

        if (code == 2) {
            if (endY == 6) {
                board[0][5] = 'r';
                board[0][7] = ' ';
            }
            else {
                board[0][3] = 'r';
                board[0][0] = ' ';
            }
        }
    }

    board[startX][startY] = ' ';
    board[endX][endY] = piece;

    if (pawnToQueen) {
        return 2;
    }

    if (isUnderAttack((piece == 'w') ? blackKing[0] : whiteKing[0], (piece == 'w') ? blackKing[1] : whiteKing[1], oppositeKing)) {
        code += 10;
    }

    return code;
}

// Display the chess board in terminal
void displayBoard() {
    printf("\n   A B C D E F G H\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", BOARD_SIZE - i);

        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }

        printf("%d\n", BOARD_SIZE - i);
    }

    printf("   A B C D E F G H\n");
}

int main() {
    int startX, startY, endX, endY, turn = 0, status;

    generateBoard();

    while (1) {
        displayBoard();
        char side = (turn % 2 == 0) ? 'w' : 'b';
        printf("\n%c's turn. Enter move (start, end): ", side);
        scanf("%c %d %c %d", &startY, &startX, &endY, &endX);

        if (startX < 1 || startX > BOARD_SIZE || endX < 1 || endX > BOARD_SIZE
            || startY < 'A' || startY > 'A' + BOARD_SIZE - 1 || endY < 'A' || endY > 'A' + BOARD_SIZE - 1) {
            printf("Invalid input. Please enter between a1 to h8.\n");
            continue;
        }

        startX = BOARD_SIZE - startX;
        endX = BOARD_SIZE - endX;
        startY -= 'A';
        endY -= 'A';

        status = makeMove(startX, startY, endX, endY);

        if (status == 0) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        if (status == 11) {
            printf("Illegal move. King is under attack.\n");
            continue;
        }

        if (status == 12) {
            printf("King is under check.\n");
            continue;
        }

        if (status == 13) {
            printf("Checkmate!\n");
            break;
        }

        if (status == 2) {
            printf("Pawn promoted to Queen!\n");
        }

        turn++;

        if (turn == 50) {
            printf("Game drawn. Maximum moves reached.\n");
            break;
        }
    }

    return 0;
}