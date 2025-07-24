//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // set the seed for random number generation

    char* nouns[] = {"government", "aliens", "Illuminati", "Big Pharma", "the New World Order", "the deep state", "vaccines", "chemtrails", "fluoride", "the internet", "the media", "the education system", "the banking system"};
    char* verbs[] = {"control", "manipulate", "brainwash", "poison", "monitor", "influence", "hide", "create", "spread", "weaken", "destroy", "change", "take over"};
    char* adjectives[] = {"secret", "powerful", "hidden", "dangerous", "invisible", "corrupt", "deceptive", "toxic", "invasive", "man-made", "mind-controlling", "illuminating", "perverting"};
    char* connectors[] = {"because", "due to the fact that", "caused by", "as a result of", "in order to", "for the purpose of", "in order for them to", "with the intention of"};

    int num_theories = rand() % 11 + 10; // generate a random number of theories between 10 and 20 inclusive
    
    printf("Here are %d random conspiracy theories:\n", num_theories);
    
    for (int i = 0; i < num_theories; i++) {
        char* noun1 = nouns[rand() % 13]; // randomly select a noun
        char* verb1 = verbs[rand() % 13]; // randomly select a verb
        char* adj1 = adjectives[rand() % 13]; // randomly select an adjective
        
        char* connector = connectors[rand() % 8]; // randomly select a connector
        
        char* noun2 = nouns[rand() % 13]; // randomly select another noun
        char* verb2 = verbs[rand() % 13]; // randomly select another verb
        char* adj2 = adjectives[rand() % 13]; // randomly select another adjective
        
        printf("%d. The %s %s the %s in a %s way %s the %s to %s the %s %s.\n", i+1, noun1, verb1, adj1, connector, noun2, verb2, adj2, noun1, noun2);
    }
    
    return 0;
}