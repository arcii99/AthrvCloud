//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int prob, rand_prob;

    srand(time(NULL)); // randomize the seed
    rand_prob = rand() % 100; // generate a random number between 0 and 99

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Please answer the following question truthfully:\n");
    printf("Do you believe in aliens? (1 for yes, 0 for no) ");
    scanf("%d", &prob);

    if(prob == 1) {
        printf("\nYour probability of experiencing an alien invasion is %d%%.\n", rand_prob);
    } else if(prob == 0) {
        printf("\nYour probability of experiencing an alien invasion is 0%%.\n");
    } else {
        printf("Invalid input. Please enter either 1 or 0.\n"); // check for invalid input
    }

    printf("\nThank you for using the Alien Invasion Probability Calculator!\n");
    return 0;
}