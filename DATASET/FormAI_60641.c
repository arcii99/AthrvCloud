//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: invasive
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *threadFunction(void *arg) {
    int *num = (int *) arg;
    printf("%d is the parameter of thread function.\n", *num);
    (*num)++;
    return (void *) num;
}

int main() {
    pthread_t thread;
    int param = 10;
    int *threadRetVal;

    if(pthread_create(&thread, NULL, threadFunction, &param)) {
        printf("Error creating thread.\n");
        exit(EXIT_FAILURE);
    }

    if(pthread_join(thread, (void **) &threadRetVal)) {
        printf("Error joining thread.\n");
        exit(EXIT_FAILURE);
    }

    printf("Returned value from thread function is %d\n", *threadRetVal);

    printf("Main program execution complete.\n");

    return EXIT_SUCCESS;
}