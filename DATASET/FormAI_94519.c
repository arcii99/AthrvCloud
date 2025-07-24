//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize random seed
    srand(time(NULL));

    // array of conspiracy theories
    char *theories[] = {"The moon landing was faked.", 
                        "The government is using chemtrails to control the population.",
                        "The earth is flat.",
                        "The Illuminati controls the world.",
                        "9/11 was an inside job.",
                        "The JFK assassination was a CIA plot.",
                        "The world will end in 2022.",
                        "Aliens have already made contact with humanity.",
                        "The coronavirus vaccine is a way for the government to track people.",
                        "The Illuminati controls Hollywood."};

    // generate random index for conspiracy theory
    int random_index = rand() % 10;

    // print out the conspiracy theory
    printf("Did you know that %s\n", theories[random_index]);

    return 0;
}