//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_LENGTH 1000 // Maximum length of the message

// Function to encrypt the message
void* encrypt(void* arg) {
    char* message = (char*) arg; // Casting the argument to a char pointer
    int shift = 3; // Shift value for encryption

    for (int i = 0; message[i] != '\0'; ++i) {
        // For each character in the message
        if (message[i] >= 'A' && message[i] <= 'Z') {
            // If the character is uppercase
            message[i] = (message[i] + shift - 'A') % 26 + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            // If the character is lowercase
            message[i] = (message[i] + shift - 'a') % 26 + 'a';
        }
    }

    return NULL; // Doesn't return anything
}

int main() {
    char message[MAX_LENGTH]; // Message to be encrypted
    pthread_t thread; // Thread id
    int status; // Status code for thread join

    printf("Enter the message to be encrypted: ");
    fgets(message, MAX_LENGTH, stdin); // Get the input message
    
    // Create the thread to encrypt the message
    status = pthread_create(&thread, NULL, encrypt, (void*) message);
    if (status != 0) {
        printf("Error: Unable to create thread.\n");
        exit(1); // Terminate the program with an error
    }

    // Wait for the thread to complete
    status = pthread_join(thread, NULL);
    if (status != 0) {
        printf("Error: Unable to join thread.\n");
        exit(1); // Terminate the program with an error
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0; // Terminate the program successfully
}