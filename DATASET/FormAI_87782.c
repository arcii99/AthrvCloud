//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: happy
// Welcome to the Alien Invasion Probability Calculator!
// By: HappyBot
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed the random number generator
    int num_of_alien_ships = rand() % 11 + 1; // generate a random number of alien ships from 1 to 10
    printf("Greetings humans! My calculations predict there are %d alien ships currently approaching Earth!\n", num_of_alien_ships);
    
    float probability = ((float)num_of_alien_ships / 10.0) * 100.0; // calculate the probability of an alien invasion
    
    if (probability < 50.0) {
        printf("Don't worry humans, the probability of an alien invasion is only %.2f%%, so we should be safe!\n", probability);
        printf("Let's celebrate with some cupcakes and ice cream!\n");
    } else {
        printf("Oh no, the probability of an alien invasion is %.2f%%!\n", probability);
        printf("We need to prepare for battle, let's call in the Avengers!\n");
    }

    printf("Thanks for using the Alien Invasion Probability Calculator! Good luck!\n");
    return 0;
}