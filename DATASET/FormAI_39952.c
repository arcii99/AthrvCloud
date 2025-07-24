//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_conspiracy_theory() {
    char *adjectives[] = {"sinister", "secret", "hidden", "mysterious", "sneaky", "covert"};
    char *nouns[] = {"Illuminati", "government", "aliens", "nazis", "dogs", "reptilians"};
    char *actions[] = {"control", "manipulate", "brainwash", "enslave", "spy on", "abduct"};

    srand(time(NULL));
    int adjIndex = rand() % 6;
    int nounIndex = rand() % 6;
    int actionIndex = rand() % 6;

    char conspiracyTheory[100];
    snprintf(conspiracyTheory, 100, "The %s %s %s us!", adjectives[adjIndex], nouns[nounIndex], actions[actionIndex]);

    printf("Here's a conspiracy theory for you: %s\n", conspiracyTheory);
}

int main() {
    printf("Welcome to the Random Conspiracy Theory Generator! Press enter to generate a conspiracy theory...\n");
    while (1) {
        getchar();
        generate_conspiracy_theory();
    }

    return 0;
}