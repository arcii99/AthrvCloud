//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int simulation_type;
    srand(time(NULL));

    // Prompt user for simulation type
    printf("Welcome to the airport baggage handling simulation system.\n");
    printf("Please select the type of simulation:\n");
    printf("1 - Single-terminal simulation\n");
    printf("2 - Multi-terminal simulation\n");
    scanf("%d", &simulation_type);

    // Single-terminal simulation
    if (simulation_type == 1) {

        printf("You have selected a single-terminal simulation.\n");
        // TODO: Single-terminal simulation code
        printf("Simulation complete.\n");

    // Multi-terminal simulation
    } else if (simulation_type == 2) {

        printf("You have selected a multi-terminal simulation.\n");
        // TODO: Multi-terminal simulation code
        printf("Simulation complete.\n");

    } else {

        printf("Invalid simulation type selected.\n");

    }

    return 0;
}