//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_conspiracy_theory(int level) {
    if(level == 0) {
        // Base case: print random conspiracy theory
        char *theories[] = {
            "The Earth is flat and the government is hiding it.",
            "The moon landing was fake and filmed in a studio.",
            "The Illuminati control all major world events.",
            "The government has secret mind control programs.",
            "The COVID-19 pandemic was planned and intentional.",
            "Aliens have already made contact with the government.",
            "The world is run by a secret cabal of lizard people."
        };
        int num_theories = sizeof(theories) / sizeof(char*);
        int rand_idx = rand() % num_theories;
        printf("- %s\n", theories[rand_idx]);
    } else {
        // Recursive case: generate sub-conspiracy-theory and wrap with context
        char *contexts[] = {
            "Did you know that %s",
            "It's often speculated that %s",
            "Many believe that %s",
            "Some say that %s",
            "Rumors are spreading that %s"
        };
        int num_contexts = sizeof(contexts) / sizeof(char*);
        int rand_cont_idx = rand() % num_contexts;

        char *sub_theories[] = {
            "the CIA has been secretly controlling the world economy for decades.",
            "there's a secret society of elite individuals that run everything from behind the scenes.",
            "the government has access to advanced alien technology and is hiding it from the public.",
            "popular media is full of hidden messages and subliminal ads that control our thoughts.",
            "all major news outlets are controlled by a single entity with its own secret agenda.",
            "the FBI is keeping watch on all of us through our phones and computers.",
            "the UN has a secret plan to establish a one-world government and enslave us all."
        };
        int num_sub_theories = sizeof(sub_theories) / sizeof(char*);
        int rand_sub_idx = rand() % num_sub_theories;

        char context[100];
        snprintf(context, 100, contexts[rand_cont_idx], sub_theories[rand_sub_idx]);
        printf("%s\n", context);

        // Recursive call with reduced level
        generate_conspiracy_theory(level - 1);
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Generate and print conspiracy theory
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("--------------------------------------------------\n");
    printf("Here is your unique theory for the day:\n");
    generate_conspiracy_theory(3);

    return 0;
}