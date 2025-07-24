//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    pthread_mutex_t lock;
} shared_counter;

void init_shared_counter(shared_counter *counter, int starting_val) {
    counter->val = starting_val;
    pthread_mutex_init(&(counter->lock), NULL);
}

void increment_counter(shared_counter *counter) {
    pthread_mutex_lock(&(counter->lock));
    (counter->val)++;
    pthread_mutex_unlock(&(counter->lock));
}

void decrement_counter(shared_counter *counter) {
    pthread_mutex_lock(&(counter->lock));
    (counter->val)--;
    pthread_mutex_unlock(&(counter->lock));
}

void *thread_worker(void *arg) {
    shared_counter *counter = (shared_counter *) arg;
    int i;
    for (i = 0; i < 100000; i++) {
        increment_counter(counter);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    shared_counter my_counter;
    init_shared_counter(&my_counter, 0);

    pthread_create(&thread1, NULL, thread_worker, (void *) &my_counter);
    pthread_create(&thread2, NULL, thread_worker, (void *) &my_counter);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of counter: %d\n", my_counter.val);

    return 0;
}