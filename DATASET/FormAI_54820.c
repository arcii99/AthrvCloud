//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int aliens = 0;
    int total_calculations = 0;

    srand(time(0)); // Seed the random generator with current time

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Enter the number of times you want to run the simulation: ");
    scanf("%d", &total_calculations);

    for(int i=0; i<total_calculations; i++) {
        int alien_ships = rand() % 101; // Random number between 0-100
        float probability = (float)alien_ships / 100; // Convert to probability between 0-1
        
        printf("\nCalculation #%d\n", i+1);
        printf("Number of Alien Ships: %d\n", alien_ships);
        printf("Probability of Alien Invasion: %.2f%%\n", probability*100);
        
        if(alien_ships == 0) {
            printf("No aliens detected.\n");
        } else if(alien_ships == 100) {
            printf("Alien invasion imminent!\n");
        } else {
            printf("Alien invasion possible, but not certain.\n");
        }
        
        aliens += alien_ships; // Keep a running total of alien ships
    }
    
    float average_aliens = (float)aliens / total_calculations;
    printf("\n\nSummary:\n");
    printf("Total Calculations: %d\n", total_calculations);
    printf("Average Number of Alien Ships: %.2f\n", average_aliens);
     
    return 0;
}