//FormAI DATASET v1.0 Category: Temperature monitor ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    // Retro Style Temperature Monitor
    printf("\n===========================================");
    printf("\n  WELCOME TO RETRO STYLE TEMPERATURE MONITOR");
    printf("\n===========================================\n");
    printf("\n");

    srand(time(0)); // Seed for Random Number Generation

    // Temperature Variables
    int currTemp = 0;
    int minTemp = 100;
    int maxTemp = 0;
    int avgTemp = 0;
    int tempCount = 0;

    // Temperature History Array (last 10 readings)
    int tempHistory[10];
    int i;

    // Start Temperature Monitoring
    while(1){
        // Get Current Temperature (Random)
        currTemp = rand() % 50;

        // Update Temperature Variables
        if(currTemp < minTemp){
            minTemp = currTemp;
        }
        if(currTemp > maxTemp){
            maxTemp = currTemp;
        }
        avgTemp = ((avgTemp * tempCount) + currTemp) / (tempCount + 1);
        tempCount++;

        // Add Current Temperature to History Array
        for(i=0; i<9; i++){
            tempHistory[i] = tempHistory[i+1];
        }
        tempHistory[9] = currTemp;

        // Display Current Temperature and Statistics
        printf("Current Temperature: %d\n", currTemp);
        printf("Minimum Temperature: %d\n", minTemp);
        printf("Maximum Temperature: %d\n", maxTemp);
        printf("Average Temperature: %d\n", avgTemp);

        // Display Temperature History
        printf("Temperature History: ");
        for(i=0; i<10; i++){
            printf("%d ", tempHistory[i]);
        }
        printf("\n");

        // Sleep for 1 Second
        sleep(1);
    }

    return 0;
}