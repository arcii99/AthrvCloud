//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

//initialize variables
int alien_ships = 0;
int invasion_probability = 0;
int random_number = 0;

//seed random number generator
srand(time(NULL));

//ask user how many alien ships they think could invade
printf("How many alien ships do you think could invade Earth?\n");
scanf("%d", &alien_ships);

//calculate probability of invasion
invasion_probability = (alien_ships * 100) / 1000000;

//generate random number between 1-100 to add to probability 
random_number = rand() % 100 + 1;
invasion_probability += random_number;

//display probability of invasion and random number generated
printf("The probability of an alien invasion is %d%%\n", invasion_probability);
printf("The additional random number generated was %d\n", random_number);

return 0;
}