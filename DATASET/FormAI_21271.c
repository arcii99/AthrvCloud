//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

char map[HEIGHT][WIDTH];
int playerX, playerY;

void generateMap(){
    srand(time(NULL));
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if(rand() % 2 == 0){
                map[i][j] = '.';
            }
            else{
                map[i][j] = '#';
            }
        }
    }
}

void printMap(){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void initPlayer(){
    playerX = WIDTH/2;
    playerY = HEIGHT/2;
    map[playerY][playerX] = '@';
}

void movePlayer(int moveX, int moveY){
    if(playerX + moveX < WIDTH && playerX + moveX >= 0 &&
        playerY + moveY < HEIGHT && playerY + moveY >= 0 &&
        map[playerY + moveY][playerX + moveX] != '#'){
        map[playerY][playerX] = '.';
        playerX += moveX;
        playerY += moveY;
        map[playerY][playerX] = '@';
    }
}

int main(){
    generateMap();
    printMap();
    initPlayer();

    char input;
    while(1){
        system("clear");
        printMap();
        printf("Control the player with w,a,s,d\n");
        scanf(" %c", &input);
        if(input == 'w'){
            movePlayer(0, -1);
        }
        else if(input == 'a'){
            movePlayer(-1, 0);
        }
        else if(input == 's'){
            movePlayer(0, 1);
        }
        else if(input == 'd'){
            movePlayer(1, 0);
        }
    }
    return 0;
}