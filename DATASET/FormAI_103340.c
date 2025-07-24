//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

int map[WIDTH][HEIGHT];

void init_map() {
    for(int i=0; i<WIDTH; i++) {
        for(int j=0; j<HEIGHT; j++) {
            map[i][j] = 1;
        }
    }
}

void print_map() {
    for(int j=0; j<HEIGHT; j++) {
        for(int i=0; i<WIDTH; i++) {
            if(map[i][j] == 1) {
                printf("#");
            }
            else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void generate_dungeon() {
    srand(time(NULL));
    int iterations = 1000;
    for (int i=0; i<iterations; i++) {
        int x = rand() % (WIDTH - 2) + 1;
        int y = rand() % (HEIGHT - 2) + 1;
        int direction = rand() % 4;
        switch(direction) {
            case 0:
                if (map[x+1][y] == 1) {
                    map[x+1][y] = 0;
                    map[x+2][y] = 0;
                }
                break;
            case 1:
                if (map[x-1][y] == 1) {
                    map[x-1][y] = 0;
                    map[x-2][y] = 0;
                }
                break;
            case 2:
                if (map[x][y+1] == 1) {
                    map[x][y+1] = 0;
                    map[x][y+2] = 0;
                }
                break;
            case 3:
                if (map[x][y-1] == 1) {
                    map[x][y-1] = 0;
                    map[x][y-2] = 0;
                }
                break;
        }
    }
}

int main() {
    init_map();
    generate_dungeon();
    print_map();
    return 0;
}