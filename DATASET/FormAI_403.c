//FormAI DATASET v1.0 Category: Chess AI ; Style: high level of detail
#include <stdio.h>

// Function to initialize the chessboard
void initializeBoard(char board[8][8]) {
    // Initialize the position of white pieces
    board[0][0] = 'R'; board[0][1] = 'N'; board[0][2] = 'B'; board[0][3] = 'Q';
    board[0][4] = 'K'; board[0][5] = 'B'; board[0][6] = 'N'; board[0][7] = 'R';
    board[1][0] = 'P'; board[1][1] = 'P'; board[1][2] = 'P'; board[1][3] = 'P';
    board[1][4] = 'P'; board[1][5] = 'P'; board[1][6] = 'P'; board[1][7] = 'P';

    // Initialize the position of black pieces
    board[7][0] = 'r'; board[7][1] = 'n'; board[7][2] = 'b'; board[7][3] = 'q';
    board[7][4] = 'k'; board[7][5] = 'b'; board[7][6] = 'n'; board[7][7] = 'r';
    board[6][0] = 'p'; board[6][1] = 'p'; board[6][2] = 'p'; board[6][3] = 'p';
    board[6][4] = 'p'; board[6][5] = 'p'; board[6][6] = 'p'; board[6][7] = 'p';

    // Fill the remaining squares with empty spaces
    for(int i=2; i<=5; i++) {
        for(int j=0; j<8; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the chessboard
void displayBoard(char board[8][8]) {
    printf("  a b c d e f g h\n");
    for(int i=0; i<8; i++) {
        printf("%d ", 8-i);
        for(int j=0; j<8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", 8-i);
    }
    printf("  a b c d e f g h\n");
}

int main() {
    char board[8][8];
    initializeBoard(board);
    displayBoard(board);
    return 0;
}