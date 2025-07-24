//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Initialize the random seed
    srand((unsigned int) time(NULL));

    char* subjects[] = {"The government", "Big Pharma", "The Illuminati", "Aliens", "The Reptilian Elite", "The Deep State"};
    char* verbs[] = {"is controlling", "is manipulating", "is brainwashing", "is experimenting on", "is hiding information about", "is suppressing evidence of"};
    char* objects[] = {"the weather", "our minds", "vaccines", "the moon landing", "Area 51", "the existence of extraterrestrial life"};

    int num_subjects = sizeof(subjects) / sizeof(subjects[0]);
    int num_verbs = sizeof(verbs) / sizeof(verbs[0]);
    int num_objects = sizeof(objects) / sizeof(objects[0]);

    char conspiracy[100];

    // Generate a random conspiracy theory
    sprintf(conspiracy, "%s %s %s", subjects[rand() % num_subjects], verbs[rand() % num_verbs], objects[rand() % num_objects]);

    printf("Did you know? %s\n", conspiracy);

    return 0;
}