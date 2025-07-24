//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int resources = 10;

void* thread_function(void* arg) {
    int id = *(int*)arg;
    while (resources > 0) {
        pthread_mutex_lock(&mutex);
        if (resources > 0) {
            printf("Thread %d is scavenging resources!\n", id);
            sleep(1);
            resources--;
            printf("Thread %d found a resource! Total resources left: %d\n", id, resources);   
        }
        pthread_mutex_unlock(&mutex);
    }
    printf("Thread %d is heading back to base\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int i;
    printf("The apocalypse has happened and resources are scarce.\n");
    printf("There are only %d resources left in the world.\n", resources);
    printf("A group of survivors set out to scavenge resources...\n");
    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All threads have returned to base with resources.\n");
    printf("The survivors have gathered enough resources to survive another day.\n");
    pthread_mutex_destroy(&mutex);
    return 0;
}