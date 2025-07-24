//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Create arrays of possible conspiracy theories and actors involved
    char* theories[] = {
        "The moon landing was faked.",
        "The government is hiding proof of extraterrestrial life.",
        "Aliens have infiltrated our government.",
        "9/11 was an inside job.",
        "The Illuminati controls everything.",
        "Bigfoot is real and the government is covering it up.",
        "The assassination of JFK was a government cover-up."
    };

    char* actors[] = {
        "The government",
        "The Freemasons",
        "The CIA",
        "The FBI",
        "Billionaires",
        "The New World Order"
    };

    // Seed the random number generator
    srand(time(NULL));

    // Repeat 10 times to generate 10 conspiracy theories
    for (int i = 0; i < 10; i++)
    {
        // Generate a random index for the theory and actor arrays
        int theoryIndex = rand() % (sizeof(theories) / sizeof(theories[0]));
        int actorIndex = rand() % (sizeof(actors) / sizeof(actors[0]));

        // Print the conspiracy theory
        printf("Theory %d: %s\n", i + 1, theories[theoryIndex]);

        // Determine if the actor is singular or plural
        char* actor = actors[actorIndex];
        if (actorIndex == 0 || actorIndex == 2)
            printf("%s is behind it.\n\n", actor);
        else
            printf("%s are behind it.\n\n", actor);
    }

    return 0;
}