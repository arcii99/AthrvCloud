//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // seed random number generator
    int x = rand() % 10;  // generate random x value between 0 and 9
    int y = rand() % 10;  // generate random y value between 0 and 9
    char space[10][10];   // 2D array representing the game board
    
    // Initialize game board with empty space
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            space[i][j] = '-';
        }
    }
    
    // Place the spaceship at random x,y location
    space[x][y] = 'S';
    printf("You are in command of a spaceship located at (%d,%d).\n", x, y);
    
    // Game loop
    while(1) {
        // Print current game board
        printf("\n");
        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                printf("%c ", space[i][j]);
            }
            printf("\n");
        }
        
        // Prompt user for direction
        char dir;
        printf("\nWhich direction do you want to move? (N/S/E/W): ");
        scanf(" %c", &dir);
        
        // Move the spaceship in the chosen direction
        if(dir == 'N' && x > 0) {
            space[x][y] = '-';
            x--;
            space[x][y] = 'S';
        } else if(dir == 'S' && x < 9) {
            space[x][y] = '-';
            x++;
            space[x][y] = 'S';
        } else if(dir == 'E' && y < 9) {
            space[x][y] = '-';
            y++;
            space[x][y] = 'S';
        } else if(dir == 'W' && y > 0) {
            space[x][y] = '-';
            y--;
            space[x][y] = 'S';
        } else {
            printf("Invalid direction. Try again.\n");
            continue;
        }
        
        // Generate random event
        int event = rand() % 10;
        
        if(event == 0) {
            // Asteroid field
            printf("\nAn asteroid field is blocking your path!\n");
            printf("You take 5 damage to your shields.\n");
        } else if(event == 1) {
            // Alien encounter
            printf("\nAn alien spacecraft appears!\n");
            printf("You engage in battle with the alien ship.\n");
            printf("After a fierce battle, you emerge victorious.\n");
        } else if(event == 2) {
            // Wormhole
            printf("\nYou encounter a wormhole!\n");
            printf("Do you want to enter it? (Y/N): ");
            char choice;
            scanf(" %c", &choice);
            if(choice == 'Y') {
                printf("You enter the wormhole and emerge in a distant part of the galaxy.\n");
                // Generate new random location and move spaceship there
                x = rand() % 10;
                y = rand() % 10;
                space[x][y] = 'S';
            } else {
                printf("You choose not to enter the wormhole.\n");
            }
        } else {
            // Nothing happens
            printf("\nYou continue on your journey without incident.\n");
        }
        
        // Check for victory condition
        if(x == 0 && y == 0) {
            printf("\nCongratulations! You have reached your destination.\n");
            printf("Thanks for playing!\n");
            break;
        }
    }
    
    return 0;
}