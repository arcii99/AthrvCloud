//FormAI DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));         // Seed the random number generator with the current time

    int table[6][6];           // Define a 6x6 array for the table
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            table[i][j] = rand() % 10;    // Fill the table with random numbers between 0 and 9
        }
    }

    int player_score = 0;       // Initialize the player's score to 0
    int computer_score = 0;     // Initialize the computer's score to 0
    int player_turn = 1;        // Initialize the player's turn to 1

    while (1) {                 // Loop indefinitely until break is encountered
        system("clear");        // Clear the screen for a new turn

        printf("Table:\n");     // Print the table
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                printf("%d ", table[i][j]);
            }
            printf("\n");
        }

        if (player_turn == 1) {         // Player's turn
            printf("Player's turn:\n");
            printf("Enter row and column to select (0-5): ");
            int row, col;
            scanf("%d %d", &row, &col);

            if (row < 0 || row > 5 || col < 0 || col > 5) {    // Validate input
                printf("Invalid input, please try again.\n");
                continue;
            }

            player_score += table[row][col];    // Add the selected number to the player's score
            table[row][col] = -1;               // Replace the selected number with -1 to mark it as used
            player_turn = 0;                    // Set player's turn to 0 for the next turn
        }

        else {                          // Computer's turn
            printf("Computer's turn:\n");

            int max_val = -1;           // Initialize max_val to -1
            int max_row = -1;           // Initialize max_row to -1
            int max_col = -1;           // Initialize max_col to -1

            for (int i = 0; i < 6; i++) {           // Loop through the table to find the largest unused number
                for (int j = 0; j < 6; j++) {
                    if (table[i][j] > max_val) {
                        max_val = table[i][j];
                        max_row = i;
                        max_col = j;
                    }
                }
            }

            computer_score += max_val;              // Add the selected number to the computer's score
            table[max_row][max_col] = -1;           // Replace the selected number with -1 to mark it as used
            player_turn = 1;                        // Set player's turn to 1 for the next turn
        }

        printf("Player's score: %d\n", player_score);        // Print the player's score
        printf("Computer's score: %d\n", computer_score);    // Print the computer's score

        if (player_score + computer_score == 30) {           // Check if the game is over
            printf("Game over!\n");

            if (player_score > computer_score) {             // Print the winner
                printf("Player wins!\n");
            }
            else if (computer_score > player_score) {
                printf("Computer wins!\n");
            }
            else {
                printf("It's a tie!\n");
            }

            break;                                          // Exit the while loop to end the game
        }

        printf("Press enter to continue...");
        getchar();                                          // Wait for user input before starting the next turn
    }

    return 0;           // Exit the program
}