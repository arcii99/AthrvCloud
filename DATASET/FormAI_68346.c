//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 50
#define NUM_TERMINALS 10 

typedef struct Baggage {
    int bagID;
    int terminalID;
    time_t arrivalTime;
}Baggage;

void checkBaggage(Baggage* bag) {
    printf("Checking baggage %d at Terminal %d\n", bag->bagID, bag->terminalID);
}

int main(){
    srand(time(NULL)); // set random seed

    Baggage bags[NUM_BAGS];
    for(int i=0; i<NUM_BAGS; i++){
        bags[i].bagID = i+1;
        bags[i].terminalID = rand() % NUM_TERMINALS + 1;
        bags[i].arrivalTime = time(NULL) - (rand() % 3600) * 24;
    }

    printf("Welcome to the airport baggage handling simulation program!\n");
    printf("We will simulate handling bags for %d terminals and %d bags.\n", NUM_TERMINALS, NUM_BAGS);

    for(int i=0; i<NUM_BAGS; i++){
        printf("Bag %d arrived at Terminal %d at %s", bags[i].bagID, bags[i].terminalID, ctime(&bags[i].arrivalTime));
        checkBaggage(&bags[i]);
    }

    printf("All baggage has been checked. Have a pleasant flight!\n");

    return 0;
}