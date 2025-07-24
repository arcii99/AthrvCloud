//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: scalable
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256
#define NUM_THEORIES 5

const char *nouns[] = {
    "government",
    "aliens",
    "technology",
    "secret organization",
    "big corporations",
    "celebrities",
    "religion",
    "media",
    "military",
    "historical figures",
    "elite",
    "monarchy",
    "educational institutions",
    "medical industry"
};

const char *verbs[] = {
    "created",
    "secretly controls",
    "manipulates",
    "are working with",
    "is hiding",
    "is spying on",
    "is experimenting on",
    "has been replaced by",
    "is sabotaging",
    "is brainwashing",
    "has been infiltrated by"
};

const char *adjectives[] = {
    "suspicious",
    "dangerous",
    "secretive",
    "conspiratorial",
    "mysterious",
    "powerful",
    "manipulative",
    "evil",
    "corrupt",
    "unscrupulous"
};

const char *theories[] = {
    "The %s %s our minds with %s technology.",
    "The %s %s %s to undermine our freedom.",
    "The %s %s the %s to keep us in the dark.",
    "The %s %s %s to take over the world.",
    "The %s %s the %s to keep their power."
};

char *generate_theory() {
    char *theory = malloc(MAX_LEN);
    if (theory == NULL)
        return NULL;

    int n_idx = rand() % (sizeof(nouns)/sizeof(char*));
    int v_idx = rand() % (sizeof(verbs)/sizeof(char*));
    int a_idx1 = rand() % (sizeof(adjectives)/sizeof(char*));
    int a_idx2 = rand() % (sizeof(adjectives)/sizeof(char*));
    int t_idx = rand() % (NUM_THEORIES);

    snprintf(theory, MAX_LEN, theories[t_idx], nouns[n_idx], verbs[v_idx], adjectives[a_idx1], adjectives[a_idx2]);

    return theory;
}

int main() {
    srand(42);  // for consistent output

    for (int i = 0; i < 5; i++) {
        char *theory = generate_theory();
        if (theory == NULL) {
            fprintf(stderr, "Failed to generate theory!\n");
            return 1;
        }
        printf("%s\n", theory);
        free(theory);
    }

    return 0;
}