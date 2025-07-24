//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Define variables
    double probability = 0.0;
    char response[10];

    // Greet user and ask if they want to calculate the probability of an alien invasion
    printf("Greetings, human! Would you like to calculate the probability of an alien invasion? (yes/no) ");
    scanf("%s", response);

    // If the user responds with "yes", calculate the probability
    if(strcmp(response, "yes") == 0) {
        // Generate a random number between 0 and 100 for the probability
        probability = (double) rand() / RAND_MAX * 100;

        // Print the probability
        printf("The probability of an alien invasion is %f%%\n", probability);
    }
    // If the user responds with anything else, bid them farewell
    else {
        printf("Farewell, human!\n");
    }
    return 0;
}