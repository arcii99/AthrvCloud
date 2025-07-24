//FormAI DATASET v1.0 Category: Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LENGTH 1000

// encryption function
void encrypt(char* message, int key) {
   char ch;
   int i;
   for(i = 0; message[i] != '\0'; ++i) {
      ch = message[i];
      if(ch >= 'a' && ch <= 'z') {
         ch = ch + key;
         if(ch > 'z') {
            ch = ch - 'z' + 'a' - 1;
         }
         message[i] = ch;
      }
      else if(ch >= 'A' && ch <= 'Z') {
         ch = ch + key;
         if(ch > 'Z') {
            ch = ch - 'Z' + 'A' - 1;
         }
         message[i] = ch;
      }
   }
}

// decryption function
void decrypt(char* message, int key) {
   char ch;
   int i;
   for(i = 0; message[i] != '\0'; ++i) {
      ch = message[i];
      if(ch >= 'a' && ch <= 'z') {
         ch = ch - key;
         if(ch < 'a') {
            ch = ch + 'z' - 'a' + 1;
         }
         message[i] = ch;
      }
      else if(ch >= 'A' && ch <= 'Z') {
         ch = ch - key;
         if(ch < 'A') {
            ch = ch + 'Z' - 'A' + 1;
         }
         message[i] = ch;
      }
   }
}

// thread function to encrypt
void *encrypt_func(void *arg) {
    char *message = (char*)arg;
    printf("Original Message: %s\n", message);
    encrypt(message, 3);
    printf("Encrypted Message: %s\n", message);
}

// thread function to decrypt
void *decrypt_func(void *arg) {
    char *message = (char*)arg;
    printf("Encrypted Message: %s\n", message);
    decrypt(message, 3);
    printf("Decrypted Message: %s\n", message);
}

int main() {
    char message[MAX_LENGTH];

    printf("Enter a message to encrypt:\n");
    fgets(message, MAX_LENGTH, stdin);

    pthread_t threads[2];

    // create thread to encrypt message
    if (pthread_create(&threads[0], NULL, encrypt_func, (void *)message) != 0) {
        fprintf(stderr, "Error creating thread 1\n");
        return 1;
    }

    // create thread to decrypt message
    if (pthread_create(&threads[1], NULL, decrypt_func, (void *)message) != 0) {
        fprintf(stderr, "Error creating thread 2\n");
        return 1;
    }

    // wait for threads to finish
    if (pthread_join(threads[0], NULL) != 0) {
        fprintf(stderr, "Error joining thread 1\n");
        return 1;
    }
    if (pthread_join(threads[1], NULL) != 0) {
        fprintf(stderr, "Error joining thread 2\n");
        return 1;
    }

    return 0;
}