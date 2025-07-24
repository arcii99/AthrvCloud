//FormAI DATASET v1.0 Category: Random ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers within a range
int generateRandomNumber(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main() {
    int lower, upper, num;
    printf("Enter the lower limit of the range: ");
    scanf("%d", &lower);
    printf("Enter the upper limit of the range: ");
    scanf("%d", &upper);

    // Seed the random number generator with current time
    srand(time(0));

    printf("\nGenerating 10 random numbers within the range %d and %d: \n", lower, upper);
    for(int i = 0; i < 10; i++) {
        num = generateRandomNumber(lower, upper);
        printf("%d ", num);
    }

    return 0;
}