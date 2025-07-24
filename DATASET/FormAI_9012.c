//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t threads[10]; // a maximum of 10 threads
int thread_counter = 0; // the number of threads created so far

void* print_hello(void* arg) {
    printf("Hello from thread %d!\n", (int)arg);
    pthread_exit(NULL); // exit the thread
}

int main() {
    while (1) { // keep creating threads forever
        if (thread_counter == 10) { // if all 10 threads are already created
            thread_counter = 0; // reset the thread counter
            sleep(5); // sleep for 5 seconds before creating new threads
        }
        pthread_create(&threads[thread_counter], NULL, print_hello, (void*)thread_counter);
        thread_counter++; // increment the thread counter
    }
    return 0;
}