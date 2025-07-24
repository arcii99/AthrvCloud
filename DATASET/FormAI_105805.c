//FormAI DATASET v1.0 Category: Chess AI ; Style: cheerful
// Welcome to my amazing chess AI program!
#include <stdio.h>
#include <stdbool.h>

char gameBoard[8][8]; // The chess board is 8x8
bool isWhiteTurn = true; // This tracks whose turn it is - white goes first!
int numMoves = 0; // A fun little counter for how many moves have been made

// Set up the initial game board - look at those pawns go!
void initializeBoard() {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(i < 2) { // If it's in the first two rows, it's a black piece
                if(j == 0 || j == 7) { // Rooks!
                    gameBoard[i][j] = 'r';
                } else if(j == 1 || j == 6) { // Knights!
                    gameBoard[i][j] = 'n';
                } else if(j == 2 || j == 5) { // Bishops!
                    gameBoard[i][j] = 'b';
                } else if(j == 3) { // The Queen!
                    gameBoard[i][j] = 'q';
                } else if(j == 4) { // The King!
                    gameBoard[i][j] = 'k';
                }
            } else if(i > 5) { // If it's in the last two rows, it's a white piece
                if(j == 0 || j == 7) { // Rooks!
                    gameBoard[i][j] = 'R';
                } else if(j == 1 || j == 6) { // Knights!
                    gameBoard[i][j] = 'N';
                } else if(j == 2 || j == 5) { // Bishops!
                    gameBoard[i][j] = 'B';
                } else if(j == 3) { // The Queen!
                    gameBoard[i][j] = 'Q';
                } else if(j == 4) { // The King!
                    gameBoard[i][j] = 'K';
                }
            } else { // The middle rows are empty at the start
                gameBoard[i][j] = ' ';
            }
        }
    }
}

// Prints out the current state of the board
void printBoard() {
    printf("\n   a b c d e f g h\n");
    for(int i=0; i<8; i++) {
        printf("%d |", 8-i);
        for(int j=0; j<8; j++) {
            printf("%c|", gameBoard[i][j]);
        }
        printf(" %d\n", 8-i);
    }
    printf("   a b c d e f g h\n\n");
}

// Updates the board based on the given move
void updateBoard(int startRow, int startCol, int destRow, int destCol) {
    gameBoard[destRow][destCol] = gameBoard[startRow][startCol];
    gameBoard[startRow][startCol] = ' ';
}

// This amazing AI will just make random moves. It's not very smart, but it's cheerful!
void makeRandomMove() {
    // Pick a random starting location and destination for the move
    int startRow, startCol, destRow, destCol;
    startRow = rand() % 8;
    startCol = rand() % 8;
    destRow = rand() % 8;
    destCol = rand() % 8;
    
    // Check that the move is valid - if not, try again!
    if(gameBoard[startRow][startCol] == ' ') {
        makeRandomMove();
    } else if(startRow == destRow && startCol == destCol) {
        makeRandomMove();
    } else {
        updateBoard(startRow, startCol, destRow, destCol);
        printf("Move %d: %c%c to %c%c\n", numMoves, startCol+'a', 8-startRow, destCol+'a', 8-destRow);
        numMoves++;
    }
}

// The main game loop!
int main() {
    printf("Welcome to my cheerful chess AI game!\n");
    initializeBoard();
    printBoard();
    while(true) {
        printf("It's %s's turn!\n", isWhiteTurn ? "white" : "black");
        makeRandomMove();
        printBoard();
        isWhiteTurn = !isWhiteTurn; // Switch to the other player's turn
    }
}