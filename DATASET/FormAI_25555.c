//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Setting seed for randomization
    
    // Arrays of words used to generate conspiracy theories
    char *nouns[] = {
        "government", "aliens", "Illuminati", "big corporations",
        "the media", "the military", "secret societies"
    };
    char *verbs[] = {
        "control", "manipulate", "dominate", "brainwash",
        "cover up", "infiltrate", "subvert"
    };
    char *adjectives[] = {
        "secret", "hidden", "sinister", "diabolical",
        "dangerous", "mysterious", "powerful"
    };
    char *conspiracies[] = {
        "The %s are using mind control to %s the masses.",
        "%s are actually %s a global shadow government.",
        "Evidence suggests that %s have %s since ancient times.",
        "%s are conducting %s experiments in secret.",
        "Recent events show that %s have %s a secret agenda."
    };
    
    // Generate and print conspiracy theory
    int n = rand() % 7; // Choosing random index for noun
    int v = rand() % 7; // Choosing random index for verb
    int a = rand() % 7; // Choosing random index for adjective
    int c = rand() % 5; // Choosing random index for conspiracy
    printf(conspiracies[c], adjectives[a], nouns[n], verbs[v]);
    
    return 0;
}