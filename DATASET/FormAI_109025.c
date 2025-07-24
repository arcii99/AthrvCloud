//FormAI DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    printf("Welcome to the C Table Game!\n\n");
    printf("The rules of the game are simple:\n");
    printf("1) You will roll a dice and move that many spaces on the board\n");
    printf("2) The first player to reach the end of the board wins!\n\n");

    // Initialize the game board
    int board[100] = {0};
    board[0] = 1;

    // Generate random obstacles on the board
    int obstacles = 10;
    for (int i = 0; i < obstacles; i++) {
        int obstacle_pos = (rand() % 98) + 1; // Generate a random number between 1 and 98 (inclusive)
        board[obstacle_pos] = -1; // Set the obstacle position to -1
    }

    // Game loop
    int player_pos = 0;
    int num_rolls = 0;
    while (player_pos < 99) {
        int roll = (rand() % 6) + 1; // Generate a random number between 1 and 6 (inclusive)
        num_rolls++;
        player_pos += roll;

        if (player_pos >= 99) {
            printf("Congratulations, you have won the game in %d rolls!\n", num_rolls);
            break;
        }

        if (board[player_pos] == -1) {
            printf("Uh oh, you hit an obstacle and have to go back %d spaces!\n", roll);
            player_pos -= roll;
        } else {
            printf("You rolled a %d and moved %d spaces.\n", roll, roll);
        }
    }

    // Print the final board state
    printf("\nFinal board state:\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", board[i]);
        if (i % 10 == 9) {
            printf("\n");
        }
    }

    return 0;
}