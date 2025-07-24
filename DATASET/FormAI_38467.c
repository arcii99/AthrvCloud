//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: accurate
#include <stdio.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));   // Seed the random number generator with the current time

    // Declare arrays of conspiracy theories
    char *nwo[] = {"The New World Order is controlling the government",
                   "The Illuminati is secretly running the world",
                   "The Bilderberg Group is deciding global policies behind closed doors"};
    char *ufos[] = {"Aliens have made contact with Earth",
                    "UFO sightings are being covered up by the government",
                    "The government is working with extraterrestrial beings"};
    char *covid[] = {"The COVID-19 vaccine is part of a government conspiracy to control the population",
                     "The virus was created in a lab and released on purpose",
                     "The pandemic is a hoax intended to distract from a secret agenda"};

    // Generate a random number between 0 and 2 to select a conspiracy theory
    int rand_nwo = rand() % 3;
    int rand_ufos = rand() % 3;
    int rand_covid = rand() % 3;

    // Print out the conspiracy theory in a sentence
    printf("Did you know that %s, %s, and %s?\n", nwo[rand_nwo], ufos[rand_ufos], covid[rand_covid]);

    // Wait for user input before exiting
    getchar();
    return 0;
}