//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define WIDTH 50
#define HEIGHT 20
#define ROOMS 10

char dungeon[WIDTH][HEIGHT];

int randInt(int min, int max){
    return rand() % (max - min) + min;
}

void generateRooms(){
    int i;
    for(i = 0; i < ROOMS; i++){
        int x1 = randInt(1, WIDTH - 5);
        int y1 = randInt(1, HEIGHT - 5);
        int x2 = randInt(2, 5);
        int y2 = randInt(2, 5);

        int j, k;
        for(j = x1; j < x1 + x2; j++){
            for(k = y1; k < y1 + y2; k++){
                dungeon[j][k] = '.';
            }
        }
    }
}

void generateCorridors(){
    int i, j;

    for(i = 1; i < ROOMS; i++){
        int x1 = randInt(1, WIDTH - 2);
        int y1 = randInt(1, HEIGHT - 2);
        
        int x2 = randInt(1, WIDTH - 2);
        int y2 = randInt(1, HEIGHT - 2);

        while(x1 != x2 || y1 != y2){
            if(x1 != x2){
                x1 += x1 < x2 ? 1 : -1;
                dungeon[x1][y1] = '#';
            }
            else if(y1 != y2){
                y1 += y1 < y2 ? 1 : -1;
                dungeon[x1][y1] = '#';
            }
        }


    }
}

void printDungeon(){
    int i, j;
    for(j = 0; j < HEIGHT; j++){
        for(i = 0; i < WIDTH; i++){
            putchar(dungeon[i][j]);
        }
        putchar('\n');
    }
}

void generateDungeon(){
    int i, j;
    for(j = 0; j < HEIGHT; j++){
        for(i = 0; i < WIDTH; i++){
            dungeon[i][j] = '#';
        }
    }

    generateRooms();
    generateCorridors();
}

int main(){
    srand(time(NULL));
    generateDungeon();
    printDungeon();

    return 0;
}