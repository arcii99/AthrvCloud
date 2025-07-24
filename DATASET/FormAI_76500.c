//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define MAX_BAGS 1000
#define MAX_BELTS 10

// define a structure for a single piece of luggage
struct luggage {
    int id;
    int weight;
};

// define a structure for the baggage belt
struct baggage_belt {
    int belt_id;
    bool is_available;
    int current_weight;
    int luggage_count;
    struct luggage luggages[MAX_BAGS];
};

// function to generate random weight for the luggage
int generate_random_weight() {
    return rand() % 30 + 1;
}

// function to generate random number of luggage
int generate_random_luggage_count() {
    return rand() % MAX_BAGS + 1;
}

int main(void) {

    // seed the random number generator
    srand(time(NULL));

    // initialize the baggage belts
    struct baggage_belt belts[MAX_BELTS];

    for (int i = 0; i < MAX_BELTS; i++) {
        belts[i].belt_id = i;
        belts[i].is_available = true;
        belts[i].current_weight = 0;
        belts[i].luggage_count = 0;
    }

    // generate random luggage
    int luggage_count = generate_random_luggage_count();

    for (int i = 0; i < luggage_count; i++) {
        struct luggage l;
        l.id = i;
        l.weight = generate_random_weight();

        // add luggage to the belt with the lowest current weight
        int min_weight = belts[0].current_weight;
        int min_belt_index = 0;

        for (int j = 1; j < MAX_BELTS; j++) {
            if (belts[j].current_weight < min_weight && belts[j].is_available) {
                min_weight = belts[j].current_weight;
                min_belt_index = j;
            }
        }

        belts[min_belt_index].luggages[belts[min_belt_index].luggage_count] = l;
        belts[min_belt_index].current_weight += l.weight;
        belts[min_belt_index].luggage_count++;
    }

    // print the luggage on the belts
    for (int i = 0; i < MAX_BELTS; i++) {
        printf("Belt %d:\n", belts[i].belt_id);

        for (int j = 0; j < belts[i].luggage_count; j++) {
            printf("Luggage %d: %d\n", belts[i].luggages[j].id, belts[i].luggages[j].weight);
        }

        printf("Total weight: %d\n\n", belts[i].current_weight);
    }

    return 0;
}