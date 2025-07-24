//FormAI DATASET v1.0 Category: Checkers Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define constants for the checkerboard size
#define BOARD_SIZE 8
#define EMPTY_SLOT ' '
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

// Declare global variables
char board[BOARD_SIZE][BOARD_SIZE];
int playerOnePieces;
int playerTwoPieces;

// Declare functions
void initializeBoard();
void printBoard();
int moveIsValid(int player, int fromRow, int fromCol, int toRow, int toCol);
void performMove(int player, int fromRow, int fromCol, int toRow, int toCol);
int getAllAvailableMoves(int player, int moveList[][2]);
int checkVictory(int player);

// Main function
int main() {
    // Initialize the board
    initializeBoard();

    // Initialize the player's piece count
    playerOnePieces = playerTwoPieces = 12;

    // Create a variable for the current player,
    // starting with player one
    int currentPlayer = 1;

    // Main game loop
    while (!checkVictory(currentPlayer)) {
        // Print the current state of the board
        printf("Current state of the board:\n");
        printBoard();

        // Create a variable for the player's chosen move,
        // starting with an invalid move
        int fromRow = -1, fromCol = -1, toRow = -1, toCol = -1;

        // Get the available moves for the current player
        int availableMoves[24][2];
        int numMoves = getAllAvailableMoves(currentPlayer, availableMoves);

        // Get input from the player until they make a valid move
        while (!moveIsValid(currentPlayer, fromRow, fromCol, toRow, toCol)) {
            // Prompt the player for their move
            printf("Player %d, please enter the row and column numbers of the piece you want to move and the destination row and column numbers (e.g. 3 4 2 5):\n", currentPlayer);

            // Read the player's move from standard input
            scanf("%d %d %d %d", &fromRow, &fromCol, &toRow, &toCol);

            // Convert the row and column numbers from 1-based to 0-based indexing
            fromRow--;
            fromCol--;
            toRow--;
            toCol--;
        }

        // Perform the player's move
        performMove(currentPlayer, fromRow, fromCol, toRow, toCol);

        // If the move was a jump, check if another jump is possible
        if (abs(fromRow - toRow) == 2) {
            int extraJumpPossible = 0;

            // Check if any jumps are possible for the same piece
            int availableJumpMoves[24][2];
            int numJumpMoves = getAllAvailableMoves(currentPlayer, availableJumpMoves);

            for (int i = 0; i < numJumpMoves; i++) {
                if (availableJumpMoves[i][0] == toRow && availableJumpMoves[i][1] == toCol) {
                    extraJumpPossible = 1;
                    break;
                }
            }

            // If another jump is possible, don't switch players
            if (extraJumpPossible) {
                printf("You made a jump! You can jump again with the same piece.\n");
                fromRow = toRow;
                fromCol = toCol;
                continue;
            }
            // If no other jumps are possible, switch players
            else {
                printf("You made a jump! You cannot jump again with the same piece.\n");
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            }
        }
        // If the move was not a jump, switch players
        else {
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
    }

    // Print the final state of the board
    printf("Final state of the board:\n");
    printBoard();

    // Print the victory message for the winning player
    printf("Congratulations, Player %d! You won!\n", currentPlayer);

    return 0;
}

// Function to initialize the checkerboard
void initializeBoard() {
    // Set all slots to empty
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = EMPTY_SLOT;
        }
    }

    // Add player one pieces to the board
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 1) {
                board[row][col] = PLAYER_ONE;
            }
        }
    }

    // Add player two pieces to the board
    for (int row = BOARD_SIZE - 3; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 1) {
                board[row][col] = PLAYER_TWO;
            }
        }
    }
}

// Function to print the checkerboard
void printBoard() {
    // Print the column numbers
    printf("  ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf(" %d ", col + 1);
    }
    printf("\n");

    // Print the separator row
    printf("  +");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("---+");
    }
    printf("\n");

    // Print each row of the board
    for (int row = 0; row < BOARD_SIZE; row++) {
        // Print the row number
        printf("%d ", row + 1);

        // Print each slot on the row
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("| %c ", board[row][col]);
        }
        printf("|\n");

        // Print the separator row
        printf("  +");
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("---+");
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int moveIsValid(int player, int fromRow, int fromCol, int toRow, int toCol) {
    // Check if the from and to locations are on the board
    if (fromRow < 0 || fromRow >= BOARD_SIZE || fromCol < 0 || fromCol >= BOARD_SIZE || toRow < 0 || toRow >= BOARD_SIZE || toCol < 0 || toCol >= BOARD_SIZE) {
        printf("Invalid move: your piece or destination is off the board.\n");
        return 0;
    }

    // Check if the from location contains a piece belonging to the player
    if (board[fromRow][fromCol] != PLAYER_ONE && board[fromRow][fromCol] != PLAYER_TWO) {
        printf("Invalid move: that space does not contain your piece.\n");
        return 0;
    }

    // Check if the to location is an empty space
    if (board[toRow][toCol] != EMPTY_SLOT) {
        printf("Invalid move: that space is already occupied.\n");
        return 0;
    }

    // Check if the move is diagonal
    if (abs(fromRow - toRow) != abs(fromCol - toCol)) {
        printf("Invalid move: your piece can only move diagonally.\n");
        return 0;
    }

    // Check if the move is more than one space
    if (abs(fromRow - toRow) > 2) {
        printf("Invalid move: your piece can only move one or two spaces.\n");
        return 0;
    }

    // Check if the move direction is correct for the player's pieces
    if (player == 1 && board[fromRow][fromCol] != PLAYER_ONE) {
        printf("Invalid move: you can only move your own pieces.\n");
        return 0;
    }
    if (player == 2 && board[fromRow][fromCol] != PLAYER_TWO) {
        printf("Invalid move: you can only move your own pieces.\n");
        return 0;
    }

    // Check if a move is a jump
    int jumpRow = (fromRow + toRow) / 2;
    int jumpCol = (fromCol + toCol) / 2;

    if (abs(fromRow - toRow) == 2) {
        // Check if the jump is valid
        if ((player == 1 && board[jumpRow][jumpCol] == PLAYER_TWO) || (player == 2 && board[jumpRow][jumpCol] == PLAYER_ONE)) {
            return 1;
        }
        else {
            printf("Invalid move: you can only jump over your opponent's pieces.\n");
            return 0;
        }
    }

    // If the move is not a jump, it is valid
    return 1;
}

// Function to perform a move
void performMove(int player, int fromRow, int fromCol, int toRow, int toCol) {
    // Move the piece to the new location
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = EMPTY_SLOT;

    // Check if the move was a jump
    if (abs(fromRow - toRow) == 2) {
        int jumpRow = (fromRow + toRow) / 2;
        int jumpCol = (fromCol + toCol) / 2;

        // Remove the jumped piece from the board
        board[jumpRow][jumpCol] = EMPTY_SLOT;

        // Decrement the piece count for the opponent
        if (player == 1) {
            playerTwoPieces--;
        }
        else {
            playerOnePieces--;
        }
    }
}

// Function to get all available moves for a player
int getAllAvailableMoves(int player, int moveList[][2]) {
    int numMoves = 0;

    // Loop through all pieces on the board
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            // Check if the piece belongs to the current player
            if ((player == 1 && board[row][col] == PLAYER_ONE) || (player == 2 && board[row][col] == PLAYER_TWO)) {
                // Check each diagonal direction for available moves
                int directions[4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}};

                for (int i = 0; i < 4; i++) {
                    int nextRow = row + directions[i][0];
                    int nextCol = col + directions[i][1];

                    // Check if the next diagonal space is valid
                    if (nextRow >= 0 && nextRow < BOARD_SIZE && nextCol >= 0 && nextCol < BOARD_SIZE && board[nextRow][nextCol] == EMPTY_SLOT) {
                        // A regular move is available
                        moveList[numMoves][0] = row;
                        moveList[numMoves][1] = col;
                        moveList[numMoves+1][0] = nextRow;
                        moveList[numMoves+1][1] = nextCol;
                        numMoves++;
                    }
                    else if (nextRow >= 0 && nextRow < BOARD_SIZE && nextCol >= 0 && nextCol < BOARD_SIZE &&
                             board[nextRow][nextCol] != board[row][col] && board[nextRow][nextCol] != EMPTY_SLOT) {
                        // A jump move is available
                        int jumpRow = nextRow + directions[i][0];
                        int jumpCol = nextCol + directions[i][1];

                        if (jumpRow >= 0 && jumpRow < BOARD_SIZE && jumpCol >= 0 && jumpCol < BOARD_SIZE && board[jumpRow][jumpCol] == EMPTY_SLOT) {
                            moveList[numMoves][0] = row;
                            moveList[numMoves][1] = col;
                            moveList[numMoves+1][0] = jumpRow;
                            moveList[numMoves+1][1] = jumpCol;
                            numMoves++;
                        }
                    }
                }
            }
        }
    }

    return numMoves;
}

// Function to check for victory
int checkVictory(int player) {
    // Check if the player has no pieces left
    if (player == 1 && playerOnePieces == 0) {
        return 1;
    }
    if (player == 2 && playerTwoPieces == 0) {
        return 1;
    }

    // Check if the player has no moves left
    int availableMoves[24][2];
    int numMoves = getAllAvailableMoves(player, availableMoves);

    if (numMoves == 0) {
        return 1;
    }

    // If neither condition is met, the game is not over
    return 0;
}