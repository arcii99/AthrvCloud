//FormAI DATASET v1.0 Category: Chess AI ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

//Piece Constants
#define EMPTY 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

//Player Constants
#define PLAYER1 1
#define PLAYER2 -1

//Function to print board
void printBoard(int board[][BOARD_SIZE]) {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Function to check if a move is within the bounds of the board
int inBounds(int row, int col) {
    if(row < 0 || col < 0 || row >= BOARD_SIZE || col >= BOARD_SIZE) {
        return 0;
    }
    return 1;
}

//Function to check if a move is a valid move for a pawn
int isValidPawnMove(int board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, int player) {
    //Movement direction for player 1 and player 2
    int dir = player == PLAYER1? 1 : -1;
    
    //Checking if the move is within the bounds of the board
    if(!inBounds(toRow, toCol)) {
        return 0;
    }
    
    //If pawn is moving forward
    if(toCol == fromCol) {
        //If moving one square forward
        if(toRow == fromRow + dir && board[fromRow+dir][fromCol] == EMPTY) {
            return 1;
        }
        //If moving two squares forward
        else if(toRow == fromRow + 2*dir && fromRow == (player == PLAYER1? 1 : 6) && board[fromRow+dir][fromCol] == EMPTY && board[fromRow+2*dir][fromCol] == EMPTY) {
            return 1;
        }    
    }
    //If pawn is capturing a piece
    else if(abs(toCol - fromCol) == 1 && toRow == fromRow + dir) {
        if(board[toRow][toCol] * player < 0) {
            return 1;
        }
    }
    return 0;
}

//Function to check if a move is valid for a knight
int isValidKnightMove(int board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, int player) {
    //Checking if the move is within the bounds of the board
    if(!inBounds(toRow, toCol)) {
        return 0;
    }
    //Checking if the move is a valid L shape move
    if(abs(toRow - fromRow) == 2 && abs(toCol - fromCol) == 1 || abs(toRow - fromRow) == 1 && abs(toCol - fromCol) == 2) {
        if(board[toRow][toCol] * player <= 0) {
            return 1;
        }
    }
    return 0;
}

//Function to check if a move is valid for a bishop
int isValidBishopMove(int board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, int player) {
    //Checking if the move is within the bounds of the board
    if(!inBounds(toRow, toCol)) {
        return 0;
    }
    //Checking if the move is a diagonal move
    int rowDiff = toRow - fromRow;
    int colDiff = toCol - fromCol;
    if(abs(rowDiff) == abs(colDiff)) {
        //Checking if there are any pieces in the bishop's path
        int dirRow = rowDiff > 0? 1 : -1;
        int dirCol = colDiff > 0? 1 : -1;
        for(int i=1; i<abs(rowDiff); i++) {
            if(board[fromRow+i*dirRow][fromCol+i*dirCol] != EMPTY) {
                return 0;
            }
        }
        if(board[toRow][toCol] * player <= 0) {
            return 1;
        }
    }
    return 0;
}

//Function to check if a move is valid for a rook
int isValidRookMove(int board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, int player) {
    //Checking if the move is within the bounds of the board
    if(!inBounds(toRow, toCol)) {
        return 0;
    }
    //Checking if the move is a vertical or horizontal move
    int rowDiff = toRow - fromRow;
    int colDiff = toCol - fromCol;
    if(rowDiff == 0 || colDiff == 0) {
        //Checking if there are any pieces in the rook's path
        int dirRow = rowDiff > 0? 1 : -1;
        int dirCol = colDiff > 0? 1 : -1;
        for(int i=1; i<abs(rowDiff); i++) {
            if(board[fromRow+i*dirRow][fromCol+i*dirCol] != EMPTY) {
                return 0;
            }
        }
        if(board[toRow][toCol] * player <= 0) {
            return 1;
        }
    }
    return 0;
}

//Function to check if a move is valid for a queen
int isValidQueenMove(int board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, int player) {
    //Checking if the move is within the bounds of the board
    if(!inBounds(toRow, toCol)) {
        return 0;
    }
    //Checking if the move is a diagonal, vertical or horizontal move
    int rowDiff = toRow - fromRow;
    int colDiff = toCol - fromCol;
    if(abs(rowDiff) == abs(colDiff) || rowDiff == 0 || colDiff == 0) {
        if(abs(rowDiff) == abs(colDiff)) {
            //Checking if there are any pieces in the bishop's path
            int dirRow = rowDiff > 0? 1 : -1;
            int dirCol = colDiff > 0? 1 : -1;
            for(int i=1; i<abs(rowDiff); i++) {
                if(board[fromRow+i*dirRow][fromCol+i*dirCol] != EMPTY) {
                    return 0;
                }
            }
        }
        else if(rowDiff == 0) {
            //Checking if there are any pieces in the rook's path
            int dirCol = colDiff > 0? 1 : -1;
            for(int i=1; i<abs(colDiff); i++) {
                if(board[fromRow][fromCol+i*dirCol] != EMPTY) {
                    return 0;
                }
            }
        }
        else {
            //Checking if there are any pieces in the rook's path
            int dirRow = rowDiff > 0? 1 : -1;
            for(int i=1; i<abs(rowDiff); i++) {
                if(board[fromRow+i*dirRow][fromCol] != EMPTY) {
                    return 0;
                }
            }
        }
        if(board[toRow][toCol] * player <= 0) {
            return 1;
        }
    }
    return 0;
}

//Function to check if a move is valid for a king
int isValidKingMove(int board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, int player) {
    //Checking if the move is within the bounds of the board
    if(!inBounds(toRow, toCol)) {
        return 0;
    }
    //Checking if the move is a valid move for a king (one square in any direction)
    if(abs(fromRow-toRow) <= 1 && abs(fromCol-toCol) <= 1) {
        if(board[toRow][toCol] * player <= 0) {
            return 1;
        }
    }
    return 0;
}

//Function to check if a move is valid overall
int isValidMove(int board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, int player) {
    //Checking if the piece being moved belongs to the player
    if(board[fromRow][fromCol] * player <= 0) {
        return 0;
    }
    //Checking if the move is a valid move for the piece being moved
    switch(abs(board[fromRow][fromCol])) {
        case PAWN:
            return isValidPawnMove(board, fromRow, fromCol, toRow, toCol, player);
        case KNIGHT:
            return isValidKnightMove(board, fromRow, fromCol, toRow, toCol, player);
        case BISHOP:
            return isValidBishopMove(board, fromRow, fromCol, toRow, toCol, player);
        case ROOK:
            return isValidRookMove(board, fromRow, fromCol, toRow, toCol, player);
        case QUEEN:
            return isValidQueenMove(board, fromRow, fromCol, toRow, toCol, player);
        case KING:
            return isValidKingMove(board, fromRow, fromCol, toRow, toCol, player);
        default:
            return 0;
    }
}

//Function to simulate a move
void simulateMove(int board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, int player) {
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = EMPTY;
}

//Function to check if a player is in check
int isCheck(int board[][BOARD_SIZE], int player) {
    int kingRow, kingCol;
    //Finding the row and column of king belonging to the player
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == KING*player) {
                kingRow = i;
                kingCol = j;
            }
        }
    }
    //Checking if any opponents pieces are attacking the king
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] * player < 0 && isValidMove(board, i, j, kingRow, kingCol, -player)) {
                return 1;
            }
        }
    }
    return 0;
}

//Function to check if a player has any move available
int hasMove(int board[][BOARD_SIZE], int player) {
    //Checking if any piece can move to any other square on the board
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] * player > 0) {
                for(int k=0; k<BOARD_SIZE; k++) {
                    for(int l=0; l<BOARD_SIZE; l++) {
                        if(isValidMove(board, i, j, k, l, player)) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

//Function to check if a player is in checkmate
int isCheckmate(int board[][BOARD_SIZE], int player) {
    //Checking if the player is in check
    if(!isCheck(board, player)) {
        return 0;
    }
    //Checking if any move can take the king out of check
    if(hasMove(board, player)) {
        return 0;
    }
    return 1;
}

//Function to get the player's move from the console
void getPlayerMove(int board[][BOARD_SIZE], int player, int *fromRow, int *fromCol, int *toRow, int *toCol) {
    printf("Player %d's turn\n", player);
    //Getting the starting row and column of the piece to be moved
    do {
        printf("Enter the row and column number of the piece to be moved (ex: 0 3): ");
        scanf("%d %d", fromRow, fromCol);
    } while(board[*fromRow][*fromCol] * player <= 0);
    //Getting the row and column of the square where the piece will be moved to
    do {
        printf("Enter the row and column number of the square to move the piece to (ex: 1 3): ");
        scanf("%d %d", toRow, toCol);
    } while(!isValidMove(board, *fromRow, *fromCol, *toRow, *toCol, player));
}

//Function to get a random move for the computer player
void getComputerMove(int board[][BOARD_SIZE], int player, int *fromRow, int *fromCol, int *toRow, int *toCol) {
    int validMoveFound = 0;
    //Finding a random piece belonging to the player and a random square to move it to
    while(!validMoveFound) {
        *fromRow = rand() % BOARD_SIZE;
        *fromCol = rand() % BOARD_SIZE;
        if(board[*fromRow][*fromCol] * player > 0) {
            *toRow = rand() % BOARD_SIZE;
            *toCol = rand() % BOARD_SIZE;
            if(isValidMove(board, *fromRow, *fromCol, *toRow, *toCol, player)) {
                validMoveFound = 1;
            }
        }
    }
}

int main() {
    //Initializing the board
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {ROOK*PLAYER2, KNIGHT*PLAYER2, BISHOP*PLAYER2, QUEEN*PLAYER2, KING*PLAYER2, BISHOP*PLAYER2, KNIGHT*PLAYER2, ROOK*PLAYER2},
        {PAWN*PLAYER2, PAWN*PLAYER2, PAWN*PLAYER2, PAWN*PLAYER2, PAWN*PLAYER2, PAWN*PLAYER2, PAWN*PLAYER2, PAWN*PLAYER2},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {PAWN*PLAYER1, PAWN*PLAYER1, PAWN*PLAYER1, PAWN*PLAYER1, PAWN*PLAYER1, PAWN*PLAYER1, PAWN*PLAYER1, PAWN*PLAYER1},
        {ROOK*PLAYER1, KNIGHT*PLAYER1, BISHOP*PLAYER1, QUEEN*PLAYER1, KING*PLAYER1, BISHOP*PLAYER1, KNIGHT*PLAYER1, ROOK*PLAYER1}
    };
    int currentPlayer = PLAYER1;
    int gameEnded = 0;
    int fromRow, fromCol, toRow, toCol;
    while(!gameEnded) {
        printBoard(board);
        if(currentPlayer == PLAYER1) {
            getPlayerMove(board, currentPlayer, &fromRow, &fromCol, &toRow, &toCol);
        }
        else {
            getComputerMove(board, currentPlayer, &fromRow, &fromCol, &toRow, &toCol);
            printf("Computer moves from (%d, %d) to (%d, %d)\n", fromRow, fromCol, toRow, toCol);
        }
        //Simulating the move
        simulateMove(board, fromRow, fromCol, toRow, toCol, currentPlayer);
        //Checking if the opponent is in checkmate
        if(isCheckmate(board, -currentPlayer)) {
            printf("Player %d wins!\n", currentPlayer);
            gameEnded = 1;
        }
        //Switching to the other player's turn
        currentPlayer *= -1;
    }
    return 0;
}