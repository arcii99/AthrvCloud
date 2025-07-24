//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

float temperature = 20.0;

void* readTemperature(void* arg) {
    while(1) {
        printf("Current temperature: %.2f C\n", temperature);
        sleep(2);
    }
}

void* monitorTemperature(void* arg) {
    while(1) {
        temperature += (float)(rand() % 5) / 10.0;
        sleep(1);
    }
}

int main() {
    pthread_t thread1, thread2;
    
    if(pthread_create(&thread1, NULL, readTemperature, NULL) != 0) {
        perror("Error: Failed to create thread1");
        exit(1);
    }
    
    if(pthread_create(&thread2, NULL, monitorTemperature, NULL) != 0) {
        perror("Error: Failed to create thread2");
        exit(1);
    }
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    return 0;
}