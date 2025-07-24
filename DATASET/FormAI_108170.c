//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: random
#include <stdio.h>

int main() {
    int total_bags, bags_processed = 0;
    printf("Enter the total number of bags: ");
    scanf("%d", &total_bags);

    while (bags_processed < total_bags) {
        printf("Processing bag %d\n", bags_processed + 1);
        bags_processed++;
        if (bags_processed == total_bags) {
            printf("All bags have been processed!\n");
            break;
        }

        // Simulate random events
        int event = rand() % 3;
        switch (event) {
            case 0:
                printf("Bag %d has been sent to the wrong flight\n", bags_processed);
                break;
            case 1:
                printf("Bag %d has been delayed due to security checks\n", bags_processed);
                break;
            case 2:
                printf("Bag %d has been successfully loaded onto the plane\n", bags_processed);
                break;
        }
    }

    return 0;
}