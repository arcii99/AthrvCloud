//FormAI DATASET v1.0 Category: Task Scheduler ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define NUM_TASKS 5
#define NUM_THREADS 3

// Function prototypes
void *task(void *arg);
void schedule(int tid);

// Global variables
int task_queue[NUM_TASKS];
int task_queue_size = 0;
sem_t mutex, sem_task;

int main() {
    pthread_t threads[NUM_THREADS];
    int tids[NUM_THREADS];

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&sem_task, 0, 0);

    // Initialize the task queue
    srand(time(NULL));
    for (int i = 0; i < NUM_TASKS; i++) {
        task_queue[i] = rand() % 10 + 1;
        task_queue_size++;
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        tids[i] = i + 1;
        pthread_create(&threads[i], NULL, task, &tids[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&sem_task);

    return 0;
}

void *task(void *arg) {
    int tid = *((int *) arg);

    while (1) {
        // Wait for signal from scheduler
        sem_wait(&sem_task);

        // Acquire mutex lock
        sem_wait(&mutex);

        // Execute task
        schedule(tid);

        // Release mutex lock
        sem_post(&mutex);
    }
}

void schedule(int tid) {
    if (task_queue_size == 0) {
        printf("Thread %d: No tasks to execute. Terminating.\n", tid);
        pthread_exit(NULL);
    }

    // Get next task from queue
    int task_time = task_queue[0];
    for (int i = 0; i < task_queue_size - 1; i++) {
        task_queue[i] = task_queue[i+1];
    }
    task_queue_size--;

    // Execute task
    printf("Thread %d: Executing task for %d seconds.\n", tid, task_time);
    sleep(task_time);

    // Signal scheduler that task is complete
    printf("Thread %d: Task complete.\n", tid);
    sem_post(&sem_task);
}