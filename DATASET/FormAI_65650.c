//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int timeOfDay = 0; // 0 = midnight, 1 = morning, 2 = afternoon, 3 = evening

    srand(time(NULL)); // initialize random number generator

    printf("Welcome to the Traffic Flow Simulation!\n\n");

    // randomly generate initial values for traffic variables
    int numCarsNorth = rand() % 10 + 1;
    int numCarsSouth = rand() % 10 + 1;
    int numCarsEast = rand() % 10 + 1;
    int numCarsWest = rand() % 10 + 1;
    int greenLight = 0; // 0 = N/S, 1 = E/W

    // run simulation for 24 hours (1440 minutes)
    for (int i = 0; i < 1440; i++) {
        // update time of day every hour (60 minutes)
        if (i % 60 == 0) {
            timeOfDay++;
            printf("--- %s ---\n\n", timeOfDay == 1 ? "Morning" : timeOfDay == 2 ? "Afternoon" : "Evening");
        }

        // print current traffic stats
        printf("Northbound: %d cars\n", numCarsNorth);
        printf("Southbound: %d cars\n", numCarsSouth);
        printf("Eastbound: %d cars\n", numCarsEast);
        printf("Westbound: %d cars\n\n", numCarsWest);

        // switch traffic lights every 5 minutes
        if (i % 5 == 0) {
            greenLight = !greenLight;
            printf("--- %s light is green! ---\n\n", greenLight == 0 ? "North/South" : "East/West");
        }

        // update traffic variables based on cars arriving and leaving
        switch (greenLight) {
            case 0: // N/S light is green
                numCarsNorth += rand() % 5 + 1;
                numCarsSouth += rand() % 5 + 1;
                numCarsEast -= rand() % 3 + 1;
                numCarsWest -= rand() % 3 + 1;
                break;
            case 1: // E/W light is green
                numCarsEast += rand() % 5 + 1;
                numCarsWest += rand() % 5 + 1;
                numCarsNorth -= rand() % 3 + 1;
                numCarsSouth -= rand() % 3 + 1;
                break;
        }

        // ensure traffic variables do not go below 0
        if (numCarsNorth < 0) numCarsNorth = 0;
        if (numCarsSouth < 0) numCarsSouth = 0;
        if (numCarsEast < 0) numCarsEast = 0;
        if (numCarsWest < 0) numCarsWest = 0;

        // simulate cars leaving the intersection every minute
        numCarsNorth -= rand() % 2;
        numCarsSouth -= rand() % 2;
        numCarsEast -= rand() % 2;
        numCarsWest -= rand() % 2;
    }

    printf("Thank you for participating in the Traffic Flow Simulation!\n");

    return 0;
}