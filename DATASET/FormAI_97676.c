//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_MONSTERS 10

struct Position {
    int x;
    int y;
};

struct Monster {
    struct Position position;
    char symbol;
};

char map[MAP_HEIGHT][MAP_WIDTH];
struct Monster monsters[MAX_MONSTERS];
int num_monsters;

void generate_map() {
    // Generate random walls and floors for the map
    srand(time(NULL));
    for (int y=0; y<MAP_HEIGHT; y++) {
        for (int x=0; x<MAP_WIDTH; x++) {
            if (rand() % 100 < 40) {
                map[y][x] = '#';
            } else {
                map[y][x] = '.';
            }
        }
    }
}

void add_monster(int x, int y, char symbol) {
    // Add a new monster to the array of monsters
    struct Monster monster = { .position = {x, y}, .symbol = symbol };
    monsters[num_monsters++] = monster;
}

void generate_monsters() {
    // Generate random monsters on the map
    srand(time(NULL));
    num_monsters = 0;
    for (int i=0; i<MAX_MONSTERS; i++) {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        add_monster(x, y, 'M');
    }
}

void print_map() {
    // Print the current state of the map with monsters
    for (int y=0; y<MAP_HEIGHT; y++) {
        for (int x=0; x<MAP_WIDTH; x++) {
            // Check if there is a monster at this position
            char symbol = map[y][x];
            for (int i=0; i<num_monsters; i++) {
                struct Monster monster = monsters[i];
                if (monster.position.x == x && monster.position.y == y) {
                    symbol = monster.symbol;
                    break;
                }
            }
            printf("%c", symbol);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    generate_map();
    generate_monsters();
    print_map();
    return 0;
}