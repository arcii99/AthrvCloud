//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of bits that will be used for the encryption keys
#define NUM_BITS 16

// Define the maximum value of a key or message
#define MAX_VALUE ((1 << NUM_BITS) - 1)

// Define the number of keys that will be generated
#define NUM_KEYS 100

// Define the number of messages that will be encrypted
#define NUM_MESSAGES 10

// Define the encryption function
int encrypt(int message, int key)
{
    return message ^ key;
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Generate the encryption keys
    int keys[NUM_KEYS];
    for (int i = 0; i < NUM_KEYS; i++) {
        keys[i] = rand() % MAX_VALUE;
    }

    // Generate the messages to be encrypted
    int messages[NUM_MESSAGES];
    for (int i = 0; i < NUM_MESSAGES; i++) {
        messages[i] = rand() % MAX_VALUE;
    }

    // Encrypt the messages with each key
    for (int i = 0; i < NUM_KEYS; i++) {
        for (int j = 0; j < NUM_MESSAGES; j++) {
            int encrypted_message = encrypt(messages[j], keys[i]);
            printf("Key %d encrypts message %d to %d\n", keys[i], messages[j], encrypted_message);
        }
    }

    return 0;
}