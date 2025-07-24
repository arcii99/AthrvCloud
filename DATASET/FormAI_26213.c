//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // set seed for random number generator

    char *nouns [] = {"government", "aliens", "Illuminati", "Big Pharma", "Deep State"}; // list of possible nouns
    char *verbs [] = {"controls", "is behind", "created", "manipulates", "orchestrates"}; // list of possible verbs
    char *adjectives [] = {"secret", "sinister", "shadowy", "ulterior", "nefarious"}; // list of possible adjectives
    char *theories [] = {"vaccines cause autism", "9/11 was an inside job", "chemtrails are real", "moon landing was fake", "Flat Earth is real"}; // list of possible conspiracy theories

    int theory_index = rand() % 5; // choose a random conspiracy theory
    int noun_index = rand() % 5; // choose a random noun
    int verb_index = rand() % 5; // choose a random verb
    int adj_index = rand() % 5; // choose a random adjective

    printf("Did you know that the %s %s %s the %s? It's all part of their %s agenda!\n", adjectives[adj_index], nouns[noun_index], verbs[verb_index], theories[theory_index], adjectives[adj_index]);

    return 0;
}