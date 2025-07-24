//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *nouns[] = {
    "government", "aliens", "Illuminati", "Big Pharma",
    "globalists", "CIA", "Masons", "New World Order",
    "Elders of Zion", "Bigfoot", "chemtrails", "Flat Earthers",
    "Satanists", "Reptilians", "Area 51", "Deep State"
};

char *verbs[] = {
    "are controlling", "are manipulating", "are brainwashing", "are hiding",
    "are experimenting on", "are surveilling", "are conspiring against",
    "are covering up", "are infiltrating", "are obscuring"
};

char *adjectives[] = {
    "secret", "sinister", "nefarious", "malevolent", "covert",
    "hypnotic", "esoteric", "paranormal", "occult", "mysterious"
};

char *location[] = {
    "in the skies", "underground", "in the oceans", "on the moon",
    "in space", "in the Vatican", "in Area 51", "in the Bermuda Triangle",
    "in the pyramids", "in the forest", "in the desert", "in the Arctic"
};

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    int num_theories = 10; // generate 10 random conspiracy theories
    
    for (int i = 0; i < num_theories; i++) {
        int noun_idx = rand() % (sizeof(nouns)/sizeof(char*)); // pick random noun index
        int verb_idx = rand() % (sizeof(verbs)/sizeof(char*)); // pick random verb index
        int adj_idx = rand() % (sizeof(adjectives)/sizeof(char*)); // pick random adjective index
        int loc_idx = rand() % (sizeof(location)/sizeof(char*)); // pick random location index
        
        printf("%d. The %s %s the %s %s.\n", i+1, adjectives[adj_idx], nouns[noun_idx], verbs[verb_idx], location[loc_idx]);
    }
    
    return 0;
}