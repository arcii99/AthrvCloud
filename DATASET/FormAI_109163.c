//FormAI DATASET v1.0 Category: Chess engine ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Function Prototypes */
void printBoard(char board[8][8]);
bool validateMove(char board[8][8], char player, char start[2], char end[2]);

int main() {
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

    printBoard(board);

    char player1 = 'w';
    char player2 = 'b';

    char currentPlayer = player1;

    while (true) {
        char start[2];
        char end[2];

        printf("Player %c's turn.\n", currentPlayer);
        printf("Enter starting position (e.g. 'a1'): ");
        scanf("%s", start);
        printf("Enter ending position (e.g. 'a2'): ");
        scanf("%s", end);

        bool validMove = validateMove(board, currentPlayer, start, end);

        if (validMove) {
            // Update board
            int startRow = start[1] - '0' - 1;
            int startCol = start[0] - 'a';
            int endRow = end[1] - '0' - 1;
            int endCol = end[0] - 'a';

            board[endRow][endCol] = board[startRow][startCol];
            board[startRow][startCol] = ' ';

            printBoard(board);

            // Switch player
            if (currentPlayer == player1) {
                currentPlayer = player2;
            } else {
                currentPlayer = player1;
            }
        } else {
            printf("Invalid move, try again.\n");
        }
    }

    return 0;
}

void printBoard(char board[8][8]) {
    printf("\n");
    for (int row = 7; row >= 0; row--) {
        printf("%d ", row + 1);
        for (int col = 0; col < 8; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

bool validateMove(char board[8][8], char player, char start[2], char end[2]) {
    // Get start and end positions
    int startRow = start[1] - '0' - 1;
    int startCol = start[0] - 'a';
    int endRow = end[1] - '0' - 1;
    int endCol = end[0] - 'a';

    // Check if start position has a piece belonging to the current player
    if (board[startRow][startCol] == ' ' || 
        (player == 'w' && board[startRow][startCol] >= 'a' && board[startRow][startCol] <= 'z') ||
        (player == 'b' && board[startRow][startCol] >= 'A' && board[startRow][startCol] <= 'Z')) {
        return false;
    }

    // Check if end position has a piece belonging to the current player
    if ((player == 'w' && board[endRow][endCol] >= 'A' && board[endRow][endCol] <= 'Z') ||
        (player == 'b' && board[endRow][endCol] >= 'a' && board[endRow][endCol] <= 'z')) {
        return false;
    }

    // Check for valid moves based on piece type
    switch (board[startRow][startCol]) {
        case 'p':
        case 'P':
            // Pawn moves
            if (player == 'w') {
                if ((endRow == startRow + 1 && endCol == startCol && board[endRow][endCol] == ' ') || 
                    (startRow == 1 && endRow == 3 && endCol == startCol && 
                     board[2][startCol] == ' ' && board[3][startCol] == ' ')) {
                    return true;
                } else if (endRow == startRow + 1 && (endCol == startCol - 1 || endCol == startCol + 1) && 
                           board[endRow][endCol] >= 'a' && board[endRow][endCol] <= 'z') {
                    return true;
                }
            } else {
                if ((endRow == startRow - 1 && endCol == startCol && board[endRow][endCol] == ' ') || 
                    (startRow == 6 && endRow == 4 && endCol == startCol && 
                     board[5][startCol] == ' ' && board[4][startCol] == ' ')) {
                    return true;
                } else if (endRow == startRow - 1 && (endCol == startCol - 1 || endCol == startCol + 1) && 
                           board[endRow][endCol] >= 'A' && board[endRow][endCol] <= 'Z') {
                    return true;
                }
            }
            break;
        case 'n':
        case 'N':
            // Knight moves
            if ((endRow == startRow + 2 && (endCol == startCol + 1 || endCol == startCol - 1)) || 
                (endRow == startRow - 2 && (endCol == startCol + 1 || endCol == startCol - 1)) ||
                (endCol == startCol + 2 && (endRow == startRow + 1 || endRow == startRow - 1)) ||
                (endCol == startCol - 2 && (endRow == startRow + 1 || endRow == startRow - 1))) {
                return true;
            }
            break;
        case 'b':
        case 'B':
            // Bishop moves
            if (abs(endRow - startRow) == abs(endCol - startCol)) {
                int rowDir = (endRow > startRow) ? 1 : -1;
                int colDir = (endCol > startCol) ? 1 : -1;
                int i = startRow;
                int j = startCol;
                while (true) {
                    i += rowDir;
                    j += colDir;
                    if (i == endRow && j == endCol) {
                        return true;
                    } else if (board[i][j] != ' ') {
                        break;
                    }
                }
            }
            break;
        case 'r':
        case 'R':
            // Rook moves
            if (endRow == startRow || endCol == startCol) {
                int rowDir = (endRow > startRow) ? 1 : -1;
                int colDir = (endCol > startCol) ? 1 : -1;
                int i = startRow;
                int j = startCol;
                while (true) {
                    i += rowDir;
                    j += colDir;
                    if (i == endRow && j == endCol) {
                        return true;
                    } else if (board[i][j] != ' ') {
                        break;
                    }
                }
            }
            break;
        case 'q':
        case 'Q':
            // Queen moves
            if (abs(endRow - startRow) == abs(endCol - startCol)) {
                int rowDir = (endRow > startRow) ? 1 : -1;
                int colDir = (endCol > startCol) ? 1 : -1;
                int i = startRow;
                int j = startCol;
                while (true) {
                    i += rowDir;
                    j += colDir;
                    if (i == endRow && j == endCol) {
                        return true;
                    } else if (board[i][j] != ' ') {
                        break;
                    }
                }
            } else if (endRow == startRow || endCol == startCol) {
                int rowDir = (endRow > startRow) ? 1 : -1;
                int colDir = (endCol > startCol) ? 1 : -1;
                int i = startRow;
                int j = startCol;
                while (true) {
                    i += rowDir;
                    j += colDir;
                    if (i == endRow && j == endCol) {
                        return true;
                    } else if (board[i][j] != ' ') {
                        break;
                    }
                }
            }
            break;
        case 'k':
        case 'K':
            // King moves
            if (abs(endRow - startRow) <= 1 && abs(endCol - startCol) <= 1) {
                return true;
            }
            break;
        default:
            break;
    }

    return false;
}