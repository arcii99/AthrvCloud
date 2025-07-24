//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS 100
#define MAX_WEIGHT 50

int main()
{
    int numBags = 0;
    int totalWeight = 0;
    int avgWeight = 0;
    int bagWeights[MAX_BAGS];

    printf("Welcome to the Airport Baggage Handling Simulation!\n\n");

    // Get user input for number of bags
    printf("How many bags need to be handled? (maximum %d)\n", MAX_BAGS);
    scanf("%d", &numBags);

    // Get user input for each bag's weight
    for (int i = 0; i < numBags; i++) {
        printf("Enter the weight of bag #%d (maximum %d): ", i+1, MAX_WEIGHT);
        scanf("%d", &bagWeights[i]);

        // Verify weight is within range
        if (bagWeights[i] > MAX_WEIGHT) {
            printf("Error: bag weight exceeds maximum weight of %d.\n", MAX_WEIGHT);
            return 1; // Exit program with error code
        }

        // Increment total weight counter
        totalWeight += bagWeights[i];
    }

    // Calculate and display average weight
    avgWeight = totalWeight / numBags;
    printf("\nAverage bag weight: %d\n", avgWeight);

    // Determine if the bags meet airplane weight limits
    if (totalWeight > (MAX_WEIGHT * numBags)) {
        printf("Error: the total weight of %d exceeds the maximum allowed weight of %d.\n", totalWeight, (MAX_WEIGHT * numBags));
        return 1; // Exit program with error code
    }
    else {
        printf("Bags are within airplane weight limits.\n");
    }

    return 0; // Exit program with success code
}