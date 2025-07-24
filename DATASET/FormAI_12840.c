//FormAI DATASET v1.0 Category: Smart home light control ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int light_status = 0;
pthread_mutex_t lock;

void* change_light(void* arg)
{
    while(1){
        pthread_mutex_lock(&lock);
        if(light_status == 0){
            light_status = 1;
            printf("Light has turned ON!\n");
        }
        else{
            light_status = 0;
            printf("Light has turned OFF!\n");
        }
        pthread_mutex_unlock(&lock);
        sleep(2);
    }
}

int main()
{
    pthread_t thread_id;
    
    // initialize mutex lock
    if(pthread_mutex_init(&lock, NULL) != 0){
        printf("Mutex initialization failed!\n");
        return 1;
    }
    
    // create thread
    if(pthread_create(&thread_id, NULL, &change_light, NULL) != 0){
        printf("Thread creation failed!\n");
        return 1;
    }
    
    // main thread
    while(1){
        pthread_mutex_lock(&lock);
        if(light_status == 0){
            printf("Light is currently OFF.\n");
        }
        else{
            printf("Light is currently ON.\n");
        }
        pthread_mutex_unlock(&lock);
        sleep(1);
    }

    // clean up mutex lock
    pthread_mutex_destroy(&lock);
    
    return 0;
}