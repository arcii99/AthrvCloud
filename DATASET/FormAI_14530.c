//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: romantic
#include <stdio.h>

int main() {

    //variables
    int numPassengers = 100;
    int numBags = 2;
    int capacity = 50;
    int baggageCounter = 0;
    
    //processing
    for(int i = 1; i <= numPassengers; i++) {
        printf("Passenger %d has %d bags. \n", i, numBags);
        for(int j = 1; j <= numBags; j++) {
            if(baggageCounter < capacity) {
                printf("Baggage %d for passenger %d has been loaded. \n", j, i);
                baggageCounter++;
            } else {
                printf("Baggage conveyor belt is full. Please wait for the next flight. \n");
                break;
            }
        }
    }
    
    //output
    printf("Total number of bags processed: %d \n", baggageCounter);
    
    return 0;
}