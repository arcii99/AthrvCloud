//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // Seed for random number generator
    char* subjects[] = {"The government", "The Illuminati", "Aliens", "Telepathic beings", "Time travelers"};
    char* verbs[] = {"are secretly controlling", "planned", "are manipulating", "have orchestrated", "are behind"};
    char* objects[] = {"the weather", "mass media", "technology", "the economy", "the world events"}; // Arrays of words to be used in the conspiracy theory

    printf("Welcome to the Ultra-Precise Random Conspiracy Theory Generator!\n\n");

    for(int i = 0; i < 10; i++)
    {
        printf("%d) ", i+1); // Print current conspiracy theory number
        printf("%s %s %s.\n", subjects[rand() % 5], verbs[rand() % 5], objects[rand() % 5]); // Print randomly generated conspiracy theory
    }

    printf("\nHope these conspiracy theories have got your brain working extra hard.\n");

    return 0; // End of program
}