//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* subjects[] = {"Government", "Illuminati", "Aliens", "Big Pharma", "Media", "Bankers", "Globalists", "Reptilians"};
char* verbs[] = {"control", "manipulate", "brainwash", "experiment on", "haunt", "corrupt", "enslave", "destroy"};
char* objects[] = {"the population", "the environment", "the economy", "our minds", "technology", "the future"};

char* generate_conspiracy_theory() {
    int s = rand() % 8;
    int v = rand() % 8;
    int o = rand() % 6;

    char* theory = (char*)malloc(100 * sizeof(char));
    sprintf(theory, "%s %s %s", subjects[s], verbs[v], objects[o]);
    return theory;
}

int main() {
    srand(time(NULL));
    printf("Here are five conspiracy theories generated randomly:\n");

    for(int i=0; i<5; i++) {
        char* theory = generate_conspiracy_theory();
        printf("%d. %s\n", i+1, theory);
        free(theory);
    }

    return 0;
}