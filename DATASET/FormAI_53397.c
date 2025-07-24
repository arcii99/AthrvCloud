//FormAI DATASET v1.0 Category: Dice Roller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, sum = 0;
    srand(time(0)); // Seed for random number generator
    printf("Enter the number of dice: ");
    scanf("%d", &n);
    printf("Dice rolled: ");
    for (i = 0; i < n; i++) {
        int roll = (rand() % 6) + 1; // Generating random numbers from 1 to 6
        printf("%d ", roll);
        sum += roll; // Adding up all the rolls
    }
    printf("\nTotal: %d\n", sum);
    return 0;
}