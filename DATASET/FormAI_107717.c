//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Struct to hold baggage information
typedef struct {
    int id;
    int weight;
} Baggage;

// Function to generate random baggage
Baggage generateBaggage(int id) {
    Baggage baggage;
    baggage.id = id;
    baggage.weight = rand() % 50;
    return baggage;
}

// Function to simulate baggage arrival
void baggageArrival(Baggage *baggageArray, int size) {
    printf("Baggage arrives:\n");
    for(int i = 0; i < size; i++) {
        baggageArray[i] = generateBaggage(i+1);
        printf("Baggage %d with weight %d kg\n", baggageArray[i].id, baggageArray[i].weight);
    }
    printf("\n");
}

// Function to simulate baggage scanning
void baggageScanner(Baggage *baggageArray, int size) {
    printf("Baggage scanning:\n");
    for(int i = 0; i < size; i++) {
        printf("Baggage %d is being scanned\n", baggageArray[i].id);
    }
    printf("\n");
}

// Function to simulate baggage sorting
void baggageSorter(Baggage *baggageArray, int size) {
    printf("Baggage sorting:\n");
    for(int i = 0; i < size; i++) {
        printf("Baggage %d is being sorted\n", baggageArray[i].id);
    }
    printf("\n");
}

int main() {
    // Generate 10 random baggage
    Baggage baggageArray[10];
    baggageArrival(baggageArray, 10);

    // Simulate baggage handling process
    baggageScanner(baggageArray, 10);
    baggageSorter(baggageArray, 10);

    return 0;
}