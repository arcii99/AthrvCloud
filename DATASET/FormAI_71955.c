//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int generateRandomNumber(int n)
{
    srand(time(NULL)); // srand( ) is used to seed the rand( ) function with the help of time( ) function
    return rand() % n;
}

int main()
{
    // Array of possible conspiracy theories
    char theories[10][100] = {"The moon landing was fake.",
                              "9/11 was an inside job.",
                              "The government is hiding the existence of aliens.",
                              "The Illuminati controls the world.",
                              "Chemtrails are a government mind-control tactic.",
                              "The Flat Earth Society is right.",
                              "COVID-19 was created in a lab as a bioweapon.",
                              "Bigfoot is real and the government is hiding it.",
                              "The Earth is hollow and inhabited by advanced civilizations.",
                              "The Loch Ness Monster is actually a dinosaur."};

    // Array of possible culprits
    char culprits[5][100] = {"The government.",
                             "The New World Order.",
                             "The Freemasons.",
                             "The Reptilians.",
                             "The Deep State."};

    // Array of possible outcomes
    char outcomes[3][100] = {"The world will end.",
                             "The New World Order will take over.",
                             "We will all be enslaved."};

    // Choose a random conspiracy theory, culprit, and outcome and print them out
    printf("CONSPIRACY THEORY: %s\n", theories[generateRandomNumber(10)]);
    printf("CULPRIT: %s\n", culprits[generateRandomNumber(5)]);
    printf("OUTCOME: %s\n", outcomes[generateRandomNumber(3)]);

    return 0;
}