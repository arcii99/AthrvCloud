//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Function to clear the terminal screen
void clear_screen() {
    system("clear");
}

// Function to generate a random number between given range
int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(0)); // Seed the random number generator

    int score = 0; // Initialize the score to 0
    int level = 1; // Initialize the level to 1
    
    // Start of the game loop
    while (1) {
        clear_screen(); // Clear the screen
        printf("---------------\n");
        printf("Score: %d\n", score);
        printf("Level: %d\n", level);
        printf("---------------\n\n");
        printf("Instructions:\n");
        printf("Use the arrow keys to move the player\n");
        printf("Avoid the obstacles and collect the coins\n");
        printf("Press q to exit the game\n\n");

        // Generate the player and the obstacles in random positions
        int player_pos = 20;
        int obstacle_pos = generate_random_number(1, 40);
        int coin_pos = generate_random_number(1, 40);

        // Start of the game level
        while (1) {
            clear_screen(); // Clear the screen
            printf("---------------\n");
            printf("Score: %d\n", score);
            printf("Level: %d\n", level);
            printf("---------------\n\n");

            // Print the game board with player, obstacles and coin
            for (int i = 1; i <= 40; i++) {
                if (player_pos == i) {
                    printf("O");
                } else if (obstacle_pos == i) {
                    printf("X");
                } else if (coin_pos == i) {
                    printf("$");
                } else {
                    printf(" ");
                }
            }

            // Check if the player has hit an obstacle
            if (player_pos == obstacle_pos) {
                printf("\n\nYou hit an obstacle!\n");
                printf("Final Score: %d\n", score);
                exit(0);
            }

            // Check if the player has collected a coin
            if (player_pos == coin_pos) {
                score += 10; // Increase the score
                coin_pos = 0; // Remove the coin from the board
            }

            // Get user input
            char input;
            scanf(" %c", &input);

            // Move the player based on user input
            if (input == 'q') {
                printf("\n\nYou quit the game!\n");
                printf("Final Score: %d\n", score);
                exit(0);
            } else if (input == 'a') {
                if (player_pos > 1) {
                    player_pos--;
                }
            } else if (input == 'd') {
                if (player_pos < 40) {
                    player_pos++;
                }
            }

            // Move the obstacle towards the player on every level
            if (obstacle_pos > player_pos) {
                obstacle_pos--;
            } else if (obstacle_pos < player_pos) {
                obstacle_pos++;
            }

            // Check if the player has completed the level
            if (coin_pos == 0 && obstacle_pos == player_pos) {
                printf("\n\nYou completed level %d!\n", level);
                score += 50; // Increase the score
                level++; // Increase the level
                sleep(1); // Pause for 1 second
                break; // Exit the game level loop
            }

            usleep(100000); // Pause for 100 milliseconds
        }
    }
    
    return 0;
}