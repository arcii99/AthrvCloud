//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num_planes = rand() % 10 + 1; // generate a random number of planes between 1 and 10
    printf("Welcome to our Baggage Handling Simulation program!\n");
    printf("Today, we have %d planes arriving at our airport.\n", num_planes);
    printf("Let's get started!\n");

    int total_bags_checked = 0;
    int total_bags_loaded = 0;
    int current_plane = 0;
    int num_bags;

    while (current_plane < num_planes) {
        printf("Plane %d is now arriving at the gate.\n", current_plane+1);
        num_bags = rand() % 100 + 1; // generate a random number of bags for the current plane between 1 and 100
        printf("This plane has %d bags.\n", num_bags);

        // simulate baggage check
        int bags_checked = 0;
        for (int i = 0; i < num_bags; i++) {
            int check = rand() % 2; // simulate whether the bag passes or fails security check
            if (check == 0) {
                printf("Bag %d failed security check.\n", i+1);
            } else {
                printf("Bag %d passed security check.\n", i+1);
                bags_checked++;
            }
        }
        printf("%d out of %d bags passed security check.\n", bags_checked, num_bags);
        total_bags_checked += num_bags;
        printf("Total bags checked: %d\n", total_bags_checked);

        // simulate baggage loading
        int bags_loaded = 0;
        for (int i = 0; i < bags_checked; i++) {
            int load = rand() % 2; // simulate whether the bag is loaded onto the plane or not
            if (load == 0) {
                printf("Bag %d did not make it onto the plane.\n", i+1);
            } else {
                printf("Bag %d was loaded onto the plane.\n", i+1);
                bags_loaded++;
            }
        }
        printf("%d out of %d bags were loaded onto the plane.\n", bags_loaded, bags_checked);
        total_bags_loaded += bags_loaded;
        printf("Total bags loaded: %d\n", total_bags_loaded);

        current_plane++;
        printf("Plane %d has departed from the gate.\n", current_plane);
    }
    printf("All planes have departed. Thank you for using our Baggage Handling Simulation program!\n");
    return 0;
}