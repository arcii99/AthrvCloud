//FormAI DATASET v1.0 Category: Chess engine ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>

// Define board size and piece values
#define BOARD_SIZE 8

#define EMPTY 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

#define WHITE 10
#define BLACK 20

typedef struct{
    int piece; // type of piece (i.e. pawn, rook, etc.)
    int color; // color of the piece (i.e. white, black)
} Square;

Square board[BOARD_SIZE][BOARD_SIZE]; // Initialize an empty chess board

/* Function to initialize the chess board with starting
 * pieces in their respective positions */
void initBoard(){
    int i, j;
    // Set up pawns
    for(i=0;i<BOARD_SIZE;i++){
        board[1][i].piece = PAWN;
        board[1][i].color = BLACK;
        board[6][i].piece = PAWN;
        board[6][i].color = WHITE;
    }
    // Set up knights
    board[0][1].piece = KNIGHT;
    board[0][1].color = BLACK;
    board[0][6].piece = KNIGHT;
    board[0][6].color = BLACK;
    board[7][1].piece = KNIGHT;
    board[7][1].color = WHITE;
    board[7][6].piece = KNIGHT;
    board[7][6].color = WHITE;
    // Set up bishops
    board[0][2].piece = BISHOP;
    board[0][2].color = BLACK;
    board[0][5].piece = BISHOP;
    board[0][5].color = BLACK;
    board[7][2].piece = BISHOP;
    board[7][2].color = WHITE;
    board[7][5].piece = BISHOP;
    board[7][5].color = WHITE;
    // Set up rooks
    board[0][0].piece = ROOK;
    board[0][0].color = BLACK;
    board[0][7].piece = ROOK;
    board[0][7].color = BLACK;
    board[7][0].piece = ROOK;
    board[7][0].color = WHITE;
    board[7][7].piece = ROOK;
    board[7][7].color = WHITE;
    // Set up queens
    board[0][3].piece = QUEEN;
    board[0][3].color = BLACK;
    board[7][3].piece = QUEEN;
    board[7][3].color = WHITE;
    // Set up kings
    board[0][4].piece = KING;
    board[0][4].color = BLACK;
    board[7][4].piece = KING;
    board[7][4].color = WHITE;
    // Set all remaining squares to empty
    for(i=2;i<6;i++){
        for(j=0;j<BOARD_SIZE;j++){
            board[i][j].piece = EMPTY;
            board[i][j].color = 0;
        }
    }
}

/*Function that prints out the current state of the board*/
void printBoard(){
    int i, j;
    char piece;
    for(i=0;i<BOARD_SIZE;i++){
        printf("%d ", BOARD_SIZE - i);
        for(j=0;j<BOARD_SIZE;j++){
            switch(board[i][j].piece){
                case EMPTY: piece = ' '; break;
                case PAWN: piece = 'P'; break;
                case KNIGHT: piece = 'N'; break;
                case BISHOP: piece = 'B'; break;
                case ROOK: piece = 'R'; break;
                case QUEEN: piece = 'Q'; break;
                case KING: piece = 'K'; break;
            }
            if(board[i][j].color == WHITE){
                piece = tolower(piece); // Change to lowercase if piece belongs to white
            }
            printf("| %c ", piece);
        }
        printf("|\n");
    }
    printf("  ");
    for(i=0;i<BOARD_SIZE;i++){
        printf(" %c  ", 'a' + i);
    }
    printf("\n");
}

/*Function that moves the piece from the starting square 
 * to the ending square only if the move is legal*/
bool move(int startRow, int startCol, int endRow, int endCol, int color){
    //TODO: implement move logic
    return true;
}

int main(){
    initBoard();
    printBoard();
    return 0;
}