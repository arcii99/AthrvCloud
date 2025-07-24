//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants 
#define ROWS 10
#define COLS 10
#define NUM_GHOSTS 5
#define MAX_MOVES 20

// Define colors
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// Define function to randomly place ghosts in the array
void placeGhosts(int ghosts[NUM_GHOSTS][2]) {
    srand(time(NULL)); // Seed the random number generator
    for(int i = 0; i < NUM_GHOSTS; i++) {
        ghosts[i][0] = rand() % ROWS;
        ghosts[i][1] = rand() % COLS;
    }
}

// Define function to display the haunted house
void display(char house[ROWS][COLS]) {
    printf("\n"); 
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            switch(house[i][j]) {
                case '#':
                    printf(WHITE "%c ", house[i][j]);
                    break;
                case 'G':
                    printf(RED "%c ", house[i][j]);
                    break;
                case '*':
                    printf(YELLOW "%c ", house[i][j]);
                    break;
                default:
                    printf("%c ", house[i][j]);
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    char house[ROWS][COLS]; // Create array to represent the haunted house
    int ghosts[NUM_GHOSTS][2]; // Create array to hold the ghosts' positions
    int x, y; // Player's current position
    int numMoves = 0; // Count the number of moves
    char move; // Store user's move
    int gameover = 0; // Boolean to check if the game is over
    int foundGhost = 0; // Boolean to check if the player found a ghost
    
    // Initialize the haunted house
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            house[i][j] = '#'; // Use '#' to represent walls
        }
    }
    
    // Place the ghosts randomly in the house
    placeGhosts(ghosts);
    for(int i = 0; i < NUM_GHOSTS; i++) {
        int x = ghosts[i][0];
        int y = ghosts[i][1];
        house[x][y] = 'G'; // Use 'G' to represent ghosts
    }
    
    // Choose a random starting position for the player
    srand(time(NULL)); // Seed the random number generator
    x = rand() % ROWS;
    y = rand() % COLS;
    house[x][y] = '*'; // Use '*' to represent the player
    
    // Start the game loop
    while(!gameover && numMoves < MAX_MOVES) {
        system("clear"); // Clear the screen
        display(house); // Display the haunted house
        
        // Get the user's move
        printf("\nUse WASD to move around. You have %d moves left.\n", MAX_MOVES - numMoves);
        scanf(" %c", &move); 
        switch(move) {
            case 'w':
                if(x > 0) {
                    x--;
                }
                break;
            case 'a':
                if(y > 0) {
                    y--;
                }
                break;
            case 's':
                if(x < ROWS - 1) {
                    x++;
                }
                break;
            case 'd':
                if(y < COLS - 1) {
                    y++;
                }
                break;
            default:
                break;
        }
        
        numMoves++; // Increment the number of moves
        
        // Check if the player found a ghost
        for(int i = 0; i < NUM_GHOSTS; i++) {
            if(x == ghosts[i][0] && y == ghosts[i][1]) {
                foundGhost = 1;
                house[x][y] = 'X'; // Use 'X' to represent a found ghost
                break;
            }
        }
        
        // Check if the player has won or lost
        if(foundGhost) {
            printf("\n" GREEN "Congratulations! You found a ghost in %d moves.\n", numMoves);
            gameover = 1;
        } else if(numMoves == MAX_MOVES) {
            printf("\n" RED "Oh no! You couldn't find a ghost in %d moves. Game over.\n", MAX_MOVES);
            gameover = 1;
        } else {
            house[x][y] = '*'; // Update the player's position in the house
        }
    }
    
    return 0;
}