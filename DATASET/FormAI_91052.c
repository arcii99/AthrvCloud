//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;
int sharedVariable = 0;

void *threadFunction(void *arg) {
    int threadID = *(int*)arg;
    for(int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        sharedVariable++;
        printf("Thread %d: Shared Variable = %d\n", threadID, sharedVariable);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t threads[2];
    int threadID[2];
    pthread_mutex_init(&mutex, NULL);
    for(int i = 0; i < 2; i++) {
        threadID[i] = i;
        if(pthread_create(&threads[i], NULL, threadFunction, &threadID[i]) != 0) {
            printf("Error: Thread %d not created.\n", i);
            exit(1);
        }
    }
    for(int i = 0; i < 2; i++) {
        if(pthread_join(threads[i], NULL) != 0) {
            printf("Error: Thread %d did not terminate.\n", i);
            exit(1);
        }
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}