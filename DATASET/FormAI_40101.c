//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CONSPIRACIES 5
#define NUM_SHAPESHIFTERS 4

int main()
{
    char* conspiracies[NUM_CONSPIRACIES] = {"The government is hiding the truth about UFOs",
                                            "The moon landing was faked",
                                            "The Illuminati controls the world",
                                            "The Earth is flat",
                                            "Chemtrails are poisoning the population"};

    char* shapeshifters[NUM_SHAPESHIFTERS] = {"Reptilians",
                                             "Aliens",
                                             "Demons",
                                             "Vampires"};

    srand(time(NULL));

    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    printf("*********************************************************\n");

    printf("Here's your unique theory: \n");

    int conspiracy_index = rand() % NUM_CONSPIRACIES;
    int shapeshifter_index = rand() % NUM_SHAPESHIFTERS;

    char* conspiracy = conspiracies[conspiracy_index];
    char* shapeshifter = shapeshifters[shapeshifter_index];

    printf("%s are actually behind %s\n", shapeshifter, conspiracy);

    printf("*********************************************************\n");

    printf("Thank you for using the Random Conspiracy Theory Generator!\n");

    return 0;
}