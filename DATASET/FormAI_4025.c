//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int ram_usage = 0;
pthread_mutex_t lock;

void update_ram_usage(int value){
    pthread_mutex_lock(&lock);
    ram_usage += value;
    pthread_mutex_unlock(&lock);
}

void* monitor_ram_usage(void* arg){
    while(1){
        printf("RAM Usage: %d\n", ram_usage);
        sleep(1);
    }
}

void* random_ram_usage(void* arg){
    int min = 5;
    int max = 20;

    while(1){
        int value = (rand() % (max - min + 1)) + min;
        update_ram_usage(value);
        sleep(2);
    }
}

int main(){
    pthread_t monitor_thread;
    pthread_t random_thread_1, random_thread_2;

    srand(time(NULL));
    pthread_mutex_init(&lock, NULL);

    // Create monitor thread to continuously monitor RAM usage
    if(pthread_create(&monitor_thread, NULL, monitor_ram_usage, NULL)){
        printf("Error: monitor_thread could not be created\n");
        return 1;
    }

    // Create random threads to simulate random RAM usage
    if(pthread_create(&random_thread_1, NULL, random_ram_usage, NULL)){
        printf("Error: random_thread_1 could not be created\n");
        return 1;
    }

    if(pthread_create(&random_thread_2, NULL, random_ram_usage, NULL)){
        printf("Error: random_thread_2 could not be created\n");
        return 1;
    }

    // Join threads
    pthread_join(monitor_thread, NULL);
    pthread_join(random_thread_1, NULL);
    pthread_join(random_thread_2, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}