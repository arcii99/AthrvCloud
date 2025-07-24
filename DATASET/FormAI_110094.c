//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define THREAD_COUNT 5
#define NUM_CONSPIRACIES 10

char *conspiracy_theories[] = {"The moon landing was faked.",
                               "The government controls the weather.",
                               "The Illuminati controls everything.",
                               "Aliens are real and the government is hiding it.",
                               "The earth is flat.",
                               "The Titanic was sunk on purpose.",
                               "9/11 was an inside job.",
                               "Chemtrails are poisoning us.",
                               "The government is hiding the cure for cancer.",
                               "The world will end in 2021."};

void* generate_conspiracy(void* arg) {
    int thread_num = *((int*) arg);
    srand(time(NULL) + thread_num);
    for (int i = 0; i < NUM_CONSPIRACIES; i++) {
        int r = rand() % 10;
        printf("Thread %d: %s\n", thread_num, conspiracy_theories[r]);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREAD_COUNT];
    int thread_args[THREAD_COUNT];
    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_args[i] = i + 1;
        int rc = pthread_create(&threads[i], NULL, generate_conspiracy, &thread_args[i]);
        if (rc) {
            printf("Error: Unable to create thread %d\n", i);
            exit(-1);
        }
    }
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}