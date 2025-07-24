//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NUM_OF_FLIGHTS 5
#define MAX_NUM_OF_PASSENGERS 1000
#define MAX_NUM_OF_BAGS 3

int main() {
    srand(time(NULL));  // Initialize random seed
    
    int numOfFlights = rand() % MAX_NUM_OF_FLIGHTS + 1;  // Random number of flights
    
    printf("Welcome to the airport baggage handling simulation!\n\n");
    printf("Today we have %d flights scheduled.\n\n", numOfFlights);
    
    for (int i = 1; i <= numOfFlights; i++) {
        int numOfPassengers = rand() % MAX_NUM_OF_PASSENGERS + 1;  // Random number of passengers for each flight
        
        printf("Flight %d is now boarding with %d passengers on board!\n", i, numOfPassengers);
        printf("Please proceed to the baggage drop area.\n\n");
        
        for (int j = 1; j <= numOfPassengers; j++) {
            int numOfBags = rand() % MAX_NUM_OF_BAGS + 1;  // Random number of bags for each passenger
            
            printf("Passenger %d has %d bags to check in.\n", j, numOfBags);
            
            for (int k = 1; k <= numOfBags; k++) {
                printf("Bag %d is being processed...\n", k);
                
                int processingTime = rand() % 6 + 5;  // Random processing time between 5-10 seconds
                
                printf("Bag %d has been processed in %d seconds and is now on its way to the plane!\n", k, processingTime);
            }
            
            printf("\n");
        }
        
        printf("All bags have been processed for Flight %d. Have a safe trip!\n\n", i);
    }
    
    printf("Thank you for using our airport baggage handling simulation. Have a great day!\n");
    
    return 0;
}