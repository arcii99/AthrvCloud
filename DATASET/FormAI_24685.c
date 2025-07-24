//FormAI DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int board[10][10];  // the game board
    int row, col;  // coordinates for user input
    int i, j;  // loop indices
    int moves_left = 50;  // number of moves remaining
    int points = 0;  // total score
    srand(time(0));  // seed the random number generator

    // initialize the board
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            board[i][j] = rand() % 6;  // random number from 0 to 5
        }
    }

    // print the board
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", i);
        for (j = 0; j < 10; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // main game loop
    while (moves_left > 0) {
        // get user input
        printf("Enter coordinates (row, col): ");
        scanf("%d %d", &row, &col);

        // check if the coordinates are valid
        if (row < 0 || row >= 10 || col < 0 || col >= 10) {
            printf("Invalid coordinates. Please try again.\n");
            continue;  // go back to the start of the loop
        }

        // check if the move is legal
        if (board[row][col] == 0) {
            printf("That square is already empty. Please try again.\n");
            continue;  // go back to the start of the loop
        }

        // add points to the score
        points += board[row][col] * 10;
        printf("You scored %d points!\n", board[row][col] * 10);

        // remove the tile from the board
        board[row][col] = 0;

        // print the updated board
        printf("  0 1 2 3 4 5 6 7 8 9\n");
        for (i = 0; i < 10; i++) {
            printf("%d ", i);
            for (j = 0; j < 10; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // decrement the number of moves remaining
        moves_left--;
        printf("You have %d moves left.\n", moves_left);

        // check if the game is over
        if (moves_left == 0) {
            printf("Game over! Final score: %d\n", points);
            break;  // exit the loop
        }
    }

    return 0;
}