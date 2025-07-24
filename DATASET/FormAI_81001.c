//FormAI DATASET v1.0 Category: Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
char message[BUFFER_SIZE];
char encrypted_message[BUFFER_SIZE];

void* encrypt(void* arg) {
    char* str = (char*) arg;
    int length = strlen(str);

    for (int i = 0; str[i] != '\0'; ++i) {
        encrypted_message[i] = str[i] + 3;
    }

    printf("The encrypted message is: %s\n", encrypted_message);
    return NULL;
}

int main() {
    pthread_t tid;
    printf("Enter a message to encrypt: ");
    fgets(message, BUFFER_SIZE, stdin);

    pthread_create(&tid, NULL, &encrypt, message);
    pthread_join(tid, NULL);

    return 0;
}