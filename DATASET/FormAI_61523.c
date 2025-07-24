//FormAI DATASET v1.0 Category: Checkers Game ; Style: creative
#include <stdio.h>

/* Variables */

// The Board
char board[8][8];

// Players
char playerOne = 'X';
char playerTwo = 'O';

// Turn Counter
int turn = 1;

// Function Prototypes
void printBoard();
int validMove(int, int, int, int, int, char);
int checkWin();
void endGame(char);

/* Main Function */

int main() {
    // Initialize Board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = ' ';
            }
            else {
                board[i][j] = '-';
            }
        }
    }
    
    // Set Initial Pieces
    board[0][1] = playerOne;
    board[0][3] = playerOne;
    board[0][5] = playerOne;
    board[0][7] = playerOne;
    board[1][0] = playerOne;
    board[1][2] = playerOne;
    board[1][4] = playerOne;
    board[1][6] = playerOne;
    board[2][1] = playerOne;
    board[2][3] = playerOne;
    board[2][5] = playerOne;
    board[2][7] = playerOne;
    
    board[5][0] = playerTwo;
    board[5][2] = playerTwo;
    board[5][4] = playerTwo;
    board[5][6] = playerTwo;
    board[6][1] = playerTwo;
    board[6][3] = playerTwo;
    board[6][5] = playerTwo;
    board[6][7] = playerTwo;
    board[7][0] = playerTwo;
    board[7][2] = playerTwo;
    board[7][4] = playerTwo;
    board[7][6] = playerTwo;
    
    // Start Game
    int gameOver = 0;
    while (!gameOver) {
        // Print Board
        printf("\n\n");
        printf("Turn %d - Player %c's turn:\n", turn, (turn % 2 == 1) ? playerOne : playerTwo);
        printBoard();
        
        // Get Move
        int startX, startY, endX, endY;
        printf("Enter start position (x,y): ");
        scanf("%d,%d", &startX, &startY);
        printf("Enter end position (x,y): ");
        scanf("%d,%d", &endX, &endY);
        
        // Check Move
        int valid = validMove(startX, startY, endX, endY, turn % 2 == 1, board[startX][startY]);
        if (valid == 1) {
            // Make Move
            board[endX][endY] = board[startX][startY];
            board[startX][startY] = '-';
            turn++;
            
            // Check Win
            int winner = checkWin();
            if (winner == 1) {
                endGame(playerOne);
                gameOver = 1;
            }
            else if (winner == 2) {
                endGame(playerTwo);
                gameOver = 1;
            }
        }
        else {
            printf("Invalid move! Try again.\n");
        }
    }
    
    return 0;
}

/* Function Definitions */

// Print Board Function
void printBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Valid Move Function
int validMove(int startX, int startY, int endX, int endY, int playerOneTurn, char piece) {
    // Check if move is diagonal and has correct direction
    if (abs(startX - endX) != abs(startY - endY) || ((playerOneTurn && endX < startX) || (!playerOneTurn && endX > startX))) {
        return 0;
    }
    
    // Check if move is to an empty square or to capture an opponent's piece
    if (board[endX][endY] != '-' && ((playerOneTurn && board[endX][endY] == playerTwo) || (!playerOneTurn && board[endX][endY] == playerOne))) {
        return 0;
    }
    if (board[endX][endY] != '-' && board[endX][endY] != ' ' && ((endX - startX > 1) || (startX - endX > 1))) {
        return 0;
    }
    if (board[endX][endY] != '-' && board[endX][endY] != ' ' && (piece != 'K' && piece != 'Q' && abs(endX - startX) != 2)) {
        return 0;
    }
    if (board[endX][endY] == '-' && ((endX - startX > 2) || (startX - endX > 2))) {
        return 0;
    }
    
    // Check if move is valid for piece type
    if ((piece == 'x' || piece == 'o') && abs(endX - startX) != 1) {
        return 0;
    }
    if (piece == 'X' && ((endX - startX > 2) || (startX - endX > 2))) {
        return 0;
    }
    if (piece == 'O' && ((endX - startX > 2) || (startX - endX > 2))) {
        return 0;
    }
    
    return 1;
}

// Check Win Function
int checkWin() {
    int playerOnePieces = 0;
    int playerTwoPieces = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == playerOne || board[i][j] == 'K' || board[i][j] == 'Q') {
                playerOnePieces++;
            }
            else if (board[i][j] == playerTwo || board[i][j] == 'O') {
                playerTwoPieces++;
            }
        }
    }
    
    if (playerOnePieces == 0) {
        return 2;
    }
    else if (playerTwoPieces == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

// End Game Function
void endGame(char winner) {
    printf("\n\n%s wins!\n\n", winner == playerOne ? "Player One" : "Player Two");
    printBoard();
}