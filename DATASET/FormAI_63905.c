//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Conspiracy theories
    char* theories[] = {"The moon landing was faked", "The government controls the weather", "Aliens have visited Earth", "9/11 was an inside job", "The Illuminati controls everything"};

    // People who are accused
    char* people[] = {"The CIA", "The Freemasons", "The Rothschilds", "The New World Order", "The Deep State"};

    // Actions taken
    char* actions[] = {"Covered up evidence", "Manipulated the media", "Bribed officials", "Started a war", "Assassinated key individuals"};

    // Randomize seed
    srand(time(NULL));

    // Generate conspiracy theory
    int theoryIndex = rand() % 5;
    char* theory = theories[theoryIndex];

    // Generate person responsible
    int personIndex = rand() % 5;
    char* person = people[personIndex];

    // Generate action taken
    int actionIndex = rand() % 5;
    char* action = actions[actionIndex];

    // Print conspiracy theory
    printf("Did you hear about the latest conspiracy theory?\n\n");
    printf("%s\n", theory);
    printf("\n");
    printf("It is believed that %s %s to make it happen.\n", person, action);

    return 0;
}