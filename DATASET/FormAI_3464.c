//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *random_element(char **array, int length) {
    srand((unsigned int) time(NULL));
    int index = rand() % length;
    return array[index];
}

void generate_theory() {
    char *subjects[] = {"government", "aliens", "illuminati", "religion", "media", "technology"};
    int subjects_length = sizeof(subjects) / sizeof(char *);
    char *actions[] = {"is controlling", "invented", "is hiding", "is conspiring with", "is manipulating", "is brainwashing"};
    int actions_length = sizeof(actions) / sizeof(char *);
    char *objects[] = {"the population", "the weather", "technology", "the economy", "the media", "our minds"};
    int objects_length = sizeof(objects) / sizeof(char *);

    printf("The %s %s %s.\n", random_element(subjects, subjects_length), random_element(actions, actions_length), random_element(objects, objects_length));
}

int main() {
    int num_theories = 10;

    for (int i = 0; i < num_theories; i++) {
        generate_theory();
    }

    return 0;
}