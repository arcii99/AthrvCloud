//FormAI DATASET v1.0 Category: Checkers Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum{EMPTY, RED, BLACK} PieceColor;
typedef struct{
    PieceColor pieceColor;
    int isKing;
}Piece;

Piece board[BOARD_SIZE][BOARD_SIZE];

//Initialize the board with pieces
void initializeBoard(){
    int row, col;
    for(row=0; row<BOARD_SIZE; row++){
        for(col=0; col<BOARD_SIZE; col++){
            if((row+col)%2 == 0){
                if(row < 3){
                    board[row][col].pieceColor = BLACK;
                    board[row][col].isKing = 0;
                }
                else if(row > 4){
                    board[row][col].pieceColor = RED;
                    board[row][col].isKing = 0;
                }
                else{
                    board[row][col].pieceColor = EMPTY;
                    board[row][col].isKing = 0;
                }
            }
            else{
                board[row][col].pieceColor = EMPTY;
                board[row][col].isKing = 0;
            }
        }
    }
}

//Print the current state of the board
void printBoard(){
    int row, col;
    printf("\n   ");
    for(col=0; col<BOARD_SIZE; col++){
        printf("%d ", col);
    }
    printf("\n");
    
    for(row=0; row<BOARD_SIZE; row++){
        printf("%d ", row);
        for(col=0; col<BOARD_SIZE; col++){
            switch(board[row][col].pieceColor){
                case EMPTY:
                    printf("- ");
                    break;
                case RED:
                    if(board[row][col].isKing){
                        printf("K ");
                    }
                    else{
                        printf("R ");
                    }
                    break;
                case BLACK:
                    if(board[row][col].isKing){
                        printf("K ");
                    }
                    else{
                        printf("B ");
                    }
                    break;
            }
        }
        printf("\n");
    }
}

//Check if a move is valid
int isValidMove(int startRow, int startCol, int destRow, int destCol, PieceColor player){
    //Check if destination is within the bounds of the board
    if(destRow<0 || destRow>=BOARD_SIZE || destCol<0 || destCol>=BOARD_SIZE){
        return 0;
    }
    //Check if destination is empty
    if(board[destRow][destCol].pieceColor != EMPTY){
        return 0;
    }
    //Check if player is moving their own piece
    if(board[startRow][startCol].pieceColor != player){
        return 0;
    }
    //Check if player is moving a king piece the correct amount of spaces
    if(board[startRow][startCol].isKing && abs(destRow-startRow) != abs(destCol-startCol)){
        return 0;
    }
    //Check if player is moving a non-king piece in the correct direction
    if(!board[startRow][startCol].isKing){
        if(player == RED && destRow > startRow){
            return 0;
        }
        if(player == BLACK && destRow < startRow){
            return 0;
        }
        //Check if player is moving piece only one diagonal space
        if(abs(destRow-startRow) != 1 || abs(destCol-startCol) != 1){
            return 0;
        }
    }
    return 1;
}

//Move a piece on the board
void movePiece(int startRow, int startCol, int destRow, int destCol){
    board[destRow][destCol] = board[startRow][startCol];
    board[startRow][startCol].pieceColor = EMPTY;
    board[startRow][startCol].isKing = 0;
    //Check if piece has become a king
    if(board[destRow][destCol].pieceColor == BLACK && destRow == 0){
        board[destRow][destCol].isKing = 1;
    }
    if(board[destRow][destCol].pieceColor == RED && destRow == BOARD_SIZE-1){
        board[destRow][destCol].isKing = 1;
    }
}

//Check if player has won the game
int checkWin(PieceColor player){
    int row, col, playerCount=0;
    for(row=0; row<BOARD_SIZE; row++){
        for(col=0; col<BOARD_SIZE; col++){
            if(board[row][col].pieceColor == player){
                playerCount++;
            }
        }
    }
    if(playerCount == 0){
        return 1;
    }
    else{
        return 0;
    }
}

//Play the game
void playGame(){
    PieceColor currentPlayer = RED;
    int startRow, startCol, destRow, destCol;
    
    while(1){
        printBoard();
        printf("Player %d's turn\n", currentPlayer);
        printf("Enter the starting row and column of the piece to move: ");
        scanf("%d %d", &startRow, &startCol);
        printf("Enter the destination row and column: ");
        scanf("%d %d", &destRow, &destCol);
        if(isValidMove(startRow, startCol, destRow, destCol, currentPlayer)){
            movePiece(startRow, startCol, destRow, destCol);
            if(currentPlayer == RED){
                currentPlayer = BLACK;
            }
            else{
                currentPlayer = RED;
            }
            if(checkWin(currentPlayer)){
                printf("Player %d has won the game!\n", currentPlayer);
                break;
            }
        }
        else{
            printf("Invalid move!\n");
        }
    }
}

int main(){
    initializeBoard();
    playGame();
    return 0;
}