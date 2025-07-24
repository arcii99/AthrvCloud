//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define WIDTH 50
#define HEIGHT 20
#define ENEMY_COUNT 20
#define BULLET_COUNT 2

int ship_x, enemy_x[ENEMY_COUNT], enemy_y[ENEMY_COUNT], bullet_x[BULLET_COUNT], bullet_y[BULLET_COUNT];
int score, lives;

void init_game() {
    // Set the starting position of the ship
    ship_x = WIDTH / 2;

    // Set the starting positions of the enemies randomly
    srand(time(NULL));
    for (int i = 0; i < ENEMY_COUNT; i++) {
        enemy_x[i] = rand() % WIDTH;
        enemy_y[i] = rand() % (HEIGHT / 4);
    }

    // Set the starting positions of the bullets to be off the screen
    for (int i = 0; i < BULLET_COUNT; i++) {
        bullet_x[i] = -1;
        bullet_y[i] = -1;
    }

    // Set the starting score and lives
    score = 0;
    lives = 3;
}

void draw_game() {
    // Clear the screen
    system("clear");

    // Draw the ship
    for (int i = 0; i < ship_x; i++) {
        printf(" ");
    }
    printf("A\n");

    // Draw the enemies
    for (int i = 0; i < ENEMY_COUNT; i++) {
        if (enemy_y[i] == 0) {
            // The enemy has reached the bottom of the screen, so it's game over
            lives = 0;
            return;
        }

        for (int j = 0; j < enemy_x[i]; j++) {
            printf(" ");
        }
        printf("V\n");
    }

    // Draw the bullets, if they are on the screen
    for (int i = 0; i < BULLET_COUNT; i++) {
        if (bullet_y[i] >= 0) {
            for (int j = 0; j < bullet_x[i]; j++) {
                printf(" ");
            }
            printf("*\n");
        }
    }

    // Draw the score and lives
    printf("Score: %d\n", score);
    printf("Lives: ");
    for (int i = 0; i < lives; i++) {
        printf("♥ ");
    }
    printf("\n");
}

void move_enemies() {
    // Move the enemies down
    for (int i = 0; i < ENEMY_COUNT; i++) {
        enemy_y[i]++;
    }

    // Check for collisions with bullets
    for (int i = 0; i < BULLET_COUNT; i++) {
        if (bullet_y[i] == -1) {
            // The bullet is not on the screen, so skip it
            continue;
        }

        for (int j = 0; j < ENEMY_COUNT; j++) {
            if (bullet_x[i] == enemy_x[j] && bullet_y[i] == enemy_y[j]) {
                // The bullet has hit an enemy, so remove the enemy and update the score
                enemy_y[j] = -1;
                score += 10;

                // Remove the bullet from the screen
                bullet_y[i] = -1;
            }
        }
    }
}

void move_bullets() {
    // Move the bullets up
    for (int i = 0; i < BULLET_COUNT; i++) {
        if (bullet_y[i] >= 0) {
            bullet_y[i]--;
        }
    }
}

int main() {
    init_game();

    while (lives > 0) {
        draw_game();
        move_enemies();
        move_bullets();

        // Get user input to move the ship and fire bullets
        int input = getchar();
        if (input == 'a' && ship_x > 0) {
            ship_x--;
        } else if (input == 'd' && ship_x < WIDTH - 1) {
            ship_x++;
        } else if (input == ' ' || input == '\n') {
            // Fire a bullet
            for (int i = 0; i < BULLET_COUNT; i++) {
                if (bullet_y[i] == -1) {
                    bullet_x[i] = ship_x;
                    bullet_y[i] = HEIGHT - 2;
                    break;
                }
            }
        }
    }

    // Game over
    draw_game();
    printf("Game Over! Your score is %d\n", score);

    return 0;
}