//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_conspiracy_theory(void);

int main() {
    srand(time(0)); // seed the random number generator with the current time
    int i;
    for (i = 0; i < 10; i++) { // generate 10 conspiracy theories
        generate_conspiracy_theory();
    }
    return 0;
}

void generate_conspiracy_theory(void) {
    // arrays of possible subjects, verbs, and endings for the conspiracy theory
    char *subjects[] = {"The government", "The Illuminati", "Big Pharma", "The lizard people", "NASA", "The Freemasons", "The Rothschilds"};
    char *verbs[] = {"is hiding", "controls", "created", "manipulates", "funds", "is experimenting with"};
    char *endings[] = {"aliens", "the weather", "mind control drugs", "the moon landing", "cancer cures", "climate change", "the economy", "the education system"};

    // randomly select a subject, verb, and ending from the arrays
    int subject_index = rand() % 7;
    int verb_index = rand() % 6;
    int ending_index = rand() % 8;

    // print out the conspiracy theory in a formatted string
    printf("%s %s %s.\n", subjects[subject_index], verbs[verb_index], endings[ending_index]);
}