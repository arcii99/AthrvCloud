//FormAI DATASET v1.0 Category: System administration ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* memory_management(void* arg);
void* disk_management(void* arg);
void* network_management(void* arg);

int main()
{
    int num_threads = 3;
    pthread_t tid[num_threads];
    int thread_args[num_threads];

    // Create threads for each management task
    for(int i = 0; i < num_threads; i++) {
        thread_args[i] = i;
        if(pthread_create(&tid[i], NULL, &memory_management, &thread_args[i]) != 0) {
            printf("Error creating thread for memory management\n");
            exit(EXIT_FAILURE);
        }
    }

    for(int i = 0; i < num_threads; i++) {
        if(pthread_join(tid[i], NULL) != 0) {
            printf("Error joining thread for memory management\n");
            exit(EXIT_FAILURE);
        }
    }

    // Create threads for disk management
    for(int i = 0; i < num_threads; i++) {
        thread_args[i] = i;
        if(pthread_create(&tid[i], NULL, &disk_management, &thread_args[i]) != 0) {
            printf("Error creating thread for disk management\n");
            exit(EXIT_FAILURE);
        }
    }

    for(int i = 0; i < num_threads; i++) {
        if(pthread_join(tid[i], NULL) != 0) {
            printf("Error joining thread for disk management\n");
            exit(EXIT_FAILURE);
        }
    }

    // Create threads for network management
    for(int i = 0; i < num_threads; i++) {
        thread_args[i] = i;
        if(pthread_create(&tid[i], NULL, &network_management, &thread_args[i]) != 0) {
            printf("Error creating thread for network management\n");
            exit(EXIT_FAILURE);
        }
    }

    for(int i = 0; i < num_threads; i++) {
        if(pthread_join(tid[i], NULL) != 0) {
            printf("Error joining thread for network management\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("All system administration tasks completed successfully\n");

    return 0;
}

void* memory_management(void* arg)
{
    int task_id = *(int*) arg;
    printf("Started memory management task %d\n", task_id);

    // Code for memory management task goes here
    sleep(2);

    printf("Completed memory management task %d\n", task_id);
    pthread_exit(NULL);
}

void* disk_management(void* arg)
{
    int task_id = *(int*) arg;
    printf("Started disk management task %d\n", task_id);

    // Code for disk management task goes here
    sleep(3);

    printf("Completed disk management task %d\n", task_id);
    pthread_exit(NULL);
}

void* network_management(void* arg)
{
    int task_id = *(int*) arg;
    printf("Started network management task %d\n", task_id);

    // Code for network management task goes here
    sleep(1);

    printf("Completed network management task %d\n", task_id);
    pthread_exit(NULL);
}