//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 30

int map[MAP_SIZE][MAP_SIZE];

void generate_map() {
    int i, j;
    srand(time(NULL));
    for(i = 0; i < MAP_SIZE; i++) {
        for(j = 0; j < MAP_SIZE; j++) {
            map[i][j] = rand() % 3;
        }
    }
}

void print_map() {
    int i, j;
    for(i = 0; i < MAP_SIZE; i++) {
        for(j = 0; j < MAP_SIZE; j++) {
            if(map[i][j] == 0) {
                printf(".");
            } else if(map[i][j] == 1) {
                printf("#");
            } else {
                printf("@");
            }
        }
        printf("\n");
    }
}

int main() {
    generate_map();
    print_map();
    return 0;
}