//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: systematic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 40

// Function to generate random number between a and b
int randNum(int a, int b){
    return rand() % (b - a + 1) + a;
}

// Function to randomly fill the map with walls and rooms
void fillMap(int map[ROWS][COLS]){
    // Fill map with walls
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            map[i][j] = '#';
        }
    }
    
    // Add rooms at random locations
    for(int i = 0; i < 5; i++){
        int roomWidth = randNum(3, 10);
        int roomHeight = randNum(3, 8);
        int roomX = randNum(1, COLS - roomWidth - 1);
        int roomY = randNum(1, ROWS - roomHeight - 1);
        
        for(int j = roomY; j < roomY + roomHeight; j++){
            for(int k = roomX; k < roomX + roomWidth; k++){
                map[j][k] = '.';
            }
        }
    }
}

// Function to print the map
void printMap(int map[ROWS][COLS]){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main(){
    srand(time(NULL)); // Seed the random number generator
    
    int map[ROWS][COLS];
    fillMap(map);
    
    printMap(map);

    return 0;
}