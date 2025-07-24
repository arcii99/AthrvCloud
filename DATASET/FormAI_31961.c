//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double invasionProbability(int attemptsLeft, double prevProb) {
    if(attemptsLeft == 0) {
        return prevProb; //return the final probability
    }

    double randomProb = (double)rand() / RAND_MAX; //generate a random probability between 0 and 1

    double currProb = (prevProb + randomProb) / 2; //get the average probability of the previous and random probabilities

    return invasionProbability(attemptsLeft - 1, currProb); //call the function recursively with reduced attemptsLeft and updated probability
}

int main() {
    srand(time(NULL)); //initialize the random number generator with current time as seed
    int numAttempts = 10; //set the number of attempts to 10
    double initialProb = 0.5; //set the initial probability to 0.5

    double finalProb = invasionProbability(numAttempts, initialProb); //calculate the final probability using recursion

    printf("After %d attempts, the probability of an alien invasion is: %f", numAttempts, finalProb);

    return 0;
}