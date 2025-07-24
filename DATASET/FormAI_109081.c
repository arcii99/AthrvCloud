//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: calm
#include <stdlib.h> 
#include <stdio.h>  
#include <time.h> 

#define MAP_ROWS 20
#define MAP_COLS 40

char map[MAP_ROWS][MAP_COLS];

void generate_map(){
    int i, j, random_number;
    srand(time(NULL));   // Initialize random seed

    for(i = 0; i < MAP_ROWS; i++){
        for(j = 0; j < MAP_COLS; j++){
            random_number = rand() % 100;
            if(random_number < 40){
                map[i][j] = '.';   // 40% chance of a floor tile
            } else {
                map[i][j] = '#';   // 60% chance of a wall tile
            }
        }
    }

    // Add borders to map
    for(i = 0; i < MAP_ROWS; i++){   // Top and bottom borders
        map[i][0] = '#';
        map[i][MAP_COLS - 1] = '#';
    }
    for(j = 0; j < MAP_COLS; j++){   // Left and right borders
        map[0][j] = '#';
        map[MAP_ROWS - 1][j] = '#';
    }
}

void print_map(){
    int i, j;
    for(i = 0; i < MAP_ROWS; i++){
        for(j = 0; j < MAP_COLS; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main(){
    generate_map();
    print_map();
    return 0;
}