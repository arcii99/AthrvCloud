//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen() {
    system("clear||cls");
}

int main() {
    // Initialize seed for random number generator
    srand(time(0));
    
    // Display welcome message
    clearScreen();
    printf("Welcome to the Procedural Space Adventure game!\n\n");
    printf("You are about to embark on a journey through an uncharted region of space.\n");
    printf("Your mission is to explore as much of this area as possible and gather data on any planets, stars, or other phenomena that you encounter.\n\n");
    printf("Good luck!\n\n");
    
    // Define variables
    int distanceTraveled = 0;
    int planetsVisited = 0;
    int starsVisited = 0;
    
    // Game loop
    while (1) {
        // Generate a random number between 1 and 10 to determine what is encountered
        int encounterType = rand() % 10 + 1;
        
        if (encounterType <= 7) {
            // Planet encounter
            int planetSize = rand() % 10 + 1;
            distanceTraveled += planetSize;
            planetsVisited++;
            
            clearScreen();
            printf("You have encountered a planet!\n\n");
            printf("This planet is %d units in size.\n", planetSize);
            printf("You have traveled a total of %d units.\n", distanceTraveled);
            printf("You have visited %d planets and %d stars.\n\n", planetsVisited, starsVisited);
        } else {
            // Star encounter
            int starSize = rand() % 5 + 1;
            distanceTraveled += starSize;
            starsVisited++;
            
            clearScreen();
            printf("You have encountered a star!\n\n");
            printf("This star is %d units in size.\n", starSize);
            printf("You have traveled a total of %d units.\n", distanceTraveled);
            printf("You have visited %d planets and %d stars.\n\n", planetsVisited, starsVisited);
        }
        
        // Check if player has traveled 50 units or more
        if (distanceTraveled >= 50) {
            clearScreen();
            printf("Congratulations! You have traveled %d units and visited %d planets and %d stars.\n", distanceTraveled, planetsVisited, starsVisited);
            printf("You have completed your mission!\n\n");
            break;
        }
        
        // Pause for dramatic effect
        printf("Press enter to continue...\n");
        getchar();
    }
    
    return 0;
}