//FormAI DATASET v1.0 Category: Chess engine ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define PAWN 100
#define KNIGHT 320
#define BISHOP 330
#define ROOK 500
#define QUEEN 900
#define KING 20000

// Define the chess board
int board[8][8] = {
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK}
};

// Define function to calculate score of each player based on board position
int calculateScore(int player) {
    int score = 0;
    int i, j;

    // Loop through every position on the board
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            // If the piece belongs to player, add its score to the player's score
            if (board[i][j] > 0 && player == 1) {
                score += board[i][j];
            }
            else if (board[i][j] < 0 && player == -1) {
                score += abs(board[i][j]);
            }
        }
    }

    return score;
}

int main() {
    int turn = 1;
    int i, j;
    
    // Output the initial state of the board
    printf("       a   b   c   d   e   f   g   h\n");
    printf("     +---+---+---+---+---+---+---+---+\n");
    for (i = 0; i < 8; i++) {
        printf("   %d |", 8 - i);
        for (j = 0; j < 8; j++) {
            printf(" %d |", board[i][j]);
        }
        printf(" %d\n", 8 - i);
        printf("     +---+---+---+---+---+---+---+---+\n");
    }
    printf("       a   b   c   d   e   f   g   h\n");

    // Play the game until one player wins
    while (1) {
        // Calculate the score for each player and output it
        int score_white = calculateScore(1);
        int score_black = calculateScore(-1);
        printf("White's score: %d\n", score_white);
        printf("Black's score: %d\n", score_black);

        // Check if either player has won
        if (score_white <= 0) {
            printf("Game over! Black wins!\n");
            break;
        }
        else if (score_black <= 0) {
            printf("Game over! White wins!\n");
            break;
        }

        // Get the move from the user and update the board
        char from[3], to[3];
        printf("Enter move for ");
        if (turn == 1) {
            printf("white (");
        }
        else {
            printf("black (");
        }
        printf("%d): ", turn);
        scanf("%s %s", from, to);
        int from_x = from[0] - 'a';
        int from_y = 8 - (from[1] - '0');
        int to_x = to[0] - 'a';
        int to_y = 8 - (to[1] - '0');
        board[to_y][to_x] = board[from_y][from_x];
        board[from_y][from_x] = 0;

        // Switch turns
        turn *= -1;

        // Output the updated state of the board
        printf("       a   b   c   d   e   f   g   h\n");
        printf("     +---+---+---+---+---+---+---+---+\n");
        for (i = 0; i < 8; i++) {
            printf("   %d |", 8 - i);
            for (j = 0; j < 8; j++) {
                printf(" %d |", board[i][j]);
            }
            printf(" %d\n", 8 - i);
            printf("     +---+---+---+---+---+---+---+---+\n");
        }
        printf("       a   b   c   d   e   f   g   h\n");
    }

    return 0;
}