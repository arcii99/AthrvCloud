//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* phrases[] = {
    "The Earth is flat",
    "Chemtrails are controlling our minds",
    "The moon landing was faked",
    "Aliens have secretly taken over the government",
    "The Illuminati controls everything",
    "The government is hiding the cure for cancer",
    "9/11 was an inside job",
    "Vaccines cause autism"
};

char* people[] = {
    "the government",
    "the Illuminati",
    "scientists",
    "aliens",
    "the CIA"
};

char* actions[] = {
    "are hiding the truth about",
    "are manipulating",
    "are brainwashing",
    "are using",
    "created",
    "are covering up"
};

int main() {
    srand(time(0));

    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");

    for(int i = 0; i < 5; i++) {
        int phraseIndex = rand() % 8;
        int peopleIndex = rand() % 5;
        int actionsIndex = rand() % 6;

        printf("%s %s %s.\n", people[peopleIndex], actions[actionsIndex], phrases[phraseIndex]);
    }

    printf("\nThank you for using the Random Conspiracy Theory Generator!\n");

    return 0;
}