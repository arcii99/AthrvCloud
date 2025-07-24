//FormAI DATASET v1.0 Category: Task Scheduler ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_TASKS 10
#define MAX_THREADS 5

typedef struct {
    int task_id;
    char *task_name;
} Task;

Task task_array[MAX_TASKS];
int next_task_index = 0;

pthread_mutex_t task_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;

void *task_handler(void *arg)
{
    Task *task = (Task *)arg;
    
    pthread_mutex_lock(&print_mutex);
    printf("Task %d started: %s\n", task->task_id, task->task_name);
    pthread_mutex_unlock(&print_mutex);
    
    // Do some work here
    sleep(rand() % 5);
    
    pthread_mutex_lock(&print_mutex);
    printf("Task %d finished: %s\n", task->task_id, task->task_name);
    pthread_mutex_unlock(&print_mutex);
    
    return NULL;
}

void *scheduler(void *arg)
{
    for (;;) {
        pthread_mutex_lock(&task_mutex);
        
        if (next_task_index < MAX_TASKS) {
            Task *task = &task_array[next_task_index++];
            pthread_mutex_unlock(&task_mutex);
            
            pthread_t thread;
            pthread_create(&thread, NULL, task_handler, task);
            pthread_detach(thread);
        } else {
            pthread_mutex_unlock(&task_mutex);
            sleep(1);
        }
    }
    
    return NULL;
}

int main()
{
    // Initialize tasks
    for (int i = 0; i < MAX_TASKS; i++) {
        task_array[i].task_id = i + 1;
        task_array[i].task_name = "Sample Task";
    }
    
    // Start scheduler threads
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, scheduler, NULL);
    }
    
    // Wait for threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}