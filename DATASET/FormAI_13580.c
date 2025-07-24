//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

// Define the maximum number of bags 
#define MAX_BAGS 100 

// Define the maximum number of threads 
#define MAX_THREADS 5 

// Define the number of bags in the system 
int num_bags = 0;

// Define a mutex to lock/unlock the baggage handling system 
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 

// Define a condition variable to signal when the system is full 
pthread_cond_t system_full = PTHREAD_COND_INITIALIZER; 

// Define a condition variable to signal when the system is empty 
pthread_cond_t system_empty = PTHREAD_COND_INITIALIZER; 

// Function to add bags into the system 
void* add_bags(void* arg) 
{
    while(1) 
    {
        // Lock the mutex before adding bags 
        pthread_mutex_lock(&mutex); 
    
        // If there is no space, wait for the system to signal that it is full 
        while(num_bags == MAX_BAGS) 
        {
            pthread_cond_wait(&system_full, &mutex);
        }
    
        // Generate a random number of bags 
        int new_bags = rand() % 10 + 1;
        printf("New bags have arrived: %d\n", new_bags);
    
        // Add the bags to the system 
        num_bags += new_bags;
        
        // Signal that the system is no longer empty 
        pthread_cond_signal(&system_empty);
    
        // Unlock the mutex 
        pthread_mutex_unlock(&mutex);
        
        // Sleep for a random amount of time
        sleep((rand() % 5) + 1);
    }
}

// Function to remove bags from the system 
void* remove_bags(void* arg) 
{
    while(1) 
    {
        // Lock the mutex before removing bags 
        pthread_mutex_lock(&mutex); 
    
        // If there are no bags in the system, wait for the system to signal that it is no longer empty 
        while(num_bags == 0) 
        {
            pthread_cond_wait(&system_empty, &mutex);
        }
        
        // Generate a random number of bags to remove 
        int remove_bags = rand() % 5 + 1;
        
        // If there are fewer bags in the system than requested, only remove the number of bags that are available 
        if(remove_bags > num_bags) 
        {
            remove_bags = num_bags;
        }
    
        // Remove the bags from the system 
        num_bags -= remove_bags;
        printf("Bags removed from the system: %d\n", remove_bags);
        
        // Signal that the system is no longer full 
        pthread_cond_signal(&system_full);
    
        // Unlock the mutex 
        pthread_mutex_unlock(&mutex);
        
        // Sleep for a random amount of time
        sleep((rand() % 5) + 1);
    }
}

int main()
{
    // Define an array of threads
    pthread_t threads[MAX_THREADS];
  
    // Create the threads for adding and removing bags
    pthread_create(&threads[0], NULL, add_bags, NULL);
    pthread_create(&threads[1], NULL, remove_bags, NULL);
    
    // Wait for the threads to finish
    for(int i = 0; i < MAX_THREADS; i++) 
    {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}