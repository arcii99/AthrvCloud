//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *subjects[] = {"Moon landing", "9/11", "Chemtrails", "Area 51", "The Illuminati"};

char *actions[] = {"covered up", "manipulated", "created", "planted"};

char *objects[] = {"evidence", "memes", "aliens", "mind control devices", "secret technology"};

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    // Generate 10 conspiracy theories
    for (int i = 0; i < 10; i++)
    {
        // Choose a random subject, action, and object
        int rand_subject = rand() % 5;
        int rand_action = rand() % 4;
        int rand_object = rand() % 5;

        // Print the conspiracy theory statement
        printf("%d. The %s %s the %s!\n", i+1, subjects[rand_subject], actions[rand_action], objects[rand_object]);
    }

    printf("Stay alert!\n");

    return 0;
}