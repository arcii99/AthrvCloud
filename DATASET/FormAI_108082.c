//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message(void *message) {
    char *msg = (char *) message;
    printf("%s\n", msg);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    char *msg1 = "Thread 1 says hello!";
    char *msg2 = "Thread 2 says goodbye!";

    pthread_create(&thread1, NULL, print_message, (void *) msg1);
    pthread_create(&thread2, NULL, print_message, (void *) msg2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}