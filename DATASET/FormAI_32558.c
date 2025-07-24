//FormAI DATASET v1.0 Category: Robot movement control ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 3

int xPos = 0, yPos = 0, direction = 0;

pthread_mutex_t mutex;

void *movement(void *t) {
    int id = (int) t;
    while (true) {
        pthread_mutex_lock(&mutex);
        switch (direction) {
            case 0:
                xPos++;
                yPos++;
                break;
            case 1:
                xPos++;
                break;
            case 2:
                xPos++;
                yPos--;
                break;
            case 3:
                yPos--;
                break;
            case 4:
                xPos--;
                yPos--;
                break;
            case 5:
                xPos--;
                break;
            case 6:
                xPos--;
                yPos++;
                break;
            case 7:
                yPos++;
                break;
            default:
                break;
        }        
        printf("Robot %d position: (%d, %d)\n", id, xPos, yPos);
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *directions(void *t) {
    int id = (int) t;
    while (true) {
        pthread_mutex_lock(&mutex);
        direction = rand() % 8;
        printf("Robot %d direction: %d\n", id, direction);
        sleep(2);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, t;
    pthread_mutex_init(&mutex, NULL);

    for (t = 0; t < NUM_THREADS; t++) {
        if (t < 2) {
            rc = pthread_create(&threads[t], NULL, movement, (void *)t);
        } else {
            rc = pthread_create(&threads[t], NULL, directions, (void *)t);
        }
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);
}