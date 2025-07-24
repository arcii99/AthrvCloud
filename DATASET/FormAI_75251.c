//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int random_int(int max);
void generate_theory();

int main() {
    // Set random seed
    srand(time(NULL));

    // Generate 10 conspiracy theories
    for (int i = 0; i < 10; i++) {
        printf("Conspiracy Theory #%d:\n", i+1);
        generate_theory();
        printf("\n");
    }

    return 0;
}

// Generates a random integer between 0 and max (inclusive)
int random_int(int max) {
    return rand() % (max+1);
}

// Generates and prints a new conspiracy theory
void generate_theory() {
    // Define arrays of possible components
    char *groups[] = {"the government", "aliens", "the Illuminati", "secret societies", "the deep state", "Big Pharma", "the military industrial complex"};
    char *verbs[] = {"controls", "manipulates", "plagues", "brainwashes", "plans"};
    char *nouns[] = {"technology", "the weather", "our minds", "society", "the economy", "the environment", "politics"};
    char *adjectives[] = {"corrupt", "sinister", "mind-controlling", "manipulative", "deceptive", "evil"};

    // Generate components
    int group_index = random_int(6);
    int verb_index = random_int(4);
    int noun_index = random_int(6);
    int adj_index = random_int(5);

    // Print theory
    printf("%s %s %s with %s.", 
            groups[group_index], 
            verbs[verb_index], 
            nouns[noun_index], 
            adjectives[adj_index]);
}