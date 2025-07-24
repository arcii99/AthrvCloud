//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* random_element(char** array, int size) {
    return array[rand() % size];
}

int main() {
    char* subjects[] = {"The government", "Big corporations", "Aliens", "The Illuminati", "The Freemasons", "Artificial Intelligence"};
    char* verbs[] = {"is controlling", "is manipulating", "is brainwashing", "is monitoring", "is influencing", "is secretly funding"};
    char* objects[] = {"the weather", "social media", "the economy", "our thoughts", "the education system", "the entertainment industry"};

    const int NUM_SUBJECTS = 6;
    const int NUM_VERBS = 6;
    const int NUM_OBJECTS = 6;

    time_t t;
    srand((unsigned) time(&t));

    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    while(1) {
        printf("\n%s %s %s.\n", random_element(subjects, NUM_SUBJECTS), random_element(verbs, NUM_VERBS), random_element(objects, NUM_OBJECTS));

        printf("\nPress ENTER to generate another or type 'exit' to quit.\n");

        char input[255];
        fgets(input, 255, stdin);

        if (strcmp(input, "exit\n") == 0) {
            printf("\nThanks for using the Random Conspiracy Theory Generator!\n");
            break;
        }
    }

    return 0;
}