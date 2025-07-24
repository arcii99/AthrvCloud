//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); //Initialize random number generator with current time

    double alien_prob = 0.0; //Probability of alien invasion
    int num_simulations = 100000; //Number of simulations to run
    int num_hits = 0; //Number of simulations where alien invasion occurred
    int num_years = 50; //Number of years over which to calculate probability

    for(int i=0; i<num_simulations; i++){
        int invasion_year = rand() % num_years; //Generate a random year for invasion
        if(invasion_year >= 40){ //If invasion occurs in last 10 years
            num_hits++; //Count it as a hit
        }
    }

    alien_prob = (double)num_hits/num_simulations; //Calculate probability

    printf("The probability of an alien invasion within the next 10 years is: %.2f%%\n", alien_prob*100);

    return 0;
}