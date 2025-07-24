//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGS 10  // maximum number of bags on a flight

// function prototypes
void printHeader();
void generateBaggage(int baggage[]);
void simulateBaggageHandling(int baggage[]);

// main function
int main() {
    int baggage[MAX_BAGS];
    generateBaggage(baggage);
    printHeader();
    simulateBaggageHandling(baggage);
    return 0;
}

// function to print the header
void printHeader() {
    printf("**************************************\n");
    printf("*** WELCOME TO OUR BAGGAGE HANDLING SIMULATION ***\n");
    printf("**************************************\n\n");
}

// function to generate random baggage
void generateBaggage(int baggage[]) {
    srand(time(NULL));
    printf("GENERATING BAGGAGE...\n");
    for (int i = 0; i < MAX_BAGS; i++) {
        int weight = rand() % 30 + 10; // weight between 10 to 40 pounds
        baggage[i] = weight;
    }
    printf("BAGGAGE GENERATED SUCCESSFULLY!\n\n");
}

// function to simulate baggage handling
void simulateBaggageHandling(int baggage[]) {
    bool isLoaded[MAX_BAGS] = {false}; // keep track of which bags are loaded on plane
    int totalWeight = 0; // keep track of total weight loaded on plane

    // initially, no bags are loaded on the plane
    printf("STARTING BAGGAGE HANDLING SIMULATION...\n\n");
    printf("LOADING BAGGAGE ONTO PLANE...\n");
    for (int i = 0; i < MAX_BAGS; i++) {
        if (!isLoaded[i]) {
            if (totalWeight + baggage[i] <= 200) { // if the weight limit is not exceeded
                isLoaded[i] = true;
                totalWeight += baggage[i];
                printf("BAG %d (WEIGHT %d POUNDS) HAS BEEN LOADED ONTO THE PLANE!\n", i + 1, baggage[i]);
            }
        }
    }
    printf("ALL BAGGAGE HAS BEEN LOADED ONTO THE PLANE SUCCESSFULLY!\n\n");

    // simulate unloading
    printf("ARRIVING AT DESTINATION AIRPORT...\n");
    printf("UNLOADING BAGGAGE FROM PLANE...\n");
    for (int i = 0; i < MAX_BAGS; i++) {
        if (isLoaded[i]) {
            isLoaded[i] = false;
            totalWeight -= baggage[i];
            printf("BAG %d (WEIGHT %d POUNDS) HAS BEEN UNLOADED FROM THE PLANE!\n", i + 1, baggage[i]);
        }
    }
    printf("ALL BAGGAGE HAS BEEN UNLOADED FROM THE PLANE SUCCESSFULLY!\n");

    // check if any bags were left behind
    bool isMissing = false;
    for (int i = 0; i < MAX_BAGS; i++) {
        if (isLoaded[i]) {
            isMissing = true;
            break;
        }
    }
    if (isMissing) {
        printf("\nOH NO! SOME BAGGAGE HAS BEEN LEFT BEHIND ON THE PLANE!\n");
        printf("PLEASE CONTACT THE AIRLINE STAFF TO RETRIEVE YOUR BAGGAGE.\n");
    } else {
        printf("\nALL BAGGAGE HAS BEEN SUCCESSFULLY UNLOADED FROM THE PLANE. THANK YOU FOR FLYING WITH US!\n");
    }
}