//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int id;
    char message[50];
} thread_info;

void* thread_function(void* arg) {
    thread_info* info = (thread_info*) arg;
    printf("Thread #%d: %s\n", info->id, info->message);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    thread_info info1 = {1, "Hello from thread 1!"};
    thread_info info2 = {2, "Greetings from thread 2!"};

    if (pthread_create(&thread1, NULL, thread_function, (void*) &info1)) {
        fprintf(stderr, "Error creating thread 1!\n");
        exit(1);
    }

    if (pthread_create(&thread2, NULL, thread_function, (void*) &info2)) {
        fprintf(stderr, "Error creating thread 2!\n");
        exit(1);
    }

    if (pthread_join(thread1, NULL)) {
        fprintf(stderr, "Error joining thread 1!\n");
        exit(1);
    }

    if (pthread_join(thread2, NULL)) {
        fprintf(stderr, "Error joining thread 2!\n");
        exit(1);
    }

    printf("All threads have completed their tasks!\n");

    return 0;
}