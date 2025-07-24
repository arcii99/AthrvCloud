//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE_WEIGHT 30 // Maximum baggage weight allowed
#define MAX_BAGGAGE_VOLUME 5 // Maximum baggage volume allowed
#define MAX_BAGGAGE_COUNT 100 // Maximum number of bags in a flight
#define MAX_FLIGHT_COUNT 10 // Maximum number of flights to handle

// Structure for baggage
typedef struct {
    int id; // Baggage ID
    float weight; // Baggage weight in kgs
    float volume; // Baggage volume in cubic feet
} baggage;

// Function to generate a baggage with random weights and volume
baggage generateBaggage(int id) {
    baggage bag;
    bag.id = id;
    bag.weight = ((float) rand() / (float) (RAND_MAX)) * MAX_BAGGAGE_WEIGHT;
    bag.volume = ((float) rand() / (float) (RAND_MAX)) * MAX_BAGGAGE_VOLUME;
    return bag;
}

int main() {
    srand(time(NULL)); // Seed for random number generator
    
    // Initializing flight and baggage arrays
    int flightBaggageCount[MAX_FLIGHT_COUNT];
    baggage flightBaggage[MAX_FLIGHT_COUNT][MAX_BAGGAGE_COUNT];
    
    // Selecting the number of flights randomly
    int numOfFlights = rand() % MAX_FLIGHT_COUNT + 1;
    printf("Number of flights : %d\n", numOfFlights);
    
    // Generating baggage for each flight and storing in arrays
    for (int i = 0; i < numOfFlights; i++) {
        printf("\nFlight %d:\n", i+1);
        int numOfBags = rand() % MAX_BAGGAGE_COUNT + 1;
        printf("Number of baggage : %d\n", numOfBags);
        flightBaggageCount[i] = numOfBags;

        // Generating baggage for the flight
        for (int j = 0; j < numOfBags; j++) {
            flightBaggage[i][j] = generateBaggage(j+1);
        }
    }

    // Simulating the baggage handling process for each flight
    for (int i = 0; i < numOfFlights; i++) {
        printf("\nSimulating baggage handling for Flight %d:\n", i+1);
        float totalWeight = 0;
        float totalVolume = 0;
        
        // Check the weight and volume of individual bags
        for (int j = 0; j < flightBaggageCount[i]; j++) {
            baggage bag = flightBaggage[i][j];
            printf("Weight of Bag %d : %0.2f kgs\n", bag.id, bag.weight);
            printf("Volume of Bag %d : %0.2f cubic feet\n", bag.id, bag.volume);
            totalWeight += bag.weight;
            totalVolume += bag.volume;
        }
        
        // Check if the weight and volume exceeds the maximum limit
        if (totalWeight > MAX_BAGGAGE_WEIGHT * flightBaggageCount[i]) {
            printf("Baggage weight exceeds the maximum limit for Flight %d!\n", i+1);
            continue;
        }
        if (totalVolume > MAX_BAGGAGE_VOLUME * flightBaggageCount[i]) {
            printf("Baggage volume exceeds the maximum limit for Flight %d!\n", i+1);
            continue;
        }
        
        // If baggage passes the check, print success message
        printf("All baggage cleared for Flight %d!\n", i+1);
    }

    return 0;
}