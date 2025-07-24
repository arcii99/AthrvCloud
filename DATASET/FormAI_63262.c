//FormAI DATASET v1.0 Category: System event logger ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAX_LOGS 1000

typedef struct {
    char* event;
    char* timestamp;
} Log;

Log logs[MAX_LOGS];
pthread_mutex_t log_mutex = PTHREAD_MUTEX_INITIALIZER;
int log_index = 0;

// Logs an event with a given timestamp
void log_event(char* event, char* timestamp) {
    pthread_mutex_lock(&log_mutex);

    if (log_index >= MAX_LOGS) {
        printf("Log limit reached\n");
        return;
    }

    Log new_log;
    new_log.event = event;
    new_log.timestamp = timestamp;
    logs[log_index++] = new_log;

    pthread_mutex_unlock(&log_mutex);
}

// Thread function that logs events at random intervals
void* logger_thread(void* arg) {
    char* events[] = {"Event 1", "Event 2", "Event 3", "Event 4", "Event 5"};
    int event_count = 5;

    while (1) {
        int random_event = rand() % event_count;
        char timestamp[30];
        time_t current_time = time(NULL);
        strftime(timestamp, sizeof(timestamp), "%d-%m-%Y %T", localtime(&current_time));
        
        log_event(events[random_event], timestamp);
        sleep(rand() % 5);
    }

    return NULL;
}

// Displays all logged events
void display_logs() {
    pthread_mutex_lock(&log_mutex);

    if (log_index == 0) {
        printf("No logs to display\n");
    } else {
        printf("Logs:\n");
        for (int i = 0; i < log_index; i++) {
            printf("%s: %s\n", logs[i].timestamp, logs[i].event);
        }
    }

    pthread_mutex_unlock(&log_mutex);
}

int main() {
    pthread_t logger_tid;
    srand(time(NULL));
    int choice;

    pthread_create(&logger_tid, NULL, logger_thread, NULL);

    while (1) {
        printf("Enter choice:\n1. Display logs\n2. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                display_logs();
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}