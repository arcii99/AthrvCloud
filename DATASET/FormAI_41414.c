//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

//Function to generate a random number between 1 and 100
int generateRandomNumber() {
    int randomNum = rand() % 100 + 1;
    return randomNum;
}

//Function to calculate the probability of alien invasion
void calculateAlienInvasionProbability() {
    int alienProbability = generateRandomNumber();
    printf("Alien Invasion Probability: %d%%\n", alienProbability);
    if(alienProbability > 50) {
        printf("Prepare for an Alien Invasion!");
    } else {
        printf("Do not worry, the chances of an Alien Invasion are low.");
    }
}

//Main function
int main() {
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    char answer;
    do {
        //Ask user if they want to calculate probability
        printf("Would you like to calculate the probability of an Alien Invasion? (y/n)\n");
        scanf(" %c", &answer);

        //If user says yes, calculate probability
        if (answer == 'y') {
            calculateAlienInvasionProbability();
        }
    } while (answer == 'y');
    printf("Thank you for using the Alien Invasion Probability Calculator!");
    return 0;
}