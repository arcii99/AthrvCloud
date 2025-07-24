//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAP_SIZE 10     // Size of map
#define MAX_MOVES 15    // Maximum number of moves player can make
#define MAX_ITEMS 3     // Maximum number of items player can have

// Struct for each item on the map
typedef struct Item {
    char name[20];
    int x;
    int y;
} Item;

// Struct for the player
typedef struct Player {
    int x;
    int y;
    int moves_left;
    int num_items;
    Item items[MAX_ITEMS];
} Player;

// Generates a random number between min and max (inclusive)
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Initializes the map with random items
void initialize_map(Item map[], int map_size) {
    int i;
    for (i = 0; i < map_size; i++) {
        Item item;
        strcpy(item.name, "item");
        item.x = random_number(0, map_size-1);
        item.y = random_number(0, map_size-1);
        map[i] = item;
    }
}

// Prints the map with the player and items
void print_map(Item map[], int map_size, Player player) {
    int i, j;

    // Print top border
    printf("+");
    for (i = 0; i < map_size; i++) {
        printf("--+");
    }
    printf("\n");

    // Print each row of the map
    for (i = 0; i < map_size; i++) {
        printf("|");
        for (j = 0; j < map_size; j++) {
            // Print player if at this location
            if (i == player.y && j == player.x) {
                printf(" P ");
            } else {
                // Check if an item is at this location
                int k;
                int found = 0;
                for (k = 0; k < map_size; k++) {
                    if (map[k].x == j && map[k].y == i) {
                        printf(" %s ", map[k].name);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("   ");
                }
            }
            printf("|");
        }
        printf("\n");

        // Print middle and bottom borders
        printf("+");
        for (j = 0; j < map_size; j++) {
            printf("--+");
        }
        printf("\n");
    }
}

// Checks if the player has collected all items
int check_won(Player player) {
    return (player.num_items == MAX_ITEMS);
}

int main() {
    srand(time(NULL));   // Initialize random seed

    Item map[MAP_SIZE];   // Create map
    initialize_map(map, MAP_SIZE);  // Initialize map

    Player player;   // Create player
    player.x = random_number(0, MAP_SIZE-1);
    player.y = random_number(0, MAP_SIZE-1);
    player.moves_left = MAX_MOVES;
    player.num_items = 0;

    // Print welcome message and instructions
    printf("Welcome to Map Quest!\n");
    printf("The objective of this game is to collect all of the items on the map within %d moves.\n", MAX_MOVES);
    printf("Use the arrow keys to move the player. When you land on an item, you will automatically collect it.\n");
    printf("Press any key to begin.\n");
    getchar();

    // Main game loop
    int game_over = 0;
    while (!game_over) {
        printf("\033[2J\033[1;1H");   // Clear console and move cursor to top-left corner
        printf("Moves left: %d\n\n", player.moves_left);
        print_map(map, MAP_SIZE, player);

        // Check if game is over
        if (check_won(player)) {
            printf("Congratulations! You have collected all of the items.\n");
            game_over = 1;
            continue;
        } else if (player.moves_left == 0) {
            printf("Game over. You have run out of moves.\n");
            game_over = 1;
            continue;
        }

        // Get player input
        char input;
        printf("Use arrow keys to move player.\n");
        scanf(" %c", &input);

        // Update player position based on input
        if (input == 'up') {
            if (player.y > 0) {
                player.y--;
            }
        } else if (input == 'down') {
            if (player.y < MAP_SIZE-1) {
                player.y++;
            }
        } else if (input == 'left') {
            if (player.x > 0) {
                player.x--;
            }
        } else if (input == 'right') {
            if (player.x < MAP_SIZE-1) {
                player.x++;
            }
        }

        // Check if player is on an item and collect it if so
        int i;
        for (i = 0; i < MAP_SIZE; i++) {
            if (map[i].x == player.x && map[i].y == player.y) {
                printf("You have collected a %s.\n", map[i].name);
                player.items[player.num_items] = map[i];
                player.num_items++;
                map[i].x = -1;
                map[i].y = -1;
                break;
            }
        }

        player.moves_left--;
    }

    return 0;
}