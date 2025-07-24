//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seeding the random number generator

    char *conspiracy_theories[] = {
        "The moon landing was faked by the government.",
        "The Illuminati control world governments.",
        "The FBI assassinated JFK.",
        "Chemtrails are a government experiment.",
        "9/11 was an inside job.",
        "The government is hiding evidence of extraterrestrial life.",
        "The Earth is flat and NASA is lying to us.",
        "The Rothschilds control the world's wealth.",
        "The New World Order is a real thing.",
        "The government is using HAARP to control the weather.",
        "The 2012 Mayan apocalypse was real and predicted by aliens.",
        "The Bermuda Triangle is a portal to another dimension.",
        "Paul McCartney died in 1966 and was replaced by a look-alike.",
        "The Denver International Airport is a secret government base.",
        "The government is using vaccines to control the population.",
    };

    int num_theories = sizeof(conspiracy_theories) / sizeof(char *);
    int rand_index = rand() % num_theories;

    printf("Did you know? %s\n", conspiracy_theories[rand_index]);

    return 0;
}