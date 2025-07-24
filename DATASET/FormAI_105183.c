//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 60

char space[HEIGHT][WIDTH];

void createSpace(){ // Initializing space
    int i,j;
    for(i = 0; i < HEIGHT; i++){
        for(j = 0; j < WIDTH; j++){
            if(i == HEIGHT - 1){
                space[i][j] = '-';
            }
            else if(j == WIDTH/2){
                space[i][j] = '|';
            }
            else{
                space[i][j] = ' ';
            }
        }
    }
}

void inputPlayer(char playerDir, int *playerPos){ // Handle the player input
    if(playerDir == 'a' && *playerPos > 0){
        space[HEIGHT-1][*playerPos] = ' ';
        space[HEIGHT-1][--*playerPos] = '|';
    }
    else if(playerDir == 'd' && *playerPos < WIDTH-1){
        space[HEIGHT-1][*playerPos] = ' ';
        space[HEIGHT-1][++*playerPos] = '|';
    }
}

void display(){ // Display the space
    int i,j;
    for(i = 0; i < HEIGHT; i++){
        for(j = 0; j < WIDTH; j++){
            printf("%c", space[i][j]);
        }
        printf("\n");
    }
}

void createAlien(int *alienX, int *alienY){ // Create an alien randomly
    srand(time(NULL));
    *alienY = rand() % (WIDTH-2) + 1;
    *alienX = 0;
    space[*alienX][*alienY] = 'o';
}

void moveAlien(int *alienX, int *alienY){ // Move the alien linearly
    space[*alienX][*alienY] = ' ';
    if(*alienX == HEIGHT-2){
        createAlien(alienX, alienY);
        return;
    }
    space[++*alienX][*alienY] = 'o';
}

void checkCollision(int *playerPos, int alienX, int alienY){ // Check the collision between player and alien
    if(alienX == HEIGHT-1 && alienY == *playerPos){
        printf("\n\nGAME OVER\n\n");
        exit(0);
    }
}

int main(){
    createSpace();
    int playerPos = WIDTH/2, alienX, alienY;
    createAlien(&alienX, &alienY);
    char playerDir;
    printf("Use a/d to move left and right. Aim for the alien (o)!\n\n");
    while(1){
        display();
        scanf("%c", &playerDir);
        inputPlayer(playerDir, &playerPos);
        checkCollision(&playerPos, alienX, alienY);
        moveAlien(&alienX, &alienY);
    }
    return 0;
}