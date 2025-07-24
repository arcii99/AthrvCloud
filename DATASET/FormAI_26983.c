//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: modular
#include <stdio.h>  // For standard input and output
#include <stdlib.h> // For standard library functions
#include <time.h>   // For time-based operations

// Macros for game constants
#define WIDTH 80
#define HEIGHT 20
#define MAX_OBSTACLES 10

// Struct to represent game entities
typedef struct {
    int x;
    int y;
} Entity;

// Function prototypes
void initialize(Entity *player, Entity obstacles[]);
void draw(Entity *player, Entity obstacles[]);
void update(Entity *player, Entity obstacles[]);

// Game entry point
int main() {
    srand(time(NULL));

    Entity player, obstacles[MAX_OBSTACLES];
    initialize(&player, obstacles);

    while (1) {
        draw(&player, obstacles);

        // Exit game loop if player reaches end
        if (player.x == WIDTH) {
            printf("\nCongratulations! You won!\n");
            break;
        }

        update(&player, obstacles);

        // Exit game loop if player hits an obstacle
        for (int i = 0; i < MAX_OBSTACLES; i++) {
            if (player.x == obstacles[i].x && player.y == obstacles[i].y) {
                printf("\nGame Over! You hit an obstacle!\n");
                return 0;
            }
        }
    }

    return 0;
}

// Function to initialize game entities
void initialize(Entity *player, Entity obstacles[]) {
    player->x = 0;
    player->y = HEIGHT / 2;

    for (int i = 0; i < MAX_OBSTACLES; i++) {
        obstacles[i].x = rand() % WIDTH;
        obstacles[i].y = rand() % HEIGHT;
    }
}

// Function to draw game entities on screen
void draw(Entity *player, Entity obstacles[]) {
    system("clear"); // Clear console screen

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == player->y && j == player->x) {
                printf("P"); // Draw player
            } else {
                int is_obstacle = 0;
                for (int k = 0; k < MAX_OBSTACLES; k++) {
                    if (obstacles[k].x == j && obstacles[k].y == i) {
                        printf("O"); // Draw obstacle
                        is_obstacle = 1;
                        break;
                    }
                }
                if (!is_obstacle) {
                    printf("."); // Draw empty space
                }
            }
        }
        printf("\n"); // New line after each row
    }
}

// Function to update game entities based on user input
void update(Entity *player, Entity obstacles[]) {
    // Read user input
    char input;
    scanf(" %c", &input);

    // Move player based on input
    switch (input) {
    case 'w':
        if (player->y > 0) {
            player->y--;
        }
        break;
    case 'a':
        if (player->x > 0) {
            player->x--;
        }
        break;
    case 's':
        if (player->y < HEIGHT - 1) {
            player->y++;
        }
        break;
    case 'd':
        if (player->x < WIDTH - 1) {
            player->x++;
        }
        break;
    }

    // Move obstacles randomly
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;

        if (obstacles[i].x + dx >= 0 && obstacles[i].x + dx < WIDTH) {
            obstacles[i].x += dx;
        }
        if (obstacles[i].y + dy >= 0 && obstacles[i].y + dy < HEIGHT) {
            obstacles[i].y += dy;
        }
    }
}