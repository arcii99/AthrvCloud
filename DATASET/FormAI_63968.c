//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: modular
#include <stdio.h>
#include <pthread.h>

void* task(void* arg) { // function to be run concurrently
    int num = *(int*) arg; // typecast argument to int*
    printf("Thread %d is running\n", num);
    pthread_exit(NULL); // exit thread
}

int main() {
    pthread_t threads[5]; // array of threads
    int args[5]; // array of arguments
    
    // create 5 threads and pass arguments
    for (int i = 0; i < 5; i++) {
        args[i] = i+1; // set argument for thread i
        pthread_create(&threads[i], NULL, task, &args[i]); // create thread i
    }
    
    // wait for all threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("All threads are done\n");
    return 0;
}