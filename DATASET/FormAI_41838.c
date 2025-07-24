//FormAI DATASET v1.0 Category: Checkers Game ; Style: recursive
#include <stdio.h>

#define BOARD_SIZE 8
#define EMPTY 0
#define PLAYER_1 1
#define PLAYER_2 2

int board[BOARD_SIZE][BOARD_SIZE] = { 0 };
int turn = PLAYER_1;

/**
 * Check for a valid move for a given player.
 * Returns 1 if a valid move exists, 0 otherwise.
*/
int valid_move(int player, int row, int col)
{
    // check if position is within the board bounds
    if (row < 0 || col < 0 || row >= BOARD_SIZE || col >= BOARD_SIZE) {
        return 0;
    }

    // check that the player is moving their own piece
    if (board[row][col] != player) {
        return 0;
    }

    // check if the move is diagonal
    int delta_row = (player == PLAYER_1) ? -1 : 1;
    if (col < 2 || col > BOARD_SIZE - 3 ||
        board[row + delta_row][col - 1] == player ||
        board[row + delta_row][col + 1] == player) {
        return 0;
    }

    // check if the move is to an empty square
    if (board[row + delta_row][col] != EMPTY) {
        return 0;
    }

    return 1; // valid move found
}

/**
 * Recursive function to make a move and check for a chain reaction.
 * Returns 1 if a chain reaction occurred, 0 otherwise.
*/
int make_move(int player, int row, int col)
{
    // make the move
    board[row][col] = EMPTY;
    int delta_row = (player == PLAYER_1) ? -1 : 1;
    board[row + delta_row][col] = player;

    // check for a chain reaction
    int chain_reaction = 0;
    if (valid_move(player, row + 2 * delta_row, col - 2) &&
        make_move(player, row + 2 * delta_row, col - 2)) {
        chain_reaction = 1;
    }
    if (valid_move(player, row + 2 * delta_row, col + 2) &&
        make_move(player, row + 2 * delta_row, col + 2)) {
        chain_reaction = 1;
    }

    return chain_reaction; // return whether a chain reaction occurred
}

/**
 * Function to print the game board to the console.
*/
void print_board()
{
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

int main()
{
    int player_1_count = 12;
    int player_2_count = 12;

    // place player 1 pieces
    for (int row = 0; row < BOARD_SIZE / 2 - 1; row++) {
        for (int col = (row + 1) % 2; col < BOARD_SIZE; col += 2) {
            board[row][col] = PLAYER_1;
        }
    }

    // place player 2 pieces
    for (int row = BOARD_SIZE / 2 + 1; row < BOARD_SIZE; row++) {
        for (int col = (row + 1) % 2; col < BOARD_SIZE; col += 2) {
            board[row][col] = PLAYER_2;
        }
    }

    // main game loop
    while (player_1_count > 0 && player_2_count > 0) {
        // print the board to the console
        print_board();

        // get the player's move
        printf("Player %d's turn.\n", turn);
        int row, col;
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &row, &col);

        // check if the move is valid
        if (!valid_move(turn, row, col)) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // make the move and check for a chain reaction
        int chain_reaction = make_move(turn, row, col);

        // update the player counts
        player_1_count = 0;
        player_2_count = 0;
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                if (board[row][col] == PLAYER_1) {
                    player_1_count++;
                }
                else if (board[row][col] == PLAYER_2) {
                    player_2_count++;
                }
            }
        }

        // switch the turn if no chain reaction occurred
        if (!chain_reaction) {
            turn = (turn == PLAYER_1) ? PLAYER_2 : PLAYER_1;
        }
    }

    // print the game over message
    printf("Game over. ");
    if (player_1_count > 0) {
        printf("Player 1 wins!\n");
    }
    else {
        printf("Player 2 wins!\n");
    }

    return 0;
}