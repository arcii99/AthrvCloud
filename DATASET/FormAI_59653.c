//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int map[10][10] = { 
                        {1,1,0,0,0,0,0,0,0,0},
                        {1,1,0,0,0,0,0,0,0,0},
                        {1,1,1,1,0,0,0,0,0,0},
                        {1,1,1,1,1,1,0,0,0,0},
                        {0,0,0,1,1,1,1,0,0,0},
                        {0,0,0,1,1,1,1,1,1,0},
                        {0,0,0,0,0,0,1,1,1,0},
                        {0,0,0,0,0,0,0,1,1,0},
                        {0,0,0,0,0,0,0,0,1,0},
                        {0,0,0,0,0,0,0,0,1,1}
                    };
    srand(time(NULL)); // Initialize random seed for random starting position
    
    int playerX = rand()%9+1; // Random starting position of player
    int playerY = rand()%9+1;

    printf("Welcome to the GPS Navigation Simulation program. You are currently in a medieval city.\n");
    printf("Use the arrow keys to navigate the city and find landmarks.\n");

    while (1) {
        printf("\nCurrent Location: (%d,%d)\n\n",playerX,playerY);

        if(map[playerY][playerX] == 1) {
            printf("You found a landmark! It is a castle.\n");
        }

        printf("Navigate (Use arrow keys): \n");
        
        switch(getchar()) {
            case 'w':
                if(playerY == 0 || map[playerY-1][playerX] == 0) {
                    printf("Invalid move. You cannot go there.\n");
                    break;
                }
                playerY--;
                break;
            case 's':
                if(playerY == 9 || map[playerY+1][playerX] == 0) {
                    printf("Invalid move. You cannot go there.\n");
                    break;
                }
                playerY++;
                break;
            case 'a':
                if(playerX == 0 || map[playerY][playerX-1] == 0) {
                    printf("Invalid move. You cannot go there.\n");
                    break;
                }
                playerX--;
                break;
            case 'd':
                if(playerX == 9 || map[playerY][playerX+1] == 0) {
                    printf("Invalid move. You cannot go there.\n");
                    break;
                }
                playerX++;
                break;
            default:
                printf("Invalid input. Please use arrow keys.\n");
                break;
        }
    }
    return 0;
}