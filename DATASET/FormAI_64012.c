//FormAI DATASET v1.0 Category: Checkers Game ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    printf("Montague Checkers versus Capulet Checkers. Let the game begin!\n");

    int board[8][8] = {0}; // initialize the checkerboard

    // Montague checkers (player 1) are represented by -1
    // Capulet checkers (player 2) are represented by 1
    // 0 represents an empty space on the board

    int player = -1; // start with Montague's turn

    while (1) { // loop until a winner is declared
        // display the current board state
        printf("\n");
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                printf("%2d", board[row][col]);
            }
            printf("\n");
        }

        int piece_row, piece_col, move_row, move_col;

        // get the piece the player wants to move
        printf("\nIt is ");
        if (player == -1) {
            printf("Montague's turn.\n");
        } else {
            printf("Capulet's turn.\n");
        }
        printf("Enter the row and column of the piece you want to move (e.g. 3 2): ");
        scanf("%d %d", &piece_row, &piece_col);

        // get the move the player wants to make
        printf("Enter the row and column of the move you want to make (e.g. 4 3): ");
        scanf("%d %d", &move_row, &move_col);

        // check if the move is legal
        if (player == -1) { // Montague's turn
            if (board[piece_row][piece_col] == -1) { // make sure it is a Montague checker
                if (move_row == piece_row - 1 && (move_col == piece_col - 1 || move_col == piece_col + 1)) { // simple jump move
                    if(board[move_row][move_col] == 0) {
                        board[move_row][move_col] = -1;
                        board[piece_row][piece_col] = 0;
                    } else {
                        printf("That space is already occupied.\n");
                    }
                } else if (move_row == piece_row - 2 && (move_col == piece_col - 2 || move_col == piece_col + 2)) { // jump over an enemy piece
                    if (board[move_row][move_col] == 0 && board[piece_row + 1][(piece_col + move_col) / 2] == 1) { // make sure space is empty and there is an enemy piece to jump over
                        board[move_row][move_col] = -1;
                        board[piece_row][piece_col] = 0;
                        board[piece_row + 1][(piece_col + move_col) / 2] = 0;
                    } else {
                        printf("That space is not empty or there is no enemy piece to jump over.\n");
                    }
                } else {
                    printf("That is an illegal move.\n");
                }
            } else {
                printf("That is not one of your pieces.\n");
            }
        } else { // Capulet's turn
            if (board[piece_row][piece_col] == 1) { // make sure it is a Capulet checker
                if (move_row == piece_row + 1 && (move_col == piece_col - 1 || move_col == piece_col + 1)) { // simple jump move
                    if(board[move_row][move_col] == 0) {
                        board[move_row][move_col] = 1;
                        board[piece_row][piece_col] = 0;
                    } else {
                        printf("That space is already occupied.\n");
                    }
                } else if (move_row == piece_row + 2 && (move_col == piece_col - 2 || move_col == piece_col + 2)) { // jump over an enemy piece
                    if (board[move_row][move_col] == 0 && board[piece_row - 1][(piece_col + move_col) / 2] == -1) { // make sure space is empty and there is an enemy piece to jump over
                        board[move_row][move_col] = 1;
                        board[piece_row][piece_col] = 0;
                        board[piece_row - 1][(piece_col + move_col) / 2] = 0;
                    } else {
                        printf("That space is not empty or there is no enemy piece to jump over.\n");
                    }
                } else {
                    printf("That is an illegal move.\n");
                }
            } else {
                printf("That is not one of your pieces.\n");
            }
        }

        // check if the game is over
        int montague_pieces_remaining = 0;
        int capulet_pieces_remaining = 0;
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                if (board[row][col] == -1) {
                    montague_pieces_remaining++;
                } else if (board[row][col] == 1) {
                    capulet_pieces_remaining++;
                }
            }
        }

        if (montague_pieces_remaining == 0) {
            printf("\nCapulet wins!\n");
            break;
        } else if (capulet_pieces_remaining == 0) {
            printf("\nMontague wins!\n");
            break;
        }

        // switch to the other player
        player = -player;
    }

    return 0;
}