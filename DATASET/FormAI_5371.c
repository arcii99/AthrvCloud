//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    // Seed the random number generator
    srand(time(NULL));

    // Generate random numbers for the key variables
    int alien_count = rand() % 10000 + 1000;
    int earth_population = rand() % 9000000 + 1000000;
    int invasion_chances = rand() % 100;

    // Print out the generated variables
    printf("\nAccording to our sources, there are approximately %d alien invaders. ", alien_count);
    printf("They are taking on Earth, with a population of %d. ", earth_population);
    printf("Our experts have calculated that the chances of an alien invasion succeeding is around %d%%.\n\n", invasion_chances);

    // Use some deductive reasoning to analyze the situation
    if (invasion_chances >= 50) {
        printf("Dear me, this is a rather troublesome situation! If the aliens' strength in numbers is legitimate, then it is safe to say that an invasion is imminent!\n\n");
    } else {
        printf("Not to worry, it seems as though the odds are in our favor! Unless the aliens have some sort of technological advantage, we should be safe from an invasion.\n\n");
    }

    // Just for fun, let's generate a random Sherlock Holmes quote to end this program
    char* quotes[5] = {"Elementary, my dear Watson!", "The game is afoot!", "To a great mind, nothing is little.", "I never guess. It is a shocking habit -- destructive to the logical faculty.", "My name is Sherlock Holmes. It is my business to know what other people don't know."};
    int random_quote = rand() % 5;
    printf("%s\n", quotes[random_quote]);

    return 0;
}