//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number within a range
int generateRandom(int rangeMin, int rangeMax) {
    return (rand() % (rangeMax - rangeMin + 1)) + rangeMin;
}

int main() {
    // seed the random function with current time
    srand(time(NULL));

    // define the variables for game state
    int health = 100;
    int sanity = 100;
    int scareCount = 0;
    int gameWon = 0;

    printf("\nYou have entered a haunted house.");
    printf("\nYour goal is to survive and escape the horrors inside.");
    printf("\nYour health and sanity will decrease as you encounter scares.");

    // game loop
    while (health > 0 && sanity > 0 && !gameWon) {
        printf("\n\nYou are currently at room %d.", scareCount+1);

        // determine what happens in each room based on a random scare generator
        int scareGenerator = generateRandom(1,10);
        switch(scareGenerator) {
            case 1:
                printf("\nYou hear a loud scream and take 10 health damage!");
                health -= 10;
                break;
            case 2:
            case 3:
                printf("\nYou feel a chill down your spine and take 5 sanity damage.");
                sanity -= 5;
                break;
            case 4:
            case 5:
            case 6:
                printf("\nYou stumble upon a ghostly apparition and take 5 health and sanity damage.");
                health -= 5;
                sanity -= 5;
                break;
            case 7:
            case 8:
                printf("\nYou see a shadowy figure dart across the room and take 10 sanity damage.");
                sanity -= 10;
                break;
            case 9:
                printf("\nYou find a key and use it to unlock a secret passageway!");
                scareCount++;
                break;
            case 10:
                printf("\nYou encounter a wandering spirit who offers to heal you.");
                health = 100;
                sanity = 100;
                break;
        }

        // check if game is won
        if (scareCount >= 5) {
            printf("\nCongratulations! You have found your way out of the haunted house.");
            gameWon = 1;
        }

        // display remaining health and sanity
        printf("\n\nYour current health is %d and your current sanity is %d.", health, sanity);
    }

    // check if game is lost
    if (health <= 0 || sanity <= 0) {
        printf("\n\nYou have lost the game. Better luck next time.");
    }

    return 0;
}