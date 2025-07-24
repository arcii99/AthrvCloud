//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    // Seed the random generator with time
    srand(time(NULL));
    
    // Declare and initialize variables for number of alien sightings and total sightings
    int numAlienSightings = 0;
    int totalSightings = 0;
    
    // Declare and initialize variable for probability of alien invasion
    double probOfInvasion = 0.0;
    
    // Welcome user to the alien invasion probability calculator
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    
    // Prompt user to enter number of sightings and read input
    printf("How many sightings have there been in the past month?\n");
    scanf("%d", &totalSightings);
    
    // Generate a random number for the number of alien sightings
    numAlienSightings = rand() % totalSightings;
    
    // Calculate probability of alien invasion as the percentage of alien sightings out of total sightings
    probOfInvasion = ((double)numAlienSightings / (double)totalSightings) * 100;
    
    // Display the calculated probability of alien invasion to the user
    printf("Based on the %d sightings reported, there is a %.2f%% chance of an alien invasion!\n", totalSightings, probOfInvasion);
    
    // Excitedly thank the user for using the program and wish them luck in defending themselves against the aliens!
    printf("Thank you for using the Alien Invasion Probability Calculator! Good luck defending against the extraterrestrial threat!\n");
    
    // Return 0 to indicate successful program completion
    return 0;
}