//FormAI DATASET v1.0 Category: Checkers Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BOARD_SIZE 8
#define MAX_PIECES 24

// Piece is a struct containing its type and its position
typedef struct {
    char type;
    int row;
    int column;
} Piece;

// Function to initialize the board with pieces
void initializeBoard(Piece* board) {
    int i, j, pieceCount = 0;
    char pieceTypes[] = {'m', 'M', 'd', 'D'};
    
    // Initialize the black pieces
    for (i = 0; i < 3; i++) {
        for (j = (i+1)%2; j < BOARD_SIZE; j += 2) {
            board[pieceCount].type = pieceTypes[i];
            board[pieceCount].row = i;
            board[pieceCount].column = j;
            pieceCount++;
        }
    }
    
    // Initialize the white pieces
    for (i = 0; i < 3; i++) {
        for (j = (i+1)%2; j < BOARD_SIZE; j += 2) {
            board[pieceCount].type = toupper(pieceTypes[i]);
            board[pieceCount].row = BOARD_SIZE-1-i;
            board[pieceCount].column = j;
            pieceCount++;
        }
    }
}

// Function to print the board with pieces
void printBoard(Piece* board) {
    int i, j;
    
    printf("\n    0   1   2   3   4   5   6   7\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            Piece p; int k;
            for (k = 0; k < MAX_PIECES; k++)
                if (board[k].row == i && board[k].column == j)
                    p = board[k];
            printf(" %c |", p.type);
        }
        printf("\n  +---+---+---+---+---+---+---+---+\n");
    }
}

// Function to get the piece at a given position
Piece getPieceAtPosition(Piece* board, int row, int column) {
    int i;

    for (i = 0; i < MAX_PIECES; i++) {
        if (board[i].row == row && board[i].column == column) {
            return board[i];
        }
    }

    Piece emptyPiece = {'.', -1, -1};
    return emptyPiece;
}
 
// Function to check if a move is valid or not
int isValidMove(Piece* board, int startRow, int startColumn, int endRow, int endColumn, int player) {
    Piece startPiece = getPieceAtPosition(board, startRow, startColumn);
    Piece endPiece = getPieceAtPosition(board, endRow, endColumn);
    
    // Check if the start position is valid
    if (startPiece.type == '.' || startPiece.type == ' ') {
        return 0;
    }

    // Check if the end position is valid
    if (endPiece.type != '.') {
        return 0;
    }
    
    // Check if the start and end positions are in the same diagonal
    int rowDiff = endRow - startRow;
    int colDiff = endColumn - startColumn;
    if (abs(rowDiff) != abs(colDiff)) {
        return 0;
    }
    
    // Check if the move is a jump
    if (abs(rowDiff) > 1) {
        int jumpRow = startRow + rowDiff / 2;
        int jumpColumn = startColumn + colDiff / 2;
        Piece jumpPiece = getPieceAtPosition(board, jumpRow, jumpColumn);
        
        if (jumpPiece.type == '.' || jumpPiece.type == ' ' || jumpPiece.type == startPiece.type || toupper(jumpPiece.type) == toupper(startPiece.type) || (player == 1 && islower(jumpPiece.type)) || (player == 2 && isupper(jumpPiece.type))) {
            return 0;
        } else {
            return 2;
        }
    }

    // Check if the move is a move forward
    if (player == 1 && rowDiff > 0 && startPiece.type == 'm' && endRow != BOARD_SIZE-1) {
        return 0;
    }
    if (player == 2 && rowDiff < 0 && startPiece.type == 'M' && endRow != 0) {
        return 0;
    }
    
    // Check if the move is a regular move
    if (endRow < startRow && toupper(startPiece.type) == toupper(player == 1 ? 'm' : 'M')) {
        return 0;
    }
    if (endRow > startRow && toupper(startPiece.type) == toupper(player == 2 ? 'm' : 'M')) {
        return 0;
    }
    
    return 1;
}

// Function to make a move on the board
void makeMove(Piece* board, int startRow, int startColumn, int endRow, int endColumn) {
    Piece startPiece = getPieceAtPosition(board, startRow, startColumn);
    Piece endPiece = getPieceAtPosition(board, endRow, endColumn);
    
    // Check if the move is a jump
    if (abs(endRow-startRow) > 1) {
        int jumpRow = startRow + (endRow-startRow)/2;
        int jumpColumn = startColumn + (endColumn-startColumn)/2;
        Piece jumpPiece = getPieceAtPosition(board, jumpRow, jumpColumn);
        
        // Remove the jumped piece and place the current piece in the end position
        int i, k = -1;
        for (i = 0; i < MAX_PIECES; i++) {
            if (board[i].row == jumpRow && board[i].column == jumpColumn) {
                k = i;
                break;
            }
        }
        if (k != -1) {
            board[k] = (Piece) {'.', -1, -1};
        }
    }
    
    // Move the current piece to the end position
    int i, k = -1;
    for (i = 0; i < MAX_PIECES; i++) {
        if (board[i].row == startRow && board[i].column == startColumn) {
            k = i;
            break;
        }
    }
    if (k != -1) {
        board[k].row = endRow;
        board[k].column = endColumn;
        
        // Make the piece a king if it reaches the last row
        if ((board[k].type == 'm' && endRow == BOARD_SIZE-1) || (board[k].type == 'M' && endRow == 0)) {
            board[k].type = toupper(board[k].type);
        }
    }
}

// Function to check if the game has ended and print the winner
int checkGame(Piece* board) {
    int i, blackCount = 0, whiteCount = 0;
    
    // Check if all pieces of a player have been captured
    for (i = 0; i < MAX_PIECES; i++) {
        if (board[i].type == 'm' || board[i].type == 'M') {
            if (islower(board[i].type)) {
                blackCount++;
            } else {
                whiteCount++;
            }
        }
    }
    if (blackCount == 0) {
        printf("\nCongratulations! White wins the game!\n");
        return 1;
    }
    if (whiteCount == 0) {
        printf("\nCongratulations! Black wins the game!\n");
        return 1;
    }
    
    return 0;
}

int main() {
    // Initialization
    Piece board[MAX_PIECES];
    initializeBoard(board);
    int player = 1;
    
    // Game loop
    while (1) {
        printBoard(board);
        
        int startRow, startColumn, endRow, endColumn, validMove;
        char input[10];
        
        // Get the starting position and make sure it is valid
        do {
            printf("\nPlayer %d, enter the starting position: ", player);
            scanf("%s", input);
            startRow = input[0] - '0';
            startColumn = input[1] - '0';
            if (startRow < 0 || startRow >= BOARD_SIZE || startColumn < 0 || startColumn >= BOARD_SIZE) {
                printf("Invalid starting position. Try again.\n");
                continue;
            }
            validMove = 0;
            int i;
            for (i = 0; i < MAX_PIECES; i++) {
                if (board[i].row == startRow && board[i].column == startColumn) {
                    if ((toupper(board[i].type) == player == 1 ? 'm' : 'M') || (player == 2 && islower(board[i].type)) || (player == 1 && isupper(board[i].type))) {
                        validMove = 1;
                    }
                }
            }
            if (!validMove) {
                printf("Invalid starting position. Try again.\n");
            }
        } while (!validMove);
        
        // Get the ending position and make sure it is valid 
        do {
            printf("Player %d, enter the ending position: ", player);
            scanf("%s", input);
            endRow = input[0] - '0';
            endColumn = input[1] - '0';
            if (endRow < 0 || endRow >= BOARD_SIZE || endColumn < 0 || endColumn >= BOARD_SIZE) {
                printf("Invalid ending position. Try again.\n");
                continue;
            }
            validMove = isValidMove(board, startRow, startColumn, endRow, endColumn, player);
            if (validMove == 0) {
                printf("Invalid move. Try again.\n");
            }
        } while (validMove == 0);
        
        // Make the move
        makeMove(board, startRow, startColumn, endRow, endColumn);
        
        // Check if the game has ended
        if (checkGame(board)) {
            break;
        }
        
        // Switch players
        player = player == 1 ? 2 : 1;
    }
    
    return 0;
}