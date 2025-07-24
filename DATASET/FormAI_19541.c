//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 25

char dungeon[WIDTH][HEIGHT];

void initDungeon(){
    for (int x = 0; x < WIDTH; x++){
        for (int y = 0; y < HEIGHT; y++){
            dungeon[x][y] = ' ';
        }
    }
}

void randomizeDungeon(){
    srand(time(NULL));

    for (int x = 0; x < WIDTH; x++){
        for (int y = 0; y < HEIGHT; y++){
            if (rand() % 100 < 50){
                dungeon[x][y] = '#';
            } else {
                dungeon[x][y] = '.';
            }
        }
    }
}

void printDungeon(){
    for (int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            printf("%c", dungeon[x][y]);
        }
        printf("\n");
    }
}

int main(){
    initDungeon();
    randomizeDungeon();
    printDungeon();

    return 0;
}