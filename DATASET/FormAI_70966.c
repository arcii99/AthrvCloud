//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_msg(void *arg);

int main() {

    pthread_t thread_1, thread_2;
    char *msg_1 = "Thread 1 says hello!";
    char *msg_2 = "Thread 2 says goodbye!";

    // create thread 1
    if(pthread_create(&thread_1, NULL, print_msg, (void *)msg_1)) {
        fprintf(stderr, "Error creating thread 1.\n");
        return EXIT_FAILURE;
    }

    // create thread 2
    if(pthread_create(&thread_2, NULL, print_msg, (void *)msg_2)) {
        fprintf(stderr, "Error creating thread 2.\n");
        return EXIT_FAILURE;
    }

    // wait for threads to finish
    if(pthread_join(thread_1, NULL)) {
        fprintf(stderr, "Error joining thread 1.\n");
        return EXIT_FAILURE;
    }

    if(pthread_join(thread_2, NULL)) {
        fprintf(stderr, "Error joining thread 2.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void *print_msg(void *arg) {

    char *msg = (char *)arg;
    printf("%s\n", msg);
    pthread_exit(NULL);
}