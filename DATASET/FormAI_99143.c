//FormAI DATASET v1.0 Category: Chess AI ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 4
#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef struct {
    int row, col;
} Position;

typedef struct {
    Position from, to;
} Move;

int board[BOARD_SIZE][BOARD_SIZE] = {
        {-1, -2, -3, -4, -5, -3, -2, -1},
        {-6, -6, -6, -6, -6, -6, -6, -6},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {6, 6, 6, 6, 6, 6, 6, 6},
        {1, 2, 3, 4, 5, 3, 2, 1}
};

int evaluateBoard() {
    int whiteScore = 0, blackScore = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            int piece = board[row][col];
            if (piece != 0) {
                int pieceScore = abs(piece);
                if (piece > 0) {
                    whiteScore += pieceScore;
                } else {
                    blackScore += pieceScore;
                }
            }
        }
    }
    return whiteScore - blackScore;
}

bool isAttacked(int row, int col, int player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] * player < 0) {
                int temp = board[i][j] * player;
                switch (temp) {
                    case 1: {
                        if (abs(i - row) == 1 && abs(j - col) == 1) {
                            return true;
                        }
                        break;
                    }
                    case 2: {
                        if ((abs(i - row) == 1 && abs(j - col) == 2) ||
                            (abs(i - row) == 2 && abs(j - col) == 1)) {
                            return true;
                        }
                        break;
                    }
                    case 3: {
                        if ((abs(i - row) == abs(j - col)) ||
                            (i == row || j == col)) {
                            return true;
                        }
                        break;
                    }
                    case 4: {
                        if (((i == row && j != col) ||
                             (j == col && i != row)) ||
                            (abs(i - row) == abs(j - col))) {
                            return true;
                        }
                        break;
                    }
                    case 5: {
                        if ((abs(i - row) <= 1 && abs(j - col) <= 1) &&
                            !(i == row && j == col)) {
                            return true;
                        }
                        break;
                    }
                    case 6: {
                        for (int k = i - 1; k >= 0; k--) {
                            if (board[k][j] != 0) {
                                if (board[k][j] * player < 0 &&
                                    abs(k - row) == 1 &&
                                    j == col) {
                                    return true;
                                }
                                break;
                            }
                        }
                        for (int k = i + 1; k < BOARD_SIZE; k++) {
                            if (board[k][j] != 0) {
                                if (board[k][j] * player < 0 &&
                                    abs(k - row) == 1 &&
                                    j == col) {
                                    return true;
                                }
                                break;
                            }
                        }
                        for (int k = j - 1; k >= 0; k--) {
                            if (board[i][k] != 0) {
                                if (board[i][k] * player < 0 &&
                                    abs(k - col) == 1 &&
                                    i == row) {
                                    return true;
                                }
                                break;
                            }
                        }
                        for (int k = j + 1; k < BOARD_SIZE; k++) {
                            if (board[i][k] != 0) {
                                if (board[i][k] * player < 0 &&
                                    abs(k - col) == 1 &&
                                    i == row) {
                                    return true;
                                }
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    return false;
}

bool isValidMove(Move move, int player) {
    if (board[move.from.row][move.from.col] * player <= 0) {
        return false;
    }
    int temp = board[move.from.row][move.from.col];
    switch (temp) {
        case 1: {
            if (abs(move.from.row - move.to.row) == 1 &&
                abs(move.from.col - move.to.col) == 1 &&
                board[move.to.row][move.to.col] * player <= 0) {
                return true;
            }
            break;
        }
        case 2: {
            if (((abs(move.from.row - move.to.row) == 1 &&
                  abs(move.from.col - move.to.col) == 2) ||
                 (abs(move.from.row - move.to.row) == 2 &&
                  abs(move.from.col - move.to.col) == 1)) &&
                board[move.to.row][move.to.col] * player <= 0) {
                return true;
            }
            break;
        }
        case 3: {
            int i = move.from.row, j = move.from.col;
            if ((abs(move.to.row - i) == abs(j - move.to.col)) ||
                (move.to.row == i || move.to.col == j)) {
                int x = (move.to.row - i) / abs(i - move.to.row);
                int y = (move.to.col - j) / abs(j - move.to.col);
                for (int k = i + x, l = j + y;
                     k != move.to.row || l != move.to.col;
                     k += x, l += y) {
                    if (board[k][l] != 0) {
                        return false;
                    }
                }
                if (board[move.to.row][move.to.col] * player <= 0) {
                    return true;
                }
            }
            break;
        }
        case 4: {
            int i = move.from.row, j = move.from.col;
            if (((move.to.row == i && move.to.col != j) ||
                 (move.to.col == j && move.to.row != i)) ||
                (abs(move.to.row - i) == abs(j - move.to.col))) {
                int x, y;
                if (move.to.row > i)
                    x = 1;
                else if (move.to.row < i)
                    x = -1;
                else
                    x = 0;
                if (move.to.col > j)
                    y = 1;
                else if (move.to.col < j)
                    y = -1;
                else
                    y = 0;
                for (int k = i + x, l = j + y;
                     k != move.to.row || l != move.to.col;
                     k += x, l += y) {
                    if (board[k][l] != 0) {
                        return false;
                    }
                }
                if (board[move.to.row][move.to.col] * player <= 0) {
                    return true;
                }
            }
            break;
        }
        case 5: {
            if ((abs(move.to.row - move.from.row) <= 1 &&
                 abs(move.to.col - move.from.col) <= 1) &&
                !(move.to.row == move.from.row &&
                  move.to.col == move.from.col) &&
                board[move.to.row][move.to.col] * player <= 0) {
                return true;
            }
            break;
        }
        case 6: {
            int i = move.from.row, j = move.from.col;
            if ((move.to.col == j) &&
                (move.to.row - i == -1 * player ||
                 (move.to.row - i == -2 * player && i == 6 * player)) &&
                board[move.to.row][move.to.col] == 0) {
                return true;
            }
            if ((abs(move.to.col - j) == 1) &&
                (move.to.row - i == -1 * player) &&
                board[move.to.row][move.to.col] * player < 0) {
                return true;
            }
            break;
        }
    }
    return false;
}

void makeMove(Move move) {
    board[move.to.row][move.to.col] = board[move.from.row][move.from.col];
    board[move.from.row][move.from.col] = 0;
}

void unMakeMove(Move move, int takenPiece) {
    board[move.from.row][move.from.col] = board[move.to.row][move.to.col];
    board[move.to.row][move.to.col] = takenPiece;
}

int minimax(int depth, int alpha, int beta, int player, int* bestRow, int* bestCol) {
    if (depth == MAX_DEPTH) {
        return evaluateBoard();
    }
    int maxValue = INT_MIN, minValue = INT_MAX;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] * player > 0) {
                for (int i = row; i < BOARD_SIZE; i++) {
                    for (int j = (i == row ? col + 1 : 0); j < BOARD_SIZE; j++) {
                        if (isValidMove((Move) {.from = {row, col}, .to = {i, j}}, player)) {
                            int takenPiece = board[i][j];
                            makeMove((Move) {.from = {row, col}, .to = {i, j}});
                            int score = minimax(depth + 1, alpha, beta, -player, bestRow, bestCol);
                            unMakeMove((Move) {.from = {row, col}, .to = {i, j}}, takenPiece);
                            if (player == 1) {
                                if (score > maxValue) {
                                    maxValue = score;
                                    if (depth == 0) {
                                        *bestRow = row;
                                        *bestCol = col;
                                    }
                                }
                                alpha = alpha > score ? alpha : score;
                            } else {
                                if (score < minValue) {
                                    minValue = score;
                                }
                                beta = beta < score ? beta : score;
                            }
                            if (beta <= alpha) {
                                return player == 1 ? maxValue : minValue;
                            }
                        }
                    }
                }
            }
        }
    }
    return player == 1 ? maxValue : minValue;
}

void printBoard() {
    printf("\n   |");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %c |", (char) ('A' + i));
    }
    printf("\n");
    for (int i = 0; i < 3 * (BOARD_SIZE + 1); i++) {
        printf("-");
    }
    printf("\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf(" %d |", BOARD_SIZE - row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            switch (board[row][col]) {
                case -1:
                    printf(" k |");
                    break;
                case -2:
                    printf(" n |");
                    break;
                case -3:
                    printf(" b |");
                    break;
                case -4:
                    printf(" r |");
                    break;
                case -5:
                    printf(" q |");
                    break;
                case -6:
                    printf(" p |");
                    break;
                case 1:
                    printf(" K |");
                    break;
                case 2:
                    printf(" N |");
                    break;
                case 3:
                    printf(" B |");
                    break;
                case 4:
                    printf(" R |");
                    break;
                case 5:
                    printf(" Q |");
                    break;
                case 6:
                    printf(" P |");
                    break;
                default:
                    printf("   |");
                    break;
            }
        }
        printf(" %d\n", BOARD_SIZE - row);
        for (int i = 0; i < 3 * (BOARD_SIZE + 1); i++) {
            printf("-");
        }
        printf("\n");
    }
    printf("   |");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %c |", (char) ('A' + i));
    }
    printf("\n");
}

int main() {
    printf("Welcome to Chess!\n");
    printf("The board is represented by integer values:\n");
    printf("-1 -> black king, -2 -> black knight, -3 -> black bishop, -4 -> black rook,\n");
    printf("-5 -> black queen, -6 -> black pawn, 1 -> white king, 2 -> white knight,\n");
    printf("3 -> white bishop, 4 -> white rook, 5 -> white queen, 6 -> white pawn,\n");
    printf("0 -> empty cell\n");
    printBoard();
    while (true) {
        int humanRow, humanCol;
        while (true) {
            printf("Enter the position of the piece you want to move (ex: A1): ");
            char input[3];
            scanf("%s", input);
            humanRow = BOARD_SIZE - (input[1] - '0');
            humanCol = input[0] - 'A';
            if (humanRow < 0 || humanRow >= BOARD_SIZE ||
                humanCol < 0 || humanCol >= BOARD_SIZE ||
                board[humanRow][humanCol] == 0) {
                printf("Invalid input, please try again.\n");
            } else if ((board[humanRow][humanCol] < 0 && evaluateBoard() > 0) ||
                       (board[humanRow][humanCol] > 0 && evaluateBoard() < 0)) {
                printf("Not your turn, please try again.\n");
            } else {
                break;
            }
        }
        int aiRow, aiCol;
        printf("Processing...\n");
        minimax(0, INT_MIN, INT_MAX, -1, &aiRow, &aiCol);
        printf("AI decided to move its piece from (%d,%d) to (%d,%d).\n", aiRow, aiCol, aiRow - 1, aiCol);
        makeMove((Move) {.from = {humanRow, humanCol}, .to = {aiRow, aiCol}});
        printBoard();
        if (evaluateBoard() > 0) {
            printf("Congratulations, you win!\n");
            break;
        } else if (evaluateBoard() < 0) {
            printf("Sorry, you lost...\n");
            break;
        }
    }
    return 0;
}