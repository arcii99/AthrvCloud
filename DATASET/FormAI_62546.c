//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

double probability; // The probability of an alien invasion
int aliens; // The number of aliens expected to invade
int years; // The number of years until the predicted invasion

srand(time(NULL)); 

// The program generates a random probability of an alien invasion 
probability = (double) rand() / (double) RAND_MAX; 

// The program then generates a random number of aliens expected to invade
aliens = rand() % 1000000000 + 1; 

// The program generates a random number of years until the predicted invasion
years = rand() % 100 + 1; 

// Finally, the program prints out the results
printf("The probability of an alien invasion is: %f\n", probability); 
printf("The number of aliens expected to invade is: %d\n", aliens); 
printf("The predicted invasion is expected to happen in %d years\n", years);

return 0;
}