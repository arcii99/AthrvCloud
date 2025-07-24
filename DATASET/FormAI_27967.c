//FormAI DATASET v1.0 Category: Chess AI ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

//define constants
#define KING 200
#define QUEEN 9
#define ROOK 5
#define BISHOP 3
#define KNIGHT 2
#define PAWN 1

//declare functions
void initializeBoard(char board[][8]);
void printBoard(char board[][8]);
char getPiece(char board[][8], int row, int col);
int evaluate(char board[][8], char color);

int main()
{
    //initialize board
    char board[8][8];
    initializeBoard(board);

    //print board
    printf("Initial board:\n");
    printBoard(board);

    //evaluate board
    int score = evaluate(board, 'w');
    printf("Evaluation score for white: %d\n", score);

    return 0;
}

//function to initialize board
void initializeBoard(char board[][8])
{
    //set black pieces
    board[0][0] = board[0][7] = 'r';
    board[0][1] = board[0][6] = 'n';
    board[0][2] = board[0][5] = 'b';
    board[0][3] = 'q';
    board[0][4] = 'k';
    for(int i=0; i<8; i++)
        board[1][i] = 'p';

    //set empty squares
    for(int i=2; i<6; i++)
        for(int j=0; j<8; j++)
            board[i][j] = '_';

    //set white pieces
    for(int i=0; i<8; i++)
        board[6][i] = 'P';
    board[7][0] = board[7][7] = 'R';
    board[7][1] = board[7][6] = 'N';
    board[7][2] = board[7][5] = 'B';
    board[7][3] = 'Q';
    board[7][4] = 'K';
}

//function to print board
void printBoard(char board[][8])
{
    printf("  a b c d e f g h\n");
    for(int i=0; i<8; i++)
    {
        printf("%d ", 8-i);
        for(int j=0; j<8; j++)
            printf("%c ", board[i][j]);
        printf("%d\n", 8-i);
    }
    printf("  a b c d e f g h\n");
}

//function to get piece on given square
char getPiece(char board[][8], int row, int col)
{
    if(row<0 || row>7 || col<0 || col>7)
        return '_';
    return board[row][col];
}

//function to evaluate board
int evaluate(char board[][8], char color)
{
    int score = 0;
    char piece, opponent;
    if(color=='w')
        opponent = 'b';
    else
        opponent = 'w';

    //evaluate pawns
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
        {
            piece = getPiece(board, i, j);
            if(piece=='P' && color=='w')
                score += PAWN;
            else if(piece=='p' && color=='b')
                score += PAWN * -1;
        }

    //evaluate knights
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
        {
            piece = getPiece(board, i, j);
            if(piece=='N' && color=='w')
                score += KNIGHT;
            else if(piece=='n' && color=='b')
                score += KNIGHT * -1;
        }

    //continue evaluating other piece, and so on.

    return score;
}