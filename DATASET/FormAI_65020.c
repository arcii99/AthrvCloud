//FormAI DATASET v1.0 Category: Chess AI ; Style: authentic
//Include necessary headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8 //Define board size 8x8

//Representing pieces with integers
#define EMPTY 0 
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

//Defining piece color
#define WHITE 0
#define BLACK 1

//Initialize chess board
int chessBoard[BOARD_SIZE][BOARD_SIZE] = {
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
};

//Function to print the chessboard
void printBoard() {
    printf("\n");
    for(int i=0; i < 8; i++) {
        for(int j=0; j < 8; j++) {
            printf("%d ", chessBoard[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printBoard(); //Print initial board
    return 0;
}