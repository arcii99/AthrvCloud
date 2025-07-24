//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set up random seed
    srand(time(NULL));

    // List of conspiracy theories
    char *conspiracyTheories[] = {
        "The government is controlling our minds with chemtrails",
        "Aliens are among us, disguised as everyday people",
        "The moon landing was faked",
        "The Illuminati controls everything",
        "The world is flat",
        "9/11 was an inside job",
        "Elvis is still alive",
        "The Bermuda Triangle is a gateway to another dimension",
        "Bigfoot is real and the government is covering it up",
        "The apocalypse is coming and only the elite know about it"
    };

    // Pick a random conspiracy theory
    int randomIndex = rand() % 10;
    char *conspiracyTheory = conspiracyTheories[randomIndex];

    // Print out conspiracy theory to user
    printf("Did you know... %s\n", conspiracyTheory);

    return 0;
}