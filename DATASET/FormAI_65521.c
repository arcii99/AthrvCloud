//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Starting the Baggage Handling Simulation...\n");
    int numOfBags = 50;
    int baggageCount = 0;
    int timeElapsed = 0;
    
    while (baggageCount < numOfBags) {
        timeElapsed++;
        printf("Time Elapsed: %d seconds\n", timeElapsed);
        
        // Randomly add baggage
        int randomNum = rand() % 100;
        if (randomNum < 20) {
            printf("New Baggage Added!\n");
            baggageCount++;
        }
        
        // Randomly remove baggage
        randomNum = rand() % 100;
        if (randomNum < 10) {
            printf("Baggage Removed!\n");
            baggageCount--;
        }
        
        // Check if baggage is getting delayed
        if (timeElapsed % 10 == 0 && baggageCount > 0) {
            printf("Baggage Delayed Due to Security Check...\n");
        }
        
        // Check if baggage is getting lost
        if (timeElapsed % 30 == 0 && baggageCount > 0) {
            printf("Baggage Lost!\n");
            baggageCount--;
        }
    }
    
    printf("All %d Bags Have Been Processed. Simulation Completed.", numOfBags);
    return 0;
}