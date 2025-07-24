//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: secure
#include <stdio.h>  
#include <stdlib.h> 
#include <pthread.h> 

pthread_mutex_t mutex;     //Global mutex variable

void* thread_function(void* arg) {  
    pthread_mutex_lock(&mutex);           //Locking mutex
    printf("Thread executing\n"); 
    pthread_mutex_unlock(&mutex);         //Unlocking mutex
    return NULL;  
}  

int main() {
    if (pthread_mutex_init(&mutex, NULL) != 0) {     //Mutex initialization, returns error on failure
        printf("Mutex initialization failed.\n");
        return 1;
    }
    int no_of_threads = 5;
    pthread_t ids[no_of_threads];       //Thread id array
    int i;
    for (i = 0; i < no_of_threads; i++) {
        if (pthread_create(&ids[i], NULL, thread_function, NULL) != 0) {        //Thread creation, returns error on failure
            printf("Thread creation failed [%d].\n", i);
            return 1;
        }
    }
    for (i = 0; i < no_of_threads; i++) {
        if (pthread_join(ids[i], NULL) != 0) {       //Thread join, returns error on failure
            printf("Thread join failed [%d].\n", i);
            return 1;
        }
    }
    printf("All threads executed.\n");
    pthread_mutex_destroy(&mutex);      //Destroying mutex
    return 0;
}