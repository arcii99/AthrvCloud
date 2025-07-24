//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to generate random numbers within given range
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int numberOfBaggage = 50; // Total number of baggage
    int queue[numberOfBaggage]; // Array to store baggage queue
    int i, j, temp;

    // Initialize baggage queue with random numbers
    for (i = 0; i < numberOfBaggage; i++) {
        queue[i] = random_number(100, 500);
    }

    // Print initial baggage queue
    printf("Initial Baggage Queue: ");
    for (i = 0; i < numberOfBaggage; i++) {
        printf("%d ", queue[i]);
    }

    // Sorting baggage queue in ascending order using bubble sort algorithm
    for (i = 0; i < numberOfBaggage - 1; i++) {
        for (j = 0; j < numberOfBaggage - i - 1; j++) {
            if (queue[j] > queue[j+1]) {
                temp = queue[j];
                queue[j] = queue[j+1];
                queue[j+1] = temp;
            }
        }
    }

    // Print sorted baggage queue
    printf("\n\nSorted Baggage Queue: ");
    for (i = 0; i < numberOfBaggage; i++) {
        printf("%d ", queue[i]);
    }

    // Simulating baggage handling process using sleep function
    printf("\n\nStarting baggage handling process...\n\n");
    for (i = 0; i < numberOfBaggage; i++) {
        printf("Handling baggage %d\n", queue[i]);
        sleep(1); // wait for 1 second
    }

    printf("\nAll baggage have been handled successfully!\n");

    return 0;
}