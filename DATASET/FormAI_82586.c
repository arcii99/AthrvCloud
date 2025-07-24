//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_ENEMIES 10
#define MAX_ITEMS 5

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    char symbol;
    Position position;
} Entity;

Entity player;
Entity enemies[MAX_ENEMIES];
Entity items[MAX_ITEMS];

char map[MAX_ROWS][MAX_COLS];
bool game_over = false;

// Function Declarations
bool is_collision(Position pos);
void move_player(char direction);
void move_enemy(int enemy_index);
void generate_map();
void generate_items();
void generate_enemies();

int main() {
    srand(time(NULL)); // Seed the random number generator

    generate_map();
    generate_items();
    generate_enemies();

    // Place player in a random position on the map
    int random_row = rand() % MAX_ROWS;
    int random_col = rand() % MAX_COLS;
    while (map[random_row][random_col] != '.') {
        random_row = rand() % MAX_ROWS;
        random_col = rand() % MAX_COLS;
    }
    player.position.row = random_row;
    player.position.col = random_col;
    player.symbol = '@';

    // Game Loop
    while(!game_over) {
        printf("Legend:\n @ - Player\n e - Enemy\n i - Item\n . - Empty Space\n\n");
        // Print the map
        for (int row = 0; row < MAX_ROWS; row++) {
            for (int col = 0; col < MAX_COLS; col++) {
                if (player.position.row == row && player.position.col == col) {
                    printf("%c ", player.symbol);
                }
                else {
                    bool entity_placed = false;
                    for (int i = 0; i < MAX_ENEMIES; i++) {
                        if (enemies[i].position.row == row && enemies[i].position.col == col) {
                            printf("%c ", enemies[i].symbol);
                            entity_placed = true;
                        }
                    }
                    for (int i = 0; i < MAX_ITEMS; i++) {
                        if (items[i].position.row == row && items[i].position.col == col) {
                            printf("%c ", items[i].symbol);
                            entity_placed = true;
                        }
                    }
                    if (!entity_placed) {
                        printf("%c ", map[row][col]);
                    }
                }
            }
            printf("\n");
        }

        // Get user input
        printf("Enter movement direction (w/a/s/d) or 'q' to quit: ");
        char input;
        scanf(" %c", &input);
        if (input == 'q') {
            game_over = true;
            printf("Game Over!\n");
        }
        else {
            move_player(input);

            // Move enemies
            for (int i = 0; i < MAX_ENEMIES; i++) {
                move_enemy(i);
            }

            // Check for collisions with enemies or items
            for (int i = 0; i < MAX_ENEMIES; i++) {
                if (player.position.row == enemies[i].position.row && player.position.col == enemies[i].position.col) {
                    game_over = true;
                    printf("Game Over!\n");
                }
            }
            for (int i = 0; i < MAX_ITEMS; i++) {
                if (player.position.row == items[i].position.row && player.position.col == items[i].position.col) {
                    printf("Picked up an item!\n");
                    items[i].symbol = '.';
                }
            }
        }
    }

    return 0;
}

// Function Definitions
bool is_collision(Position pos) {
    if (pos.row < 0 || pos.row >= MAX_ROWS || pos.col < 0 || pos.col >= MAX_COLS) {
        return true; // out of bounds
    }
    else if (map[pos.row][pos.col] != '.') {
        return true; // collided with wall
    }
    else {
        return false; // no collision
    }
}

void move_player(char direction) {
    Position new_pos = player.position;
    switch (direction) {
        case 'w': // up
            new_pos.row--;
            break;
        case 'a': // left
            new_pos.col--;
            break;
        case 's': // down
            new_pos.row++;
            break;
        case 'd': // right
            new_pos.col++;
            break;
        default: // invalid input
            break;
    }
    if (!is_collision(new_pos)) {
        player.position = new_pos;
    }
}

void move_enemy(int enemy_index) {
    // Generate a random direction
    int random_direction = rand() % 4;
    Position new_pos = enemies[enemy_index].position;
    switch (random_direction) {
        case 0: // up
            new_pos.row--;
            break;
        case 1: // left
            new_pos.col--;
            break;
        case 2: // down
            new_pos.row++;
            break;
        case 3: // right
            new_pos.col++;
            break;
        default: // invalid direction
            break;
    }
    if (!is_collision(new_pos)) {
        enemies[enemy_index].position = new_pos;
    }
}

void generate_map() {
    // Fill map with empty spaces
    for (int row = 0; row < MAX_ROWS; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            map[row][col] = '.';
        }
    }

    // Generate walls
    for (int i = 0; i < (MAX_ROWS + MAX_COLS) / 3; i++) {
        int random_row = rand() % MAX_ROWS;
        int random_col = rand() % MAX_COLS;
        if (!(random_row == 0 && random_col == 0) && !(random_row == MAX_ROWS - 1 && random_col == MAX_COLS - 1)) {
            map[random_row][random_col] = '#';
        }
    }
}

void generate_items() {
    // Generate items
    for (int i = 0; i < MAX_ITEMS; i++) {
        int random_row = rand() % MAX_ROWS;
        int random_col = rand() % MAX_COLS;
        while (map[random_row][random_col] != '.') {
            random_row = rand() % MAX_ROWS;
            random_col = rand() % MAX_COLS;
        }
        items[i].position.row = random_row;
        items[i].position.col = random_col;
        items[i].symbol = 'i';
    }
}

void generate_enemies() {
    // Generate enemies
    for (int i = 0; i < MAX_ENEMIES; i++) {
        int random_row = rand() % MAX_ROWS;
        int random_col = rand() % MAX_COLS;
        while (map[random_row][random_col] != '.') {
            random_row = rand() % MAX_ROWS;
            random_col = rand() % MAX_COLS;
        }
        enemies[i].position.row = random_row;
        enemies[i].position.col = random_col;
        enemies[i].symbol = 'e';
    }
}