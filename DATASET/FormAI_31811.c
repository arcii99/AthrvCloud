//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define TOTAL_BAGS 1000
#define MAX_WEIGHT 50
#define MAX_NUM_OF_FLIGHTS 10
#define MIN_FLIGHT_NUM 100
#define MAX_FLIGHT_NUM 999

// Define struct for each baggage
typedef struct Baggage {
    int flightNum;
    int weight;
} Baggage;

// Generate a random flight number
int generateFlightNum() {
    return rand() % (MAX_FLIGHT_NUM - MIN_FLIGHT_NUM + 1) + MIN_FLIGHT_NUM;
}

// Generate a random baggage weight
int generateBaggageWeight() {
    return rand() % MAX_WEIGHT + 1;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Create an array of struct for all baggage
    Baggage baggages[TOTAL_BAGS];
    for (int i = 0; i < TOTAL_BAGS; i++) {
        baggages[i].flightNum = generateFlightNum();
        baggages[i].weight = generateBaggageWeight();
    }
    
    // Create an array of queues for each flight
    int numOfFlights = rand() % MAX_NUM_OF_FLIGHTS + 1;
    int numOfBagsInEachFlight[numOfFlights];
    int totalBagsForAllFlights = 0;
    for (int i = 0; i < numOfFlights; i++) {
        numOfBagsInEachFlight[i] = 0;
    }
    for (int i = 0; i < TOTAL_BAGS; i++) {
        int flightNum = baggages[i].flightNum;
        numOfBagsInEachFlight[flightNum - MIN_FLIGHT_NUM]++;
        totalBagsForAllFlights++;
    }
    printf("Number of flights: %d\n", numOfFlights);
    printf("Total number of bags: %d\n", TOTAL_BAGS);
    printf("Total number of bags for all flights: %d\n\n", totalBagsForAllFlights);

    // Sort the baggage array by flight number using bubble sort
    for (int i = 0; i < TOTAL_BAGS - 1; i++) {
        for (int j = 0; j < TOTAL_BAGS - i - 1; j++) {
            if (baggages[j].flightNum > baggages[j + 1].flightNum) {
                Baggage tempBaggage = baggages[j];
                baggages[j] = baggages[j + 1];
                baggages[j + 1] = tempBaggage;
            }
        }
    }
    
    // Queue up each baggage for its respective flight
    int currentFlightNum = MIN_FLIGHT_NUM;
    int currentBagIndex = 0;
    for (int i = 0; i < numOfFlights; i++) {
        printf("Flight %d has %d bags:\n", currentFlightNum, numOfBagsInEachFlight[i]);
        for (int j = 0; j < numOfBagsInEachFlight[i]; j++) {
            printf("\tBag %d: weight %d\n", j + 1, baggages[currentBagIndex].weight);
            currentBagIndex++;
        }
        printf("\n");
        currentFlightNum++;
    }
    
    return 0;
}