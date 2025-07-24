//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

// Struct for holding player position
typedef struct {
    int x;
    int y;
} Player;

// Struct for holding monster position
typedef struct {
    int x;
    int y;
} Monster;

// Initialize player and monster positions
Player player = {0, 0};
Monster monster = {0, 0};

// Create a 2D array for the map
char map[MAP_HEIGHT][MAP_WIDTH];

// Function for generating a random number within a range
int random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function for initializing the map with random wall and floor tiles
void initialize_map() {
    srand(time(NULL));

    // Fill the map with walls
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }

    // Fill the map with randomly placed floors
    for (int i = 1; i < MAP_HEIGHT - 1; i++) {
        for (int j = 1; j < MAP_WIDTH - 1; j++) {
            if (random_int(0, 100) < 40) {
                map[i][j] = '.';
            }
        }
    }

    // Place the player in a random location
    player.x = random_int(1, MAP_WIDTH - 2);
    player.y = random_int(1, MAP_HEIGHT - 2);
    map[player.y][player.x] = '@';

    // Place the monster in a random location
    monster.x = random_int(1, MAP_WIDTH - 2);
    monster.y = random_int(1, MAP_HEIGHT - 2);
    map[monster.y][monster.x] = 'M';
}

// Function for printing the map
void print_map() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Main game loop
int main() {
    initialize_map();
    print_map();

    // Game loop
    while (1) {
        char input;
        printf("Enter a direction (WASD): ");
        scanf(" %c", &input);

        // Move the player based on input
        switch (input) {
            case 'w':
                if (map[player.y - 1][player.x] != '#') {
                    map[player.y][player.x] = '.';
                    player.y--;
                    map[player.y][player.x] = '@';
                }
                break;
            case 'a':
                if (map[player.y][player.x - 1] != '#') {
                    map[player.y][player.x] = '.';
                    player.x--;
                    map[player.y][player.x] = '@';
                }
                break;
            case 's':
                if (map[player.y + 1][player.x] != '#') {
                    map[player.y][player.x] = '.';
                    player.y++;
                    map[player.y][player.x] = '@';
                }
                break;
            case 'd':
                if (map[player.y][player.x + 1] != '#') {
                    map[player.y][player.x] = '.';
                    player.x++;
                    map[player.y][player.x] = '@';
                }
                break;
            default:
                printf("Invalid input!\n");
                break;
        }

        // If the player moves onto the monster, the game ends
        if (player.x == monster.x && player.y == monster.y) {
            printf("You have defeated the monster! Congratulations!\n");
            break;
        }

        // Move the monster towards the player
        if (player.x > monster.x && map[monster.y][monster.x + 1] != '#') {
            map[monster.y][monster.x] = '.';
            monster.x++;
            map[monster.y][monster.x] = 'M';
        } else if (player.x < monster.x && map[monster.y][monster.x - 1] != '#') {
            map[monster.y][monster.x] = '.';
            monster.x--;
            map[monster.y][monster.x] = 'M';
        } else if (player.y > monster.y && map[monster.y + 1][monster.x] != '#') {
            map[monster.y][monster.x] = '.';
            monster.y++;
            map[monster.y][monster.x] = 'M';
        } else if (player.y < monster.y && map[monster.y - 1][monster.x] != '#') {
            map[monster.y][monster.x] = '.';
            monster.y--;
            map[monster.y][monster.x] = 'M';
        }

        // If the monster moves onto the player, the game ends
        if (player.x == monster.x && player.y == monster.y) {
            printf("The monster has defeated you! Game over.\n");
            break;
        }

        // Print the updated map
        print_map();
    }

    return 0;
}