//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

struct traffic_light {
    int status;
    pthread_cond_t cond;
    pthread_mutex_t mutex;
};

void *green_light(void *arg);
void *yellow_light(void *arg);
void *red_light(void *arg);

int main() {
    struct traffic_light green = { GREEN, PTHREAD_COND_INITIALIZER, PTHREAD_MUTEX_INITIALIZER };
    struct traffic_light yellow = { YELLOW, PTHREAD_COND_INITIALIZER, PTHREAD_MUTEX_INITIALIZER };
    struct traffic_light red = { RED, PTHREAD_COND_INITIALIZER, PTHREAD_MUTEX_INITIALIZER };

    pthread_t green_thread, yellow_thread, red_thread;
    pthread_create(&green_thread, NULL, green_light, (void *)&green);
    pthread_create(&yellow_thread, NULL, yellow_light, (void *)&yellow);
    pthread_create(&red_thread, NULL, red_light, (void *)&red);

    pthread_join(green_thread, NULL);
    pthread_join(yellow_thread, NULL);
    pthread_join(red_thread, NULL);

    return 0;
}

void *green_light(void *arg) {
    struct traffic_light *light = (struct traffic_light *)arg;
    while(1) {
        pthread_mutex_lock(&light->mutex);
        printf("*** GREEN LIGHT ON ***\n");
        fflush(stdout);
        pthread_cond_wait(&light->cond, &light->mutex);
        pthread_mutex_unlock(&light->mutex);
    }
    pthread_exit(NULL);
}

void *yellow_light(void *arg) {
    struct traffic_light *light = (struct traffic_light *)arg;

    while(1) {
        pthread_mutex_lock(&light->mutex);
        printf("--- YELLOW LIGHT ON ---\n");
        fflush(stdout);
        sleep(3);
        light->status = RED;
        printf("!!! YELLOW LIGHT OFF !!!\n");
        printf("*** RED LIGHT ON ***\n");
        fflush(stdout);
        pthread_cond_broadcast(&light->cond);
        pthread_mutex_unlock(&light->mutex);
        sleep(2);
    }
    pthread_exit(NULL);
}

void *red_light(void *arg) {
    struct traffic_light *light = (struct traffic_light *)arg;

    while(1) {
        pthread_mutex_lock(&light->mutex);
        printf("### RED LIGHT ON ###\n");
        fflush(stdout);
        sleep(5);
        light->status = GREEN;
        printf("!!! RED LIGHT OFF !!!\n");
        printf("*** GREEN LIGHT ON ***\n");
        fflush(stdout);
        pthread_cond_broadcast(&light->cond);
        pthread_mutex_unlock(&light->mutex);
        sleep(2);
    }
    pthread_exit(NULL);
}