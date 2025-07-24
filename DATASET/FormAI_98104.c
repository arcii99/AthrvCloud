//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int count;
} shared_data;

void *increment_count(void *data) {
    shared_data *sd = (shared_data *)data;
    for (int i = 0; i < 1000; i++) {
        sd->count++;
        printf("I'm incrementing the count, look at me go!\n");
    }
    pthread_exit(NULL);
}

int main() {
    shared_data sd = {0};

    printf("Starting up the threads...\n");

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, increment_count, (void *)&sd);
    pthread_create(&thread2, NULL, increment_count, (void *)&sd);

    printf("Threads started, time to do some work!\n");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("All done, final count is %d\n", sd.count);

    return 0;
}