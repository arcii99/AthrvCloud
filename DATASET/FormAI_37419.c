//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

int gameMap[MAP_WIDTH][MAP_HEIGHT]; // game map

void generateMap(int map[MAP_WIDTH][MAP_HEIGHT]){
    int x,y;
    srand((unsigned int)time(NULL)); // seed random number generator
    for(x=0;x<MAP_WIDTH;x++){
        for(y=0;y<MAP_HEIGHT;y++){
            if(rand()%100<30){ // 30% chance for a wall tile
                map[x][y]=1;
            }
            else{
                map[x][y]=0;
            }
        }
    }
}

int main(){
    generateMap(gameMap); // generate the map
    int x,y;
    printf("+");
    for(x=0;x<MAP_WIDTH;x++){
        printf("-");
    }
    printf("+\n");
    for(y=0;y<MAP_HEIGHT;y++){
        printf("|");
        for(x=0;x<MAP_WIDTH;x++){
            if(gameMap[x][y]==1){
                printf("#");
            }
            else{
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("+");
    for(x=0;x<MAP_WIDTH;x++){
        printf("-");
    }
    printf("+\n");

    return 0;
}