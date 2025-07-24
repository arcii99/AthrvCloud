//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* adjectives[] = {"sinister", "malevolent", "dark", "ominous", "suspicious", "mysterious", "shadowy", "cryptic", "enigmatic", "nefarious", "ominous", "dangerous", "secretive", "unidentified", "threatening"};
char* nouns[] = {"government", "Illuminati", "aliens", "Illuminati aliens", "deep state", "new world order", "Big Pharma", "international bankers", "CIA", "FBI", "NASA", "NSA", "Democrats", "Republicans"};
char* verbs[] = {"manipulating", "brainwashing", "mind-controlling", "illuminating", "spying on", "poisoning", "infiltrating", "conspiring against", "experimenting on", "plotting with", "covering up for", "supressing the truth about"};

int main() {
    srand(time(NULL)); //seed for random number generator
    
    int adj_index = rand() % 15; //randomly select an adjective
    int noun_index = rand() % 14; //randomly select a noun
    int verb_index = rand() % 12; //randomly select a verb
    
    printf("The %s %s is %s the %s!", adjectives[adj_index], nouns[noun_index], verbs[verb_index], nouns[noun_index]);
    
    return 0;
}