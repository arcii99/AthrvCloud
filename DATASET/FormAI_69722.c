//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// function to clear the terminal screen 
void clear() {
    system("clear");
}

// function to display the game maze
void maze(int playerX, int playerY) {
    int i, j;
    for(i=0; i<20; i++) {
        for(j=0; j<20; j++) {
            if(i==0 || i==19 || j==0 || j==19) {
                printf("#");
            } else if (i==playerY && j==playerX) {
                printf("P");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int playerX = 1; // player starting X position 
    int playerY = 1; // player starting Y position 
    int treasureX = 18; // treasure X position
    int treasureY = 18; // treasure Y position
    
    srand(time(0)); // seed for random number generator
    int treasureFound = 0; // flag to track if the treasure has been found
    
    while(!treasureFound) {
        clear(); // clear the screen
        maze(playerX, playerY); // display the maze
        
        int move; // variable to store user's move
        printf("Use arrow keys to move. Press 'q' to quit.\n");
        move = getchar(); // get user's move from keyboard
        
        // handle user's move
        switch(move) {
            case 'q':
                printf("Quitting game...\n");
                return 0;
            case 'w':
                playerY--;
                break;
            case 'a':
                playerX--;
                break;
            case 's':
                playerY++;
                break;
            case 'd':
                playerX++;
                break;
            default:
                break;
        }
        
        // check if player found the treasure
        if(playerX == treasureX && playerY == treasureY) {
            treasureFound = 1;
        }
    }
    
    // player found the treasure
    clear();
    printf("Congratulations! You found the treasure!\n");
    printf("Press any key to exit.");
    getchar(); // pause so user can press any key to exit
    return 0;
}