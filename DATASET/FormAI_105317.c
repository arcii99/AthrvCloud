//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 50 //maximum number of bags to be processed
#define MAX_BAG_WEIGHT 50 //maximum weight of a single bag
#define MAX_DELAY_TIME 10 //maximum delay time for processing a baggage

struct Baggage {
    int weight;
    char destination[20];
};

void processBaggage(struct Baggage b) {
    //simulate baggage handling process
    int delay_time = rand() % MAX_DELAY_TIME;
    printf("\nProcessing baggage to %s with weight %d kg", b.destination, b.weight);
    printf("\nDelay time: %d seconds", delay_time);
    printf("\nBaggage processed successfully!");
}

int main() {
    srand(time(NULL)); //initialize random number generator

    printf("Welcome to the airport baggage handling simulation program!\n");

    //generate MAX_BAGGAGE number of bags
    struct Baggage bags[MAX_BAGGAGE];
    for(int i=0; i<MAX_BAGGAGE; i++) {
        bags[i].weight = rand() % MAX_BAG_WEIGHT;
        printf("\nEnter destination of baggage %d: ", i+1);
        scanf("%s", bags[i].destination);
    }

    //process each bag
    for(int i=0; i<MAX_BAGGAGE; i++) {
        printf("\n\n-----------------------------------------------------------");
        if(bags[i].weight > 0) {
            processBaggage(bags[i]);
        } else {
            printf("\nBaggage %d is empty and will not be processed", i+1);
        }
        printf("\n-----------------------------------------------------------");
    }

    printf("\n\nThank you for using the airport baggage handling simulation program!\n");

    return 0;
}