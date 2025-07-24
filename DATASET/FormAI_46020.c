//FormAI DATASET v1.0 Category: System event logger ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_EVENTS 1000 // Maximum number of events that can be logged
#define NUM_THREADS 5 // Number of threads to be created

pthread_mutex_t mutex; // Mutex for synchronizing access to the event log

typedef struct {
    int id; // Event ID
    char timestamp[20]; // Timestamp of the event
    char message[100]; // Message describing the event
} Event;

Event event_log[MAX_EVENTS]; // Array to store the event log
int num_events = 0; // Current number of events in the log

void *event_logger(void *thread_id) {
    int *id = (int*) thread_id;
    while(1) {
        pthread_mutex_lock(&mutex);
        if(num_events < MAX_EVENTS) {
            Event new_event;
            new_event.id = num_events+1;

            // Generate timestamp
            time_t raw_time;
            struct tm* time_info;
            time(&raw_time);
            time_info = localtime(&raw_time);
            strftime(new_event.timestamp, 20, "%Y-%m-%d %H:%M:%S", time_info);

            // Get message from user input
            printf("Thread %d - Enter message for event %d: ", *id, new_event.id);
            fgets(new_event.message, 100, stdin);

            // Add new event to the log
            event_log[num_events] = new_event;
            num_events++;
        }
        pthread_mutex_unlock(&mutex);
        usleep(rand() % 1000000); // Random sleep time between 0 to 1000000 microseconds
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize mutex
    if(pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Mutex initialization failed.\n");
        return 1;
    }

    // Create threads
    for(int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i+1;
        if(pthread_create(&threads[i], NULL, event_logger, &thread_ids[i]) != 0){
            printf("Thread creation failed.\n");
            return 1;
        }
    }

    // Join threads
    for(int i = 0; i < NUM_THREADS; i++) {
        if(pthread_join(threads[i], NULL) != 0){
            printf("Thread join failed.\n");
            return 1;
        }
    }

    // Print event log
    printf("Event Log:\n");
    for(int i = 0; i < num_events; i++) {
        printf("ID: %d\tTimestamp: %s\tMessage: %s", event_log[i].id, event_log[i].timestamp, event_log[i].message);
    }

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}