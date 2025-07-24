//FormAI DATASET v1.0 Category: Data mining ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_DATA 100
#define MIN_SUPPORT 0.5

typedef struct {
    int data[MAX_DATA];
    int support;
} Itemset;

Itemset dataset[] = {
    {{1, 2, 3}, 6},
    {{1, 2, 4}, 4},
    {{1, 4, 5}, 5},
    {{2, 3, 4}, 3},
    {{2, 3, 5}, 6},
    {{3, 4, 5}, 4},
    {{1, 2}, 8},
    {{1, 3}, 7},
    {{1, 4}, 9},
    {{1, 5}, 7},
    {{2, 3}, 5},
    {{2, 4}, 8},
    {{2, 5}, 9},
    {{3, 4}, 3},
    {{3, 5}, 11},
    {{4, 5}, 9},
};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *find_frequent_items(void *args) {
    int thread_num = *(int *)args;
    int num_items = sizeof(dataset[0].data) / sizeof(dataset[0].data[0]);
    int num_sets = sizeof(dataset) / sizeof(dataset[0]);

    int freq_items[MAX_DATA] = {0};

    for (int i = thread_num; i < num_items; i += NUM_THREADS) {
        int count = 0;
        for (int j = 0; j < num_sets; j++) {
            if (dataset[j].data[i]) {
                count += dataset[j].support;
            }
        }
        if (count >= MIN_SUPPORT * num_sets) {
            freq_items[i] = 1;
        }
    }

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < num_items; ++i) {
        if (freq_items[i]) {
            printf("Thread %d: item %d has support count %d\n", thread_num, i, freq_items[i]);
        }
    }
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, find_frequent_items, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}