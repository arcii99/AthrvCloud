//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, l;
    int x[10], y[10];
    int total_errors = 0;
    int time_taken = 0;

    // Generate random numbers for test
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        x[i] = rand() % 10 + 1;
        y[i] = rand() % 10 + 1;
    }

    // Display instructions
    printf("Welcome to the Typing Speed Test! Your task is to enter the sum of two numbers displayed on the screen as fast as possible without making errors.\n");

    // Begin test
    for (j = 0; j < 3; j++) { // Three rounds
        printf("Round %d: Ready...\n", j+1);
        getchar(); // Wait for user to be ready
        printf("Go!\n");
        clock_t start = clock(); // Start clock
        for (k = 0; k < 10; k++) { // Display 10 sums
            printf("%d + %d = ", x[k], y[k]);
            int answer;
            scanf("%d", &answer);
            if (answer != x[k]+y[k]) { // Check for errors
                total_errors++;
            }
        }
        clock_t end = clock(); // Stop clock
        time_taken += (int)(end-start)/CLOCKS_PER_SEC; // Calculate time taken
    }

    // Display results
    printf("Test complete!\n");
    printf("Total errors: %d\n", total_errors);
    printf("Time taken: %d seconds\n", time_taken);
    printf("Your typing speed is: %.2f characters per minute\n", ((float)total_errors*3*20)/(time_taken/60.0));

    return 0;
}