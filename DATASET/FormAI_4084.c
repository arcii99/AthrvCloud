//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LUGGAGE_NUM 100
#define MAX_BELT_SIZE 10

/* Struct Definition */
struct Luggage {
    int id;
    int weight;
};

/* Function Prototypes */
void loadLuggage(struct Luggage[], int*);
void simulateBaggageHandling(struct Luggage[], int);
int getBeltIndex(bool[], int);
void displayBeltStatus(bool[], int);

/* Main Function */
int main() {
   
    struct Luggage luggage[MAX_LUGGAGE_NUM];
    int numLuggage = 0;
    
    loadLuggage(luggage, &numLuggage);
    simulateBaggageHandling(luggage, numLuggage);
    
    return 0;
}

/* Function to load randomly generated luggage */
void loadLuggage(struct Luggage luggage[], int* numLuggage) {
    srand(time(NULL));
    *numLuggage = rand() % MAX_LUGGAGE_NUM + 1;
    for (int i = 0; i < *numLuggage; i++) {
        luggage[i].id = i + 1;
        luggage[i].weight = rand() % 50 + 1;
    }
    printf("Total Luggage: %d\n", *numLuggage);
}

/* Function to simulate baggage handling */
void simulateBaggageHandling(struct Luggage luggage[], int numLuggage) {
    bool belt[MAX_BELT_SIZE] = {false};
    int currentBeltIndex = 0;
    int luggageCounter = 0;
    
    while (luggageCounter < numLuggage) {
        if (belt[currentBeltIndex] == false) {
            printf("Placing Luggage %d weighing %dkg on Belt %d.\n", 
                   luggage[luggageCounter].id, luggage[luggageCounter].weight, currentBeltIndex+1);
            belt[currentBeltIndex] = true;
            luggageCounter++;
        }
        currentBeltIndex = getBeltIndex(belt, currentBeltIndex);
        displayBeltStatus(belt, MAX_BELT_SIZE);
    }
}

/* Function to get next available belt index */
int getBeltIndex(bool belt[], int currentBeltIndex) {
    int index = currentBeltIndex;
    do {
        index = (index + 1) % MAX_BELT_SIZE;
    } while (belt[index] == true && index != currentBeltIndex);
    return index;
}

/* Function to display current belt status */
void displayBeltStatus(bool belt[], int size) {
    printf("Belt Status: ");
    for (int i = 0; i < size; i++) {
        if (belt[i] == true) {
            printf("[%d]", i+1); // Belt contains luggage
        } else {
            printf("[%c]", ' '); // Belt is empty
        }
    }
    printf("\n\n");
}