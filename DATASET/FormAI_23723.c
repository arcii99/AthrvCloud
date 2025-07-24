//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// A function that adds two numbers
void *addition(void *arg) {
    int num1 = *((int*) arg);
    int num2 = *((int*) arg + 1);
    int sum = num1 + num2;
    printf("The sum is %d\n", sum);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    int nums[2] = {3, 5};
    printf("Starting the surreal C Threading Library example...\n");

    // Create a new thread to run the addition function
    if(pthread_create(&thread, NULL, addition, (void *)nums)) {
        printf("Error creating thread.\n");
        exit(EXIT_FAILURE);
    }

    // Wait for the thread to finish before continuing
    pthread_join(thread, NULL);

    printf("Program executed successfully.\n");

    return 0;
}