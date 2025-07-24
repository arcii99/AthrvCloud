//FormAI DATASET v1.0 Category: Chess engine ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Board Settings
#define BOARD_SIZE 8
char board[BOARD_SIZE][BOARD_SIZE];

// Piece Definitions
#define EMPTY_SPACE '-'
#define B_PAWN 'p'
#define B_KNIGHT 'n'
#define B_BISHOP 'b'
#define B_ROOK 'r'
#define B_QUEEN 'q'
#define B_KING 'k'
#define W_PAWN 'P'
#define W_KNIGHT 'N'
#define W_BISHOP 'B'
#define W_ROOK 'R'
#define W_QUEEN 'Q'
#define W_KING 'K'

// Piece Score Definitions
#define PAWN_SCORE 1
#define KNIGHT_SCORE 3
#define BISHOP_SCORE 3
#define ROOK_SCORE 5
#define QUEEN_SCORE 9
#define KING_SCORE 100

// Evaluate Board Function
int evaluate_board() {
    int score = 0;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            switch(board[i][j]) {
                case W_PAWN:
                    score += PAWN_SCORE;
                    break;
                case W_KNIGHT:
                    score += KNIGHT_SCORE;
                    break;
                case W_BISHOP:
                    score += BISHOP_SCORE;
                    break;
                case W_ROOK:
                    score += ROOK_SCORE;
                    break;
                case W_QUEEN:
                    score += QUEEN_SCORE;
                    break;
                case W_KING:
                    score += KING_SCORE;
                    break;
                case B_PAWN:
                    score -= PAWN_SCORE;
                    break;
                case B_KNIGHT:
                    score -= KNIGHT_SCORE;
                    break;
                case B_BISHOP:
                    score -= BISHOP_SCORE;
                    break;
                case B_ROOK:
                    score -= ROOK_SCORE;
                    break;
                case B_QUEEN:
                    score -= QUEEN_SCORE;
                    break;
                case B_KING:
                    score -= KING_SCORE;
                    break;
                default:
                    break;
            }
        }
    }
    return score;
}

// Print Board Function
void print_board() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Initialize Board Function
void init_board() {
    board[0][0] = B_ROOK; 
    board[0][1] = B_KNIGHT; 
    board[0][2] = B_BISHOP; 
    board[0][3] = B_QUEEN; 
    board[0][4] = B_KING; 
    board[0][5] = B_BISHOP;
    board[0][6] = B_KNIGHT; 
    board[0][7] = B_ROOK;

    for(int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = B_PAWN;
        board[6][i] = W_PAWN;
    }

    board[7][0] = W_ROOK; 
    board[7][1] = W_KNIGHT; 
    board[7][2] = W_BISHOP; 
    board[7][3] = W_QUEEN; 
    board[7][4] = W_KING; 
    board[7][5] = W_BISHOP;
    board[7][6] = W_KNIGHT; 
    board[7][7] = W_ROOK;
}

int main() {
    printf("Welcome to my cheerful C Chess engine!\n");

    // Initialize Board
    init_board();

    // Print Board
    printf("\nInitial Board:\n");
    print_board();

    // Evaluate Board
    int score = evaluate_board();
    printf("\nScore: %d\n", score);

    return 0;
}