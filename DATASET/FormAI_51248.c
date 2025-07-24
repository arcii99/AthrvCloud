//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // set the seed for random number generation
    srand(time(NULL));
    
    // initialize variables to store input data
    int num_planets, num_invaded;
    
    // get user input for number of planets in the galaxy
    printf("Enter the total number of planets in the galaxy: ");
    scanf("%d", &num_planets);
    
    // get user input for number of planets already invaded
    printf("Enter the number of planets already invaded by aliens: ");
    scanf("%d", &num_invaded);

    // calculate the probability of alien invasion
    double invasion_prob = ((double)num_invaded / (double)num_planets) * 100.0;
    printf("The probability of an alien invasion is %.2f%%\n", invasion_prob);

    // check if invasion is imminent
    if (invasion_prob > 50.0) {
        printf("Warning! The probability of an alien invasion is high. Please take necessary precautions.\n");
    } else {
        printf("The chances of an alien invasion are low. You can rest easy!\n");
    }

    // generate random numbers to simulate alien attacks
    int num_attacks = rand() % num_invaded + 1;
    printf("Aliens have attacked %d planet(s).\n", num_attacks);
    printf("The remaining number of planets are %d.\n", num_planets - num_invaded - num_attacks); 

    return 0;
}