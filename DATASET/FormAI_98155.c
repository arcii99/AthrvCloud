//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg){
    int *ptr = (int *)arg;
    printf("Hello from thread %d!\n", *ptr);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int thread1_id = 1, thread2_id = 2;
    printf("Let's say hello to some threads!\n");
    pthread_create(&thread1, NULL, thread_function, &thread1_id);
    pthread_create(&thread2, NULL, thread_function, &thread2_id);
    printf("Greetings from main thread!\n");
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Goodbye from all threads!\n");
    return 0;
}