//FormAI DATASET v1.0 Category: modern Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define KEY_LENGTH 12 //Define the length of the encryption key
#define THREAD_NUM 4 //Define the number of threads to use

char plain_text[1024]; //Define character array for plain text
char encrypted_text[1024]; //Define character array for encrypted text
char decryption_key[KEY_LENGTH + 1]; //Define char array for decryption key

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //Declare a mutex lock

void *encrypt(void *arg) {
    int i;
    long id = (long) arg; //Get thread id
    int start = id * (sizeof(plain_text) / THREAD_NUM); //Calculate start position for encryption
    int end = (id + 1) * (sizeof(plain_text) / THREAD_NUM); //Calculate end position for encryption
    for (i = start; i < end; i++) {
        pthread_mutex_lock(&mutex); //Lock mutex to avoid race condition
        encrypted_text[i] = plain_text[i] ^ decryption_key[i % KEY_LENGTH]; //Encryption using XOR operation
        pthread_mutex_unlock(&mutex); //Unlock the mutex
    }
    pthread_exit(NULL); //Exit the thread
}

void *decrypt(void *arg) {
    int i;
    long id = (long) arg; //Get thread id
    int start = id * (sizeof(encrypted_text) / THREAD_NUM); //Calculate start position for decryption
    int end = (id + 1) * (sizeof(encrypted_text) / THREAD_NUM); //Calculate end position for decryption
    for (i = start; i < end; i++) {
        pthread_mutex_lock(&mutex); //Lock mutex to avoid race condition
        plain_text[i] = encrypted_text[i] ^ decryption_key[i % KEY_LENGTH]; //Decryption using XOR operation
        pthread_mutex_unlock(&mutex); //Unlock the mutex
    }
    pthread_exit(NULL); //Exit the thread
}

int main() {
    int i;
    pthread_t threads[THREAD_NUM];
    printf("Enter plain text: ");
    fgets(plain_text, sizeof(plain_text), stdin); //Get input from user
    printf("Enter encryption key: ");
    fgets(decryption_key, sizeof(decryption_key), stdin); //Get input from user
    printf("Plain text: %s", plain_text);
    for (i = 0; i < THREAD_NUM; i++) {
        //Create encryption threads
        if (pthread_create(&threads[i], NULL, encrypt, (void *) i)) {
            fprintf(stderr, "Error creating thread.\n");
            return 1; //Exit the program if thread could not be created
        }
    }
    for (i = 0; i < THREAD_NUM; i++) {
        pthread_join(threads[i], NULL); //Wait for all the encryption threads to complete
    }
    printf("Encrypted text: %s\n", encrypted_text);
    for (i = 0; i < THREAD_NUM; i++) {
        //Create decryption threads
        if (pthread_create(&threads[i], NULL, decrypt, (void *) i)) {
            fprintf(stderr, "Error creating thread.\n");
            return 1; //Exit the program if thread could not be created
        }
    }
    for (i = 0; i < THREAD_NUM; i++) {
        pthread_join(threads[i], NULL); //Wait for all the decryption threads to complete
    }
    printf("Decrypted text: %s\n", plain_text);
    return 0;
}