//FormAI DATASET v1.0 Category: Checkers Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Function to print the current state of the board
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n    ");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%c ", 'a'+i);
    }
    printf("\n   +-+-+-+-+-+-+-+-+\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf(" %d|", i+1);
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == 0) printf(" |");
            else if(board[i][j] == 1) printf("O|");
            else if(board[i][j] == 2) printf("X|");
            else if(board[i][j] == 3) printf("K|");
        }
        printf(" %d\n", i+1);
        printf("   +-+-+-+-+-+-+-+-+\n");
    }
    printf("    ");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%c ", 'a'+i);
    }
}

// Function to initialize the board
void initialize_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if((i+j)%2 == 0 && i < 3) board[i][j] = 2; // black pieces
            else if((i+j)%2 == 0 && i > 4) board[i][j] = 1; // white pieces
            else board[i][j] = 0; // empty squares
        }
    }
}

// Function to check if a move is valid
bool is_valid_move(int board[BOARD_SIZE][BOARD_SIZE], int player, int startX, int startY, int endX, int endY) {
    if(board[startX][startY] == 0) return false; // starting square must not be empty
    if(board[endX][endY] != 0) return false; // ending square must be empty
    if(player == 1 && board[startX][startY] == 2) return false; // white player can only move white pieces
    if(player == 2 && board[startX][startY] == 1) return false; // black player can only move black pieces
    int diffX = endX - startX;
    int diffY = endY - startY;
    if(abs(diffX) != abs(diffY)) return false; // pieces can only move diagonally
    if(abs(diffX) > 2) return false; // pieces can only move up to 2 squares at a time
    if(abs(diffX) == 2) { // if the piece is jumping over another piece
        int middleX = (startX + endX) / 2;
        int middleY = (startY + endY) / 2;
        if(board[middleX][middleY] == 0 || board[middleX][middleY] == player) return false; // there must be an opponent's piece in between
    }
    if(player == 1 && diffX > 0) return false; // white pieces can only move upwards
    if(player == 2 && diffX < 0) return false; // black pieces can only move downwards
    if(board[startX][startY] == 3 && abs(diffX) == 1) return false; // kings can move 1 or 2 squares diagonally
    return true;
}

// Function to apply a move to the board
void apply_move(int board[BOARD_SIZE][BOARD_SIZE], int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = 0;
    if(abs(endX-startX) == 2) { // if the piece is jumping over another piece
        int middleX = (startX + endX) / 2;
        int middleY = (startY + endY) / 2;
        board[middleX][middleY] = 0;
    }
    if(board[endX][endY] == 1 && endX == 0) board[endX][endY] = 3; // white pieces can be promoted to kings
    if(board[endX][endY] == 2 && endX == BOARD_SIZE-1) board[endX][endY] = 3; // black pieces can be promoted to kings
}

// Function to check if the game is over
bool is_game_over(int board[BOARD_SIZE][BOARD_SIZE], int player) {
    int num_pieces = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == player || board[i][j] == player+2) num_pieces++;
        }
    }
    return num_pieces == 0;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    int currentPlayer = 1;
    bool game_over = false;
    while(!game_over) {
        print_board(board);
        printf("\n%s's turn (O): ", currentPlayer == 1 ? "White" : "Black");
        int startX, startY, endX, endY;
        scanf("%d %c %d %c", &startY, &startX, &endY, &endX); // e.g. 2 b 3 c
        startX--;
        startY -= 'a';
        endX--;
        endY -= 'a';
        if(is_valid_move(board, currentPlayer, startX, startY, endX, endY)) {
            apply_move(board, startX, startY, endX, endY);
            if(is_game_over(board, currentPlayer)) {
                printf("\n%s wins!\n", currentPlayer == 1 ? "White" : "Black");
                game_over = true;
            } else {
                currentPlayer = currentPlayer == 1 ? 2 : 1;
            }
        } else {
            printf("\nInvalid move! Try again.\n");
        }
    }
    return 0;
}