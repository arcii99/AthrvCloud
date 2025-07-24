//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_BAGS 10

struct baggage {
    int id;
    int weight;
};

struct conveyor_belt {
    int current_weight;
    int max_weight;
    int num_bags;
    struct baggage bags[NUM_BAGS];
    pthread_mutex_t mutex;
};

void *loader(void *arg);
void *unloader(void *arg);

int main() {
    int i;
    pthread_t thread_id[NUM_THREADS];
    struct conveyor_belt cb;
    cb.current_weight = 0;
    cb.max_weight = 1000;
    cb.num_bags = 0;
    pthread_mutex_init(&cb.mutex, NULL);
    for (i = 0; i < NUM_THREADS; i++) {
        if (i < NUM_THREADS/2) {
            pthread_create(&thread_id[i], NULL, loader, (void *)&cb);
        } else {
            pthread_create(&thread_id[i], NULL, unloader, (void *)&cb);
        }
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_id[i], NULL);
    }
    pthread_mutex_destroy(&cb.mutex);
    return 0;
}

void *loader(void *arg) {
    struct conveyor_belt *cb = (struct conveyor_belt *)arg;
    int i;
    for (i = 0; i < NUM_BAGS; i++) {
        struct baggage bag;
        bag.id = i+1;
        bag.weight = rand() % 100;
        pthread_mutex_lock(&cb->mutex);
        while ((cb->current_weight + bag.weight) > cb->max_weight) {
            pthread_mutex_unlock(&cb->mutex);
            printf("Loader %ld: Conveyor belt is full, waiting for space...\n",
                    pthread_self());
            sleep(rand() % 5);
            pthread_mutex_lock(&cb->mutex);
        }
        printf("Loader %ld: Loading bag %d, weight=%d, current_weight=%d\n",
                pthread_self(), bag.id, bag.weight, cb->current_weight);
        cb->bags[cb->num_bags] = bag;
        cb->num_bags++;
        cb->current_weight += bag.weight;
        pthread_mutex_unlock(&cb->mutex);
        sleep(rand() % 5);
    }
    printf("Loader %ld: Finished loading bags\n", pthread_self());
    pthread_exit(NULL);
}

void *unloader(void *arg) {
    struct conveyor_belt *cb = (struct conveyor_belt *)arg;
    int i;
    for (i = 0; i < NUM_BAGS; i++) {
        pthread_mutex_lock(&cb->mutex);
        while (cb->num_bags == 0) {
            pthread_mutex_unlock(&cb->mutex);
            printf("Unloader %ld: Conveyor belt is empty, waiting for bags...\n",
                    pthread_self());
            sleep(rand() % 5);
            pthread_mutex_lock(&cb->mutex);
        }
        struct baggage bag = cb->bags[cb->num_bags-1];
        printf("Unloader %ld: Unloading bag %d, weight=%d, current_weight=%d\n",
                pthread_self(), bag.id, bag.weight, cb->current_weight);
        cb->num_bags--;
        cb->current_weight -= bag.weight;
        pthread_mutex_unlock(&cb->mutex);
        sleep(rand() % 5);
    }
    printf("Unloader %ld: Finished unloading bags\n", pthread_self());
    pthread_exit(NULL);
}