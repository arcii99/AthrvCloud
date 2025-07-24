//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

void generateMap(int map[WIDTH][HEIGHT]){
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Generate random map data
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            map[x][y] = rand() % 2;
        }
    }
}

void printMap(int map[WIDTH][HEIGHT]){
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            if(map[x][y] == 1){
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main(){
    int map[WIDTH][HEIGHT];
    generateMap(map);
    printMap(map);

    return 0;
}