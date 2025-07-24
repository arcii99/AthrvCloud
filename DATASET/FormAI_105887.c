//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Declare arrays for each category
    char *adjectives[] = {
        "brave", "courageous", "fearless", "valiant", "gallant", "stalwart", "chivalrous", "dauntless",
        "daring", "intrepid", "heroic", "bold", "fierce", "mighty", "adventurous", "audacious"
    };
    int num_adjectives = sizeof(adjectives) / sizeof(adjectives[0]);

    char *nouns[] = {
        "knight", "warrior", "hero", "savior", "champion", "crusader", "paladin", "gladiator",
        "adventurer", "conqueror", "defender", "protector", "legend", "myth", "god", "king"
    };
    int num_nouns = sizeof(nouns) / sizeof(nouns[0]);

    char *verbs[] = {
        "will conquer", "shall vanquish", "must overcome", "shall triumph over", "will emerge victorious from",
        "must defeat", "shall overpower", "will slay", "must prevail over", "shall exterminate", "will destroy",
        "shall subdue", "must crush", "will overpower", "shall overthrow", "must humble"
    };
    int num_verbs = sizeof(verbs) / sizeof(verbs[0]);

    // Generate a random number for each category
    int adj_index = rand() % num_adjectives;
    int noun_index = rand() % num_nouns;
    int verb_index = rand() % num_verbs;

    // Print the fortune
    printf("Dear adventurer, thou art a %s %s that %s all obstacles in thy path.\n", adjectives[adj_index], nouns[noun_index], verbs[verb_index]);

    return 0;
}