//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char* subjects[] = {"The Government", "The Illuminati", "Aliens", "Time travellers", "The Deep State"};
    char* verbs[] = {"is controlling", "manipulated", "invented", "altered", "concealed"};
    char* objects[] = {"the weather patterns", "our minds", "the economy", "the media", "vaccines", "the truth"};

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Here is your unique conspiracy theory:\n");

    for (int i = 0; i < 5; i++) {
        int rand_subject = rand() % 5;
        int rand_verb = rand() % 5;
        int rand_object1 = rand() % 6;
        int rand_object2 = rand() % 6;
        while (rand_object1 == rand_object2)
            rand_object2 = rand() % 6;

        printf("%s %s %s and %s %s.\n", subjects[rand_subject], verbs[rand_verb],
               objects[rand_object1], objects[rand_object2], verbs[rand_verb]);
    }
    return 0;
}