//FormAI DATASET v1.0 Category: Checkers Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8            // Size of board
#define NO_PIECE -1             // No piece on a square
#define BLACK_PAWN 0            // Black pawn
#define BLACK_KING 1            // Black king
#define WHITE_PAWN 2            // White pawn
#define WHITE_KING 3            // White king

// Function to initialize board
void init_board(int board[][BOARD_SIZE]) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if((i+j) % 2 == 0) {
                if(i < 3) board[i][j] = WHITE_PAWN;
                else if(i > 4) board[i][j] = BLACK_PAWN;
                else board[i][j] = NO_PIECE;
            }
            else board[i][j] = NO_PIECE;
        }
    }
}

// Function to print board
void print_board(int board[][BOARD_SIZE]) {
    printf("  0 1 2 3 4 5 6 7\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == NO_PIECE) printf("- ");
            else if(board[i][j] == BLACK_PAWN) printf("b ");
            else if(board[i][j] == BLACK_KING) printf("B ");
            else if(board[i][j] == WHITE_PAWN) printf("w ");
            else printf("W ");
        }
        printf("%d\n", i);
    }
    printf("  0 1 2 3 4 5 6 7\n");
}

// Function to check if a move is legal
bool is_legal_move(int board[][BOARD_SIZE], int row1, int col1, int row2, int col2) {
    // Check if there is a piece on starting square
    if(board[row1][col1] == NO_PIECE) return false;
    // Check if target square is within board bounds
    if(row2 < 0 || row2 > BOARD_SIZE-1 || col2 < 0 || col2 > BOARD_SIZE-1) return false;
    // Check if target square is empty
    if(board[row2][col2] != NO_PIECE) return false;
    // Check if move is diagonal
    if(abs(row2-row1) != abs(col2-col1)) return false;
    // Check if diagonal is only 1 square
    if(abs(row2-row1) != 1 && abs(row2-row1) != 2) return false;
    // Check if move is consistent with piece type
    if(board[row1][col1] == BLACK_PAWN && row2 < row1) return false;
    if(board[row1][col1] == WHITE_PAWN && row2 > row1) return false;
    // Check if move is a capture
    if(abs(row2-row1) == 2) {
        int cap_row = (row1+row2)/2;
        int cap_col = (col1+col2)/2;
        if(board[cap_row][cap_col] == NO_PIECE) return false;
        if(board[row1][col1] == BLACK_PAWN && board[cap_row][cap_col] != WHITE_PAWN && board[cap_row][cap_col] != WHITE_KING) return false;
        if(board[row1][col1] == WHITE_PAWN && board[cap_row][cap_col] != BLACK_PAWN && board[cap_row][cap_col] != BLACK_KING) return false;
    }
    return true;
}

// Function to make a move
void make_move(int board[][BOARD_SIZE], int row1, int col1, int row2, int col2) {
    // Make the move
    board[row2][col2] = board[row1][col1];
    board[row1][col1] = NO_PIECE;
    // If this was a capture, remove the captured piece
    if(abs(row2-row1) == 2) {
        int cap_row = (row1+row2)/2;
        int cap_col = (col1+col2)/2;
        board[cap_row][cap_col] = NO_PIECE;
    }
    // If this was a pawn that reached the other side of the board, promote it to a king
    if(board[row2][col2] == BLACK_PAWN && row2 == 0) board[row2][col2] = BLACK_KING;
    if(board[row2][col2] == WHITE_PAWN && row2 == BOARD_SIZE-1) board[row2][col2] = WHITE_KING;
}

// Function to check if the game is over
bool is_game_over(int board[][BOARD_SIZE]) {
    int black_pieces = 0;
    int white_pieces = 0;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == BLACK_PAWN || board[i][j] == BLACK_KING) black_pieces++;
            else if(board[i][j] == WHITE_PAWN || board[i][j] == WHITE_KING) white_pieces++;
        }
    }
    if(black_pieces == 0 || white_pieces == 0) return true;
    return false;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    while(!is_game_over(board)) {
        print_board(board);
        int row1, col1, row2, col2;
        printf("Enter starting row: ");
        scanf("%d", &row1);
        printf("Enter starting column: ");
        scanf("%d", &col1);
        printf("Enter target row: ");
        scanf("%d", &row2);
        printf("Enter target column: ");
        scanf("%d", &col2);
        if(is_legal_move(board, row1, col1, row2, col2)) {
            make_move(board, row1, col1, row2, col2);
        }
        else {
            printf("Illegal move.\n");
        }
    }
    print_board(board);
    printf("Game over.\n");
    return 0;
}