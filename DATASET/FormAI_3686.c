//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Creating arrays for each part of the conspiracy theory
    char *nouns[] = {"government", "aliens", "Illuminati", "freemasons", "CIA"};
    char *verbs[] = {"control", "manipulate", "brainwash", "spy on", "experiment on"};
    char *adjectives[] = {"secret", "hidden", "unknown", "undiscovered", "unrevealed"};
    char *targets[] = {"humans", "the population", "society", "civilization", "the masses"};

    // Seeding the random number generator
    srand(time(NULL));

    // Generating a random conspiracy theory
    int n_index = rand() % 5;
    int v_index = rand() % 5;
    int adj_index = rand() % 5;
    int t_index = rand() % 5;

    // Printing the conspiracy theory
    printf("Did you know that the %s %s %s %s?\n", adjectives[adj_index], nouns[n_index], verbs[v_index], targets[t_index]);

    return 0;
}