//FormAI DATASET v1.0 Category: Chess AI ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Structure to store individual pieces on board
typedef struct{
    int x; // horizontal position
    int y; // vertical position
    char type; // type of piece
    int points; // point value of the piece
} Piece;

// Function to initialize the board with starting position
// 'X' represents black pieces and 'O' represents white pieces
// 0 represents empty square
void initBoard(int board[BOARD_SIZE][BOARD_SIZE]){
    board[0][0] = board[0][7] = board[7][0] = board[7][7] = 'X'; // Rooks
    board[0][1] = board[0][6] = board[7][1] = board[7][6] = 'X'; // Knights
    board[0][2] = board[0][5] = board[7][2] = board[7][5] = 'X'; // Bishops
    board[0][3] = board[7][3] = 'X'; // Queens
    board[0][4] = board[7][4] = 'X'; // Kings
    for(int i=0; i<BOARD_SIZE; i++){
        board[1][i] = 'X'; // Black pawns
        board[6][i] = 'O'; // White pawns
    }
    for(int i=2; i<6; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            board[i][j] = 0; // Empty squares
        }
    }
}

// Function to print the board
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]){
    for(int i=0; i<BOARD_SIZE; i++){
        printf("\n");
        for(int j=0; j<BOARD_SIZE; j++){
            if(board[i][j] != 0){
                printf("%c ", board[i][j]);
            }
            else{
                printf(". ");
            }
        }
    }
    printf("\n\n");
}

// Function to check if move is valid
int isValidMove(int board[BOARD_SIZE][BOARD_SIZE], Piece piece, int newX, int newY){
    // Check boundaries
    if(newX < 0 || newX >= BOARD_SIZE || newY < 0 || newY >= BOARD_SIZE){
        return 0;
    }
    // Check if square is occupied by friendly piece
    if(board[newY][newX] != 0){
        if((piece.type == 'X' && board[newY][newX] == 'X') || (piece.type == 'O' && board[newY][newX] == 'O')){
            return 0;
        }
    }
    // Check if move follows piece movement rules
    switch(piece.type){
        case 'X': // Rook
            if(piece.x != newX && piece.y != newY){
                return 0;
            }
            if(piece.x == newX){
                int dir = newY > piece.y ? 1 : -1;
                for(int i=piece.y+dir; i!=newY; i+=dir){
                    if(board[i][newX] != 0){
                        return 0; // Path blocked
                    }
                }
            }
            else{
                int dir = newX > piece.x ? 1 : -1;
                for(int i=piece.x+dir; i!=newX; i+=dir){
                    if(board[newY][i] != 0){
                        return 0; // Path blocked
                    }
                }
            }
            break;
        case 'O': // Bishop
            if((newX-piece.x) != (newY-piece.y) && (newX-piece.x) != (piece.y-newY)){
                return 0;
            }
            int xDir = newX > piece.x ? 1 : -1;
            int yDir = newY > piece.y ? 1 : -1;
            for(int i=piece.x+xDir, j=piece.y+yDir; i!=newX && j!=newY; i+=xDir, j+=yDir){
                if(board[j][i] != 0){
                    return 0; // Path blocked
                }
            }
            break;
        case 'Q': // Queen
            // Shares movement rules of bishop and rook combined
            if((newX-piece.x) != (newY-piece.y) && (newX-piece.x) != (piece.y-newY) && piece.x != newX && piece.y != newY){
                return 0;
            }
            if(piece.x == newX){
                int dir = newY > piece.y ? 1 : -1;
                for(int i=piece.y+dir; i!=newY; i+=dir){
                    if(board[i][newX] != 0){
                        return 0; // Path blocked
                    }
                }
            }
            else if(piece.y == newY){
                int dir = newX > piece.x ? 1 : -1;
                for(int i=piece.x+dir; i!=newX; i+=dir){
                    if(board[newY][i] != 0){
                        return 0; // Path blocked
                    }
                }
            }
            else{
                int xDir = newX > piece.x ? 1 : -1;
                int yDir = newY > piece.y ? 1 : -1;
                for(int i=piece.x+xDir, j=piece.y+yDir; i!=newX && j!=newY; i+=xDir, j+=yDir){
                    if(board[j][i] != 0){
                        return 0; // Path blocked
                    }
                }
            }
            break;
        case 'K': // King
            if(abs(newX-piece.x) > 1 || abs(newY-piece.y) > 1){
                return 0;
            }
            break;
        case 'P': // Pawn
            if(piece.y == newY){ // Moving forward
                if(piece.x == newX){ // One square forward
                    if(piece.type == 'O'){ // White pawn
                        if(board[newY-1][newX] != 0){
                            return 0; // Path blocked
                        }
                    }
                    else{ // Black pawn
                        if(board[newY+1][newX] != 0){
                            return 0; // Path blocked
                        }
                    }
                }
                else{ // Two squares forward
                    if((piece.type == 'O' && piece.y != 6) || (piece.type == 'X' && piece.y != 1)){
                        return 0; // Invalid move
                    }
                    if(piece.type == 'O'){ // White pawn
                        if(board[newY-1][newX] != 0 || board[newY-2][newX] != 0){
                            return 0; // Path blocked
                        }
                    }
                    else{ // Black pawn
                        if(board[newY+1][newX] != 0 || board[newY+2][newX] != 0){
                            return 0; // Path blocked
                        }
                    }
                }
            }
            else{ // Capturing move
                if(abs(newX-piece.x) != 1 || abs(newY-piece.y) != 1){
                    return 0; // Invalid move
                }
                if(board[newY][newX] == 0){ // Cannot capture an empty square
                    return 0;
                }
            }
            break;
    }
    return 1;
}

// Function to move piece to new position and update board
void movePiece(int board[BOARD_SIZE][BOARD_SIZE], Piece *piece, int newX, int newY){
    board[piece->y][piece->x] = 0;
    if(board[newY][newX] != 0){ // Capturing move
        for(int i=0; i<BOARD_SIZE; i++){
            for(int j=0; j<BOARD_SIZE; j++){
                if(board[i][j] != 0 && board[i][j] == board[newY][newX]){ // Find piece being captured
                    board[i][j] = 0;
                }
            }
        }
    }
    board[newY][newX] = piece->type;
    piece->x = newX;
    piece->y = newY;
}

// Function to get user input for piece to move and new position
void getUserInput(int board[BOARD_SIZE][BOARD_SIZE], int *x, int *y, int *newX, int *newY){
    printf("\nPiece to move (enter coordinates separated by space): ");
    scanf("%d %d", x, y);
    printf("\nNew position (enter coordinates separated by space): ");
    scanf("%d %d", newX, newY);
    printf("\n");
}

// Function to get random move for AI player
void getAIMove(int board[BOARD_SIZE][BOARD_SIZE], int *x, int *y, int *newX, int *newY){
    Piece piece;
    do{
        *y = rand() % BOARD_SIZE;
        *x = rand() % BOARD_SIZE;
        piece.type = board[*y][*x];
    } while(piece.type == 0 || piece.type == 'O'); // AI only moves black pieces
    piece.y = *y;
    piece.x = *x;
    // AI player can make random move to any empty square or capture an opposing piece
    // AI does not check for checks or mate at this time
    do{
        *newY = rand() % BOARD_SIZE;
        *newX = rand() % BOARD_SIZE;
    } while(!isValidMove(board, piece, *newX, *newY));
}

int main(){
    int board[BOARD_SIZE][BOARD_SIZE], turns = 0, x, y, newX, newY;
    Piece piece;
    initBoard(board);
    while(1){
        printBoard(board);
        if(turns % 2 == 0){
            printf("\nWhite's turn\n");
            getUserInput(board, &x, &y, &newX, &newY);
            piece.type = board[y][x];
            piece.y = y;
            piece.x = x;
            if(isValidMove(board, piece, newX, newY)){
                movePiece(board, &piece, newX, newY);
                turns++;
            }
            else{
                printf("\nInvalid move. Try again.\n");
            }
        }
        else{
            printf("\nBlack's turn\n");
            getAIMove(board, &x, &y, &newX, &newY);
            piece.type = board[y][x];
            piece.y = y;
            piece.x = x;
            movePiece(board, &piece, newX, newY);
            turns++;
        }
    }
    return 0;
}