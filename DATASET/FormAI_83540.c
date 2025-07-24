//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // initialize random number generator with current time
    srand(time(NULL));

    // list of conspiracy theories
    char *theories[] = {
        "The moon landing was faked.",
        "9/11 was an inside job.",
        "The government is hiding evidence of extraterrestrial life.",
        "The earth is flat.",
        "The Illuminati control the world.",
        "The pharmaceutical industry is suppressing a cure for cancer.",
        "COVID-19 is a hoax.",
        "Global warming is a hoax.",
        "The Rothschild family control the global economy.",
        "The Denver airport is a secret government base.",
        "The Pyramids were built by aliens.",
        "There is a secret society of shape-shifting reptilian humanoids.",
        "The Holocaust never happened.",
        "The government is using chemtrails to control the population.",
        "The CIA assassinated JFK.",
        "The Titanic was sunk on purpose.",
        "The Bermuda Triangle is a portal to another dimension.",
        "The New World Order is coming.",
        "The US government has a secret time machine.",
        "The world is controlled by a small group of elite families."
    };

    // generate a random index to select a theory
    int index = rand() % 20;

    // print the selected theory
    printf("Conspiracy theory: %s\n", theories[index]);

    return 0;
}