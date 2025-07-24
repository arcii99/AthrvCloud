//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 40

int foodX, foodY, score = 0;
char map[ROW][COL];

void generateFood(){
    foodX = rand()%ROW;
    foodY = rand()%COL;
    map[foodX][foodY] = '@';
}

void initializeMap(){
    int i, j;
    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            if(i == 0 || j == 0 || i == ROW-1 || j == COL-1)
                map[i][j] = '#';
            else
                map[i][j] = ' ';
        }
    }
    generateFood();
}

void printMap(){
    int i, j;
    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main(){
    initializeMap();
    int snakeX = ROW/2, snakeY = COL/2, directionX = 0, directionY = 0;
    map[snakeX][snakeY] = 'O';
    while(1){
        system("clear");
        map[snakeX][snakeY] = ' ';
        snakeX += directionX;
        snakeY += directionY;
        if(snakeX == foodX && snakeY == foodY){
            generateFood();
            score += 10;
        }
        map[snakeX][snakeY] = 'O';
        if(snakeX == 0 || snakeX == ROW-1 || snakeY == 0 || snakeY == COL-1){
            printf("Game Over! Your score is %d\n", score);
            return 0;
        }
        printMap();
        printf("Score: %d\n", score);
        char c = getchar();
        switch(c){
            case 'w': directionX = -1; directionY = 0; break;
            case 'a': directionX = 0; directionY = -1; break;
            case 's': directionX = 1; directionY = 0; break;
            case 'd': directionX = 0; directionY = 1; break;
        }
    }
    return 0;
}