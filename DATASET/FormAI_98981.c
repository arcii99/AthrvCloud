//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: multiplayer
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int count = 0;

void *car(void *arg) {
    pthread_mutex_lock(&mutex);
    count++;
    pthread_mutex_unlock(&mutex);
    printf("Car %d arrives at the traffic light\n", *(int *)arg);
    pthread_mutex_lock(&mutex);
    while (count != 4) {
        pthread_cond_wait(&cond, &mutex);
    }
    pthread_mutex_unlock(&mutex);
    printf("Car %d crosses the intersection\n", *(int *)arg);
    pthread_exit(NULL);
}

void *traffic_light(void *arg) {
    while (1) {
        printf("Green light\n");
        sleep(3);
        printf("Yellow light\n");
        sleep(1);
        printf("Red light\n");
        pthread_mutex_lock(&mutex);
        count = 0;
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t tid[5];
    int car_id[5];
    for (int i = 0; i < 5; i++) {
        car_id[i] = i + 1;
        pthread_create(&tid[i], NULL, car, &car_id[i]);
    }
    pthread_t traffic_light_tid;
    pthread_create(&traffic_light_tid, NULL, traffic_light, NULL);
    pthread_join(traffic_light_tid, NULL);
    for (int i = 0; i < 5; i++) {
        pthread_join(tid[i], NULL);
    }
    return 0;
}