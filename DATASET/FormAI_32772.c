//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int health = 100; // Initialize player's health to 100
    int score = 0; // Initialize player's score to 0
    int planetCount = 0; // Initialize planet count to 0
    int visitedPlanets[10] = {0}; // Initialize visited planets array to all 0's

    printf("Welcome to the Procedural Space Adventure!\n");

    // Loop until player's health reaches 0 or all planets are visited
    while (health > 0 && planetCount < 10) {
        int planetIndex = getRandomNumber(1, 10); // Generate random planet index between 1 and 10
        
        // Check if planet has already been visited
        if (visitedPlanets[planetIndex - 1] == 1) {
            printf("You have already visited this planet!\n");
            continue; // Skip the rest of the loop and generate a new planet index
        }

        visitedPlanets[planetIndex - 1] = 1; // Mark as visited

        printf("You have arrived at Planet %d!\n", planetIndex);

        // Generate random event
        int event = getRandomNumber(1, 3); 
        
        if (event == 1) {
            int treasure = getRandomNumber(10, 100); // Generate random treasure between 10 and 100
            score += treasure; // Add treasure to player's score
            printf("You have found a treasure of %d points!\n", treasure);
        } else if (event == 2) {
            int damage = getRandomNumber(10, 30); // Generate random damage between 10 and 30
            health -= damage; // Subtract damage from player's health
            printf("You have been attacked by space pirates and suffered %d damage!\n", damage);

            if (health <= 0) {
                printf("You have lost the game! Your score is %d.\n", score);
                break; // Exit the loop and end the game
            }
        } else {
            printf("This planet has no special events.\n");
        }

        planetCount++; // Increment planet count
    }

    if (planetCount == 10) {
        printf("Congratulations! You have visited all 10 planets and won the game!\n");
    }

    printf("Your final score is %d.\n", score);

    return 0;
}