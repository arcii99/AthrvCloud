//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// We define our map size as constant, adjust this value to make a smaller or bigger map
#define MAP_SIZE 20

// Struct to represent the protagonist with location and health
typedef struct {
    int row;
    int col;
    int health;
} Protagonist;

// A 2D array to represent our map
char map[MAP_SIZE][MAP_SIZE];

// Function to generate the map procedurally
void generateMap() {

    // Randomize the map seed
    srand(time(NULL));

    // Create a border in the map
    for (int i = 0; i < MAP_SIZE; i++) {
        map[i][0] = '#';
        map[i][MAP_SIZE-1] = '#';
        map[0][i] = '#';
        map[MAP_SIZE-1][i] = '#';
    }

    // Place some objects in the map, represented by '@'
    int num_objects = (rand() % (MAP_SIZE*MAP_SIZE/10)) + 1; // Random number of objects
    for (int i = 0; i < num_objects; i++) {
        int random_row = rand() % (MAP_SIZE-2) + 1;
        int random_col = rand() % (MAP_SIZE-2) + 1;
        map[random_row][random_col] = '@';
    }
}

// Function to print the map
void printMap(Protagonist p) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (p.row == i && p.col == j) {
                printf("P ");
            } else {
                printf("%c ", map[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to move our protagonist in the map
void moveProtagonist(Protagonist* p, char direction) {
    switch(direction) {
        case 'w': // Move up
            if (map[p->row-1][p->col] != '#') p->row--;
            break;
        case 'a': // Move left
            if (map[p->row][p->col-1] != '#') p->col--;
            break;
        case 's': // Move down
            if (map[p->row+1][p->col] != '#') p->row++;
            break;
        case 'd': // Move right
            if (map[p->row][p->col+1] != '#') p->col++;
            break;
    }
}

// Protagonist picks up object
void pickupObject(Protagonist* p) {
    if (map[p->row][p->col] == '@') {
        p->health += 5;
        map[p->row][p->col] = ' ';
    }
}

int main() {

    // Create our protagonist and give a random starting location and health
    Protagonist p;
    p.row = rand() % (MAP_SIZE-2) + 1;
    p.col = rand() % (MAP_SIZE-2) + 1;
    p.health = 50;

    // Generate the procedural map
    generateMap();

    // Game loop
    while (p.health > 0) {
        system("clear"); // Clear console for new map print
        printMap(p);
        printf("Health: %d\n", p.health);

        char input;
        printf("Enter a move (w,a,s,d), 'q' to quit: ");
        scanf(" %c", &input);

        if (input == 'q') break; // Quit game

        moveProtagonist(&p, input); // Move protagonist based on input
        pickupObject(&p); // Protagonist picks up object (if any)

    }

    // Game over
    printf("Game over! You scored %d points.\n", p.health);

    return 0;
}