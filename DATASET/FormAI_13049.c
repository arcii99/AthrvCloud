//FormAI DATASET v1.0 Category: Memory Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4 // define grid size
#define MAX_MOVES (GRID_SIZE * GRID_SIZE) // calculate max moves

int main() {
    int board[GRID_SIZE][GRID_SIZE] = {0}; // start with empty board

    srand(time(NULL)); // seed random number generator

    // randomly generate numbers to place in board
    for (int i = 1; i <= MAX_MOVES / 2; i++) {
        for (int j = 0; j < 2; j++) {
            int row, col;
            do {
                row = rand() % GRID_SIZE;
                col = rand() % GRID_SIZE;
            } while (board[row][col] != 0); // keep generating random coordinates until an empty spot is found
            board[row][col] = i;
        }
    }

    int moves[MAX_MOVES] = {-1}; // player's moves will be stored in this array
    int num_moves = 0; // start with no moves

    printf("Welcome to Memory Game!\n\n");

    while (num_moves < MAX_MOVES) {
        // print the board
        printf("Board:\n\n");
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (board[i][j] == 0) {
                    printf("  "); // empty spot
                } else if (moves[num_moves] != -1 && i == moves[num_moves] / GRID_SIZE && j == moves[num_moves] % GRID_SIZE) {
                    printf("%2d", board[i][j]); // player has revealed this spot
                } else {
                    printf("##"); // spot has not yet been revealed
                }
            }
            printf("\n");
        }

        // get player's move
        int move1, move2;
        do {
            printf("Enter two coordinates (row col) to reveal a card: ");
            fflush(stdout);
            scanf("%d %d", &move1, &move2);
            move1--; // adjust for 0-indexing
            move2--;
        } while (move1 < 0 || move1 >= GRID_SIZE || move2 < 0 || move2 >= GRID_SIZE || moves[num_moves] == move1 * GRID_SIZE + move2); // make sure the move is valid and has not already been made

        moves[num_moves] = move1 * GRID_SIZE + move2; // store the move in the array
        num_moves++;

        // check if the moves match
        if (num_moves % 2 == 0) {
            int first_move = moves[num_moves - 2];
            int second_move = moves[num_moves - 1];
            if (board[first_move / GRID_SIZE][first_move % GRID_SIZE] == board[second_move / GRID_SIZE][second_move % GRID_SIZE]) {
                printf("\nMatch found!\n");
            } else {
                printf("\nNo match. Try again.\n");
            }
        }

        printf("\n");
    }

    printf("Congratulations! You have won the game!\n");

    return 0;
}