//FormAI DATASET v1.0 Category: Chess engine ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 8
#define COLS 8
#define KING 1000
#define QUEEN 9
#define ROOK 5
#define BISHOP 3
#define KNIGHT 3
#define PAWN 1

//Position of chess board.
typedef struct position {
    int row;
    int col;
} position;

//Chess piece.
typedef struct piece {
    char symbol;            //'k': King, 'q': Queen, 'r': Rook, 'b': Bishop, 'n': Knight, 'p': Pawn
    int value;
} piece;

//Chess board.
typedef struct board {
    piece b[ROWS][COLS];
} board;

//Print chess board.
void printBoard(board chessboard) {
    printf("\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++)
            printf("%c ", chessboard.b[i][j].symbol);
        printf("\n");
    }
}

//Initialize chess board with pieces.
void initializeBoard(board * chessboard) {
    //Black side.
    chessboard->b[0][0].symbol = 'r';
    chessboard->b[0][0].value = ROOK;
    chessboard->b[0][1].symbol = 'n';
    chessboard->b[0][1].value = KNIGHT;
    chessboard->b[0][2].symbol = 'b';
    chessboard->b[0][2].value = BISHOP;
    chessboard->b[0][3].symbol = 'q';
    chessboard->b[0][3].value = QUEEN;
    chessboard->b[0][4].symbol = 'k';
    chessboard->b[0][4].value = KING;
    chessboard->b[0][5].symbol = 'b';
    chessboard->b[0][5].value = BISHOP;
    chessboard->b[0][6].symbol = 'n';
    chessboard->b[0][6].value = KNIGHT;
    chessboard->b[0][7].symbol = 'r';
    chessboard->b[0][7].value = ROOK;
    for(int i=0; i<COLS; i++) {
        chessboard->b[1][i].symbol = 'p';
        chessboard->b[1][i].value = PAWN;
    }
    //Empty spaces.
    for(int i=2; i<ROWS-2; i++) {
        for(int j=0; j<COLS; j++) {
            chessboard->b[i][j].symbol = '.';
            chessboard->b[i][j].value = 0;
        }
    }
    //White side.
    for(int i=0; i<COLS; i++) {
        chessboard->b[6][i].symbol = 'P';
        chessboard->b[6][i].value = PAWN;
    }
    chessboard->b[7][0].symbol = 'R';
    chessboard->b[7][0].value = ROOK;
    chessboard->b[7][1].symbol = 'N';
    chessboard->b[7][1].value = KNIGHT;
    chessboard->b[7][2].symbol = 'B';
    chessboard->b[7][2].value = BISHOP;
    chessboard->b[7][3].symbol = 'Q';
    chessboard->b[7][3].value = QUEEN;
    chessboard->b[7][4].symbol = 'K';
    chessboard->b[7][4].value = KING;
    chessboard->b[7][5].symbol = 'B';
    chessboard->b[7][5].value = BISHOP;
    chessboard->b[7][6].symbol = 'N';
    chessboard->b[7][6].value = KNIGHT;
    chessboard->b[7][7].symbol = 'R';
    chessboard->b[7][7].value = ROOK;
}

//Generate random position of piece.
position randomPosition() {
    position p;
    p.row = rand() % ROWS;
    p.col = rand() % COLS;
    return p;
}

//Initialize random move for any piece.
position * randomMove(board chessboard, position p) {
    //Pointer to move position.
    position * move = (position *) malloc(sizeof(position));
    move->row = rand() % ROWS;
    move->col = rand() % COLS;
    //If same position then invalid.
    if(move->row == p.row && move->col == p.col)
        return NULL;
    //If this position if empty then valid.
    if(chessboard.b[move->row][move->col].value == 0)
        return move;
    //If this position has opponent piece then valid.
    if(islower(chessboard.b[p.row][p.col].symbol) != islower(chessboard.b[move->row][move->col].symbol))
        return move;
    //Otherwise invalid.
    return NULL;
}

//Function to move piece.
void movePiece(board * chessboard, position * move, position p) {
    chessboard->b[move->row][move->col] = chessboard->b[p.row][p.col];
    chessboard->b[p.row][p.col].symbol = '.';
    chessboard->b[p.row][p.col].value = 0;
}

//Function to play random move.
void playRandomMove(board * chessboard) {
    //Generate random position of piece to move.
    position p = randomPosition();
    //Validation check to see if this is a valid move.
    while(chessboard->b[p.row][p.col].value == 0 || !(islower(chessboard->b[p.row][p.col].symbol) && chessboard->b[p.row][p.col].value == PAWN) ) {
        p = randomPosition();
    }
    //Generate random move and validation.
    position * move = NULL;
    while(move == NULL)
        move = randomMove(*chessboard, p);
    //Move piece.
    movePiece(chessboard, move, p);
}

//Driver function to play chess.
void playChess() {
    //Create and initialize chess board.
    board chessboard;
    initializeBoard(&chessboard);
    //Start playing random moves.
    for(int i=1; i<=100; i++) {
        printf("Move %d:\n", i);
        printBoard(chessboard);
        playRandomMove(&chessboard);
    }
}

//Main function.
int main() {
    //Initialize the random seed.
    srand(time(NULL));
    //Play chess.
    playChess();
    return 0;
}