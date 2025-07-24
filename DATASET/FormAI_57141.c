//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define global constant values
#define MAX_BAGGAGE_WEIGHT 50
#define MAX_BAGGAGE_VOLUME 100
#define MAX_BAGGAGE_NUM 10
#define MAX_CHECKED_BAGGAGE_NUM 5
#define MAX_UNCHECKED_BAGGAGE_NUM 5

// Struct to represent baggage
typedef struct {
    int weight;
    int volume;
    bool is_checked;
} Baggage;

// Function to create a new baggage randomly
Baggage create_random_baggage() {
    Baggage baggage;
    baggage.weight = rand() % MAX_BAGGAGE_WEIGHT + 1;
    baggage.volume = rand() % MAX_BAGGAGE_VOLUME + 1;
    baggage.is_checked = (rand() % 2 == 0) ? true : false;
    return baggage;
}

int main() {
    srand(time(0)); // Seed for random number generator

    // Initialize variables
    int unchecked_baggage_num = 0;
    int checked_baggage_num = 0;
    Baggage unchecked_baggage[MAX_UNCHECKED_BAGGAGE_NUM];
    Baggage checked_baggage[MAX_CHECKED_BAGGAGE_NUM];

    // Generate new baggage and process them
    for (int i = 0; i < MAX_BAGGAGE_NUM; i++) {
        Baggage baggage = create_random_baggage();

        // If baggage is checked, add it to checked baggage array
        if (baggage.is_checked && checked_baggage_num < MAX_CHECKED_BAGGAGE_NUM) {
            checked_baggage[checked_baggage_num] = baggage;
            checked_baggage_num++;
            printf("A checked baggage with weight %d and volume %d has been added.\n", baggage.weight, baggage.volume);
        }
        // If baggage is not checked, add it to unchecked baggage array
        else if (unchecked_baggage_num < MAX_UNCHECKED_BAGGAGE_NUM) {
            unchecked_baggage[unchecked_baggage_num] = baggage;
            unchecked_baggage_num++;
            printf("An unchecked baggage with weight %d and volume %d has been added.\n", baggage.weight, baggage.volume);
        }
        else {
            printf("A baggage with weight %d and volume %d cannot be added as all slots are full.\n", baggage.weight, baggage.volume);
        }

        printf("Currently, there are %d unchecked baggage and %d checked baggage in the airport.\n", unchecked_baggage_num, checked_baggage_num);
        printf("\n");
    }

    printf("All baggage have been processed.\n");

    return 0;
}