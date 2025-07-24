//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20

char map[HEIGHT][WIDTH];

enum Direction {UP, DOWN, LEFT, RIGHT};

struct Player {
    int x;
    int y;
    int health;
};

void generateMap() {
    // Generate map using procedural methods
    // ...
    // Fill map with '@' symbol
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            map[i][j] = '@';
        }
    }
}

void printMap(struct Player* player) {
    // Print map with player character
    system("clear"); // Unix specific command
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == player->y && j == player->x) {
                printf("@");
            } else {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}

int movePlayer(struct Player* player, enum Direction direction) {
    int newX = player->x;
    int newY = player->y;
    switch (direction) {
        case UP:
            newY--;
            break;
        case DOWN:
            newY++;
            break;
        case LEFT:
            newX--;
            break;
        case RIGHT:
            newX++;
            break;
    }
    if (newX < 0 || newX >= WIDTH || newY < 0 || newY >= HEIGHT) {
        return 0; // Cannot move outside of map
    }
    if (map[newY][newX] == '#') {
        return 0; // Cannot move through walls
    }
    player->x = newX;
    player->y = newY;
    return 1;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    generateMap();
    struct Player player = {.x = WIDTH / 2, .y = HEIGHT / 2, .health = 100};
    while (player.health > 0) {
        printMap(&player);
        printf("Health: %d\n", player.health);
        printf("Move (w,a,s,d): ");
        char input;
        scanf(" %c", &input);
        enum Direction direction;
        switch (input) {
            case 'w':
                direction = UP;
                break;
            case 's':
                direction = DOWN;
                break;
            case 'a':
                direction = LEFT;
                break;
            case 'd':
                direction = RIGHT;
                break;
            default:
                continue; // Skip current iteration of loop if invalid input
        }
        if (movePlayer(&player, direction)) {
            // Successful movement, random chance to take damage
            if (rand() % 10 == 0) {
                player.health -= 10;
                printf("You took damage!\n");
            }
        } else {
            printf("Cannot move there.\n");
        }
    }
    printf("Game over.\n");
    return 0;
}