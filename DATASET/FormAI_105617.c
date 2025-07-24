//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // set seed for random number generator
    srand(time(NULL));

    // conspiracy theories array
    char *conspiracyTheories[] = {
        "The moon landing was faked by the government.",
        "The Illuminati secretly control the world's governments.",
        "Area 51 is hiding evidence of extraterrestrial life.",
        "The COVID-19 vaccine is a government plot to control the population.",
        "9/11 was an inside job orchestrated by the government.",
        "The Denver airport is the headquarters of the New World Order.",
        "The government is hiding evidence of the existence of Bigfoot.",
        "The Bermuda Triangle is a portal to another dimension.",
        "The Earth is flat and NASA is hiding the truth.",
        "The Loch Ness Monster is real and has been seen by government officials.",
        "The government is hiding evidence of time travel technology.",
        "The pyramids were built by aliens.",
        "The government is hiding the cure for cancer to keep the population under control.",
        "The Illuminati are behind every major world event.",
        "The government is using chemtrails to control the weather and the population.",
        "The moon is a hologram created by the government to control us.",
    };

    // generate random index
    int randomIndex = rand() % (sizeof(conspiracyTheories) / sizeof(*conspiracyTheories));

    // print conspiracy theory
    printf("Did you know: %s\n", conspiracyTheories[randomIndex]);

    return 0;
}