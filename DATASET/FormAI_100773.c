//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char *adjectives[] = {"bloodthirsty", "sinister", "shadowy", "mysterious", "diabolical", "ominous", "cryptic", "enigmatic", "suspicious", "unnerving"};
    char *nouns[] = {"Illuminati", "government", "aliens", "New World Order", "Big Pharma", "secret society", "Freemasons", "Deep State", "global elite", "reptilians"};
    char *verbs[] = {"control", "manipulate", "brainwash", "influence", "dominate", "enslave", "ensnare", "capture", "ensconce", "subjugate"};

    srand(time(0));
    int adj_index = rand() % 10;
    int noun_index = rand() % 10;
    int verb_index = rand() % 10;

    // Randomly select adjectives, nouns and verbs to form a conspiracy theory.
    printf("Did you know that the %s %s are using %s to %s our minds?", 
           adjectives[adj_index], nouns[noun_index], nouns[rand() % 10], verbs[verb_index]);

    printf("\nBut that's not all. The %s %s are also working with %s to %s the population.", 
           adjectives[rand() % 10], nouns[noun_index], nouns[rand() % 10], verbs[rand() % 10]);

    printf("\nAnd if that wasn't enough, the %s %s have been secretly %s %s for decades, without anyone knowing.", 
           adjectives[adj_index], nouns[rand() % 10], verbs[rand() % 10], nouns[rand() % 10]);

    printf("\nSo, be careful out there. You never know who might be trying to %s you.", 
           verbs[rand() % 10]);

    return 0;
}