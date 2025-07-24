//FormAI DATASET v1.0 Category: Checkers Game ; Style: excited
#include <stdio.h>

// The board is an 8x8 grid
#define BOARD_DIMENSION 8

// Constants for board pieces
#define EMPTY ' '
#define RED 'R'
#define BLACK 'B'

// Struct to represent a checker piece
typedef struct CheckerPiece {
    char color;
    int row;
    int col;
} CheckerPiece;

// Function to print the current state of the board
void printBoard(char board[][BOARD_DIMENSION]) {
    printf("\n");
    printf("   0 1 2 3 4 5 6 7\n"); // Column labels
    printf("  -----------------\n");
    
    // Rows
    for (int i = 0; i < BOARD_DIMENSION; i++) {
        printf("%d ", i); // Row labels
        printf("|%c|%c|%c|%c|%c|%c|%c|%c|%d\n",
            board[i][0], board[i][1], board[i][2], board[i][3],
            board[i][4], board[i][5], board[i][6], board[i][7], i); // Board contents
        printf("  -----------------\n");
    }
    
    printf("   0 1 2 3 4 5 6 7\n"); // Column labels
    printf("\n");
}

// Function to initialize the board with pieces in their starting positions
void initializeBoard(char board[][BOARD_DIMENSION]) {
    // Initialize all spaces to empty
    for (int i = 0; i < BOARD_DIMENSION; i++) {
        for (int j = 0; j < BOARD_DIMENSION; j++) {
            board[i][j] = EMPTY;
        }
    }
    
    // Initialize black pieces
    board[0][1] = BLACK;
    board[0][3] = BLACK;
    board[0][5] = BLACK;
    board[0][7] = BLACK;
    board[1][0] = BLACK;
    board[1][2] = BLACK;
    board[1][4] = BLACK;
    board[1][6] = BLACK;
    board[2][1] = BLACK;
    board[2][3] = BLACK;
    board[2][5] = BLACK;
    board[2][7] = BLACK;
    
    // Initialize red pieces
    board[5][0] = RED;
    board[5][2] = RED;
    board[5][4] = RED;
    board[5][6] = RED;
    board[6][1] = RED;
    board[6][3] = RED;
    board[6][5] = RED;
    board[6][7] = RED;
    board[7][0] = RED;
    board[7][2] = RED;
    board[7][4] = RED;
    board[7][6] = RED;
}

// Function to move a checker piece to the specified location
void movePiece(char board[][BOARD_DIMENSION], CheckerPiece *piece, int row, int col) {
    board[piece->row][piece->col] = EMPTY;
    piece->row = row;
    piece->col = col;
    board[piece->row][piece->col] = piece->color;
}

// Function to check if a move is valid
int isValidMove(char board[][BOARD_DIMENSION], CheckerPiece *piece, int row, int col) {
    // Check if destination is out of bounds
    if (row < 0 || row >= BOARD_DIMENSION || col < 0 || col >= BOARD_DIMENSION) {
        return 0;
    }
    
    // Check if destination is not empty
    if (board[row][col] != EMPTY) {
        return 0;
    }
    
    // Determine direction of move based on piece color
    int dir;
    if (piece->color == BLACK) {
        dir = 1;
    } else { // RED
        dir = -1;
    }
    
    // Check if move is diagonal
    int rowDiff = row - piece->row;
    int colDiff = col - piece->col;
    if (rowDiff != dir || (colDiff != 1 && colDiff != -1)) {
        return 0;
    }
    
    // Valid move
    return 1;
}

// Function to check if the specified player has any valid moves left
int hasValidMoves(char board[][BOARD_DIMENSION], char player) {
    CheckerPiece piece;
    int rowDiff, colDiff;
    
    // Iterate over all pieces on the board
    for (int i = 0; i < BOARD_DIMENSION; i++) {
        for (int j = 0; j < BOARD_DIMENSION; j++) {
            // Check if this is a piece belonging to the specified player
            if (board[i][j] == player) {
                piece.color = player;
                piece.row = i;
                piece.col = j;
                
                // Check all possible moves for this piece
                for (int k = -1; k <= 1; k += 2) { // Iterate over -1 and 1
                    rowDiff = k;
                    colDiff = -1;
                    if (isValidMove(board, &piece, piece.row + rowDiff, piece.col + colDiff)) {
                        return 1;
                    }
                    colDiff = 1;
                    if (isValidMove(board, &piece, piece.row + rowDiff, piece.col + colDiff)) {
                        return 1;
                    }
                }
            }
        }
    }
    
    // No valid moves found
    return 0;
}

// Function to check if a capture is possible by moving to the specified location
int isCapturePossible(char board[][BOARD_DIMENSION], CheckerPiece *piece, int row, int col) {
    // Check if destination is out of bounds
    if (row < 0 || row >= BOARD_DIMENSION || col < 0 || col >= BOARD_DIMENSION) {
        return 0;
    }
    
    // Check if destination is not empty
    if (board[row][col] != EMPTY) {
        return 0;
    }
    
    // Determine direction of move based on piece color
    int dir;
    if (piece->color == BLACK) {
        dir = 1;
    } else { // RED
        dir = -1;
    }
    
    // Check if move is diagonal
    int rowDiff = row - piece->row;
    int colDiff = col - piece->col;
    if (rowDiff != dir*2 || (colDiff != 2 && colDiff != -2)) {
        return 0;
    }
    
    // Check if there is an opposite-colored piece in between the current and destination locations
    if (board[piece->row + dir][piece->col + colDiff/2] == EMPTY) {
        return 0;
    } else if (board[piece->row + dir][piece->col + colDiff/2] == piece->color) {
        return 0;
    }
    
    // Capture is possible
    return 1;
}

// Function to perform a capture move by moving the piece to the specified location and removing the captured piece
void performCapture(char board[][BOARD_DIMENSION], CheckerPiece *piece, int row, int col) {
    // Remove the captured piece from the board
    board[piece->row + (row - piece->row)/2][piece->col + (col - piece->col)/2] = EMPTY;
    
    // Move the capturing piece to the specified location
    movePiece(board, piece, row, col);
}

// Function to check if any capture moves are available for the specified player
int hasCaptureMoves(char board[][BOARD_DIMENSION], char player) {
    CheckerPiece piece;
    int rowDiff, colDiff;
    
    // Iterate over all pieces on the board
    for (int i = 0; i < BOARD_DIMENSION; i++) {
        for (int j = 0; j < BOARD_DIMENSION; j++) {
            // Check if this is a piece belonging to the specified player
            if (board[i][j] == player) {
                piece.color = player;
                piece.row = i;
                piece.col = j;
                
                // Check all possible moves for this piece
                for (int k = -1; k <= 1; k += 2) { // Iterate over -1 and 1
                    rowDiff = k;
                    colDiff = -1;
                    if (isCapturePossible(board, &piece, piece.row + rowDiff*2, piece.col + colDiff*2)) {
                        return 1;
                    }
                    colDiff = 1;
                    if (isCapturePossible(board, &piece, piece.row + rowDiff*2, piece.col + colDiff*2)) {
                        return 1;
                    }
                }
            }
        }
    }
    
    // No capture moves found
    return 0;
}

// Function to perform a move by moving the piece to the specified location
void performMove(char board[][BOARD_DIMENSION], CheckerPiece *piece, int row, int col) {
    // Move piece to specified location
    movePiece(board, piece, row, col);
}

// Function to get the user's move input and update the board accordingly
void makeMove(char board[][BOARD_DIMENSION], char player) {
    CheckerPiece piece;
    int row, col;
    
    while (1) {
        // Prompt user for move
        printf("%c's turn\n", player);
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &row, &col);
        
        // Check if selected piece belongs to the specified player
        if (board[row][col] != player) {
            printf("That piece does not belong to you. Please try again.\n");
            continue;
        }
        
        // Set checker piece struct
        piece.color = player;
        piece.row = row;
        piece.col = col;
        
        // Check if the piece has any valid moves
        if (!isValidMove(board, &piece, row+1, col-1) && !isValidMove(board, &piece, row+1, col+1)) {
            printf("That piece has no valid moves. Please select another piece.\n");
            continue;
        }
        
        // Check if the piece has any capture moves
        if (hasCaptureMoves(board, player)) {
            int captureMovesOnly = 0;
            while (1) {
                printf("Capture move available. Enter the row and column of the destination space to perform the capture: ");
                scanf("%d %d", &row, &col);
                
                // Check if this is a valid capture move
                if (!isCapturePossible(board, &piece, row, col)) {
                    printf("That is not a valid capture move. Please try again.\n");
                    captureMovesOnly = 1;
                    continue;
                }
                
                // Perform capture move
                performCapture(board, &piece, row, col);
                
                // Check if there are any additional capture moves
                if (isCapturePossible(board, &piece, row+2, col-2) ||
                        isCapturePossible(board, &piece, row+2, col+2) ||
                        isCapturePossible(board, &piece, row-2, col-2) ||
                        isCapturePossible(board, &piece, row-2, col+2)) {
                    printf("Additional capture move available. Please continue capturing.\n");
                } else {
                    return;
                }
            }
        } else {
            while (1) {
                printf("Enter the row and column of the destination space for your piece: ");
                scanf("%d %d", &row, &col);
                
                // Check if this is a valid move
                if (!isValidMove(board, &piece, row, col)) {
                    printf("That is not a valid move. Please try again.\n");
                    continue;
                }
                
                // Perform move
                performMove(board, &piece, row, col);
                
                return;
            }
        }
    }
}

int main() {
    // Create empty board
    char board[BOARD_DIMENSION][BOARD_DIMENSION];
    
    // Initialize board with pieces in starting positions
    initializeBoard(board);
    
    // Print initial board state
    printBoard(board);
    
    // Game loop
    char currentPlayer = RED; // RED goes first
    while (1) {
        // Check if current player has any valid moves left
        if (!hasValidMoves(board, currentPlayer)) {
            printf("%c has no valid moves left. Other player wins!", currentPlayer);
            return 0;
        }
        
        // Make move for current player
        makeMove(board, currentPlayer);
        
        // Print updated board state
        printBoard(board);
        
        // Switch to other player
        if (currentPlayer == RED) {
            currentPlayer = BLACK;
        } else {
            currentPlayer = RED;
        }
    }
}