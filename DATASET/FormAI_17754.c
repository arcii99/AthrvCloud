//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // initialize random seed
    int randNum = rand() % 5; // generate random number between 0-4
    char* conspiracy;

    switch(randNum) {
        case 0:
            conspiracy = "The moon landing was faked by the government to win the space race against the Soviet Union.";
            break;
        case 1:
            conspiracy = "The Illuminati controls the world governments and economies through secret societies and occult practices.";
            break;
        case 2:
            conspiracy = "9/11 was an inside job orchestrated by the US government to justify going to war in the Middle East.";
            break;
        case 3:
            conspiracy = "The Earth is flat and NASA is covering up the truth about the shape of our planet.";
            break;
        case 4:
            conspiracy = "COVID-19 was engineered in a lab by governments and pharmaceutical companies to control the population through fear.";
            break;
        default:
            conspiracy = "Something went wrong with the random number generator.";
            break;
    }

    printf("Random Conspiracy Theory Generator:\n------------------------------------\n%s\n", conspiracy);

    return 0;
}