//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: enthusiastic
// Welcome to the Ultimate Space Adventure game!
// In this game, you are the captain of a spaceship on a mission to explore unknown galaxies
// Your objective is to navigate through the galaxies, avoid obstacles, and collect treasures
// Are you ready to embark on this exciting adventure? Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_GALAXIES 10
#define MAX_TREASURES 5
#define MAX_OBSTACLES 3

// Define struct for galaxy map
typedef struct {
    char name[20];
    int treasures[MAX_TREASURES];
    int obstacles[MAX_OBSTACLES];
} Galaxy;

// Function to generate random integers within a range
int generateRandomInRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to display game instructions
void displayInstructions() {
    printf("Welcome to the Ultimate Space Adventure game!\n");
    printf("In this game, you are the captain of a spaceship on a mission to explore unknown galaxies\n");
    printf("Your objective is to navigate through the galaxies, avoid obstacles, and collect treasures\n");
    printf("You will start with 3 lives and will lose a life every time you hit an obstacle\n");
    printf("Collect all treasures in a galaxy to earn bonus points\n");
    printf("You can navigate using the arrow keys (up, down, left, right)\n");
    printf("Press 'q' to quit the game at any time\n\n");
}

// Function to initialize galaxy maps
void initializeGalaxyMaps(Galaxy* galaxies, int numGalaxies) {
    for (int i = 0; i < numGalaxies; i++) {
        sprintf(galaxies[i].name, "Galaxy %d", i+1);
        for (int j = 0; j < MAX_TREASURES; j++) {
            galaxies[i].treasures[j] = generateRandomInRange(1, 10);
        }
        for (int j = 0; j < MAX_OBSTACLES; j++) {
            galaxies[i].obstacles[j] = generateRandomInRange(1, 10);
        }
    }
}

// Function to display galaxy map
void displayGalaxyMap(Galaxy galaxy) {
    printf("------------------------------\n");
    printf("|     %s    |\n", galaxy.name);
    printf("------------------------------\n");
    printf("| Treasures : ");
    for (int i = 0; i < MAX_TREASURES; i++) {
        printf("%d ", galaxy.treasures[i]);
    }
    printf(" |\n");
    printf("| Obstacles : ");
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        printf("%d ", galaxy.obstacles[i]);
    }
    printf(" |\n");
    printf("------------------------------\n");
}

// Function to move character based on user input
void moveCharacter(int* positionX, int* positionY, char input) {
    switch(input) {
        case 'w': // up
            (*positionX)--;
            break;
        case 's': // down
            (*positionX)++;
            break;
        case 'a': // left
            (*positionY)--;
            break;
        case 'd': // right
            (*positionY)++;
            break;
    }
}

// Function to check if character has collided with an obstacle
int checkCollision(Galaxy galaxy, int positionX, int positionY) {
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        if (galaxy.obstacles[i] == (positionX * 10 + positionY)) {
            return 1;
        }
    }
    return 0;
}

// Function to check if character has collected all treasures
int checkTreasureCollection(Galaxy galaxy, int* treasuresCollected) {
    for (int i = 0; i < MAX_TREASURES; i++) {
        if (galaxy.treasures[i] == -1) {
            continue;
        }
        if (galaxy.treasures[i] == (*treasuresCollected) + 1) {
            (*treasuresCollected)++;
            printf("You have collected Treasure %d!\n", galaxy.treasures[i]);
            galaxy.treasures[i] = -1;
            if (*treasuresCollected == MAX_TREASURES) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Display game instructions
    displayInstructions();
    
    // Initialize galaxy maps
    Galaxy galaxies[MAX_GALAXIES];
    initializeGalaxyMaps(galaxies, MAX_GALAXIES);
    
    // Set starting position of character
    int positionX = 0;
    int positionY = 0;
    
    // Set initial score and lives for player
    int score = 0;
    int lives = 3;
    
    int currentGalaxy = 0;
    int treasuresCollected = 0;
    
    // Loop through galaxies
    while (currentGalaxy < MAX_GALAXIES) {
        printf("------------------------------\n");
        printf("|       CURRENT STATUS       |\n");
        printf("------------------------------\n");
        printf("| Lives     : %d\n", lives);
        printf("| Score     : %d\n", score);
        printf("| Treasures : %d/%d\n", treasuresCollected, MAX_TREASURES);
        printf("------------------------------\n\n");
        displayGalaxyMap(galaxies[currentGalaxy]);
        
        // Loop through character movements
        while(1) {
            // Get user input for movement
            char input;
            printf("Move using arrow keys (up, down, left, right) : ");
            scanf(" %c", &input);
            if (input == 'q') {
                printf("Goodbye!\n");
                return 0;
            }
            
            // Move character based on user input
            int tempPositionX = positionX;
            int tempPositionY = positionY;
            moveCharacter(&tempPositionX, &tempPositionY, input);
            
            // Check if character has collided with obstacle
            if (checkCollision(galaxies[currentGalaxy], tempPositionX, tempPositionY)) {
                printf("You hit an obstacle! You lost a life.\n\n");
                lives--;
                if (lives == 0) {
                    printf("Game Over! You ran out of lives.\n");
                    printf("Final score : %d\n", score);
                    return 0;
                }
                break;
            }
            
            // Check if character has collected treasure
            if (checkTreasureCollection(galaxies[currentGalaxy], &treasuresCollected)) {
                printf("You collected all treasures! You earned bonus points.\n\n");
                score += 1000;
                break;
            }
            
            // Update character position
            positionX = tempPositionX;
            positionY = tempPositionY;
            
            // Add score for each movement
            score += 10;
        }
        
        // Move to next galaxy
        currentGalaxy++;
        treasuresCollected = 0;
        positionX = 0;
        positionY = 0;
        printf("You completed %s!\n\n", galaxies[currentGalaxy-1].name);
    }
    
    // Display final score
    printf("Congratulations! You completed the game!\n");
    printf("Final score : %d\n", score);
    
    return 0;
}