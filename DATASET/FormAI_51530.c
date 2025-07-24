//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: funny
#include <stdio.h>
#include <pthread.h>

void* thread_fun(void* arg) {
    printf("I'm a thread running concurrently with the main function. Wheeee!\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_id;
    printf("Hello, I'm the main function. Let's create a thread!\n");
    int result = pthread_create(&thread_id, NULL, thread_fun, NULL);
    if (result == 0) {
        printf("Thread created successfully!\n");
    } else {
        printf("Oops, something went wrong while creating the thread. ABORT! ABORT!\n");
        return 1;
    }
    pthread_join(thread_id, NULL); // Wait for the thread to finish executing
    printf("Wow, that was awesome. I'm gonna go take a nap now. See you later, alligator!\n");
    return 0;
}