//FormAI DATASET v1.0 Category: Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2
#define MESSAGE_SIZE 100
#define KEY 3 // Caesar Cipher key

void* encrypt(void* arg);
void* decrypt(void* arg);

char message[MESSAGE_SIZE];
char encrypted_message[MESSAGE_SIZE];
char decrypted_message[MESSAGE_SIZE];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;

    printf("Enter a message to encrypt: ");
    fgets(message, MESSAGE_SIZE, stdin);

    rc = pthread_create(&threads[0], NULL, encrypt, NULL);
    if (rc) {
        fprintf(stderr, "Error creating encrypt thread.\n");
        return 1;
    }

    rc = pthread_create(&threads[1], NULL, decrypt, NULL);
    if (rc) {
        fprintf(stderr, "Error creating decrypt thread.\n");
        return 1;
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print original message, encrypted message, and decrypted message
    printf("Original message: %s", message);
    printf("Encrypted message: %s", encrypted_message);
    printf("Decrypted message: %s", decrypted_message);

    return 0;
}

void* encrypt(void* arg) {
    pthread_mutex_lock(&mutex); // lock mutex

    // Encrypt message using Caesar Cipher
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted_message[i] = (message[i] - 'a' + KEY) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted_message[i] = (message[i] - 'A' + KEY) % 26 + 'A';
        } else {
            encrypted_message[i] = message[i];
        }
    }

    pthread_cond_signal(&cond); // signal waiting thread
    pthread_mutex_unlock(&mutex); // unlock mutex

    pthread_exit(NULL);
}

void* decrypt(void* arg) {
    pthread_mutex_lock(&mutex); // lock mutex

    // Wait for signal from encrypt thread
    pthread_cond_wait(&cond, &mutex);

    // Decrypt message using Caesar Cipher
    for (int i = 0; encrypted_message[i] != '\0'; i++) {
        if (encrypted_message[i] >= 'a' && encrypted_message[i] <= 'z') {
            decrypted_message[i] = (encrypted_message[i] - 'a' - KEY + 26) % 26 + 'a';
        } else if (encrypted_message[i] >= 'A' && encrypted_message[i] <= 'Z') {
            decrypted_message[i] = (encrypted_message[i] - 'A' - KEY + 26) % 26 + 'A';
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    pthread_mutex_unlock(&mutex); // unlock mutex
    pthread_exit(NULL);
}