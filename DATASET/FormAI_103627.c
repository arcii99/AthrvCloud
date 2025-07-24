//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* getRandomPhrase(char phrases[][256], int n) {
    int randomIndex = rand() % n;
    return phrases[randomIndex];
}

int main() {
    srand(time(NULL));
    char conspiracyPhrases[][256] = {
        "The government is using satellites to control our thoughts.",
        "The moon landing was faked.",
        "Aliens have secretly taken over the world's governments.",
        "The Illuminati controls everything from behind the scenes.",
        "COVID-19 was intentionally created in a lab as a bioweapon.",
        "The earth is flat and scientists are lying to us.",
        "The 9/11 attacks were an inside job.",
        "The JFK assassination was a conspiracy involving multiple parties.",
        "The world's elite are part of a global cabal that intends to enslave the masses."
    };
    int numConspiracyPhrases = sizeof(conspiracyPhrases) / sizeof(conspiracyPhrases[0]);

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Here are three randomly generated conspiracy theories for you to ponder...\n\n");

    for (int i = 0; i < 3; i++) {
        char* phrase = getRandomPhrase(conspiracyPhrases, numConspiracyPhrases);
        printf("%d. %s\n", i + 1, phrase);
    }

    printf("\nWhat do you think? Are any of these theories plausible? Or are they just the ramblings of paranoid minds?\n");

    return 0;
}