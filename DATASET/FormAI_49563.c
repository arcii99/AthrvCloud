//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_flights, max_bags_per_flight;
    
    printf("Please enter the number of flights: ");
    scanf("%d", &num_flights);
    printf("Please enter the maximum number of bags per flight: ");
    scanf("%d", &max_bags_per_flight);
    
    // Simulate the baggage handling for each flight
    for (int i = 1; i <= num_flights; i++) {
        // Generate a random number of bags for the flight
        srand(time(NULL)); // Initialize the random seed
        int num_bags = rand() % max_bags_per_flight + 1; // Generate a value between 1 and max_bags_per_flight
        
        // Handle the bags for this flight
        printf("Flight %d has %d bags:\n", i, num_bags);
        for (int j = 1; j <= num_bags; j++) {
            printf("    Bag %d loaded.\n", j);
        }
        printf("All bags for flight %d loaded successfully.\n\n", i);
    }
    
    return 0;
}