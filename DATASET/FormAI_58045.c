//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void *generateConspiracy(void *arg);

int main(int argc, char *argv[]) {
    int numThreads = atoi(argv[1]);
    printf("%d threads generating random conspiracy theories...\n", numThreads);

    pthread_t threads[numThreads];
    int i;

    for (i = 0; i < numThreads; i++) {
        pthread_create(&threads[i], NULL, generateConspiracy, NULL);
    }

    for (i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *generateConspiracy(void *arg) {
    srand(time(NULL));
    char *subjects[] = {"Government", "Illuminati", "Aliens", "Big Pharma", "New World Order"};
    char *verbs[] = {"controls", "manipulates", "brainwashes", "poisons", "infiltrates"};
    char *objects[] = {"media", "education system", "weather", "food supply", "technology"};

    int subjIndex = rand() % 5;
    int verbIndex = rand() % 5;
    int objIndex = rand() % 5;

    printf("%s %s %s.\n", subjects[subjIndex], verbs[verbIndex], objects[objIndex]);

    pthread_exit(NULL);
}