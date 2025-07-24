//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the game board
#define ROWS 10
#define COLS 20

// Define the player character and enemy character
#define PLAYER 'P'
#define ENEMY 'E'

// Define the number of enemies per row
#define ENEMIES_PER_ROW 3

// Define the shape shifting characters
char shape_shift[5] = {'@', '!', '#', '$', '%'};

// Initialize the game board and player position
char game_board[ROWS][COLS];
int player_position = COLS/2;

// Function to generate a random number for enemy movement
int random_generator(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main() {
    // Set up the game board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Fill the board with spaces
            game_board[i][j] = ' ';
        }
    }

    // Place the player character on the board
    game_board[ROWS-1][player_position] = PLAYER;

    // Generate a random seed for enemy movement
    srand(time(0));

    // Initialize enemy movement variables
    int enemy_row = 0;
    int enemy_col = 0;
    int enemy_direction = 1;

    // Place the enemies on the board
    for (int i = 0; i < ROWS-3; i++) {
        for (int j = 0; j < ENEMIES_PER_ROW; j++) {
            // Randomize the enemy positions within a row
            enemy_row = i;
            enemy_col = j*4 + random_generator(0, 3);
            game_board[enemy_row][enemy_col] = ENEMY;
        }
    }

    // Print the initial game board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", game_board[i][j]);
        }
        printf("\n");
    }

    // Loop through the game until the player reaches the end or all enemies are defeated
    for (int i = 0; i < ROWS-3; i++) {
        // Shift the shape shifting characters on every round
        for (int j = 0; j < 5; j++) {
            shape_shift[j] = shape_shift[(j+1)%5];
        }

        // Move the enemies in the row
        for (int j = 0; j < ENEMIES_PER_ROW; j++) {
            // Move the enemy in the current direction
            game_board[i][j*4 + enemy_col] = ' ';
            enemy_col += enemy_direction;
            game_board[i][j*4 + enemy_col] = ENEMY;

            // Change the direction if the enemy reaches the edge of the board
            if (enemy_col <= 0 || enemy_col >= COLS-1) {
                enemy_direction *= -1;
            }
        }

        // Print the updated game board
        system("clear"); // Clear the console before printing the updated board
        for (int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                if (game_board[j][k] == ENEMY) {
                    // Replace the enemy character with a random shape shifting character
                    game_board[j][k] = shape_shift[random_generator(0, 4)];
                }
                printf("%c", game_board[j][k]);
            }
            printf("\n");
        }

        // Check for player input each round
        char input;
        scanf("%c", &input);

        if (input == 'a') {
            // Move player left
            if (player_position > 0) {
                game_board[ROWS-1][player_position] = ' ';
                player_position--;
                game_board[ROWS-1][player_position] = PLAYER;
            }
        } else if (input == 'd') {
            // Move player right
            if (player_position < COLS-1) {
                game_board[ROWS-1][player_position] = ' ';
                player_position++;
                game_board[ROWS-1][player_position] = PLAYER;
            }
        } else if (input == 'q') {
            // Quit the game
            break;
        }

        // Check for player collision with an enemy
        if (game_board[ROWS-1][player_position] == ENEMY) {
            printf("Game over! You have been defeated.\n");
            break;
        }

        // Check if all enemies have been defeated
        int enemies_remaining = 0;
        for (int j = 0; j < COLS; j++) {
            if (game_board[i][j] == ENEMY) {
                enemies_remaining++;
            }
        }
        if (enemies_remaining == 0) {
            printf("Congratulations! You have won the game!\n");
            break;
        }

        // Delay the game for a short time before starting the next round
        usleep(100000);
    }

    return 0;
}