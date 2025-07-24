//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int baggage_count;
    float baggage_weight;
    int conveyor_belt_capacity = 50;
    float total_weight = 0;

    printf("Please enter the number of baggage pieces: ");
    scanf("%d", &baggage_count);

    for (int i=1; i <= baggage_count; i++) {
        printf("Please enter the weight of baggage piece %d: ", i);
        scanf("%f", &baggage_weight);

        if (total_weight + baggage_weight > conveyor_belt_capacity) {
            printf("Conveyor belt is full. Transfer to the plane.\n");
            total_weight = 0;
        }

        total_weight += baggage_weight;
        printf("Baggage piece %d is on the conveyor belt. Total weight on the conveyor belt: %.2f\n", i, total_weight);
    }

    // Check if there is any remaining baggage on the conveyor belt.
    if (total_weight > 0) {
        printf("%d pieces of baggage are remaining on the conveyor belt. They must be transferred to the plane.\n", baggage_count);
    }

    return 0;
}