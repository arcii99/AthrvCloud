//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    char* nouns[] = {"moon", "government", "aliens", "Illuminati", "vaccines", "chemtrails", "pyramids", "social media", "global warming", "5G"};
    char* verbs[] = {"control", "manipulate", "brainwash", "monitor", "influence", "secretly fund", "hide", "suppress", "fabricate", "experiment on"};
    char* adjectives[] = {"dangerous", "mind-controlling", "hidden", "secret", "powerful", "mysterious", "unexplainable", "sinister", "suspicious", "ominous"};

    int num_sentences = 10;
    int num_words = 6;

    printf("--------------------------------------------------------\n");
    printf("      RANDOM CONSPIRACY THEORY GENERATOR\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < num_sentences; i++) {
        printf("%d. ", i + 1);
        for (int j = 0; j < num_words; j++) {
            printf("%s ", adjectives[rand() % 10]);
            printf("%s ", nouns[rand() % 10]);
            printf("%s ", verbs[rand() % 10]);
        }
        printf("\n");
    }

    return 0;
}