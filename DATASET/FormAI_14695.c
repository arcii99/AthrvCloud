//FormAI DATASET v1.0 Category: Smart home light control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
int light = 0; //Global variable for light state
 
pthread_mutex_t mutex; //Mutex to synchronize access to the light state
 
void *turnOnLight(void *arg)
{
    pthread_mutex_lock(&mutex); //Acquire lock on mutex
    if(light == 0)
    {
        light = 1; //Turn light on
        printf("Light turned on.\n");
    }
    else
    {
        printf("Light is already on.\n");
    }
    pthread_mutex_unlock(&mutex); //Release lock on mutex
    return NULL;
}
 
void *turnOffLight(void *arg)
{
    pthread_mutex_lock(&mutex); //Acquire lock on mutex
    if(light == 1)
    {
        light = 0; //Turn light off
        printf("Light turned off.\n");
    }
    else
    {
        printf("Light is already off.\n");
    }
    pthread_mutex_unlock(&mutex); //Release lock on mutex
    return NULL;
}
 
int main()
{
    pthread_t tid1, tid2;
 
    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);
 
    // Create threads to control the light
    pthread_create(&tid1, NULL, turnOnLight, NULL);
    pthread_create(&tid2, NULL, turnOffLight, NULL);
 
    //Wait for each thread to finish
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
    // Destroy the mutex
    pthread_mutex_destroy(&mutex);
     
    return 0;
}