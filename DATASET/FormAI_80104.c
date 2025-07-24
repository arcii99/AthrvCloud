//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *nouns[] = {"moon landing", "9/11", "JFK assassination", "Illuminati", "Flat Earth", "Area 51", "chemtrails", "vaccines", "Bigfoot", "New World Order"};
    char *verbs[] = {"faked", "orchestrated", "conspired", "controlled", "manipulated", "covered up", "experimented with", "poisoned", "harnessed the power of"};
    char *adjectives[] = {"sinister", "nefarious", "devious", "dangerous", "shady", "treacherous", "unscrupulous", "corrupt"};
    char *explanations[] = {"to control the masses", "to keep the truth hidden", "to advance their agenda", "to maintain their power", "to manipulate the economy"};

    srand(time(NULL)); // initialize random seed

    int i;
    for (i = 0; i < 10; i++) {
        // randomly select a noun, verb, adjective, and explanation
        int noun_index = rand() % 10;
        int verb_index = rand() % 9;
        int adj_index = rand() % 8;
        int expl_index = rand() % 5;

        printf("The %s was %s by a %s %s %s.\n", nouns[noun_index], verbs[verb_index], adjectives[adj_index], nouns[noun_index], explanations[expl_index]);
    }

    return 0;
}