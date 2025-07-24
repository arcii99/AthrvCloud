//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random number generator
    char* subjects[] = {"The Illuminati", "Big Pharma", "The Government", "Aliens", "The Vatican", "The Reptilians"};
    char* verbs[] = {"are controlling", "have infiltrated", "manipulate", "are behind"};
    char* objects[] = {"the media", "our thoughts", "the weather", "major events", "the economy"};

    int num_sentences = 10;
    printf("Random Conspiracy Theory Generator\n");
    printf("------------------------------\n");

    for(int i = 0; i < num_sentences; i++) {
        int sub_index = rand() % 6;
        int verb_index = rand() % 4;
        int obj_index = rand() % 5;

        char* sentence = malloc(strlen(subjects[sub_index]) + strlen(verbs[verb_index]) + strlen(objects[obj_index]) + 2);
        sprintf(sentence, "%s %s %s.", subjects[sub_index], verbs[verb_index], objects[obj_index]);

        printf("%d. %s\n", i+1, sentence);
        free(sentence);
    }

    return 0;
}