//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Seed the random number generator
    srand(time(NULL));

    // Define some arrays to hold the conspiracy theories
    char *conspiracy1[] = {"The moon landing was faked by the government", 
                            "COVID-19 was created in a lab as a bioweapon",
                            "The world is controlled by a secret group of elites",
                            "Bigfoot is a government experiment gone wrong"};
    char *conspiracy2[] = {"to cover up a secret mission to the moon.",
                            "to control the population and impose martial law.",
                            "to manipulate the stock market and stay in power.",
                            "to study the effects of genetic engineering on a living creature."};
    char *conspiracy3[] = {"The Illuminati is behind it all.",
                            "The CIA is using mind control to manipulate the population.",
                            "Aliens are working with the government to control humanity.",
                            "The government has discovered a portal to another dimension."};

    // Generate a random conspiracy theory
    int randIndex1 = rand() % sizeof(conspiracy1)/sizeof(conspiracy1[0]);
    int randIndex2 = rand() % sizeof(conspiracy2)/sizeof(conspiracy2[0]);
    int randIndex3 = rand() % sizeof(conspiracy3)/sizeof(conspiracy3[0]);
    printf("Did you know that %s %s %s?\n", conspiracy1[randIndex1], conspiracy2[randIndex2], conspiracy3[randIndex3]);

    return 0;
}