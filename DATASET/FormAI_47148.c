//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    int number;
    pthread_mutex_t lock;
} Counter;

void* increment(void* args) {
    Counter* counter = (Counter*) args;

    while (counter->number < 100) {
        pthread_mutex_lock(&counter->lock);
        counter->number++;
        printf("Increment Thread: %d\n", counter->number);
        sleep(1);
        pthread_mutex_unlock(&counter->lock);
    }

    pthread_exit(NULL);
}

void* decrement(void* args) {
    Counter* counter = (Counter*) args;

    while (counter->number > 0) {
        pthread_mutex_lock(&counter->lock);
        counter->number--;
        printf("Decrement Thread: %d\n", counter->number);
        sleep(1);
        pthread_mutex_unlock(&counter->lock);
    }

    pthread_exit(NULL);
}

int main() {
    Counter counter = {50, PTHREAD_MUTEX_INITIALIZER};

    pthread_t inc_tid, dec_tid;
    pthread_create(&inc_tid, NULL, increment, &counter);
    pthread_create(&dec_tid, NULL, decrement, &counter);

    pthread_join(inc_tid, NULL);
    pthread_join(dec_tid, NULL);

    return 0;
}