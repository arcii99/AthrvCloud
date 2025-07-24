//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 60
#define HEIGHT 30

typedef struct {
    int x, y;
    char symbol;
} entity;

char map[WIDTH][HEIGHT];

entity player;
entity enemies[10];

void generate_map() {
    // generate the map using cellular automata
    // initialize the map randomly
    
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (i == 0 || i == WIDTH-1 || j == 0 || j == HEIGHT-1) {
                map[i][j] = '#'; // draw the border
            }
            else {
                map[i][j] = rand() % 100 < 45 ? '#' : '.'; // randomly fill with walls or floors
            }
        }
    }
    
    // Iterate over the map multiple times to bring out the interesting features
    // of the automata and make the map more granular
    
    for (int iteration = 0; iteration < 5; iteration++) {
        char newmap[WIDTH][HEIGHT];
        
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                int count = 0;
                for (int ii = i - 1; ii <= i + 1; ii++) {
                    for (int jj = j - 1; jj <= j + 1; jj++) {
                        if (map[ii][jj] == '#') {
                            count++;
                        }
                    }
                }
                
                if (count > 4) {
                    newmap[i][j] = '#';
                }
                else if (count < 4) {
                    newmap[i][j] = '.';
                }
                else {
                    newmap[i][j] = map[i][j];
                }
            }
        }
        
        // Update the old map with the new map
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                map[i][j] = newmap[i][j];
            }
        }
    }
}

void spawn_entities() {
    // Spawn the player in a random location
    do {
        player.x = rand() % (WIDTH - 2) + 1;
        player.y = rand() % (HEIGHT - 2) + 1;
    }
    while (map[player.x][player.y] != '.');

    player.symbol = '@';
    
    // Spawn enemies in random locations, away from the player
    for (int i = 0; i < 10; i++) {
        do {
            enemies[i].x = rand() % (WIDTH - 2) + 1;
            enemies[i].y = rand() % (HEIGHT - 2) + 1;
        }
        while (map[enemies[i].x][enemies[i].y] != '.' ||
               abs(enemies[i].x - player.x) < 10 ||
               abs(enemies[i].y - player.y) < 10);

        enemies[i].symbol = 'e';
    }
}

void draw() {
    // Draw the map and entities
    
    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            if (i == player.x && j == player.y) {
                printf("%c", player.symbol);
            }
            else {
                int enemy_present = 0;
                for (int k = 0; k < 10; k++) {
                    if (i == enemies[k].x && j == enemies[k].y) {
                        printf("%c", enemies[k].symbol);
                        enemy_present = 1;
                        break;
                    }
                }
                if (!enemy_present) {
                    printf("%c", map[i][j]);
                }
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    generate_map();
    spawn_entities();
    draw();
    return 0;
}