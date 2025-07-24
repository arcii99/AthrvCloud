//FormAI DATASET v1.0 Category: Checkers Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define WHITE_PIECE 'W'
#define BLACK_PIECE 'B'
#define EMPTY_SPACE '.'

typedef struct {
    int x;
    int y;
} Position;

char board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    board[i][j] = BLACK_PIECE;
                } else if (i > 4) {
                    board[i][j] = WHITE_PIECE;
                } else {
                    board[i][j] = EMPTY_SPACE;
                }
            } else {
                board[i][j] = EMPTY_SPACE;
            }
        }
    }
}

void printBoard() {
    printf(" ");
    for (int i = 1; i <= BOARD_SIZE; i++) {
        printf(" %d", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c", i + 'A');
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

int isValidPosition(int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return 0;
    }
    if (board[x][y] != EMPTY_SPACE) {
        return 0;
    }
    return 1;
}

Position getValidMove() {
    char input[10];
    Position pos;
    do {
        printf("Enter the position to move piece: ");
        scanf("%s", input);
        pos.y = input[0] - 'A';
        pos.x = input[1] - '1';
    } while (!isValidPosition(pos.x, pos.y));
    return pos;
}

void makeMove(Position from, Position to) {
    board[to.x][to.y] = board[from.x][from.y];
    board[from.x][from.y] = EMPTY_SPACE;
}

int isJump(Position from, Position to) {
    if (abs(from.x - to.x) == 2 && abs(from.y - to.y) == 2) {
        Position middle = {(from.x + to.x) / 2, (from.y + to.y) / 2};
        if (board[middle.x][middle.y] == BLACK_PIECE ||
            board[middle.x][middle.y] == WHITE_PIECE) {
            return 1;
        }
    }
    return 0;
}

Position getValidJump(Position from) {
    char input[10];
    Position pos;
    do {
        printf("Enter the position to jump: ");
        scanf("%s", input);
        pos.y = input[0] - 'A';
        pos.x = input[1] - '1';
    } while (!isJump(from, pos));
    return pos;
}

void makeJump(Position from, Position to) {
    Position middle = {(from.x + to.x) / 2, (from.y + to.y) / 2};
    board[middle.x][middle.y] = EMPTY_SPACE;
    makeMove(from, to);
}

int canJump(Position pos) {
    if (board[pos.x][pos.y] != WHITE_PIECE &&
        board[pos.x][pos.y] != 'W') {
        return 0;
    }
    if (pos.y >= 2 && pos.x >= 2 &&
        ((board[pos.x - 1][pos.y - 1] == BLACK_PIECE ||
          board[pos.x - 1][pos.y - 1] == 'B') &&
         board[pos.x - 2][pos.y - 2] == EMPTY_SPACE)) {
        return 1;
    }
    if (pos.y <= 5 && pos.x >= 2 &&
        ((board[pos.x - 1][pos.y + 1] == BLACK_PIECE ||
          board[pos.x - 1][pos.y + 1] == 'B') &&
         board[pos.x - 2][pos.y + 2] == EMPTY_SPACE)) {
        return 1;
    }
    if (pos.y >= 2 && pos.x <= 5 &&
        ((board[pos.x + 1][pos.y - 1] == BLACK_PIECE ||
          board[pos.x + 1][pos.y - 1] == 'B') &&
         board[pos.x + 2][pos.y - 2] == EMPTY_SPACE)) {
        return 1;
    }
    if (pos.y <= 5 && pos.x <= 5 &&
        ((board[pos.x + 1][pos.y + 1] == BLACK_PIECE ||
          board[pos.x + 1][pos.y + 1] == 'B') &&
         board[pos.x + 2][pos.y + 2] == EMPTY_SPACE)) {
        return 1;
    }
    return 0;
}

int canMove(Position pos) {
    if (board[pos.x][pos.y] != WHITE_PIECE &&
        board[pos.x][pos.y] != 'W') {
        return 0;
    }
    if (pos.y >= 1 && pos.x >= 1 && board[pos.x - 1][pos.y - 1] == EMPTY_SPACE) {
        return 1;
    }
    if (pos.y <= 6 && pos.x >= 1 && board[pos.x - 1][pos.y + 1] == EMPTY_SPACE) {
        return 1;
    }
    if (pos.y >= 1 && pos.x <= 6 && board[pos.x + 1][pos.y - 1] == EMPTY_SPACE) {
        return 1;
    }
    if (pos.y <= 6 && pos.x <= 6 && board[pos.x + 1][pos.y + 1] == EMPTY_SPACE) {
        return 1;
    }
    return 0;
}

int canWhiteJump() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (canJump((Position) {i, j})) {
                return 1;
            }
        }
    }
    return 0;
}

int canWhiteMove() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (canMove((Position) {i, j})) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    initializeBoard();
    printBoard();
    while (canWhiteJump() || canWhiteMove()) {
        printf("White's turn.\n");
        Position from = getValidMove();
        while (isJump(from, from)) {
            Position jumped = getValidJump(from);
            makeJump(from, jumped);
            printBoard();
            if (canJump(jumped)) {
                printf("Jump again.\n");
                from = jumped;
            } else {
                break;
            }
        }
        if (!isJump(from, from)) {
            Position to = getValidMove();
            makeMove(from, to);
            printBoard();
        }
    }
    return 0;
}