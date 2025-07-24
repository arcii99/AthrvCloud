//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {

    srand(time(NULL)); //Seed random number generator with current time

    int alienCivilizations = rand() % 50 + 1; //Generate a random number between 1 and 50
    float probability = (float)alienCivilizations / 50 * pow(10, -6); //Calculate the probability of an alien invasion
    float distanceYears = pow(10, rand() % 6 + 1); //Generate a random number between 10^1 and 10^6
    float timeYears = rand() % 10000 + 1; //Generate a random number between 1 and 10000

    printf("Number of known alien civilizations: %d\n", alienCivilizations);
    printf("Probability of an alien invasion: %f\n", probability);
    printf("Distance in light years from Earth: %f\n", distanceYears);
    printf("Time in years until the alien invasion: %f\n\n", timeYears);

    if(probability >= 0.00001) { //If the probability of an alien invasion is greater than or equal to 0.00001, display a warning

        printf("*** WARNING ***\n");
        printf("The probability of an alien invasion is high!\n\n");

    }

    if(distanceYears < 100) { //If the distance from Earth to the alien civilization is less than 100 light years, display a message

        printf("*** ALERT ***\n");
        printf("The distance to the alien civilization is less than 100 light years!\n\n");

    }

    if(timeYears < 100) { //If the time until the alien invasion is less than 100 years, display a message

        printf("*** URGENT ***\n");
        printf("The alien invasion is less than 100 years away!\n\n");

    }

    return 0;

}