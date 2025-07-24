//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_BAGS 100

int main() {
    int bags_to_check = rand() % 50 + 1;
    int bags_to_load = rand() % (MAX_BAGS - bags_to_check) + 1;
    int bags_checked = 0;
    int bags_loaded = 0;
    int count = 0;

    while (count < bags_to_check) {
        printf("Checking Bag %d...\n", count + 1);
        sleep(1);
        bags_checked++;
        count++;
    }

    printf("All bags have been checked. Moving on to loading.\n");

    count = 0;

    while (count < bags_to_load) {
        printf("Loading Bag %d...\n", count + 1);
        sleep(1);
        bags_loaded++;
        count++;
    }

    printf("All bags have been loaded onto the plane.\n");

    printf("Total bags checked: %d\n", bags_checked);
    printf("Total bags loaded: %d\n", bags_loaded);

    return 0;
}