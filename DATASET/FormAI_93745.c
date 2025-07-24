//FormAI DATASET v1.0 Category: Benchmarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * This program simulates a game of rock-paper-scissor. It generates random moves for the computer and
 * asks the user for their move. Then it determines who wins and prints the result along with the 
 * time taken to decide the winner.
 */

int main() {
    // Initialize the random seed
    srand(time(NULL));

    int compMove, userMove;
    double elapsed_time;
    clock_t start_time, end_time;

    printf("Welcome to Rock-Paper-Scissors Game!\n\n");
    printf("Enter your move:\n1 - Rock\n2 - Paper\n3 - Scissor\n");

    // Get the user's move
    scanf("%d", &userMove);

    // Generate the computer's move
    compMove = rand() % 3 + 1;

    // Get the starting time
    start_time = clock();

    // Determine the winner
    if (userMove == compMove) {
        printf("It's a tie!\n");
    } else if (userMove == 1 && compMove == 3 || userMove == 2 && compMove == 1 || userMove == 3 && compMove == 2) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }

    // Get the ending time
    end_time = clock();

    // Calculate the elapsed time
    elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    return 0;
}