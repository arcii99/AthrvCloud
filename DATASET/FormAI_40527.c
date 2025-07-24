//FormAI DATASET v1.0 Category: Checkers Game ; Style: excited
#include <stdio.h>

// Defining sizes for the checkerboard
#define ROWS 8 
#define COLUMNS 8

// Defining the players
#define PLAYER_ONE 1 
#define PLAYER_TWO -1 

// Defining the pieces
#define NO_PIECE 0 
#define PLAYER_ONE_CHECKER 1 
#define PLAYER_TWO_CHECKER -1 
#define PLAYER_ONE_KING 2 
#define PLAYER_TWO_KING -2 

// Defining the colors for the checkerboard
#define WHITE 0 
#define BLACK 1 

// Defining the winning conditions
#define PLAYER_ONE_WINS 1 
#define PLAYER_TWO_WINS -1 
#define DRAW 0

// Initializing the game board
int board[ROWS][COLUMNS] = { 
                            { 0, -1, 0, -1, 0, -1, 0, -1 }, 
                            { -1, 0, -1, 0, -1, 0, -1, 0 }, 
                            { 0, -1, 0, -1, 0, -1, 0, -1 }, 
                            { NO_PIECE, 0, NO_PIECE, 0, NO_PIECE, 0, NO_PIECE, 0 }, 
                            { 0, NO_PIECE, 0, NO_PIECE, 0, NO_PIECE, 0, NO_PIECE }, 
                            { PLAYER_ONE_CHECKER, 0, PLAYER_ONE_CHECKER, 0, PLAYER_ONE_CHECKER, 0, PLAYER_ONE_CHECKER, 0 }, 
                            { 0, PLAYER_ONE_CHECKER, 0, PLAYER_ONE_CHECKER, 0, PLAYER_ONE_CHECKER, 0, PLAYER_ONE_CHECKER }, 
                            { PLAYER_ONE_CHECKER, 0, PLAYER_ONE_CHECKER, 0, PLAYER_ONE_CHECKER, 0, PLAYER_ONE_CHECKER, 0 }, 
                          };

// Displaying the checkerboard
void display_board() {
    printf("\n    |-----|-----|-----|-----|-----|-----|-----|-----|\n");
    for(int i=0; i<ROWS; i++) {
        printf(" %d  |", i+1);
        for(int j=0; j<COLUMNS; j++) {
            if(board[i][j] == NO_PIECE) {
                printf("     |");
            } else if(board[i][j] == PLAYER_ONE_CHECKER) {
                printf("  X  |");
            } else if(board[i][j] == PLAYER_TWO_CHECKER) {
                printf("  O  |");
            } else if(board[i][j] == PLAYER_ONE_KING) {
                printf("  KX |");
            } else if(board[i][j] == PLAYER_TWO_KING) {
                printf("  KO |");
            }
        }
        printf("\n    |-----|-----|-----|-----|-----|-----|-----|-----|\n");
    }
    printf("       A     B     C     D     E     F     G     H\n");
}

int main() {
    int winner = NO_PIECE;
    int turn = PLAYER_ONE;

    // Beginning of the game loop
    while(winner == NO_PIECE) {
        // Displaying the checkerboard
        display_board();

        // Checking whose turn it is
        if(turn == PLAYER_ONE) {
            printf("\nPlayer 1's turn.\n");
        } else {
            printf("\nPlayer 2's turn.\n");
        }

        // Asking the user to input a move
        int start_row, start_col, end_row, end_col;
        printf("\nEnter the row and column of the piece you want to move: ");
        scanf("%d %d", &start_row, &start_col);
        printf("Enter the row and column of the cell you want to move the piece to: ");
        scanf("%d %d", &end_row, &end_col);

        // Making sure the inputs are valid
        if(start_row < 1 || start_row > ROWS || start_col < 1 || start_col > COLUMNS || end_row < 1 || end_row > ROWS || end_col < 1 || end_col > COLUMNS) {
            printf("\nInvalid input. Please try again.\n");
        } else if(board[start_row-1][start_col-1] == NO_PIECE) {
            printf("\nThere is no piece on that cell. Please try again.\n");
        } else if(board[start_row-1][start_col-1]*turn <= 0) {
            printf("\nYou cannot move your opponent's piece. Please try again.\n");
        } else {
            // Checking if the move is valid
            int delta_row = end_row - start_row;
            int delta_col = end_col - start_col;

            if(turn == PLAYER_ONE) {
                if((delta_row == -1 || delta_row == -2) && (delta_col == -1 || delta_col == 1)) {
                    // Valid move
                    printf("\nValid move.\n");
                    board[end_row-1][end_col-1] = PLAYER_ONE_CHECKER;
                    board[start_row-1][start_col-1] = NO_PIECE;
                    if(end_row == 1) {
                        board[end_row-1][end_col-1] = PLAYER_ONE_KING;
                    }
                    turn = PLAYER_TWO;
                } else {
                    // Invalid move
                    printf("\nInvalid move. Please try again.\n");
                }
            } else {
                if((delta_row == 1 || delta_row == 2) && (delta_col == -1 || delta_col == 1)) {
                    // Valid move
                    printf("\nValid move.\n");
                    board[end_row-1][end_col-1] = PLAYER_TWO_CHECKER;
                    board[start_row-1][start_col-1] = NO_PIECE;
                    if(end_row == 8) {
                        board[end_row-1][end_col-1] = PLAYER_TWO_KING;
                    }
                    turn = PLAYER_ONE;
                } else {
                    // Invalid move
                    printf("\nInvalid move. Please try again.\n");
                }
            }
        }

        // Checking for a winner
        int player_one_pieces = 0;
        int player_two_pieces = 0;
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLUMNS; j++) {
                if(board[i][j] == PLAYER_ONE_CHECKER || board[i][j] == PLAYER_ONE_KING) {
                    player_one_pieces++;
                } else if(board[i][j] == PLAYER_TWO_CHECKER || board[i][j] == PLAYER_TWO_KING) {
                    player_two_pieces++;
                }
            }
        }

        if(player_one_pieces == 0) {
            winner = PLAYER_TWO_WINS;
        } else if(player_two_pieces == 0) {
            winner = PLAYER_ONE_WINS;
        } else {
            winner = NO_PIECE;
        }
    }

    // Displaying the final state of the board
    display_board();

    // Displaying the winner
    if(winner == PLAYER_ONE_WINS) {
        printf("\nPlayer 1 wins!\n");
    } else if(winner == PLAYER_TWO_WINS) {
        printf("\nPlayer 2 wins!\n");
    } else {
        printf("\nDraw!\n");
    }

    return 0;
}