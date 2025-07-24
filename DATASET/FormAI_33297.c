//FormAI DATASET v1.0 Category: Chess AI ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

// define pieces
#define EMPTY '-'
#define PAWN 'P'
#define KNIGHT 'N'
#define BISHOP 'B'
#define ROOK 'R'
#define QUEEN 'Q'
#define KING 'K'

// define player
#define WHITE 'W'
#define BLACK 'B'

// define coordinate struct
typedef struct {
    int x;
    int y;
} Coordinate;

// define move struct
typedef struct {
    Coordinate from;
    Coordinate to;
} Move;

// define chess board
char board[BOARD_SIZE][BOARD_SIZE];

// define player turn
char turn;

// initialize board with default configuration
void initBoard() {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(i == 1) board[i][j] = PAWN;           // white pawns
            else if(i == 6) board[i][j] = PAWN;      // black pawns
            else if(i == 0 || i == 7) {
                if(j == 0 || j == 7) board[i][j] = ROOK;      // white/black rooks
                else if(j == 1 || j == 6) board[i][j] = KNIGHT;   // white/black knights
                else if(j == 2 || j == 5) board[i][j] = BISHOP;   // white/black bishops
                else if(j == 3) board[i][j] = QUEEN;    // white/black queen
                else if(j == 4) board[i][j] = KING;     // white/black king
            }
            else board[i][j] = EMPTY;              // empty cells
        }
    }
    turn = WHITE;    // white starts first
}

// display current board configuration with pieces and coordinates
void displayBoard() {
    int i, j;
    printf("  ");
    for(j = 0; j < BOARD_SIZE; j++) {
        printf(" %d ", j);
    }
    printf("\n");
    for(i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i);
        for(j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("|%d\n", i);
    }
    printf("  ");
    for(j = 0; j < BOARD_SIZE; j++) {
        printf(" %d ", j);
    }
    printf("\n");

    printf("Turn: %c\n\n", turn);
}

// get user input coordinate
Coordinate getInputCoord(char* message) {
    Coordinate coord = {-1, -1};
    char input[10];
    printf(message);
    fgets(input, 10, stdin);
    if(strlen(input) >= 3) {
        coord.x = input[0] - '0';
        coord.y = input[2] - '0';
    }
    return coord;
}

// check if coordinate is valid
int isValidCoord(Coordinate coord) {
    if(coord.x < 0 || coord.y < 0 || coord.x >= BOARD_SIZE || coord.y >= BOARD_SIZE)
        return 0;
    return 1;
}

// check if move is valid (it only checks if the move is within the board)
int isValidMove(Move move) {
    if(isValidCoord(move.from) && isValidCoord(move.to))
        return 1;
    return 0;
}

// check if move is valid according to the rules of chess
int isLegalMove(Move move) {
    // TODO: implement legal move checker
    return 1;
}

// move a piece
void movePiece(Move move) {
    int from_x = move.from.x;
    int from_y = move.from.y;
    int to_x = move.to.x;
    int to_y = move.to.y;
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = EMPTY;
}

// change player turn
void nextTurn() {
    if(turn == WHITE) turn = BLACK;
    else if(turn == BLACK) turn = WHITE;
}

// main function
int main() {
    initBoard();

    while(1) {
        displayBoard();

        // get user input
        Coordinate from = getInputCoord("Enter piece location (x,y): ");
        Coordinate to = getInputCoord("Enter destination location (x,y): ");
        Move move = {from, to};

        // check if move is valid
        if(!isValidMove(move)) {
            printf("Invalid move!\n\n");
            continue;
        }

        // move piece
        movePiece(move);

        // change player turn
        nextTurn();
    }

    return 0;
}