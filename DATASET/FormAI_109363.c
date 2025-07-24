//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global Variables
pthread_mutex_t mutex;
int wifi_strength = 0;
int wifi_count = 0;

// Function to calculate wifi strength
void* calculate_strength(void* arg){
    int signal_strength = rand() % 101; // Generate random signal strength
    pthread_mutex_lock(&mutex); // Start critical section
    wifi_strength += signal_strength;
    wifi_count++;
    printf("Wifi signal strength: %d\n", signal_strength);
    pthread_mutex_unlock(&mutex); // End critical section
    pthread_exit(NULL);
}

int main()
{
    pthread_t tid[5]; // Creating thread ids
    
    if (pthread_mutex_init(&mutex, NULL) != 0) // Initializing mutex
    {
        printf("Mutex initialization failed.\n");
        return 1;
    }
    
    for(int i=0; i<5; i++){
        pthread_create(&tid[i], NULL, calculate_strength, NULL); // Creating threads
    }
    
    for(int i=0; i<5; i++){
        pthread_join(tid[i], NULL); // Joining threads
    }
    
    printf("Total number of wifi signals: %d\n", wifi_count);
    printf("Average wifi signal strength: %d\n", wifi_strength/wifi_count);
    
    pthread_mutex_destroy(&mutex); // Destroying mutex
    
    return 0;
}