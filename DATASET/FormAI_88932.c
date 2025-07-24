//FormAI DATASET v1.0 Category: Date and time ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

pthread_mutex_t mutex;
struct tm *timeinfo;

void *print_time(void *arg) {
    time_t rawtime;
    char buffer[80];

    while (1) {
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        pthread_mutex_lock(&mutex);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
        printf("Current time: %s\n", buffer);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void *print_date(void *arg) {
    time_t rawtime;
    char buffer[80];

    while (1) {
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        pthread_mutex_lock(&mutex);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
        printf("Current date: %s\n", buffer);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t tid1, tid2;
    int ret1, ret2;

    pthread_mutex_init(&mutex, NULL);
    ret1 = pthread_create(&tid1, NULL, &print_time, NULL);
    ret2 = pthread_create(&tid2, NULL, &print_date, NULL);

    if (ret1 || ret2) {
        printf("Error creating threads\n");
        exit(1);
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_mutex_destroy(&mutex);

    return 0;
}