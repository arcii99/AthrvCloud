//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const char *subjects[] = {"The government", "The Illuminati", "Aliens", "The Freemasons", "The Reptilians"};
const char *verbs[] = {"are controlling", "created", "manipulate", "are hiding", "are secretly funding"};
const char *objects[] = {"the media", "the world's economies", "world events", "the weather", "NASA"};

void generate_conspiracy_theory() {
    srand(time(NULL)); // Seed for random number generator
    int sub_idx = rand() % sizeof(subjects) / sizeof(subjects[0]);
    int verb_idx = rand() % sizeof(verbs) / sizeof(verbs[0]);
    int obj_idx = rand() % sizeof(objects) / sizeof(objects[0]);

    char theory[100]; //Declare the conspiracy theory as a string
    strcpy(theory, subjects[sub_idx]);
    strcat(theory, " ");
    strcat(theory, verbs[verb_idx]);
    strcat(theory, " ");
    strcat(theory, objects[obj_idx]);
    strcat(theory, ".");

    printf("%s\n", theory);
}

int main() {
    printf("Random Conspiracy Theory Generator:\n");

    while (1) { // Infinite loop to create new conspiracy theories
        printf("Press Enter to generate a new theory or type 'exit' to quit.\n");
        char input[10];
        fgets(input, 10, stdin); // Take user input

        if (strcmp(input, "exit\n") == 0) { // Check if user wants to exit
            break;
        }

        generate_conspiracy_theory();
    }

    return 0;
}