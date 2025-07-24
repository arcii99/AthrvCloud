//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    unsigned char* message;
    int size;
    unsigned char result;
} checksum_args;

void* calculate_checksum(void* args) {
    checksum_args* cargs = (checksum_args*)args;
    unsigned char checksum = 0;
    for (int i = 0; i < cargs->size; i++) {
        checksum += cargs->message[i];
    }
    cargs->result = checksum;
    return NULL;
}

int main() {
    unsigned char* message1 = "Hello World!";
    int size1 = sizeof(message1) / sizeof(unsigned char);

    unsigned char* message2 = "Multi-threading is fun!";
    int size2 = sizeof(message2) / sizeof(unsigned char);

    checksum_args args1 = {message1, size1, 0};
    checksum_args args2 = {message2, size2, 0};

    pthread_t thread1;
    pthread_create(&thread1, NULL, calculate_checksum, &args1);
    pthread_t thread2;
    pthread_create(&thread2, NULL, calculate_checksum, &args2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Checksum of message1 is: %d\n", args1.result);
    printf("Checksum of message2 is: %d\n", args2.result);

    return 0;
}