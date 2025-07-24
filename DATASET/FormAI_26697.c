//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: distributed
// This C program scans for wireless network signals in a distributed style using threads and semaphores

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_DETECTION 10  // maximum number of detected networks

sem_t mutex;  // semaphore to synchronize access to shared resource
char detected_networks[MAX_DETECTION][30];  // array to store detected networks
int network_count = 0;  // count of detected networks

// function to scan for wireless network signals
void scan_for_networks() {
    // code to scan for wireless network signals goes here...
    // this code detects the network names and stores them in the array 'detected_networks'
    
    // simulate the detection of three networks
    usleep(1000);
    strcpy(detected_networks[0], "Guest Network");
    network_count++;
    usleep(1000);
    strcpy(detected_networks[1], "Office Network");
    network_count++;
    usleep(1000);
    strcpy(detected_networks[2], "Home Network");
    network_count++;
}

// function to print the detected networks
void print_detected_networks() {
    printf("Detected Networks:\n");
    for(int i=0; i<network_count; i++) {
        printf("%d. %s\n", i+1, detected_networks[i]);
    }
}

// function to run in the thread
void* thread_function(void* arg) {
    sem_wait(&mutex);
    scan_for_networks();
    sem_post(&mutex);
    return NULL;
}

int main() {
    sem_init(&mutex, 0, 1);  // initialize the semaphore
    
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    print_detected_networks();  // print the detected networks
    
    sem_destroy(&mutex);  // destroy the semaphore
    
    return 0;
}