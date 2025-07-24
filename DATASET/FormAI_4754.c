//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random numbers between 0 and 20
int randomNum() {
    int r = rand() % 21;
    return r;
}

int main() {
    srand(time(NULL));   // initializing the random number generator with the current time
    int street1[20], street2[20], street3[20];      // creating arrays to represent the streets
    int i, j, k, count = 0;

    // initializing the streets with random numbers
    for(i=0; i<20; i++) {
        street1[i] = randomNum();
        street2[i] = randomNum();
        street3[i] = randomNum();
    }

    printf("Initial Traffic Flow: \nStreet 1: ");
    for(i=0; i<20; i++) printf("%d ", street1[i]);
    printf("\nStreet 2: ");
    for(i=0; i<20; i++) printf("%d ", street2[i]);
    printf("\nStreet 3: ");
    for(i=0; i<20; i++) printf("%d ", street3[i]);
    printf("\n\n");
    
    // redirecting the traffic 
    for(i=0; i<20; i++) {
        if(street1[i] >= 15) {
            street1[i] -= 15;
            street2[i] += 10;
        }
        if(street2[i] >= 15) {
            street2[i] -= 15;
            street3[i] += 10;
        }
        if(street3[i] >= 15) {
            street3[i] -= 15;
            street1[i] += 10;
        }
    }

    // printing the new traffic flow after redirection
    printf("Traffic Flow after Redirection:\nStreet 1: ");
    for(i=0; i<20; i++) printf("%d ", street1[i]);
    printf("\nStreet 2: ");
    for(i=0; i<20; i++) printf("%d ", street2[i]);
    printf("\nStreet 3: ");
    for(i=0; i<20; i++) printf("%d ", street3[i]);
    printf("\n\n");

    // counting the number of vehicles that have reached the destination
    for(i=0; i<20; i++) {
        if(street3[i] >= 15) count++;
    }

    printf("Number of Vehicles that have Reached the Destination: %d\n", count);
    return 0;   // program executed successfully!
}