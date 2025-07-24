//FormAI DATASET v1.0 Category: Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);

int main() {
    pthread_t thread1, thread2;   
   
    int s1 = pthread_create(&thread1, NULL, thread_function, (void *) "Thread 1");
    if (s1 != 0) {
        fprintf(stderr, "Error creating thread: %d\n", s1);
        exit(EXIT_FAILURE);
    }
    
    int s2 = pthread_create(&thread2, NULL, thread_function, (void *) "Thread 2");
    if (s2 != 0) {
        fprintf(stderr, "Error creating thread: %d\n", s2);
        exit(EXIT_FAILURE);
    }
    
    printf("Main thread waiting for threads to finish...\n");
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("All threads finished. Exiting program.\n");
    
    return 0;
}

void *thread_function(void *arg) {
    char *thread_name = (char *) arg;
    int i;
    
    for (i = 0; i < 10; i++) {
        printf("%s: %d\n", thread_name, i);
        sleep(1);
    }
    
    pthread_exit(NULL);
}