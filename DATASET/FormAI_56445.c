//FormAI DATASET v1.0 Category: Checkers Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

char board[ROWS][COLS];
char selectedPiece[2];
char currentTurn = 'r';

int isPlayerPiece(char piece);
int isLegalMove(int fromRow, int fromCol, int toRow, int toCol);
int validGameMove();
int gameOver();
void printBoard();
void clearBoard();
void initialSetup();
void selectPiece();
void movePiece();

int main() {
    int gameover = 0;

    clearBoard();
    initialSetup();
    printBoard();

    while (!gameover) {
        validGameMove();
        selectPiece();
        movePiece();
        printBoard();

        if (gameOver()) {
            printf("Game over\n");
            gameover = 1;
        } else {
            if (currentTurn == 'r') {
                currentTurn = 'b';
            } else {
                currentTurn = 'r';
            }
        }
    }

    return 0;
}

int isPlayerPiece(char piece) {
    if (piece == 'r' || piece == 'R') {
        return 1;
    } else if (piece == 'b' || piece == 'B') {
        return 2;
    } else {
        return 0;
    }
}

int isLegalMove(int fromRow, int fromCol, int toRow, int toCol) {
    if ((board[toRow][toCol] != ' ') || ((toRow + toCol) % 2 == 1)) {
        return 0;
    }

    int dx = toRow - fromRow;
    int dy = toCol - fromCol;

    if (abs(dx) == 1) {
        return 1;
    }

    if (abs(dx) == 2) {
        int middlePieceRow = (fromRow + toRow) / 2;
        int middlePieceCol = (fromCol + toCol) / 2;

        if (isPlayerPiece(board[middlePieceRow][middlePieceCol])) {
            return 2;
        } else {
            return 0;
        }
    }

    return 0;
}

int validGameMove() {
    printf("\nIt's %c's turn\n", currentTurn);
    printf("Select piece coordinates: ");
    scanf("%c%c", &selectedPiece[0], &selectedPiece[1]);
    getchar();

    if (!isPlayerPiece(board[selectedPiece[0] - '0'][selectedPiece[1] - '0'])) {
        printf("That's not your piece.\n");
        return 0;
    }

    printf("Enter destination coordinates: ");
    int toRow, toCol;
    scanf("%d%s", &toRow, &toCol);
    getchar();

    if (!isLegalMove(selectedPiece[0] - '0', selectedPiece[1] - '0', toRow, toCol)) {
        printf("That's not a legal move.\n");
        return 0;
    }

    return 1;
}

int gameOver() {
    int redCount = 0;
    int blackCount = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (isPlayerPiece(board[i][j]) == 1) {
                redCount++;
            } else if (isPlayerPiece(board[i][j]) == 2) {
                blackCount++;
            }
        }
    }

    if (redCount == 0 || blackCount == 0) {
        return 1;
    } else {
        return 0;
    }
}

void printBoard() {
    printf("\n  0  1  2  3  4  5  6  7\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i);

        for (int j = 0; j < COLS; j++) {
            printf("[%c]", board[i][j]);
        }

        printf("\n");
        printf("\n");
    }

    printf("r = red piece\nR = red king\nb = black piece\nB = black king");
}

void clearBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

void initialSetup() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((i + j) % 2 == 1) {
                if (i < 3) {
                    board[i][j] = 'r';
                } else if (i > 4) {
                    board[i][j] = 'b';
                }
            }
        }
    }
}

void selectPiece() {
    printf("\nSelected piece: %c%c\n", selectedPiece[0], selectedPiece[1]);
}

void movePiece() {
    int toRow, toCol;
    printf("Enter destination coordinates: ");
    scanf("%d%d",&toRow,&toCol);
    getchar();

    int dx = toRow - (selectedPiece[0] - '0');
    int dy = toCol - (selectedPiece[1] - '0');

    board[selectedPiece[0] - '0'][selectedPiece[1] - '0'] = ' ';
    board[toRow][toCol] = currentTurn;

    if (abs(dx) == 2) {
        int middlePieceRow = (selectedPiece[0] - '0' + toRow) / 2;
        int middlePieceCol = (selectedPiece[1] - '0' + toCol) / 2;
        board[middlePieceRow][middlePieceCol] = ' ';
    }

    if (currentTurn == 'r' && toRow == 0) {
        board[toRow][toCol] = 'R';
    } else if (currentTurn == 'b' && toRow == ROWS - 1) {
        board[toRow][toCol] = 'B';
    }
}