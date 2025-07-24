//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

char *subjects[] = {
    "the government",
    "aliens",
    "big pharma",
    "the illuminati",
    "the reptilian elite",
    "the deep state",
    "the new world order",
    "the globalists"
};

char *verbs[] = {
    "is hiding",
    "is manipulating",
    "is controlling",
    "is creating",
    "is sabotaging",
    "is covering up",
    "is engineering",
    "is brainwashing"
};

char *objects[] = {
    "the truth",
    "the cure for cancer",
    "the secrets of the universe",
    "mind control techniques",
    "our DNA",
    "the weather",
    "the economy",
    "the media"
};

void *generate_conspiracy(void *arg) {
    int thread_id = *((int*) arg);
    srand((unsigned) time(NULL) + thread_id);
    int r1 = rand() % 8;
    int r2 = rand() % 8;
    int r3 = rand() % 8;
    printf("Thread #%d: %s %s %s.\n", thread_id, subjects[r1], verbs[r2], objects[r3]);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];
    int thread_args[10];
    int i;

    for (i = 0; i < 10; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, generate_conspiracy, &thread_args[i]);
    }

    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}