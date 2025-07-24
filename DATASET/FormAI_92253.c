//FormAI DATASET v1.0 Category: Checkers Game ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#define EMPTY 0
#define RED 1
#define BLACK 2
#define KINGRED 3
#define KINGBLACK 4
#define BOARD_SIZE 8

/*Struct to represent checkers game board*/
typedef struct{
    int player;                 
    int pos;
} Square;

/*Function to initialize checkers game board*/
void initBoard(Square board[][BOARD_SIZE]){
    int i, j;
    for(i=0; i<BOARD_SIZE; i++){
        for(j=0; j<BOARD_SIZE; j++){
            if(i%2 == j%2){           /*Set empty squares*/
                board[i][j].player = EMPTY;
            }
            else{
                if(i < 3){            /*Set black player pieces*/
                    board[i][j].player = BLACK;
                }
                else if(i > 4){       /*Set red player pieces*/
                    board[i][j].player = RED;
                }
            }
        }
    }
}

/*Function to print checkers game board*/
void printBoard(Square board[][BOARD_SIZE]){
    int i, j;
    printf("\n");
    for(i=0; i<BOARD_SIZE; i++){
        printf("\t   %d",i);
    }
    printf("\n\n");
    for(i=0; i<BOARD_SIZE; i++){
        printf("\t%d",i);
        for(j=0; j<BOARD_SIZE; j++){
            if(board[i][j].player == EMPTY){
                printf("\t.");
            }
            else if(board[i][j].player == RED){
                printf("\tR");
            }
            else if(board[i][j].player == BLACK){
                printf("\tB");
            }
            else if(board[i][j].player == KINGRED){
                printf("\tKR");
            }
            else if(board[i][j].player == KINGBLACK){
                printf("\tKB");
            }
        }
        printf("\n\n");
    }
}

/*Function to check if move is valid*/
int isValidMove(Square board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol){
    /*checks if move within bounds*/
    if(toRow < 0 || toRow >= BOARD_SIZE || toCol < 0 || toCol >= BOARD_SIZE){
        return 0;
    }
    /*checks if move is diagonal*/
    if((fromRow-toRow) != (fromCol-toCol) && (fromRow-toRow) != (toCol-fromCol)){
        return 0;
    }
    /*checks if end square is empty*/
    if(board[toRow][toCol].player != EMPTY){
        return 0;
    }
    /*checks if move is a single step*/
    if(abs(fromRow-toRow) == 1){
        if(board[fromRow][fromCol].player == RED && fromRow-toRow > 0){
            return 0;
        }
        else if(board[fromRow][fromCol].player == BLACK && fromRow-toRow < 0){
            return 0;
        }
    }
    /*checks if move is a jump*/
    else if(abs(fromRow-toRow) == 2){
        int jumpRow = (fromRow + toRow)/2;
        int jumpCol = (fromCol + toCol)/2;
        if(board[jumpRow][jumpCol].player == EMPTY){
            return 0;
        }
        if(board[fromRow][fromCol].player == RED && fromRow-toRow > 0){
            return 0;
        }
        else if(board[fromRow][fromCol].player == BLACK && fromRow-toRow < 0){
            return 0;
        }
        if(board[fromRow][fromCol].player == RED && board[jumpRow][jumpCol].player != BLACK && board[jumpRow][jumpCol].player != KINGBLACK){
            return 0;
        }
        else if(board[fromRow][fromCol].player == BLACK && board[jumpRow][jumpCol].player != RED && board[jumpRow][jumpCol].player != KINGRED){
            return 0;
        }
    }
    /*return 1 if valid move*/
    return 1;
}

/*Function to make move*/
void makeMove(Square board[][BOARD_SIZE], int fromRow, int fromCol, int toRow, int toCol){
    board[toRow][toCol].player = board[fromRow][fromCol].player;
    board[fromRow][fromCol].player = EMPTY;
    /*checks if jump was made*/
    if(abs(fromRow-toRow) == 2){
        int jumpRow = (fromRow + toRow)/2;
        int jumpCol = (fromCol + toCol)/2;
        board[jumpRow][jumpCol].player = EMPTY;
    }
    /*checks if king should be made*/
    if(board[toRow][toCol].player == RED && toRow == 0){
        board[toRow][toCol].player = KINGRED;
    }
    else if(board[toRow][toCol].player == BLACK && toRow == 7){
        board[toRow][toCol].player = KINGBLACK;
    }
}

int main(){
    Square board[BOARD_SIZE][BOARD_SIZE];
    initBoard(board);
    printBoard(board);
    /*Example moves*/
    int moves[][2] = {{2,1,3,2},{3,2,4,3},{5,4,4,3},{4,3,2,5},
                      {5,0,4,1},{7,0,5,2},{5,2,3,0},{2,5,3,4},
                      {4,1,2,3},{2,3,0,5},{3,4,1,3},{1,3,0,2}};
    int numMoves = sizeof(moves)/sizeof(moves[0]);
    int i;
    for(i=0; i<numMoves; i++){
        printf("Move %d\n\n",i+1);
        int fromRow = moves[i][0];
        int fromCol = moves[i][1];
        int toRow = moves[i][2];
        int toCol = moves[i][3];
        if(isValidMove(board, fromRow, fromCol, toRow, toCol)){
            makeMove(board, fromRow, fromCol, toRow, toCol);
            printBoard(board);
        }
        else{
            printf("Invalid move\n\n");
            printBoard(board);
            break;
        }
    }
    return 0;
}