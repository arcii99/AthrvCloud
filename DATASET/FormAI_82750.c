//FormAI DATASET v1.0 Category: Chess engine ; Style: complete
#include <stdio.h>

// Function to check if a move is valid
int isValidMove(char board[8][8], int fromRow, int fromCol, int toRow, int toCol) {
    // Check if move is within the boundaries of the board
    if (fromRow < 0 || fromCol < 0 || toRow < 0 || toCol < 0 || fromRow > 7 || fromCol > 7 || toRow > 7 || toCol > 7) {
        return 0;
    }

    // Check if the piece at the given position is a valid piece
    char piece = board[fromRow][fromCol];
    if (piece == ' ' || piece == '\n') {
        return 0;
    }

    // Check if the move is a legal move for the given piece
    switch (piece) {
        case 'P':
            if ((toRow - fromRow == 1) && (toCol - fromCol == 0) && board[toRow][toCol] == ' ') {
                return 1;
            } else if ((toRow - fromRow == 2) && (fromRow == 1) && (toCol - fromCol == 0) && board[toRow][toCol] == ' ') {
                return 1;
            } else if ((toRow - fromRow == 1) && (toCol - fromCol == 1) && board[toRow][toCol] != ' ') {
                return 1;
            } else if ((toRow - fromRow == 1) && (toCol - fromCol == -1) && board[toRow][toCol] != ' ') {
                return 1;
            } else {
                return 0;
            }
            break;
        case 'R':
            if ((toRow - fromRow == 0) || (toCol - fromCol == 0)) {
                int rowIncrement = (toRow - fromRow) / ((toRow - fromRow) == 0 ? 1 : abs(toRow - fromRow));
                int colIncrement = (toCol - fromCol) / ((toCol - fromCol)== 0 ? 1 : abs(toCol - fromCol));
                int cRow = fromRow + rowIncrement;
                int cCol = fromCol + colIncrement;
                while (cRow != toRow || cCol != toCol) {
                    if (board[cRow][cCol] != ' ') {
                        return 0;
                    }
                    cRow += rowIncrement;
                    cCol += colIncrement;
                }
                return 1;
            } else {
                return 0;
            }
            break;
        case 'K':
            if ((abs(toRow - fromRow) == 1 && abs(toCol - fromCol) == 0) || (abs(toRow - fromRow) == 0 && abs(toCol - fromCol) == 1) || (abs(toRow - fromRow) == 1 && abs(toCol - fromCol) == 1)) {
                return 1;
            } else {
                return 0;
            }
            break;
        case 'B':
            if (abs(toRow - fromRow) == abs(toCol - fromCol)) {
                int rowIncrement = (toRow - fromRow) / abs(toRow - fromRow);
                int colIncrement = (toCol - fromCol) / abs(toCol - fromCol);
                int cRow = fromRow + rowIncrement;
                int cCol = fromCol + colIncrement;
                while (cRow != toRow || cCol != toCol) {
                    if (board[cRow][cCol] != ' ') {
                        return 0;
                    }
                    cRow += rowIncrement;
                    cCol += colIncrement;
                }
                return 1;
            } else {
                return 0;
            }
            break;
        case 'Q':
            if (isValidMove(board, fromRow, fromCol, toRow, toCol) && (isValidMove(board, fromRow, fromCol, toRow, fromCol) || isValidMove(board, fromRow, fromCol, fromRow, toCol))) {
                return 1;
            } else {
                return 0;
            }
            break;
        case 'N':
            if ((abs(toRow - fromRow) == 2 && abs(toCol - fromCol) == 1) || (abs(toRow - fromRow) == 1 && abs(toCol - fromCol) == 2)) {
                return 1;
            } else {
                return 0;
            }
            break;
        default:
            return 0;
    }
}

// Function to display the chess board
void displayBoard(char board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
}

int main() {
    // Initialize the chess board
    char board[8][8] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };
    displayBoard(board);
    printf("\n");

    // Test isValidMove function
    printf("Testing isValidMove function:\n");
    printf("Valid move from e2 to e4: %d\n", isValidMove(board, 6, 4, 4, 4));
    printf("Invalid move from e2 to e5: %d\n", isValidMove(board, 6, 4, 3, 4));
    printf("\n");

    // Test displayBoard function
    printf("Testing displayBoard function:\n");
    displayBoard(board);
    printf("\n");

    return 0;
}