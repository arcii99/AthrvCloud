//FormAI DATASET v1.0 Category: Checkers Game ; Style: careful
#include<stdio.h>
#include<stdlib.h>

#define BOARD_SIZE 8

// Function to print the board
void printBoard(char board[][BOARD_SIZE]){
    printf("\n");
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the board with pieces
void initBoard(char board[][BOARD_SIZE]){
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            if((i+j)%2 == 0 && i<3) board[i][j] = 'B'; // Black pieces
            else if((i+j)%2 == 0 && i>=5) board[i][j] = 'W'; // White pieces
            else board[i][j] = ' '; // Empty squares
        }
    }
}

// Function to check if move is legal
int isValidMove(char board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, char player){

    // Check if toRow and toCol are within board boundaries
    if(toRow<0 || toCol<0 || toRow>=BOARD_SIZE || toCol>=BOARD_SIZE){
        printf("Invalid move. Please try again.\n");
        return 0;
    }
    // Check if destination square is empty
    if(board[toRow][toCol] != ' '){
        printf("Destination square is not empty. Please try again.\n");
        return 0;
    }
    // Check if player is moving in the right direction
    if(player == 'B' && fromRow>=toRow){
        printf("Black can only move downwards. Please try again.\n");
        return 0;
    }
    if(player == 'W' && fromRow<=toRow){
        printf("White can only move upwards. Please try again.\n");
        return 0;
    }
    // Check if the square is diagonal to the source square
    if(abs(fromRow-toRow) != abs(fromCol-toCol)){
        printf("Invalid move. Please try again.\n");
        return 0;
    }
    // Check if the player is only moving one square diagonally
    if(abs(fromRow-toRow) > 1 || abs(fromCol-toCol) > 1){
        printf("Invalid move. Please try again.\n");
        return 0;
    }
    // Check if the player is jumping over an opponent's piece
    if(abs(fromRow-toRow) == 2 && abs(fromCol-toCol) == 2){
        int midRow = (fromRow+toRow)/2;
        int midCol = (fromCol+toCol)/2;
        if(board[midRow][midCol] == ' ') {
            printf("Invalid move. Please try again.\n");
            return 0;
        }
        if((player == 'B' && board[midRow][midCol] != 'W') || (player == 'W' && board[midRow][midCol] != 'B')){
            printf("Invalid move. Please try again.\n");
            return 0;
        }
    }
    return 1;
}

// Function to make the move
void makeMove(char board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol, char player){
    board[toRow][toCol] = player;
    board[fromRow][fromCol] = ' ';
    // If player is jumping over opponent's piece, remove it
    if(abs(fromRow-toRow) == 2 && abs(fromCol-toCol) == 2){
        int midRow = (fromRow+toRow)/2;
        int midCol = (fromCol+toCol)/2;
        board[midRow][midCol] = ' ';
    }
}

// Function to check if the game is over
int isGameOver(char board[][BOARD_SIZE]){
    int countB = 0;
    int countW = 0;
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            if(board[i][j] == 'B') countB++;
            else if(board[i][j] == 'W') countW++;
        }
    }
    if(countB == 0) {
        printf("\nGame over. White wins!\n");
        return 1;
    }
    if(countW == 0) {
        printf("\nGame over. Black wins!\n");
        return 1;
    }
    return 0;
}

int main(){
    char board[BOARD_SIZE][BOARD_SIZE];
    int fromRow, fromCol, toRow, toCol;
    char player = 'B';

    initBoard(board);
    printBoard(board);
    while(1){
        printf("\n%s's turn.\n", (player=='B'?"Black":"White"));
        printf("Enter move from/to coordinates (ex: 1,2 to 2,3): ");
        scanf("%d,%d to %d,%d", &fromRow, &fromCol, &toRow, &toCol);

        if(isValidMove(board, fromRow, fromCol, toRow, toCol, player)){
            makeMove(board, fromRow, fromCol, toRow, toCol, player);
            printBoard(board);
            if(isGameOver(board)) break;
            player = (player=='B'?'W':'B');
        }
    }
    return 0;
}