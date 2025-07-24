//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // setting the random seed based on current time
    int total_days = 0, invasion_days = 0; // initializing variables to track total days and invasion days
    float probability = 0.0; // initializing probability variable
    int min_days = 7, max_days = 21; // setting minimum and maximum possible invasion days
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Please enter the number of simulations you would like to run: ");
    int num_simulations;
    scanf("%d", &num_simulations); // asking user for number of simulations
    
    for(int i = 1; i <= num_simulations; i++) { // running simulations based on user input
        
        int invasion_day = (rand() % (max_days - min_days + 1)) + min_days; // generating random invasion day
        total_days += invasion_day; // adding invasion day to total days
        if(invasion_day < 14) invasion_days++; // checking if invasion occurred within 2 weeks
        
        probability = (float)invasion_days/i; // calculating probability of invasion occurrence within 2 weeks
        
        printf("Simulation %d:\n", i);
        printf("Alien invasion occurred on day %d.\n", invasion_day);
        printf("Probability of invasion occurring within 2 weeks: %.2f%%\n\n", probability*100);
    }
    
    printf("Total number of simulations run: %d\n", num_simulations);
    printf("Average invasion day: %.2f\n", (float)total_days/num_simulations);
    printf("Probability of invasion occurring within 2 weeks: %.2f%%\n", probability*100);
    
    return 0;
}