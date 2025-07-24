//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS_PER_PLANE 500
#define MAX_PLANE_CAPACITY 100
#define MAX_PLANES 5

int main() {
    int total_bags = 0, bags_handled = 0;
    int planes_landed = 0, landing_interval = 0;
    int bags_loaded[MAX_PLANE_CAPACITY] = {0}; // Array to keep track of bags loaded into a plane
    int bags_per_plane = 0;
    srand(time(0));

    // Simulate planes landing and baggage handling until total bags are loaded on to planes
    while (bags_handled < total_bags) {
        if (planes_landed < MAX_PLANES && (rand() % 10) < 7) {
            /* With 70% probability, simulate a plane landing 
               Maximum of 5 planes can be present at a time */
            printf("Plane %d has landed\n", planes_landed + 1);
            landing_interval = rand() % 6 + 2; // Random interval between 2 and 7 minutes to unload bags
            bags_per_plane = rand() % MAX_BAGS_PER_PLANE + 1; // Random bags per plane between 1 and 500
            total_bags += bags_per_plane; // Add bags per plane to total bags
            printf("Plane %d unloaded %d bags in %d minutes\n", planes_landed + 1, bags_per_plane, landing_interval);

            // Simulate loading of bags onto the plane
            for (int i = 0; i < bags_per_plane; i++) {
                if (bags_loaded[i] == 0) {
                    /* If the position is empty, load the bag onto the plane */
                    bags_loaded[i] = 1;
                    bags_handled++;
                }
            }

            printf("%d bags loaded onto Plane %d\n", bags_per_plane, planes_landed + 1);
            planes_landed++;
        } else {
            /* If no planes have landed, wait for one minute */
            printf("No planes landed this minute\n");
        }

        /* After a minute, print current status of bags loaded on the planes */
        printf("Total bags loaded on planes: %d\n", bags_handled);
        printf("Bags loaded on each plane:");

        for (int i = 0; i < planes_landed; i++) {
            printf(" Plane %d: %d", i + 1, bags_loaded[i]);
        }

        printf("\n\n");
        sleep(1); // Wait for a minute before simulating next iteration
    }

    printf("All bags loaded onto planes successfully. Total bags: %d\n", total_bags);
    return 0;
}