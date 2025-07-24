//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));
    
    // Define arrays for conspiracy theories
    const char* conspiracy1[] = {"The government is controlling our thoughts with chemtrails",
                                 "Aliens are secretly running our government",
                                 "The moon landing was faked",
                                 "The Earth is flat and NASA is hiding the truth"};

    const char* conspiracy2[] = {"Big Pharma is hiding the cure for cancer",
                                 "The Illuminati controls the world's governments and economies",
                                 "The Rothschild family secretly rules the world",
                                 "9/11 was an inside job"};

    const char* conspiracy3[] = {"The real Elvis Presley is alive and living in hiding",
                                 "The Loch Ness Monster is a government experiment gone wrong",
                                 "The Bermuda Triangle is a portal to another dimension",
                                 "The Denver International Airport is a hub for the New World Order"};

    // Define variables for random selection
    int rand1, rand2, rand3;

    // Generate random numbers to select from each array
    rand1 = rand() % 4;
    rand2 = rand() % 4;
    rand3 = rand() % 4;

    // Print out the random conspiracy theory
    printf("Did you know that %s, %s, and %s?\n", conspiracy1[rand1], conspiracy2[rand2], conspiracy3[rand3]);

    return 0;
}