//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int redTimer = 5;
int yellowTimer = 2;
int greenTimer = 5;
int state = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *greenLight(void *arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        while(state != 0) pthread_cond_wait(&cond, &mutex);
        printf("Green Light is on\n");
        sleep(greenTimer);
        state = 1;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }
}

void *yellowLight(void *arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        while(state != 1) pthread_cond_wait(&cond, &mutex);
        printf("Yellow Light is on\n");
        sleep(yellowTimer);
        state = 2;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }
}

void *redLight(void *arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        while(state != 2) pthread_cond_wait(&cond, &mutex);
        printf("Red Light is on\n");
        sleep(redTimer);
        state = 0;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }
}

int main() {

    pthread_t greenThreadId, yellowThreadId, redThreadId;

    pthread_create(&greenThreadId, NULL, greenLight, NULL);
    pthread_create(&yellowThreadId, NULL, yellowLight, NULL);
    pthread_create(&redThreadId, NULL, redLight, NULL);

    pthread_join(greenThreadId, NULL);
    pthread_join(yellowThreadId, NULL);
    pthread_join(redThreadId, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}