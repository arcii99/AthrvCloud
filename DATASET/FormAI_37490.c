//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 30

char dungeon[HEIGHT][WIDTH];

void generate_dungeon() {
    srand(time(NULL));
    
    // Place random walls
    for(int y=0; y<HEIGHT; y++) {
        for(int x=0; x<WIDTH; x++) {
            if(rand() % 100 < 40) {
                dungeon[y][x] = '#';
            }
        }
    }
    
    // Place starting point and exit
    int startX = rand() % WIDTH;
    int startY = rand() % HEIGHT;
    dungeon[startY][startX] = 'S';
    
    int endX, endY;
    do {
        endX = rand() % WIDTH;
        endY = rand() % HEIGHT;
    } while(dungeon[endY][endX] == '#');
    
    dungeon[endY][endX] = 'E';
}

void display_dungeon() {
    for(int y=0; y<HEIGHT; y++) {
        for(int x=0; x<WIDTH; x++) {
            printf("%c", dungeon[y][x]);
        }
        printf("\n");
    }
}

int main() {
    generate_dungeon();
    display_dungeon();
    
    return 0;
}