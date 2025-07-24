//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: irregular
#include <stdio.h>
#include <pthread.h>

void *hello(void* arg) {
    char *msg = (char*) arg;
    printf("%s\n", msg);
    return NULL;
}

int main() {
    pthread_t tid1, tid2;
    char *msg1 = "Hello";
    char *msg2 = "World";

    pthread_create(&tid1, NULL, hello, (void*) msg1);
    pthread_create(&tid2, NULL, hello, (void*) msg2);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Threads finished\n");
    return 0;
}