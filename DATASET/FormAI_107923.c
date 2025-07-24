//FormAI DATASET v1.0 Category: Hotel Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_ROOMS 10
#define NUM_THREADS 5

int rooms[NUM_ROOMS] = {0}; // 0 for empty, 1 for occupied
pthread_mutex_t mutex;

void *check_in(void *tid) {
    int *my_id = (int *) tid;
    int room_number = -1;

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < NUM_ROOMS; i++) {
        if (rooms[i] == 0) {
            rooms[i] = 1;
            room_number = i;
            break;
        }
    }
    pthread_mutex_unlock(&mutex);

    if (room_number == -1) {
        printf("Sorry, all rooms are occupied!\n");
    } else {
        printf("Guest %d has checked into Room %d.\n", *my_id, room_number + 1);
    }

    pthread_exit(0);
}

void *check_out(void *tid) {
    int *my_id = (int *) tid;
    int room_number = -1;

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < NUM_ROOMS; i++) {
        if (rooms[i] == 1) {
            rooms[i] = 0;
            room_number = i;
            break;
        }
    }
    pthread_mutex_unlock(&mutex);

    if (room_number == -1) {
        printf("Sorry, there are no rooms currently occupied!\n");
    } else {
        printf("Guest %d has checked out of Room %d.\n", *my_id, room_number + 1);
    }

    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        if (i % 2 == 0) {
            pthread_create(&threads[i], NULL, check_in, (void *) &thread_ids[i]);
        } else {
            pthread_create(&threads[i], NULL, check_out, (void *) &thread_ids[i]);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}