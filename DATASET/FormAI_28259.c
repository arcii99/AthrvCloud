//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number between min and max
int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// function to create and print map
void createMap(int width, int height) {
    char gameMap[width][height];
    int i, j;
    for(i = 0; i < width; i++) {
        for(j = 0; j < height; j++) {
            int chance = generateRandom(1, 100);
            if(chance <= 40) {
                gameMap[i][j] = '#';
            } else if(chance <= 60) {
                gameMap[i][j] = '.';
            } else if(chance <= 65) {
                gameMap[i][j] = '@';
            } else {
                gameMap[i][j] = ' ';
            }
            printf("%c ", gameMap[i][j]);
        }
        printf("\n");
    }
}

// main function
int main() {
    // set seed for random number generator
    srand(time(NULL));
    
    int width = 50;
    int height = 20;
    
    createMap(width, height);
    
    return 0;
}