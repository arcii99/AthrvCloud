//FormAI DATASET v1.0 Category: Checkers Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define board dimensions
#define BOARD_SIZE 8

// Define player pieces
#define PLAYER_ONE 'O'
#define PLAYER_TWO 'X'

// Define empty space and crown pieces
#define EMPTY_SPACE '_'
#define CROWNED_ONE '0'
#define CROWNED_TWO 'X'

// Define position struct
typedef struct position {
    int row;
    int col;
} Position;

// Initialize the game board
char board[BOARD_SIZE][BOARD_SIZE] = {
    {EMPTY_SPACE, PLAYER_ONE, EMPTY_SPACE, PLAYER_ONE, EMPTY_SPACE, PLAYER_ONE, EMPTY_SPACE, PLAYER_ONE},
    {PLAYER_ONE, EMPTY_SPACE, PLAYER_ONE, EMPTY_SPACE, PLAYER_ONE, EMPTY_SPACE, PLAYER_ONE, EMPTY_SPACE},
    {EMPTY_SPACE, PLAYER_ONE, EMPTY_SPACE, PLAYER_ONE, EMPTY_SPACE, PLAYER_ONE, EMPTY_SPACE, PLAYER_ONE},
    {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
    {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
    {PLAYER_TWO, EMPTY_SPACE, PLAYER_TWO, EMPTY_SPACE, PLAYER_TWO, EMPTY_SPACE, PLAYER_TWO, EMPTY_SPACE},
    {EMPTY_SPACE, PLAYER_TWO, EMPTY_SPACE, PLAYER_TWO, EMPTY_SPACE, PLAYER_TWO, EMPTY_SPACE, PLAYER_TWO},
    {PLAYER_TWO, EMPTY_SPACE, PLAYER_TWO, EMPTY_SPACE, PLAYER_TWO, EMPTY_SPACE, PLAYER_TWO, EMPTY_SPACE}
};

// Function Prototypes
void printBoard();
Position getPositionInput(char *prompt);
int isValidMove(Position start, Position end, char player);
void movePiece(Position start, Position end);
int checkForWinner();

// Main function
int main() {
    Position startPos, endPos;
    int winner = 0;
    char currentPlayer = PLAYER_ONE;
   
    // Main game loop
    while(!winner) {
        printBoard();
        printf("Player %c's turn:\n", currentPlayer);
        startPos = getPositionInput("Enter starting row and column:");
        endPos = getPositionInput("Enter ending row and column:");
       
        // Check if move is valid
        if(isValidMove(startPos, endPos, currentPlayer)) {
            movePiece(startPos, endPos);
            winner = checkForWinner();
           
            // Switch current player
            currentPlayer = currentPlayer == PLAYER_ONE ? PLAYER_TWO : PLAYER_ONE;
        }
        else {
            printf("Invalid move. Try again.\n");
        }
    }
   
    // Print winner
    printBoard();
    printf("Player %c wins!\n", currentPlayer == PLAYER_ONE ? PLAYER_TWO : PLAYER_ONE);
    return 0;
}

// Function to print the game board
void printBoard() {
    int i, j;
   
    printf("\n  0 1 2 3 4 5 6 7 \n");
    for(i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", i);
    }
    printf("  0 1 2 3 4 5 6 7 \n\n");
}

// Function to get position input from user
Position getPositionInput(char *prompt) {
    Position pos;
   
    printf("%s", prompt);
    scanf("%d %d", &pos.row, &pos.col);
    return pos;
}

// Function to check if move is valid
int isValidMove(Position start, Position end, char player) {
    int deltaX, deltaY;
   
    // Check if end position is within bounds
    if(end.row < 0 || end.row >= BOARD_SIZE || end.col < 0 || end.col >= BOARD_SIZE) {
        return 0;
    }
   
    // Check if end position is empty
    if(board[end.row][end.col] != EMPTY_SPACE) {
        return 0;
    }
   
    // Check if player can move in that diagonal direction
    if(player == PLAYER_ONE) {
        deltaY = start.row - end.row;
    }
    else {
        deltaY = end.row - start.row;
    }
   
    deltaX = abs(start.col - end.col);
    if(deltaY != -1 || deltaX != 1 && deltaX != 2) {
        return 0;
    }
   
    // Check if player is attempting a jump
    if(deltaX == 2) {
        // Check if jump is over an opponent's piece
        Position betweenPos;
        betweenPos.row = (start.row + end.row) / 2;
        betweenPos.col = (start.col + end.col) / 2;
       
        if(player == PLAYER_ONE && board[betweenPos.row][betweenPos.col] != PLAYER_TWO && board[betweenPos.row][betweenPos.col] != CROWNED_TWO) {
            return 0;
        }
        if(player == PLAYER_TWO && board[betweenPos.row][betweenPos.col] != PLAYER_ONE && board[betweenPos.row][betweenPos.col] != CROWNED_ONE) {
            return 0;
        }
    }
   
    // Return 1 if all checks pass
    return 1;
}

// Function to move a piece on the board
void movePiece(Position start, Position end) {
    char piece = board[start.row][start.col];
    board[start.row][start.col] = EMPTY_SPACE;
   
    // Crown the piece if it reaches the opposite side
    if(piece == PLAYER_ONE && end.row == BOARD_SIZE - 1) {
        piece = CROWNED_ONE;
    }
    if(piece == PLAYER_TWO && end.row == 0) {
        piece = CROWNED_TWO;
    }
   
    board[end.row][end.col] = piece;
   
    // Remove opponent's piece if jump was made
    if(abs(start.col - end.col) == 2) {
        Position betweenPos;
        betweenPos.row = (start.row + end.row) / 2;
        betweenPos.col = (start.col + end.col) / 2;
       
        board[betweenPos.row][betweenPos.col] = EMPTY_SPACE;
    }
}

// Function to check for a winner
int checkForWinner() {
    int i, j, playerOnePieceCount = 0, playerTwoPieceCount = 0;
   
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == PLAYER_ONE || board[i][j] == CROWNED_ONE) {
                playerOnePieceCount++;
            }
            if(board[i][j] == PLAYER_TWO || board[i][j] == CROWNED_TWO) {
                playerTwoPieceCount++;
            }
        }
    }
   
    if(playerOnePieceCount == 0 || playerTwoPieceCount == 0) {
        return 1;
    }
   
    return 0;
}