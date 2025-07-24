//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGGAGE 50

int castle[10][10];
int baggageCount;

// function to initialize the castle with random baggage
void initializeCastle() {
    int i, j;
    srand(time(NULL));
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            castle[i][j] = rand() % 2;
            if(castle[i][j] == 1) {
                baggageCount++;
            }
        }
    }
}

// function to print the current state of baggage in the castle
void printCastle() {
    int i, j;
    printf("Current state of Baggage in the Castle:\n");
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            if(castle[i][j] == 1) {
                printf("B ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

// function to transport baggage to the designated area
bool transportBaggage() {
    int i, j;
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            if(castle[i][j] == 1) {
                castle[i][j] = 0;
                printf("Transporting the baggage from (%d, %d) to designated area.\n", i, j);
                baggageCount--;
                return true;
            }
        }
    }
    return false;
}

int main() {
    baggageCount = 0;
    initializeCastle();
    printCastle();
    while(baggageCount > 0) {
        if(!transportBaggage()) {
            break;
        }
    }
    printf("All the baggage have been transported.\n");
    return 0;
}