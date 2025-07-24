//FormAI DATASET v1.0 Category: Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 1000

void encrypt(char *msg, int key) {
    int len = strlen(msg);
    for(int i = 0; i < len; i++) {
        msg[i] = ((msg[i] - 'A' + key) % 26) + 'A';
    }
}

void *encryptBuffer(void *arg) {
    char *buffer = (char *)arg;
    encrypt(buffer, 3);
    pthread_exit(NULL);
}

int main() {
    char message[] = "HELLO WORLD!";
    pthread_t encrypt_thread;
    int rc;

    rc = pthread_create(&encrypt_thread, NULL, encryptBuffer, message);
    if(rc) {
        printf("Error creating thread; return code from pthread_create() is %d\n", rc);
        exit(EXIT_FAILURE);
    }

    pthread_join(encrypt_thread, NULL);

    printf("Encrypted message: %s\n", message);

    return 0;
}