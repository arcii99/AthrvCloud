//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seeding the random generator with current time
    char *subjects[] = {"The government", "The Illuminati", "Big Pharma", "The aliens", "The lizard people"};
    char *verbs[] = {"is hiding", "is controlling", "is planning", "is manipulating", "is experimenting on"};
    char *objects[] = {"the truth about vaccines", "our minds with chemtrails", "the weather", "our genes", "the economy"};

    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    while(1) { // loop until user quits
        printf("\nPress enter to generate a new conspiracy or type 'quit' to exit: ");
        char input[5];
        fgets(input, 5, stdin);

        if(strcmp(input, "quit\n") == 0) {
            printf("Exiting...\n");
            break;
        }

        int subject_index = rand() % 5;
        int verb_index = rand() % 5;
        int object_index = rand() % 5;

        printf("\n%s %s %s.\n", subjects[subject_index], verbs[verb_index], objects[object_index]);
    }

    return 0;
}