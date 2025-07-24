//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random generator
    int num_bags = rand() % 50 + 1; // generate random number of bags
    char* bag_type;

    for (int i = 0; i < num_bags; i++) {
        int bag_weight = rand() % 100 + 1; // generate random weight of bag
        if (bag_weight < 20) {
            bag_type = "Light";
        } else if (bag_weight < 50) {
            bag_type = "Medium";
        } else {
            bag_type = "Heavy";
        }
        printf("Bag #%d: %s\n", i+1, bag_type);
    }

    printf("All bags have been loaded onto the plane.\n");
    return 0;
}