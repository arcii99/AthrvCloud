//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* generateConspiracy();

int main() {
    srand(time(NULL));
    char* conspiracy = generateConspiracy();
    printf("Here is your random conspiracy theory: %s\n", conspiracy);
    free(conspiracy); // clean up allocated memory
    return 0;
}

char* generateConspiracy() {
    char* conspiracy = malloc(200 * sizeof(char)); // allocate memory for generated conspiracy
    char* subjects[] = {"The government", "The Illuminati", "Big Pharma", "Aliens", "The Deep State"};
    char* verbs[] = {"is controlling", "is manipulating", "is brainwashing", "is conspiring with", "is spying on"};
    char* objects[] = {"the media", "the weather", "our minds", "our elections", "our dreams"};

    int subIndex = rand() % 5;
    int verbIndex = rand() % 5;
    int objIndex = rand() % 5;

    strcpy(conspiracy, subjects[subIndex]);
    strcat(conspiracy, " ");
    strcat(conspiracy, verbs[verbIndex]);
    strcat(conspiracy, " ");
    strcat(conspiracy, objects[objIndex]);
    return conspiracy;
}