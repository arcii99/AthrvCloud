//FormAI DATASET v1.0 Category: Chess engine ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef char Piece;
typedef Piece Box[BOARD_SIZE][BOARD_SIZE];

/* Function to print the Chess board */
void printBoard(Box board) {
    printf("  A B C D E F G H\n");
    printf("  ---------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("%d\n", i + 1);
        printf(" |\n");
    }
    printf("  ---------------\n");
    printf("  A B C D E F G H\n");
}

/* Function to initialize the Chess board */
void initializeBoard(Box board) {
    char whitePieces[] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
    char blackPieces[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};

    // Place black pieces
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[0][i] = blackPieces[i];
        board[1][i] = 'p';
    }

    // Place white pieces
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[7][i] = whitePieces[i];
        board[6][i] = 'P';
    }
}

/* Function to convert x and y coordinates to Chess notation */
char* convertToChessNotation(int x, int y) {
    char* chessNotation = malloc(sizeof(char) * 3);
    chessNotation[0] = 'A' + y;
    chessNotation[1] = '1' + BOARD_SIZE - x - 1;
    chessNotation[2] = '\0';
    return chessNotation;
}

/* Function to convert Chess notation to x and y coordinates */
int* convertToCoordinates(char* chessNotation) {
    int* coordinates = malloc(sizeof(int) * 2);
    coordinates[0] = BOARD_SIZE - (chessNotation[1] - '1') - 1;
    coordinates[1] = chessNotation[0] - 'A';
    return coordinates;
}

/* Function to check if the move is valid */
int isValidMove(Box board, int startX, int startY, int endX, int endY) {
    // Check if the end position is occupied by a piece of the same color
    if (board[endX][endY] != '.' && board[startX][startY] == board[endX][endY]) {
        return 0;
    }

    // Check if the piece can move to the end position
    switch (board[startX][startY]) {
        case 'p': // Pawn
        case 'P':
            // Check if the pawn is moving forward
            if (startX == endX) {
                // Check if the pawn is moving 1 or 2 squares
                if ((startY - endY) * (startY - endY) == 1) {
                    // Check if the pawn is moving in the correct direction
                    if (board[startX][startY] == 'p') {
                        if (endY < startY) {
                            return 1;
                        }
                    } else {
                        if (endY > startY) {
                            return 1;
                        }
                    }
                } else if ((startY - endY) * (startY - endY) == 4) {
                    // Check if the pawn is moving 2 squares
                    if (startY == 1 || startY == BOARD_SIZE - 2) {
                        // Check if the squares between the start and end position are empty
                        int direction = (board[startX][startY] == 'p') ? -1 : 1;
                        if (board[startX][startY + direction] == '.' && board[startX][startY + 2 * direction] == '.') {
                            return 1;
                        }
                    }
                }
            } else {
                // Check if the pawn is capturing another piece diagonally
                if ((startY - endY) * (startY - endY) == 1 && (endX - startX) * (endX - startX) == 1) {
                    // Check if the the piece being captured is of the opposite color
                    if (board[startX][startY] == 'p') {
                        if (endY < startY && (board[endX][endY] == 'N' || board[endX][endY] == 'B' || board[endX][endY] == 'R' || board[endX][endY] == 'Q' || board[endX][endY] == 'K')) {
                            return 1;
                        }
                    } else {
                        if (endY > startY && (board[endX][endY] == 'n' || board[endX][endY] == 'b' || board[endX][endY] == 'r' || board[endX][endY] == 'q' || board[endX][endY] == 'k')) {
                            return 1;
                        }
                    }
                }
            }
            break;
        case 'n': // Knight
        case 'N':
            if ((startX - endX) * (startX - endX) + (startY - endY) * (startY - endY) == 5) {
                return 1;
            }
            break;
        case 'b': // Bishop
        case 'B':
            if ((startX - endX) * (startX - endX) == (startY - endY) * (startY - endY)) {
                int xDirection = (endX - startX > 0) ? 1 : -1;
                int yDirection = (endY - startY > 0) ? 1 : -1;
                int i = startX + xDirection;
                int j = startY + yDirection;
                while (i != endX && j != endY) {
                    if (board[i][j] != '.') {
                        return 0;
                    }
                    i += xDirection;
                    j += yDirection;
                }
                return 1;
            }
            break;
        case 'r': // Rook
        case 'R':
            if (startX == endX || startY == endY) {
                int direction = (startX == endX) ? ((endY - startY > 0) ? 1 : -1) : ((endX - startX > 0) ? 1 : -1);
                if (startX == endX) {
                    int j = startY + direction;
                    while (j != endY) {
                        if (board[startX][j] != '.') {
                            return 0;
                        }
                        j += direction;
                    }
                } else {
                    int i = startX + direction;
                    while (i != endX) {
                        if (board[i][startY] != '.') {
                            return 0;
                        }
                        i += direction;
                    }
                }
                return 1;
            }
            break;
        case 'q': // Queen
        case 'Q':
            if (startX == endX || startY == endY || (startX - endX) * (startX - endX) == (startY - endY) * (startY - endY)) {
                int directionX = (startX == endX) ? 0 : ((endX - startX > 0) ? 1 : -1);
                int directionY = (startY == endY) ? 0 : ((endY - startY > 0) ? 1 : -1);
                if (startX == endX || startY == endY) {
                    int direction = (startX == endX) ? ((endY - startY > 0) ? 1 : -1) : ((endX - startX > 0) ? 1 : -1);
                    if (startX == endX) {
                        int j = startY + direction;
                        while (j != endY) {
                            if (board[startX][j] != '.') {
                                return 0;
                            }
                            j += direction;
                        }
                    } else {
                        int i = startX + direction;
                        while (i != endX) {
                            if (board[i][startY] != '.') {
                                return 0;
                            }
                            i += direction;
                        }
                    }
                } else {
                    if ((startX - endX) * (startX - endX) == (startY - endY) * (startY - endY)) {
                        int xDirection = (endX - startX > 0) ? 1 : -1;
                        int yDirection = (endY - startY > 0) ? 1 : -1;
                        int i = startX + xDirection;
                        int j = startY + yDirection;
                        while (i != endX && j != endY) {
                            if (board[i][j] != '.') {
                                return 0;
                            }
                            i += xDirection;
                            j += yDirection;
                        }
                        return 1;
                    }
                }
                return 1;
            }
            break;
        case 'k': // King
        case 'K':
            if ((startX - endX) * (startX - endX) + (startY - endY) * (startY - endY) <= 2) {
                return 1;
            }
            break;
    }

    return 0;
}

/* Function to make a move */
void makeMove(Box board, int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = '.';
}

/* Function to get user input */
char* getInput() {
    char* input = malloc(sizeof(char) * 10);
    printf("Enter your move (e.g. e2e4): ");
    scanf("%s", input);
    return input;
}

int main() {
    Box board;
    initializeBoard(board);
    printBoard(board);

    while (1) {
        char* move = getInput();
        if (strlen(move) != 4) {
            printf("Invalid move.\n");
            continue;
        }
        int* start = convertToCoordinates(&move[0]);
        int* end = convertToCoordinates(&move[2]);
        if (!isValidMove(board, start[0], start[1], end[0], end[1])) {
            printf("Invalid move.\n");
            continue;
        }
        makeMove(board, start[0], start[1], end[0], end[1]);
        printBoard(board);
        free(start);
        free(end);
    }

    return 0;
}