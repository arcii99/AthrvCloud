//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char *adjectives[] = {"sinister", "ominous", "malevolent", "nefarious", "diabolical", "treacherous", "cunning", "devious", "scheming", "conniving"};
    char *nouns[] = {"government", "corporation", "secret society", "aliens", "illuminati", "freemasons", "deep state", "new world order"};
    char *verbs[] = {"manipulating", "brainwashing", "intimidating", "controlling", "spying", "infiltrating", "suppressing", "silencing", "secretly ruling"};
  
    srand(time(NULL)); // seed random number generator

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Here is your unique theory:\n");

    // generate random adjectives, nouns, and verbs
    int adjIndex = rand() % 10;
    int nounIndex = rand() % 8;
    int verbIndex = rand() % 9;

    printf("The %s %s is %s society by %s the masses.\n", adjectives[adjIndex], nouns[nounIndex], verbs[verbIndex], nouns[nounIndex]);

    // generate more conspiracy theories with user input
    char answer = 'y';
    while (answer == 'y')
    {
        // get user input
        printf("Do you want to generate another conspiracy theory? (y/n) ");
        scanf(" %c", &answer);

        // check if user wants to continue
        if (answer == 'n')
        {
            printf("Thanks for using the Random Conspiracy Theory Generator! Goodbye!\n");
            break;
        }

        // generate random adjectives, nouns, and verbs again
        adjIndex = rand() % 10;
        nounIndex = rand() % 8;
        verbIndex = rand() % 9;

        printf("Here is another conspiracy theory:\n");
        printf("The %s %s is %s society by %s the masses.\n", adjectives[adjIndex], nouns[nounIndex], verbs[verbIndex], nouns[nounIndex]);
    }

    return 0;
}