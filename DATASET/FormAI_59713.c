//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed the random number generator with current time

    char *nouns[] = {"government", "aliens", "Illuminati", "vaccines",
                     "big pharma", "globalists", "cancer", "chemtrails",
                     "weather control", "9/11", "moon landing", "Flat Earth Society",
                     "new world order", "feminism", "capitalism", "socialism",
                     "religion", "media", "education system", "computers",
                     "artificial intelligence"};

    char *adjectives[] = {"secret", "hidden", "subliminal", "mind-control",
                          "toxic", "dangerous", "experimental", "classified",
                          "manipulative", "destructive", "deceptive",
                          "brainwashing", "hypnotic", "illuminating",
                          "corrupting", "mind-boggling", "mind-bending",
                          "mind-numbing"};

    char *verbs[] = {"control", "manipulate", "experiment on", "spy on",
                    "brainwash", "indoctrinate", "misinform", "confuse",
                    "corrupt", "deceive", "hypnotize", "program",
                    "influence", "subjugate", "dominate", "enslave"};

    int num_conspiracy_theories = 10;
    int num_nouns = sizeof(nouns) / sizeof(nouns[0]);
    int num_adjectives = sizeof(adjectives) / sizeof(adjectives[0]);
    int num_verbs = sizeof(verbs) / sizeof(verbs[0]);

    printf("Random Conspiracy Theory Generator\n");
    printf("----------------------------------\n\n");

    for (int i = 0; i < num_conspiracy_theories; i++) {
        int noun_idx = rand() % num_nouns; // pick a random noun
        int adj_idx = rand() % num_adjectives; // pick a random adjective
        int verb_idx = rand() % num_verbs; // pick a random verb

        printf("%d) The %s is %s to %s the %s.\n", i+1, nouns[noun_idx],
               adjectives[adj_idx], verbs[verb_idx], nouns[noun_idx]);
    }

    return 0;
}