//FormAI DATASET v1.0 Category: Chess engine ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define WHITE 1
#define BLACK -1

// Structure for chessboard
typedef struct {
    int** board;
    int turn;
    int gameover;
} ChessBoard;

// Initialize the chessboard with starting positions of pieces
void initializeBoard(ChessBoard* cb) {
    int i, j;

    cb->board = (int**) malloc(sizeof(int*) * 8);
    for (i = 0; i < 8; i++) {
        cb->board[i] = (int*) malloc(sizeof(int) * 8);
    }

    // Initializing pawns
    for (i = 0; i < 8; i++) {
        cb->board[1][i] = WHITE * 1;
        cb->board[6][i] = BLACK * 1;
    }

    // Initializing rooks
    cb->board[0][0] = WHITE * 2;
    cb->board[0][7] = WHITE * 2;
    cb->board[7][0] = BLACK * 2;
    cb->board[7][7] = BLACK * 2;

    // Initializing knights
    cb->board[0][1] = WHITE * 3;
    cb->board[0][6] = WHITE * 3;
    cb->board[7][1] = BLACK * 3;
    cb->board[7][6] = BLACK * 3;

    // Initializing bishops
    cb->board[0][2] = WHITE * 4;
    cb->board[0][5] = WHITE * 4;
    cb->board[7][2] = BLACK * 4;
    cb->board[7][5] = BLACK * 4;

    // Initializing queens
    cb->board[0][3] = WHITE * 5;
    cb->board[7][3] = BLACK * 5;

    // Initializing kings
    cb->board[0][4] = WHITE * 6;
    cb->board[7][4] = BLACK * 6;

    cb->turn = WHITE;
    cb->gameover = 0;
}

// Print the current state of the chessboard
void printBoard(ChessBoard cb) {
    int i, j;
    char pieceSymbols[7] = {' ', 'P', 'R', 'N', 'B', 'Q', 'K'};
    printf("\n    A B C D E F G H\n");
    for (i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for (j = 0; j < 8; j++) {
            printf("%c ", pieceSymbols[abs(cb.board[i][j])]);
        }
        printf("%d\n", 8 - i);
    }
    printf("    A B C D E F G H\n\n");
}

// Evaluate the current state of the chessboard and return the score
int evaluate(ChessBoard cb) {
    int i, j;
    int score = 0;
    int pieceValue[7] = {0, 1, 5, 3, 3, 9, 100};

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (cb.board[i][j] > 0) {
                score += pieceValue[abs(cb.board[i][j])] * WHITE;
            } else if (cb.board[i][j] < 0) {
                score += pieceValue[abs(cb.board[i][j])] * BLACK;
            }
        }
    }

    return score;
}

// Check if the given position is valid and unoccupied
int isOccupied(ChessBoard cb, int row, int col) {
    if (row < 0 || row > 7 || col < 0 || col > 7) {
        return 1;
    }
    return cb.board[row][col] != 0;
}

// Check if the given position is valid and occupied by opponent
int isOpponent(ChessBoard cb, int row, int col, int color) {
    if (row < 0 || row > 7 || col < 0 || col > 7) {
        return 0;
    }
    return cb.board[row][col] * color < 0;
}

// Check if the given position is valid and empty or occupied by opponent
int isEmptyOrOpponent(ChessBoard cb, int row, int col, int color) {
    if (row < 0 || row > 7 || col < 0 || col > 7) {
        return 1;
    }
    return cb.board[row][col] == 0 || cb.board[row][col] * color < 0;
}

// Move the piece at the given position to the target position
int move(ChessBoard* cb, int row, int col, int targetRow, int targetCol) {
    if (isOccupied(*cb, row, col)) {
        int piece = cb->board[row][col];
        if (piece > 0 && cb->turn == WHITE || piece < 0 && cb->turn == BLACK) {
            if (canMove(*cb, row, col, targetRow, targetCol)) {
                cb->board[row][col] = 0;
                cb->board[targetRow][targetCol] = piece;
                cb->turn *= -1;
                return 1;
            } else {
                printf("\nInvalid move! Try again.\n");
                return 0;

            }
        } else {
            printf("\nIt is not %s's turn! Try again.\n", cb->turn == WHITE ? "white" : "black");
            return 0;
        }
    } else {
        printf("\nThere is no piece at the given position! Try again.\n");
        return 0;
    }
}

// Check if the given piece can move to the target position
int canMove(ChessBoard cb, int row, int col, int targetRow, int targetCol) {
    int piece = cb.board[row][col];
    int color = piece > 0 ? WHITE : BLACK;
    piece = abs(piece);

    int i, j;

    if (row == targetRow && col == targetCol) {
        return 0;
    }

    if (piece == 1) { // Pawn
        int dir = color == WHITE ? -1 : 1;
        if (col == targetCol) {
            if (cb.board[row + dir][col] == 0) {
                if (targetRow == row + dir) {
                    if (targetRow == 0 || targetRow == 7) {
                        promotePawn(&cb, row, col, targetRow, targetCol, color);
                    }
                    return 1;
                } else if (cb.board[row + 2 * dir][col] == 0 && row == (color == WHITE ? 6 : 1)) {
                    if (targetRow == row + 2 * dir) {
                        return 1;
                    }
                }
            }
        } else if (abs(col - targetCol) == 1) {
            if (cb.board[row+dir][targetCol] * color < 0) {
                if (targetRow == row + dir) {
                    if (targetRow == 0 || targetRow == 7) {
                        promotePawn(&cb, row, col, targetRow, targetCol, color);
                    }
                    return 1;
                }
            }
        }
    } else if (piece == 2) { // Rook
        if (row == targetRow || col == targetCol) {
            int min = row < targetRow ? row : targetRow;
            int max = row > targetRow ? row : targetRow;
            for (i = min + 1; i < max; i++) {
                if (isOccupied(cb, i, col)) {
                    return 0;
                }
            }
            min = col < targetCol ? col : targetCol;
            max = col > targetCol ? col : targetCol;
            for (j = min + 1; j < max; j++) {
                if (isOccupied(cb, row, j)) {
                    return 0;
                }
            }
            return isEmptyOrOpponent(cb, targetRow, targetCol, color);
        }
    } else if (piece == 3) { // Knight
        int dr = abs(row - targetRow);
        int dc = abs(col - targetCol);
        if ((dr == 1 && dc == 2) || (dr == 2 && dc == 1)) {
            return isEmptyOrOpponent(cb, targetRow, targetCol, color);
        }
    } else if (piece == 4) { // Bishop
        int drow = targetRow - row;
        int dcol = targetCol - col;
        if (abs(drow) == abs(dcol)) {
            int d = abs(drow);
            int inc_r = (drow > 0 ? 1 : -1);
            int inc_c = (dcol > 0 ? 1 : -1);
            for (i = 1; i < d; i++) {
                if (isOccupied(cb, row + i*inc_r, col + i*inc_c)) {
                    return 0;
                }
            }
            return isEmptyOrOpponent(cb, targetRow, targetCol, color);
        }
    } else if (piece == 5) { // Queen
        if (row == targetRow || col == targetCol) {
            return canMove(cb, row, col, targetRow, targetCol);
        } else {
            int drow = targetRow - row;
            int dcol = targetCol - col;
            if (abs(drow) == abs(dcol)) {
                return canMove(cb, row, col, targetRow, targetCol);
            }
        }
    } else if (piece == 6) { // King
        int dr = abs(row - targetRow);
        int dc = abs(col - targetCol);
        if (dr <= 1 && dc <= 1) {
            return isEmptyOrOpponent(cb, targetRow, targetCol, color);
        }
    }

    return 0;
}

// Promote the pawn at the given position to the given piece
void promotePawn(ChessBoard* cb, int row, int col, int targetRow, int targetCol, int color) {
    char pieceChars[4] = {'R', 'N', 'B', 'Q'};
    char pieceChar;
    int pieceValue;
    do {
        printf("Select a piece to promote to (R, N, B, Q): ");
        scanf("%c", &pieceChar);
    } while (pieceChar != 'R' && pieceChar != 'N' && pieceChar != 'B' && pieceChar != 'Q');
    getchar();

    switch(pieceChar) {
        case 'R':
            pieceValue = 2;
            break;
        case 'N':
            pieceValue = 3;
            break;
        case 'B':
            pieceValue = 4;
            break;
        case 'Q':
            pieceValue = 5;
            break;
    }

    cb->board[targetRow][targetCol] = pieceValue * color;
}

// Check if the current player is in check
int isInCheck(ChessBoard cb) {
    int i, j, k;
    int kingRow, kingCol;

    // Find the current player's king
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            int piece = cb.board[i][j];
            if (piece != 0 && abs(piece) == 6 && piece * cb.turn > 0) {
                kingRow = i;
                kingCol = j;
            }
        }
    }

    // Check if any of the opponent's pieces can attack the king
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            int piece = cb.board[i][j];
            if (piece != 0 && piece * cb.turn < 0) {
                if (canMove(cb, i, j, kingRow, kingCol)) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

// Check if the current player is in checkmate
int isInCheckmate(ChessBoard* cb) {
    int i, j, k;
    int kingRow, kingCol;

    // Find the current player's king
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            int piece = cb->board[i][j];
            if (piece != 0 && abs(piece) == 6 && piece * cb->turn > 0) {
                kingRow = i;
                kingCol = j;
            }
        }
    }

    // Check if the king can move to any safe position
    for (i = kingRow - 1; i <= kingRow + 1; i++) {
        for (j = kingCol - 1; j <= kingCol + 1; j++) {
            if (canMove(*cb, kingRow, kingCol, i, j) && !isInCheck(*cb)) {
                return 0;
            }
        }
    }

    // Check if any other piece can block or capture the attacking piece
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            int piece = cb->board[i][j];
            if (piece != 0 && piece * cb->turn > 0) {
                for (k = 0; k < 8; k++) {
                    int row = i + "11010201"[k] - '1';
                    int col = j + "00102010"[k] - '1';
                    if (canMove(*cb, i, j, row, col) && !isInCheck(*cb)) {
                        return 0;
                    }
                }
            }
        }
    }

    // The player is in checkmate
    cb->gameover = 1;
    return 1;
}

int main() {
    ChessBoard cb;
    initializeBoard(&cb);
    printBoard(cb);

    while (!cb.gameover) {
        printf("%s's turn\n", cb.turn == WHITE ? "White" : "Black");
        char position[3];
        printf("Enter the starting position of the piece to move (e.g. A2): ");
        scanf("%s", position);
        getchar();
        int row = 8 - (position[1] - '0');
        int col = position[0] - 'A';
        printf("Enter the target position of the piece (e.g. A3): ");
        scanf("%s", position);
        getchar();
        int targetRow = 8 - (position[1] - '0');
        int targetCol = position[0] - 'A';
        move(&cb, row, col, targetRow, targetCol);
        printBoard(cb);
        if (isInCheckmate(&cb)) {
            printf("%s wins!\n", cb.turn == WHITE ? "Black" : "White");
        } else if (isInCheck(cb)) {
            printf("Check!\n");
        }
    }

    return 0;
}