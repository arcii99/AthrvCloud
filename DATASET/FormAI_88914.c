//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>

#define MAX_THREADS 10
#define MAX_EVENTS 100

int event_count = 0;
bool danger_detected = false;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* detect_intrusion(void* arg) {
    int event_num = *(int*) arg;
    srand(time(NULL) + event_num);
    while(!danger_detected) {
        int event = rand() % 5 + 1; // simulate events
        pthread_mutex_lock(&mutex);
        printf("Event #%d detected - ", event_count);
        if(event == 1 || event == 2 || event == 3) {
            printf("normal event\n");
        } else {
            printf("intrusion detected!!!\n");
            danger_detected = true;
        }
        event_count++;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    printf("Intrusion detected - alarm raised!\n");
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int events[MAX_EVENTS];
    for(int i = 0; i < MAX_EVENTS; i++) {
        events[i] = i;
    }
    for(int i = 0; i < MAX_THREADS; i++) {
        int rc = pthread_create(&threads[i], NULL, detect_intrusion, &events[rand() % MAX_EVENTS]);
        if(rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    for(int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All threads finished - exiting program\n");
    return 0;
}