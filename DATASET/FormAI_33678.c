//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //Initialize random seed
    
    char *adjectives[] = {"sinister", "shadowy", "dark", "dangerous", "mysterious", "ominous", "nefarious", "sinful", "satanic", "creepy"};
    char *nouns[] = {"Illuminati", "government", "aliens", "secret society", "New World Order", "reptilians", "freemasons", "CIA", "NSA", "Big Pharma"};
    char *verbs[] = {"controlled", "manipulated", "brainwashed", "infiltrated", "dominated", "enslaved", "oppressed", "corrupted", "suppressed", "silenced"};
    
    int num_adjectives = sizeof(adjectives) / sizeof(adjectives[0]);
    int num_nouns = sizeof(nouns) / sizeof(nouns[0]);
    int num_verbs = sizeof(verbs) / sizeof(verbs[0]);
    
    printf("Random Conspiracy Theory Generator\n");
    printf("----------------------------------\n\n");
    
    for(int i = 1; i <= 10; i++) {
        int adj_index = rand() % num_adjectives;
        int noun_index = rand() % num_nouns;
        int verb_index = rand() % num_verbs;
        
        printf("%d) The %s %s the %s.\n", i, adjectives[adj_index], verbs[verb_index], nouns[noun_index]);
    }
    
    return 0;
}