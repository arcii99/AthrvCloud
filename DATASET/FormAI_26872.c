//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Main function
int main() {
    printf("Welcome to the Airport Baggage Handling Simulation\n");
    srand(time(NULL));
    
    // Declaring variables
    int numBaggage = rand() % 10 + 1;
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    int baggageCount = 0;
    
    // Running simulation for each baggage
    while (baggageCount != numBaggage) {
        printf("Baggage %d arrives at the airport.\n", baggageCount+1);
        
        // Checking for available counters
        if (counter1 <= counter2 && counter1 <= counter3) {
            printf("Baggage %d is assigned to counter 1.\n", baggageCount+1);
            counter1++;
        }
        else if (counter2 <= counter1 && counter2 <= counter3) {
            printf("Baggage %d is assigned to counter 2.\n", baggageCount+1);
            counter2++;
        }
        else {
            printf("Baggage %d is assigned to counter 3.\n", baggageCount+1);
            counter3++;
        }
        
        // Generating random processing time
        int processingTime = rand() % 10 + 1;
        
        // Simulating processing time
        for (int i = 0; i < processingTime; i++) {
            printf("Counter 1: %d  Counter 2: %d  Counter 3: %d\n", counter1, counter2, counter3);
        }
        
        printf("Baggage %d is processed and sent to the departure gate.\n", baggageCount+1);
        baggageCount++;
    }
    
    printf("All baggage have been processed. Have a nice flight!\n");
    
    return 0;
}