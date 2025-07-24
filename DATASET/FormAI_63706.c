//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int invasionProb; //declare variable to store invasion probability
    int randomNum; //declare variable to store randomly generated number
    srand(time(NULL)); //seed random number generator with current time

    printf("\n==============================================");
    printf("\n\t ALIEN INVASION PROBABILITY CALCULATOR");
    printf("\n==============================================\n");

    //randomly generate invasion probability between 0 and 100
    randomNum = rand() % 101;
    invasionProb = randomNum;

    printf("\nCalculating probability...\n\n");
    //wait for 1 second to simulate calculating process
    sleep(1);

    printf("Based on current data and analysis,\n");
    //wait for 1 second to simulate analyzing process
    sleep(1);

    printf("the probability of an alien invasion is %d percent.\n\n", invasionProb);

    //determine response based on invasion probability value
    if (invasionProb < 25) {
        printf("There's nothing to worry about. The probability is low.\n");
    } else if (invasionProb < 50) {
        printf("There's a moderate probability of invasion. Be prepared.\n");
    } else if (invasionProb < 75) {
        printf("The probability of invasion is high. It's time to start building defenses.\n");
    } else {
        printf("The probability of invasion is extremely high. Prepare for the worst.\n");
    }

    return 0;
}