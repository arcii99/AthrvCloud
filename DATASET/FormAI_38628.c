//FormAI DATASET v1.0 Category: Checkers Game ; Style: accurate
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];
bool hasJumped = false;

void initializeBoard(){
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if((i+j)%2 == 0){
                board[i][j] = ' ';
            } else if(i <= 2){
                board[i][j] = 'b';
            } else if(i >= 5){
                board[i][j] = 'w';
            }
        }
    }
}

void printBoard(){
    printf("-----------------\n");
    for(int i = 0; i < BOARD_SIZE; i++){
        printf("|");
        for(int j = 0; j < BOARD_SIZE; j++){
            printf("%c|", board[i][j]);
        }
        printf("\n-----------------\n");
    }
}

bool isMoveValid(int row, int col, int newRow, int newCol, char player){
    // Checks if move is within bounds
    if(newRow < 0 || newRow >= BOARD_SIZE || newCol < 0 || newCol >= BOARD_SIZE){
        return false;
    }

    // Checks if destination cell is empty
    if(board[newRow][newCol] != ' '){
        return false;
    }

    // Capturing move
    if((newRow-row) == 2 || (newRow-row) == -2){
        int captureRow = (row+newRow)/2;
        int captureCol = (col+newCol)/2;
        // Capturing own piece
        if(board[captureRow][captureCol] == player ||
          board[captureRow][captureCol] == toupper(player)){
            return false;
        }
        // Multiple capturing
        if(hasJumped){
            return false;
        }
        if(isMoveValid(newRow,newCol,newRow-2,newCol-2,player) ||
           isMoveValid(newRow,newCol,newRow-2,newCol+2,player) ||
           isMoveValid(newRow,newCol,newRow+2,newCol-2,player) ||
           isMoveValid(newRow,newCol,newRow+2,newCol+2,player)){
            return true;
        }
    }

    // Regular move
    if((newRow-row) == 1 || (newRow-row) == -1){
        // Only forward moves for non-king pieces
        if(player == 'b' && newRow < row){
            return false;
        }
        if(player == 'w' && newRow > row){
            return false;
        }
        // Enforcing single move unless capturing
        if(hasJumped){
            return false;
        }
        // Kinging
        if(player == 'b' && newRow == 0){
            board[row][col] = 'B';
        }
        if(player == 'w' && newRow == BOARD_SIZE-1){
            board[row][col] = 'W';
        }
        return true;
    }
    return false;
}

int makeMove(int row, int col, int newRow, int newCol){
    board[newRow][newCol] = board[row][col];
    board[row][col] = ' ';

    if((newRow-row) == 2 || (newRow-row) == -2){
        int capturedRow = (row+newRow)/2;
        int capturedCol = (col+newCol)/2;
        board[capturedRow][capturedCol] = ' ';
        hasJumped = true;
    } else {
        hasJumped = false;
    }

    // Promoting to king
    if(board[newRow][newCol] == 'b' && newRow == 0){
        board[newRow][newCol] = 'B';
        return 2;
    }
    if(board[newRow][newCol] == 'w' && newRow == BOARD_SIZE-1){
        board[newRow][newCol] = 'W';
        return 2;
    }
    return 1;
}

bool hasValidMove(char player){
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j] == player || board[i][j] == toupper(player)){
                if(isMoveValid(i,j,i+1,j+1,player) || isMoveValid(i,j,i+1,j-1,player) ||
                   isMoveValid(i,j,i-1,j+1,player) || isMoveValid(i,j,i-1,j-1,player)){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    initializeBoard();
    char currentPlayer = 'w';
    int numMoves = 0;
    while(numMoves < 50){
        printBoard();
        if(!hasValidMove(currentPlayer)){
            printf("%c has no valid moves.\n", currentPlayer);
            currentPlayer = (currentPlayer == 'w') ? 'b' : 'w';
            continue;
        }
        int row, col, newRow, newCol;
        printf("%c's turn: ", currentPlayer);
        scanf("%d %d %d %d", &row, &col, &newRow, &newCol);
        if(isMoveValid(row,col,newRow,newCol,currentPlayer)){
            int numCaptures = makeMove(row,col,newRow,newCol);
            printf("%d piece(s) captured.\n", numCaptures);
            currentPlayer = (currentPlayer == 'w') ? 'b' : 'w';
            numMoves++;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    printf("Game is over!");
    return 0;
}