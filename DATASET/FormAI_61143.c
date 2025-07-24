//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_message(void* ptr);

int main() {
    pthread_t thread1, thread2;
    char* message1 = "Thread 1";
    char* message2 = "Thread 2";

    int thread1_status = pthread_create(&thread1, NULL, print_message, (void*)message1);
    if (thread1_status) {
        printf("ERROR - pthread_create for thread 1 return code: %d\n", thread1_status);
        exit(-1);
    }

    int thread2_status = pthread_create(&thread2, NULL, print_message, (void*)message2);
    if (thread2_status) {
        printf("ERROR - pthread_create for thread 2 return code: %d\n", thread2_status);
        exit(-1);
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Both threads have completed execution.\n");
    return 0;
}

void* print_message(void* ptr) {
    char* message = (char*)ptr;
    printf("%s is executing.\n", message);
    pthread_exit(NULL);
}