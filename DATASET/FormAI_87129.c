//FormAI DATASET v1.0 Category: modern Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define THREADS_NUM 4
#define BUFFER_SIZE 256

char plainText[BUFFER_SIZE];
char encryptedText[BUFFER_SIZE];

/*encryption logic*/
void* encrypt(void* arg) {
    int threadID = *(int*)arg;

    /*encrypt using a unique key for each thread*/
    for (int i = threadID; i < strlen(plainText); i += THREADS_NUM) {
        encryptedText[i] = plainText[i] + threadID;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS_NUM];
    int threadIDs[THREADS_NUM];

    printf("Enter plain text to encrypt: ");
    fgets(plainText, BUFFER_SIZE, stdin);

    /*create threads and assign unique IDs to each thread*/
    for (int i = 0; i < THREADS_NUM; i++) {
        threadIDs[i] = i;
        if (pthread_create(&threads[i], NULL, encrypt, &threadIDs[i])) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    /*wait for all threads to finish*/
    for (int i = 0; i < THREADS_NUM; i++) {
        if (pthread_join(threads[i], NULL)) {
            fprintf(stderr, "Error joining thread\n");
            return 1;
        }
    }

    printf("Encrypted text: %s\n", encryptedText);

    return 0;
}