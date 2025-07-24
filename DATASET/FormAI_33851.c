//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Variables storing the player and alien positions
int player_x, player_y;
int alien_x, alien_y;

// Function prototypes
void initializeGame();
void printWorld();
int playGame();
int movePlayer(int, int);
int moveAlien(int, int);

int main() {
    int score = 0; // The player's score

    // Seed the random function using the current time
    srand(time(NULL));

    // Initialize the game and print the starting world
    initializeGame();
    printWorld();

    // Play the game until the player is caught by the alien
    while (playGame()) {
        // Move the player and alien randomly
        player_x += rand() % 3 - 1; // Move left, right or stay
        player_y += rand() % 3 - 1; // Move up, down or stay
        alien_x += rand() % 3 - 1;
        alien_y += rand() % 3 - 1;

        // Print the updated world
        printWorld();

        // Increase the player's score and print it
        score++;
        printf("Score: %d\n", score);
    }

    // Print the final score
    printf("Game over! Final score: %d\n", score);

    return 0;
}

// Initializes the player and alien positions randomly
void initializeGame() {
    player_x = rand() % 10;
    player_y = rand() % 10;
    alien_x = rand() % 10;
    alien_y = rand() % 10;
}

// Prints the current world, showing the player and alien positions
void printWorld() {
    int x, y;
    for (y = 0; y < 10; y++) {
        for (x = 0; x < 10; x++) {
            if (x == player_x && y == player_y) {
                printf("P"); // Print the player
            } else if (x == alien_x && y == alien_y) {
                printf("A"); // Print the alien
            } else {
                printf("."); // Print an empty space
            }
        }
        printf("\n"); // Move to the next line
    }
}

// Plays one round of the game, returning 1 if the player was not caught by the alien and 0 otherwise
int playGame() {
    // Move the player and the alien
    int player_dx = 0, player_dy = 0;
    int alien_dx = 0, alien_dy = 0;
    printf("Enter player movement (x y): ");
    scanf("%d %d", &player_dx, &player_dy);
    printf("Enter alien movement (x y): ");
    scanf("%d %d", &alien_dx, &alien_dy);
    int player_result = movePlayer(player_dx, player_dy);
    int alien_result = moveAlien(alien_dx, alien_dy);

    // If the player and alien occupy the same position, the game is over
    if (player_x == alien_x && player_y == alien_y) {
        return 0;
    } else {
        return 1;
    }
}

// Moves the player by dx units horizontally and dy units vertically, returning 1 if the move is valid and 0 otherwise
int movePlayer(int dx, int dy) {
    // Check if the move is valid
    if (player_x + dx >= 0 && player_x + dx < 10 && player_y + dy >= 0 && player_y + dy < 10) {
        player_x += dx;
        player_y += dy;
        return 1;
    } else {
        return 0;
    }
}

// Moves the alien by dx units horizontally and dy units vertically, returning 1 if the move is valid and 0 otherwise
int moveAlien(int dx, int dy) {
    // Check if the move is valid
    if (alien_x + dx >= 0 && alien_x + dx < 10 && alien_y + dy >= 0 && alien_y + dy < 10) {
        alien_x += dx;
        alien_y += dy;
        return 1;
    } else {
        return 0;
    }
}