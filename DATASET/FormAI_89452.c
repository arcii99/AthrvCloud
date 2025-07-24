//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_LOGS 500 // defining max number of logs to store
#define MAX_THREADS 4 // defining max number of threads for log processing

typedef struct logEntry {
    char source[50];
    char type[10];
    char message[200];
} logEntry;

typedef struct logQueue {
    logEntry logs[MAX_LOGS]; 
    int front, rear, size;
} logQueue;

logQueue q = { .front = -1, .rear = -1, .size = 0 };

pthread_mutex_t q_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t q_not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t q_not_empty = PTHREAD_COND_INITIALIZER;

bool is_queue_full() { return (q.size == MAX_LOGS); }
bool is_queue_empty() { return (q.size == 0); }

void enqueue(logEntry log) {
    if (is_queue_full()) return;
    if (q.front == -1) q.front = 0;
    q.rear = (q.rear + 1) % MAX_LOGS;
    q.logs[q.rear] = log;
    q.size++;
}

logEntry dequeue() {
    if (is_queue_empty()) {
        logEntry empty = { "", "", "" };
        return empty;
    }
    logEntry log = q.logs[q.front];
    q.front = (q.front + 1) % MAX_LOGS;
    q.size--;
    return log;
}

void* process_logs(void* ptr) {
    char* name = (char*) ptr;
    while (true) {
        pthread_mutex_lock(&q_mutex);
        while (is_queue_empty()) pthread_cond_wait(&q_not_empty, &q_mutex);
        logEntry log = dequeue();
        pthread_cond_signal(&q_not_full);
        pthread_mutex_unlock(&q_mutex);
        
        if (!strcmp(log.type, "warning")) {
            printf("[WARNING] [THREAD %s] %s from %s\n", name, log.message, log.source);
        } else if (!strcmp(log.type, "error")) {
            printf("[ERROR] [THREAD %s] %s from %s\n", name, log.message, log.source);
        } else {
            printf("[INFO] [THREAD %s] %s from %s\n", name, log.message, log.source);
        }
    }
    pthread_exit(NULL);
}

void* log_generator(void* ptr) {
    char* name = (char*) ptr;
    int i = 0;
    while (i < MAX_LOGS) {
        pthread_mutex_lock(&q_mutex);
        while (is_queue_full()) pthread_cond_wait(&q_not_full, &q_mutex);
        
        logEntry log;
        sprintf(log.source, "%s", name);
        if (i % 3 == 0) {
            sprintf(log.type, "warning");
            sprintf(log.message, "Warning message number %d from %s", i+1, name);
        } else if (i % 7 == 0) {
            sprintf(log.type, "error");
            sprintf(log.message, "Error message number %d from %s", i+1, name);
        } else {
            sprintf(log.type, "info");
            sprintf(log.message, "Info message number %d from %s", i+1, name);
        }
        enqueue(log);
        pthread_cond_signal(&q_not_empty);
        pthread_mutex_unlock(&q_mutex);
        
        i++;
        usleep(100000); // wait for 100ms before generating next log
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    char* names[MAX_THREADS] = { "Thread 1", "Thread 2", "Thread 3", "Thread 4" };
    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, process_logs, (void*) names[i]);
    }
    pthread_t generator;
    pthread_create(&generator, NULL, log_generator, (void*) "Logger");
    
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_join(generator, NULL);
    return 0;
}