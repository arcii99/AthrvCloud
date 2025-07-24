//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LENGTH 256
#define NUM_THREADS 4

char alien_language[MAX_LENGTH];
char translation[MAX_LENGTH];

void *translate(void *tid) {
    long id = (long) tid;
    int start = id * (strlen(alien_language) / NUM_THREADS);
    int end = (id + 1) * (strlen(alien_language) / NUM_THREADS);
    int i;
    for (i = start; i < end; i++) {
        if (alien_language[i] == '1') {
            translation[i] = 'a';
        } else if (alien_language[i] == '2') {
            translation[i] = 'b';
        } else if (alien_language[i] == '3') {
            translation[i] = 'c';
        } else {
            // default translation
            translation[i] = alien_language[i];
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, t;
    long tid;

    printf("Enter an alien language string (using 1, 2, 3): ");
    fgets(alien_language, MAX_LENGTH, stdin);
    alien_language[strcspn(alien_language, "\n")] = 0;

    // create threads
    for (tid = 0; tid < NUM_THREADS; tid++) {
        rc = pthread_create(&threads[tid], NULL, translate, (void *) tid);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // wait for threads to finish
    for (tid = 0; tid < NUM_THREADS; tid++) {
        rc = pthread_join(threads[tid], NULL);
        if (rc) {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    printf("Translation: %s\n", translation);

    pthread_exit(NULL);
}