//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: high level of detail
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

char *nouns[] = {"government", "aliens", "Illuminati", "Big Pharma", "secret society", "reptilians", "New World Order"};
char *verbs[] = {"control", "manipulate", "brainwash", "program", "influence", "dominate", "enslave"};
char *adjectives[] = {"global", "sinister", "mysterious", "dark", "hidden", "malevolent", "powerful"};
char *conspiracy = "The %s is using technology to %s the minds of the people. They are %s and their motives are %s.";

int main()
{
    srand(time(0)); // set random seed
    int noun_index = rand() % 7; // generate random index for noun array
    int verb_index = rand() % 7; // generate random index for verb array
    int adj_index = rand() % 7; // generate random index for adjective array

    printf(conspiracy, nouns[noun_index], verbs[verb_index], adjectives[adj_index], adjectives[verb_index]);
    
    return 0;
}