//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAP_HEIGHT 50
#define MAP_WIDTH 50

int map[MAP_HEIGHT][MAP_WIDTH] = {0};

void print_map(){
    for(int i = 0; i < MAP_HEIGHT; i++){
        for(int j = 0; j < MAP_WIDTH; j++){
            if(map[i][j] == 0) printf(".");
            else printf("#");
        }
        printf("\n");
    }
}

void generate_map(int height, int width, int density){
    // Seed random number generator
    srand(time(NULL));
    
    // Fill map with random values based on density
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int rnd = rand() % 100;
            if(rnd < density) map[i][j] = 1;
        }
    }
    print_map();
}

int main(){
    generate_map(MAP_HEIGHT, MAP_WIDTH, 45);
    return 0;
}