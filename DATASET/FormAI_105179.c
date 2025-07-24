//FormAI DATASET v1.0 Category: Physics simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Quantum Leap Simulator!\n");
    printf("In this program, you will observe a particle in a box that is in a state of superposition.\n");
    printf("Press any key to begin the simulation.\n");
    getchar();

    srand(time(NULL));
    int pos = rand() % 101;
    float prob = rand() % 101 / 100.0;

    printf("The particle is in a box that is 100 units wide.\n");
    printf("Its position is randomly generated and is currently at %d units.\n", pos);
    printf("The probability of finding the particle at its current position is %.2f.\n", prob);

    printf("Would you like to measure the particle's position? (y/n)\n");
    char ans = getchar();

    if (ans == 'y') {
        printf("You have chosen to measure the particle's position.\n");
        printf("Measuring the particle's position will cause it to collapse into a definite state.\n");
        printf("Calculating the probability of finding the particle at its current position...\n");

        if (prob > 0.5) {
            printf("The particle was found at %d units!\n", pos);
        } else {
            int new_pos = rand() % 101;
            printf("The particle was not found at %d units.\n", pos);
            printf("The particle has collapsed into a new state at %d units.\n", new_pos);
        }
    } else {
        printf("You have chosen not to measure the particle's position.\n");
        printf("Leaving the particle in a state of superposition.\n");
    }

    printf("Thank you for using the Quantum Leap Simulator!\n");
    return 0;
}