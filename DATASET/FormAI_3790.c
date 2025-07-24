//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t limit_cond = PTHREAD_COND_INITIALIZER;

int current_bandwidth = 0;
int max_bandwidth = 100;
int min_bandwidth = 0;

void *bandwidth_monitor(void *arg) {
    while (true) {
        srand(time(NULL));
        int bandwidth_change = rand() % 21 - 10;
        int new_bandwidth = current_bandwidth + bandwidth_change;
        if (new_bandwidth > max_bandwidth) {
            new_bandwidth = max_bandwidth;
        }
        if (new_bandwidth < min_bandwidth) {
            new_bandwidth = min_bandwidth;
        }
        pthread_mutex_lock(&mutex);
        current_bandwidth = new_bandwidth;
        printf("Current bandwidth: %d\n", current_bandwidth);
        if (current_bandwidth < 10) {
            printf("Warning: Network traffic is very low!\n");
        }
        if (current_bandwidth > 90) {
            printf("Warning: Network traffic is very high!\n");
        }
        pthread_cond_signal(&limit_cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void *user_feeback(void *arg) {
    while (true) {
        pthread_mutex_lock(&mutex);
        while (current_bandwidth < 10 || current_bandwidth > 90) {
            pthread_cond_wait(&limit_cond, &mutex);
        }
        printf("Network is stable. Continue working.\n");
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_t bandwidth_thread;
    pthread_t feedback_thread;
    pthread_create(&bandwidth_thread, NULL, bandwidth_monitor, NULL);
    pthread_create(&feedback_thread, NULL, user_feeback, NULL);
    pthread_join(bandwidth_thread, NULL);
    pthread_join(feedback_thread, NULL);
    return 0;
}