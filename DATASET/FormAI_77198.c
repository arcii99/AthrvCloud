//FormAI DATASET v1.0 Category: Chess engine ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the board
void initialize_board() {
    int i, j;

    // Fill the board with 0s
    memset(board, 0, sizeof(board));

    // Initialize the pawns
    for (i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = 1; // Black pawns
        board[6][i] = -1; // White pawns
    }

    // Initialize the rooks
    board[0][0] = board[0][7] = -2; // Black rooks
    board[7][0] = board[7][7] = 2; // White rooks

    // Initialize the knights
    board[0][1] = board[0][6] = -3; // Black knights
    board[7][1] = board[7][6] = 3; // White knights

    // Initialize the bishops
    board[0][2] = board[0][5] = -4; // Black bishops
    board[7][2] = board[7][5] = 4; // White bishops

    // Initialize the queens
    board[0][3] = -5; // Black queen
    board[7][3] = 5; // White queen

    // Initialize the kings
    board[0][4] = -6; // Black king
    board[7][4] = 6; // White king
}

// Function to print the board
void print_board() {
    int i, j;

    printf("\n   A  B  C  D  E  F  G  H\n\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", BOARD_SIZE - i);
        for (j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case -6:
                    printf("|BK"); // Black king
                    break;
                case -5:
                    printf("|BQ"); // Black queen
                    break;
                case -4:
                    printf("|BB"); // Black bishop
                    break;
                case -3:
                    printf("|BN"); // Black knight
                    break;
                case -2:
                    printf("|BR"); // Black rook
                    break;
                case -1:
                    printf("|BP"); // Black pawn
                    break;
                case 0:
                    printf("|  "); // Empty square
                    break;
                case 1:
                    printf("|WP"); // White pawn
                    break;
                case 2:
                    printf("|WR"); // White rook
                    break;
                case 3:
                    printf("|WN"); // White knight
                    break;
                case 4:
                    printf("|WB"); // White bishop
                    break;
                case 5:
                    printf("|WQ"); // White queen
                    break;
                case 6:
                    printf("|WK"); // White king
                    break;
            }
        }
        printf("| %d\n\n", BOARD_SIZE - i);
    }
    printf("   A  B  C  D  E  F  G  H\n\n");
}

int main() {
    initialize_board();
    print_board();

    // Randomly select the first player
    srand(time(NULL));
    int player = (rand() % 2 == 0) ? -1 : 1; // Black player: -1, White player: 1
    printf("Randomly selected player: %s\n", player == 1 ? "White" : "Black");

    // Game loop
    while (1) {
        // Get the player's move
        printf("Enter your move: ");
        char move[5];
        scanf("%s", move);

        // Validate the move
        int from_file, from_rank, to_file, to_rank;
        if (strlen(move) == 4 && move[0] >= 'a' && move[0] <= 'h' && move[1] >= '1' && move[1] <= '8'
                && move[2] >= 'a' && move[2] <= 'h' && move[3] >= '1' && move[3] <= '8') {
            from_file = move[0] - 'a';
            from_rank = BOARD_SIZE - (move[1] - '0');
            to_file = move[2] - 'a';
            to_rank = BOARD_SIZE - (move[3] - '0');
            if (board[from_rank][from_file] * player <= 0) {
                printf("Error: Invalid move, try again.\n");
                continue;
            }
        } else {
            printf("Error: Invalid move, try again.\n");
            continue;
        }

        // Make the move
        board[to_rank][to_file] = board[from_rank][from_file];
        board[from_rank][from_file] = 0;
        print_board();

        // Switch the player
        player *= -1;
    }

    return 0;
}