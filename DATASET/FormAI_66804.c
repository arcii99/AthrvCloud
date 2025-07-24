//FormAI DATASET v1.0 Category: Encryption ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

/* The maximum size of the input string */
#define MAX_SIZE 100

/* The encryption key */
#define ENCRYPTION_KEY 2

/* The input string */
char input[MAX_SIZE];

/* The encrypted string */
char encrypted[MAX_SIZE];

/* The encryption function */
void* encrypt(void* arg) {
    char* str = (char*) arg;
    int len = strlen(str);
    int i;

    for (i = 0; i < len; ++i) {
        encrypted[i] = str[i] + ENCRYPTION_KEY;
    }

    /* Null terminate the encrypted string */
    encrypted[i] = '\0';

    return NULL;
}

int main() {
    pthread_t thread;
    int result;

    /* Get user input */
    printf("Enter text to encrypt: ");
    fgets(input, MAX_SIZE, stdin);

    /* Remove trailing newline */
    input[strcspn(input, "\n")] = 0;

    /* Create the thread */
    result = pthread_create(&thread, NULL, &encrypt, input);
    if (result != 0) {
        printf("Error creating thread\n");
        return 1;
    }

    /* Wait for the thread to finish */
    pthread_join(thread, NULL);

    /* Print the encrypted string */
    printf("Encrypted: %s\n", encrypted);

    return 0;
}