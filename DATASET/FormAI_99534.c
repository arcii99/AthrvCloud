//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct baggage {
    int weight;
    char destination[20];
} Baggage;

void printBaggage(Baggage bag) {
    printf("Baggage to %s weighing %d kg\n", bag.destination, bag.weight);
}

int main() {
    srand(time(NULL));
    int numBaggage = rand() % 20 + 10;
    Baggage luggage[numBaggage];

    char destinations[][20] = {"London", "Paris", "New York", "Tokyo", "Sydney", "Dubai", "Mumbai", "Rome", "Berlin", "Moscow"};
    int i;
    for (i = 0; i < numBaggage; i++) {
        int randomWeight = rand() % 30 + 5;
        strcpy(luggage[i].destination, destinations[rand() % 10]);
        luggage[i].weight = randomWeight;
    }

    printf("Welcome to the Baggage Handling Simulation!\n\n");
    printf("We have a total of %d bags to handle today.\n", numBaggage);
    printf("Here is the list of destinations and their respective bags:\n\n");

    for (i = 0; i < numBaggage; i++) {
        printBaggage(luggage[i]);
    }

    printf("\nGood news, we have a new robot assistant to help with the baggage!");

    int totalWeight = 0;
    for (i = 0; i < numBaggage; i++) {
        totalWeight += luggage[i].weight;
    }

    printf("\n\nThe total weight of the baggage is %d kg. Our robot assistant can handle a maximum of 100 kg at a time.", totalWeight);

    int numTrips = 0;
    int remainingWeight = totalWeight;
    while (remainingWeight > 0) {
        int weightCarried = rand() % 50 + 25;
        if (weightCarried > remainingWeight) {
            weightCarried = remainingWeight;
        }

        remainingWeight -= weightCarried;
        numTrips++;

        printf("\n\nRobot makes trip number %d carrying %d kg of baggage. %d kg remains.", numTrips, weightCarried, remainingWeight);
    }

    printf("\n\nAll baggage has been successfully transported to their respective flights!");
    printf("\nThank you for using our services. Goodbye!");

    return 0;
}