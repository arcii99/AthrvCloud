//FormAI DATASET v1.0 Category: Chess AI ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define the chess board size
#define BOARD_SIZE 8

// Define player colors
#define BLACK 0
#define WHITE 1

// Define the piece types
#define KING 'K'
#define QUEEN 'Q'
#define ROOK 'R'
#define BISHOP 'B'
#define KNIGHT 'N'
#define PAWN 'P'

// Define the board structure
typedef struct {
    char pieces[BOARD_SIZE][BOARD_SIZE];
} Board;

// Initialize the board with starting positions
void initBoard(Board *board) {
    // Start with empty board
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board->pieces[i][j]=' ';
        }
    }

    // Place pawns
    for(int i=0; i<BOARD_SIZE; i++) {
        board->pieces[1][i]=PAWN;
        board->pieces[6][i]=PAWN;
    }

    // Place rooks
    board->pieces[0][0]=ROOK;
    board->pieces[0][7]=ROOK;
    board->pieces[7][0]=ROOK;
    board->pieces[7][7]=ROOK;

    // Place knights
    board->pieces[0][1]=KNIGHT;
    board->pieces[0][6]=KNIGHT;
    board->pieces[7][1]=KNIGHT;
    board->pieces[7][6]=KNIGHT;

    // Place bishops
    board->pieces[0][2]=BISHOP;
    board->pieces[0][5]=BISHOP;
    board->pieces[7][2]=BISHOP;
    board->pieces[7][5]=BISHOP;

    // Place kings
    board->pieces[0][4]=KING;
    board->pieces[7][4]=KING;

    // Place queens
    board->pieces[0][3]=QUEEN;
    board->pieces[7][3]=QUEEN;
}

// Print the board
void printBoard(Board board) {
    printf("\n   ");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf(" %c ", i+'A');
    }
    printf("\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf(" %d ", i+1);
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("|%c|", board.pieces[i][j]);
        }
        printf(" %d \n", i+1);
    }
    printf("   ");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf(" %c ", i+'A');
    }
    printf("\n\n");
}

// Make a move on the board
void move(Board *board, int fromx, int fromy, int tox, int toy) {
    board->pieces[tox][toy]=board->pieces[fromx][fromy];
    board->pieces[fromx][fromy]=' ';
}

// Get the piece color of the given piece
int getPieceColor(char piece) {
    if(piece>=65 && piece<=90) {
        return WHITE;
    }
    else if(piece>=97 && piece<=122) {
        return BLACK;
    }
}

// Check if the given square is empty
int isEmpty(Board board, int x, int y) {
    if(board.pieces[x][y]==' ') {
        return 1;
    }
    else {
        return 0;
    }
}

// Check if the given square is occupied by opponent
int isOpponent(Board board, char color, int x, int y) {
    if(color=='W' && getPieceColor(board.pieces[x][y])==BLACK) {
        return 1;
    }
    else if(color=='B' && getPieceColor(board.pieces[x][y])==WHITE) {
        return 1;
    }
    else {
        return 0;
    }
}

// Check if the given square is within the board
int isValidSquare(int x, int y) {
    if(x>=0 && x<BOARD_SIZE && y>=0 && y<BOARD_SIZE) {
        return 1;
    }
    else {
        return 0;
    }
}

// Check if the given move is legal for pawn
int isLegalMoveForPawn(Board board, int fromx, int fromy, int tox, int toy) {
    char piece=board.pieces[fromx][fromy];
    int color=getPieceColor(piece);

    // Move should be horizontal or vertical
    if(fromx!=tox && fromy!=toy) {
        return 0;
    }

    // Black pawn should move downwards and white pawn should move upwards
    if(color==BLACK && fromx>=tox) {
        return 0;
    }
    else if(color==WHITE && fromx<=tox) {
        return 0;
    }

    // Check if the move is one step forward
    if(abs(fromx-tox)==1 && fromy==toy && isEmpty(board, tox, toy)) {
        return 1;
    }

    // Check if the move is two step forward from starting position
    if(color==BLACK && fromx==1 && tox==3 && fromy==toy && isEmpty(board, tox, toy) && isEmpty(board, 2, toy)) {
        return 1;
    }
    else if(color==WHITE && fromx==6 && tox==4 && fromy==toy && isEmpty(board, tox, toy) && isEmpty(board, 5, toy)) {
        return 1;
    }

    // Check if the move is diagonal to capture a piece
    if(abs(fromx-tox)==1 && abs(fromy-toy)==1 && isOpponent(board, piece, tox, toy)) {
        return 1;
    }

    // Otherwise, the move is not valid
    return 0;
}

// Check if the given move is legal for rook
int isLegalMoveForRook(Board board, int fromx, int fromy, int tox, int toy) {
    char piece=board.pieces[fromx][fromy];

    // Move should be horizontal or vertical
    if(fromx!=tox && fromy!=toy) {
        return 0;
    }

    // Check if the path is clear
    int dx=fromx<tox?1:(fromx>tox?-1:0);
    int dy=fromy<toy?1:(fromy>toy?-1:0);
    int x=fromx+dx;
    int y=fromy+dy;
    while(x!=tox || y!=toy) {
        if(!isEmpty(board, x, y)) {
            return 0;
        }
        x+=dx;
        y+=dy;
    }

    // Check if the destination is empty or has an opponent's piece
    if(isEmpty(board, tox, toy) || isOpponent(board, piece, tox, toy)) {
        return 1;
    }

    // Otherwise, the move is not valid
    return 0;
}

// Check if the given move is legal for bishop
int isLegalMoveForBishop(Board board, int fromx, int fromy, int tox, int toy) {
    char piece=board.pieces[fromx][fromy];

    // Move should be diagonal
    if(abs(fromx-tox)!=abs(fromy-toy)) {
        return 0;
    }

    // Check if the path is clear
    int dx=fromx<tox?1:-1;
    int dy=fromy<toy?1:-1;
    int x=fromx+dx;
    int y=fromy+dy;
    while(x!=tox && y!=toy) {
        if(!isEmpty(board, x, y)) {
            return 0;
        }
        x+=dx;
        y+=dy;
    }

    // Check if the destination is empty or has an opponent's piece
    if(isEmpty(board, tox, toy) || isOpponent(board, piece, tox, toy)) {
        return 1;
    }

    // Otherwise, the move is not valid
    return 0;
}

// Check if the given move is legal for knight
int isLegalMoveForKnight(Board board, int fromx, int fromy, int tox, int toy) {
    char piece=board.pieces[fromx][fromy];

    // Move should be L-shaped
    if(!(abs(fromx-tox)==2&&abs(fromy-toy)==1) && !(abs(fromx-tox)==1&&abs(fromy-toy)==2)) {
        return 0;
    }

    // Check if the destination is empty or has an opponent's piece
    if(isEmpty(board, tox, toy) || isOpponent(board, piece, tox, toy)) {
        return 1;
    }

    // Otherwise, the move is not valid
    return 0;
}

// Check if the given move is legal for queen
int isLegalMoveForQueen(Board board, int fromx, int fromy, int tox, int toy) {
    return isLegalMoveForRook(board, fromx, fromy, tox, toy) || isLegalMoveForBishop(board, fromx, fromy, tox, toy);
}

// Check if the given move is legal for king
int isLegalMoveForKing(Board board, int fromx, int fromy, int tox, int toy) {
    char piece=board.pieces[fromx][fromy];

    // Move should be one square horizontal, vertical or diagonal
    if(abs(fromx-tox)>1 || abs(fromy-toy)>1) {
        return 0;
    }

    // Check if the destination is empty or has an opponent's piece
    if(isEmpty(board, tox, toy) || isOpponent(board, piece, tox, toy)) {
        return 1;
    }

    // Otherwise, the move is not valid
    return 0;
}

// Check if the given move is legal
int isLegalMove(Board board, int fromx, int fromy, int tox, int toy) {
    char piece=board.pieces[fromx][fromy];

    switch(piece) {
        case PAWN:
            return isLegalMoveForPawn(board, fromx, fromy, tox, toy);
        case ROOK:
            return isLegalMoveForRook(board, fromx, fromy, tox, toy);
        case BISHOP:
            return isLegalMoveForBishop(board, fromx, fromy, tox, toy);
        case KNIGHT:
            return isLegalMoveForKnight(board, fromx, fromy, tox, toy);
        case QUEEN:
            return isLegalMoveForQueen(board, fromx, fromy, tox, toy);
        case KING:
            return isLegalMoveForKing(board, fromx, fromy, tox, toy);
    }

    // Otherwise, the move is not valid
    return 0;
}

// Get the next move from the user
void getNextMove(Board board, int color, int *fromx, int *fromy, int *tox, int *toy) {
    char move[5];
    printf("Enter the move for player %c (Eg: e2e4): ", color==WHITE?'W':'B');
    scanf("%s", move);
    *fromx=move[1]-'1';
    *fromy=move[0]-'A';
    *tox=move[3]-'1';
    *toy=move[2]-'A';

    while(!isValidSquare(*fromx, *fromy) || !isValidSquare(*tox, *toy) || !isLegalMove(board, *fromx, *fromy, *tox, *toy)) {
        printf("Invalid move. Enter the move for player %c (Eg: e2e4): ", color==WHITE?'W':'B');
        scanf("%s", move);
        *fromx=move[1]-'1';
        *fromy=move[0]-'A';
        *tox=move[3]-'1';
        *toy=move[2]-'A';
    }
}

// Play the game
void playGame() {
    Board board;
    initBoard(&board);
    printBoard(board);

    int turn=WHITE;
    int fromx, fromy, tox, toy;
    while(1) {
        getNextMove(board, turn, &fromx, &fromy, &tox, &toy);
        move(&board, fromx, fromy, tox, toy);
        printBoard(board);

        turn=turn==WHITE?BLACK:WHITE;
    }
}

int main() {
    playGame();
    return 0;
}