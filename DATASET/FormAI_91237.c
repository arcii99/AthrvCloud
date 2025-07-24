//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_FLIGHTS 5
#define MAX_BAGS 10
#define BAG_WEIGHT_MIN 20
#define BAG_WEIGHT_MAX 50
#define BAG_DESTINATIONS 3

// Define struct for flight details
typedef struct {
    char flightNo[10];
    char destination[20];
    int bagsCheckedIn;
    int totalBagWeight;
} Flight;

// Define struct for baggage details
typedef struct {
    char bagTag[10];
    int weight;
    char flightNo[10];
    char destination[20];
} Baggage;

// Declare functions
void generateFlights(Flight flights[]);
void printFlights(Flight flights[]);
void checkInBags(Flight flights[], Baggage bags[]);
void transferBags(Flight flights[], Baggage bags[]);
void printBaggage(Baggage bags[]);
void shuffle(int array[], int n);

int main() {
    // Seed random generator
    srand(time(NULL));

    // Declare arrays of flights and bags
    Flight flights[MAX_FLIGHTS];
    Baggage bags[MAX_BAGS];

    // Generate flights and print details
    generateFlights(flights);
    printf("List of flights:\n");
    printFlights(flights);

    // Check in bags for flights
    checkInBags(flights, bags);
    printf("Bags checked in:\n");
    printBaggage(bags);

    // Transfer bags between flights
    transferBags(flights, bags);
    printf("Bags transferred:\n");
    printBaggage(bags);

    return 0;
}

// Function to generate flights with flight numbers, destinations, and number of bags
void generateFlights(Flight flights[]) {
    char destinations[BAG_DESTINATIONS][20] = {"London", "New York", "Dubai"};
    char flightNumbers[MAX_FLIGHTS][10] = {"AA1234", "BA5678", "QR9101", "EK1122", "UA3344"};

    for (int i = 0; i < MAX_FLIGHTS; i++) {
        strcpy(flights[i].flightNo, flightNumbers[i]);
        strcpy(flights[i].destination, destinations[rand() % BAG_DESTINATIONS]);
        flights[i].bagsCheckedIn = rand() % MAX_BAGS + 1; // 1-10 bags per flight
        flights[i].totalBagWeight = 0;
    }
}

// Function to print flight details
void printFlights(Flight flights[]) {
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("%s to %s with %d bags\n", flights[i].flightNo, flights[i].destination, flights[i].bagsCheckedIn);
    }
}

// Function to check in bags for flights
void checkInBags(Flight flights[], Baggage bags[]) {
    int bagCount = 0;
    int weights[MAX_BAGS];

    // Generate bag tags and weights
    for (int i = 0; i < MAX_BAGS; i++) {
        sprintf(bags[i].bagTag, "BT%d", i + 1);
        bags[i].weight = rand() % (BAG_WEIGHT_MAX - BAG_WEIGHT_MIN) + BAG_WEIGHT_MIN;
        weights[i] = bags[i].weight;
    }

    // Shuffle array of weights to assign them to bags randomly
    shuffle(weights, MAX_BAGS);

    // Assign bags to flights and calculate total weight for each flight
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        for (int j = 0; j < flights[i].bagsCheckedIn; j++) {
            strcpy(bags[bagCount].flightNo, flights[i].flightNo);
            strcpy(bags[bagCount].destination, flights[i].destination);
            flights[i].totalBagWeight += weights[bagCount];
            bagCount++;
        }
    }
}

// Function to transfer bags between flights
void transferBags(Flight flights[], Baggage bags[]) {
    int transferCount = rand() % MAX_BAGS + 1; // 1-10 bags to transfer
    int transferIndices[MAX_BAGS];

    // Generate list of indices for bags to transfer
    for (int i = 0; i < transferCount; i++) {
        transferIndices[i] = rand() % MAX_BAGS;
    }
    
    // Shuffle transfer indices to transfer bags to random flights
    shuffle(transferIndices, transferCount);

    // Transfer bags and update flight details
    for (int i = 0; i < transferCount; i++) {
        Baggage* bag = &bags[transferIndices[i]];
        Flight* fromFlight = NULL;
        Flight* toFlight = NULL;

        // Find current flight of bag
        for (int j = 0; j < MAX_FLIGHTS; j++) {
            if (strcmp(flights[j].flightNo, bag->flightNo) == 0) {
                fromFlight = &flights[j];
                break;
            }
        }

        // Find new flight for bag
        for (int j = 0; j < MAX_FLIGHTS; j++) {
            if (strcmp(flights[j].destination, bag->destination) == 0 && strcmp(flights[j].flightNo, bag->flightNo) != 0) {
                toFlight = &flights[j];
                break;
            }
        }

        // Transfer bag and update flight details
        toFlight->totalBagWeight += bag->weight;
        fromFlight->totalBagWeight -= bag->weight;
        strcpy(bag->flightNo, toFlight->flightNo);
    }
}

// Function to print bag details
void printBaggage(Baggage bags[]) {
    for (int i = 0; i < MAX_BAGS; i++) {
        printf("%s weighing %dkg on flight %s to %s\n", bags[i].bagTag, bags[i].weight, bags[i].flightNo, bags[i].destination);
    }
}

// Function to shuffle an array
void shuffle(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int j = i + rand() / (RAND_MAX / (n - i) + 1);
        int temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }
}