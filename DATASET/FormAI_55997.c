//FormAI DATASET v1.0 Category: System administration ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Function to generate random integer between min and max
int random_gen(int min, int max) {
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int main() {
    // Initializing variables
    int food_supply = 50, water_supply = 50, medicine_supply = 20;
    int raiders_encountered = 0, death_count = 0;
    srand(time(NULL)); // Initializing randomizer seed with current time

    while(1) { // Infinite loop for continuous monitoring
        // Random events
        int food_event = random_gen(1, 10);
        int water_event = random_gen(1, 10);
        int medicine_event = random_gen(1, 10);
        int raiders_event = random_gen(1, 10);

        // Updating supplies based on events
        if(food_event <= 4) {
            food_supply -= random_gen(10, 15);
        }
        if(water_event <= 4) {
            water_supply -= random_gen(10, 15);
        }
        if(medicine_event <= 2) {
            medicine_supply -= random_gen(1, 3);
        }
        if(raiders_event <= 5) {
            raiders_encountered += 1;
            // 50% chance of death of a random crew member during a raider encounter
            if(random_gen(1, 10) <= 5) {
                death_count += 1;
            }
        }

        // Displaying current stats
        printf("\n\n************ APOCALYPSE SYSTEM MONITOR **************\n\n");
        printf("Food Supply: %d\n", food_supply);
        printf("Water Supply: %d\n", water_supply);
        printf("Medicine Supply: %d\n", medicine_supply);
        printf("Encountered Raiders: %d\n", raiders_encountered);
        printf("Death Count: %d\n", death_count);

        // Checking if supplies have gone below critical level
        if (food_supply <= 0) {
            printf("Out of Food! Game Over.\n");
            break;
        }
        if (water_supply <= 0) {
            printf("Out of Water! Game Over.\n");
            break;
        }
        if (medicine_supply <= 0) {
            printf("Out of Medicines! Game Over.\n");
            break;
        }
        // Sleeping for 2 seconds before checking again
        sleep(2);
    }
    return 0;
}