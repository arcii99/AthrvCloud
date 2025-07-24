//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BAGS_TO_HANDLE 1000
#define MAX_BAGGAGE_SIZE 100

typedef struct {
    int id;
    int size;
} Baggage;

void addBaggage(Baggage baggageList[], int *numBaggage);
void removeBaggage(Baggage baggageList[], int *numBaggage);
void printStatus(Baggage baggageList[], int numBaggage);

int main() {
    srand(time(0));
    Baggage baggageList[BAGS_TO_HANDLE];
    int numBaggage = 0;

    while (numBaggage < BAGS_TO_HANDLE) {
        printf("Current Baggage Status:\n");
        printStatus(baggageList, numBaggage);

        addBaggage(baggageList, &numBaggage);

        printf("Current Baggage Status:\n");
        printStatus(baggageList, numBaggage);

        removeBaggage(baggageList, &numBaggage);

        printf("Current Baggage Status:\n");
        printStatus(baggageList, numBaggage);
    }

    printf("All baggage has been handled. Exiting...\n");
    return 0;
}

void addBaggage(Baggage baggageList[], int *numBaggage) {
    int randomSize = rand() % MAX_BAGGAGE_SIZE + 1;
    if (*numBaggage >= BAGS_TO_HANDLE) {
        printf("No more space for additional baggage.\n");
        return;
    }
    baggageList[*numBaggage].id = *numBaggage;
    baggageList[*numBaggage].size = randomSize;
    (*numBaggage)++;
    printf("Added a baggage with id %d and size %d.\n", *numBaggage - 1, randomSize);
}

void removeBaggage(Baggage baggageList[], int *numBaggage) {
    if (*numBaggage <= 0) {
        printf("No baggage left for removal.\n");
        return;
    }
    int randomIndex = rand() % *numBaggage;
    Baggage removedBaggage = baggageList[randomIndex];
    baggageList[randomIndex] = baggageList[*numBaggage - 1];
    (*numBaggage)--;
    printf("Removed baggage with id %d and size %d.\n", removedBaggage.id, removedBaggage.size);
}

void printStatus(Baggage baggageList[], int numBaggage) {
    printf("Number of Baggage: %d\n", numBaggage);
    printf("Baggage List:\n");
    for (int i = 0; i < numBaggage; i++) {
        printf("ID: %d, Size: %d\n", baggageList[i].id, baggageList[i].size);
    }
    printf("\n");
}