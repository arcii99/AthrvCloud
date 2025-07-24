//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_ROOMS 10
#define MAX_THREADS 5

bool isHaunted = false;
int currentRoom = 1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *visitor(void *arg) {
    while (true) {
        pthread_mutex_lock(&mutex);
        while (isHaunted || currentRoom == MAX_ROOMS) {
            pthread_cond_wait(&cond, &mutex);
        }
        currentRoom++;
        if (currentRoom == MAX_ROOMS) {
            printf("Visitor %s has escaped the haunted house!\n", (char *) arg);
        } else {
            printf("Visitor %s has entered room %d\n", (char *) arg, currentRoom);
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void *ghost(void *arg) {
    while (true) {
        pthread_mutex_lock(&mutex);
        if (currentRoom > 1) {
            isHaunted = true;
            currentRoom--;
            printf("Ghost has haunted room %d\n", currentRoom);
            pthread_cond_broadcast(&cond);
            pthread_mutex_unlock(&mutex);
            sleep(2);
            isHaunted = false;
        } else {
            pthread_mutex_unlock(&mutex);
            sleep(1);
        }
    }
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    char *visitorNames[MAX_THREADS] = {"Samantha", "John", "Michael", "Emily", "Rachel"};
    for (int i = 0; i < MAX_THREADS - 1; i++) {
        pthread_create(&threads[i], NULL, visitor, visitorNames[i]);
    }
    pthread_create(&threads[MAX_THREADS - 1], NULL, ghost, NULL);
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}