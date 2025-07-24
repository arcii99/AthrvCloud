//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Claude Shannon
// Claude Shannon Style C Threading Library Implementation Example Program

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message(void *);

int main() {
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int ret1, ret2;

    // Creating threads
    ret1 = pthread_create(&thread1, NULL, print_message, (void *)message1);
    ret2 = pthread_create(&thread2, NULL, print_message, (void *)message2);

    if (ret1 || ret2) { // Error occurred while creating thread
        printf("Error: Unable to create thread\n");
        exit(EXIT_FAILURE);
    }

    // Joining threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Threads have completed\n");

    return 0;
}

// Thread function to print message
void *print_message(void *ptr) {
    char *message = (char *)ptr;
    int i;

    for (i = 0; i < 5; i++) {
        printf("%s #%d\n", message, i+1);
        sleep(1);
    }

    pthread_exit(NULL);
}