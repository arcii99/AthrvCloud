//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h> 

// Defining constants
#define ALIEN_ODDS 3 // Probability of aliens attacking, i.e. 1 out of 3
#define NUM_DAYS 365 // Number of days in a year
#define NUM_YEARS 10 // Number of years to simulate

// Function to simulate a single day
bool simulateDay() {
    int r = rand() % ALIEN_ODDS;
    return (r == 0);
}

int main() {
    int numAttacks = 0; // Number of times aliens attack in the simulation
    srand(42); // Seed random generator with fixed value for deterministic simulation

    // Simulating for multiple years
    for(int y=0; y<NUM_YEARS; y++) {
        numAttacks = 0;
        
        // Simulating for each day of the year
        for(int d=0; d<NUM_DAYS; d++) {
            bool attacked = simulateDay();
            if(attacked) {
                numAttacks++;
            }
        }
        
        // Printing results for each year
        printf("Year %d: %d attacks\n", y+1, numAttacks);
    }
    
    return 0;
}