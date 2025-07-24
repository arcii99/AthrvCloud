//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_X 50
#define MAX_Y 20

void drawMap(int shipX, int shipY, int starX, int starY) {
    for(int r=0; r<MAX_Y; r++) {
        for(int c=0; c<MAX_X; c++) {
            if(shipX == c && shipY == r) {
                printf(" S ");
            }
            else if(starX == c && starY == r) {
                printf(" * ");
            }
            else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int score = 0;

    int shipX = MAX_X / 2;
    int shipY = MAX_Y / 2;

    int starX = rand() % MAX_X;
    int starY = rand() % MAX_Y;

    printf("Welcome to the Space Adventure game!\n");
    printf("Your mission is to collect as many stars as possible.\n");
    printf("Each star is worth 10 points.\n");
    printf("You control the spaceship using the arrow keys.\n");
    printf("Press 'q' to quit the game.\n");

    while(1) {
        drawMap(shipX,shipY,starX,starY);
        char input = getchar();
        switch(input) {
            case 'q': //quit game
                printf("Game over. Your score is %d\n", score);
                return 0;
            case 'w': //move up
                if(shipY > 0) {
                    shipY--;
                }
                break;
            case 'a': //move left
                if(shipX > 0) {
                    shipX--;
                }
                break;
            case 's': //move down
                if(shipY < MAX_Y-1) {
                    shipY++;
                }
                break;
            case 'd': //move right
                if(shipX < MAX_X-1) {
                    shipX++;
                }
                break;
        }
        if(shipX == starX && shipY == starY) { //player collects star
            score += 10;
            starX = rand() % MAX_X;
            starY = rand() % MAX_Y;
            printf("You collected a star! Your new score is %d\n", score);
        }
    }
    return 0;
}