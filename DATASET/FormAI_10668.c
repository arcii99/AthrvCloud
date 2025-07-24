//FormAI DATASET v1.0 Category: Modern Encryption ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MSG_LEN 10000
#define KEY_LEN 16

int main() {
    char message[MAX_MSG_LEN];
    char key[KEY_LEN];
    char encrypted[MAX_MSG_LEN];
    char decrypted[MAX_MSG_LEN];
    int i, j, rnd_num;

    // Set seed for random number generator
    srand(time(NULL));

    // Prompt user to enter message
    printf("Enter your message: ");
    fgets(message, MAX_MSG_LEN, stdin);

    // Generate random key
    for (i = 0; i < KEY_LEN; i++) {
        rnd_num = rand() % 26; // Generate random number between 0 and 25
        key[i] = 'A' + rnd_num; // Convert random number to uppercase letter
    }

    // Print generated key
    printf("Your encryption key is: %s\n", key);

    // Encrypt message using key
    for (i = 0, j = 0; i < strlen(message); i++, j++) {
        if (j == KEY_LEN) j = 0; // Loop through key if message is longer
        encrypted[i] = ((message[i] - 'A') + (key[j] - 'A')) % 26 + 'A'; // Encryption algorithm
    }

    encrypted[i] = '\0'; // Add null terminator to encrypted message

    // Print encrypted message
    printf("Your encrypted message is: %s\n", encrypted);

    // Decrypt message using key
    for (i = 0, j = 0; i < strlen(encrypted); i++, j++) {
        if (j == KEY_LEN) j = 0; // Loop through key if message is longer
        decrypted[i] = ((encrypted[i] - 'A') - (key[j] - 'A') + 26) % 26 + 'A'; // Decryption algorithm
    }

    decrypted[i] = '\0'; // Add null terminator to decrypted message

    // Print decrypted message
    printf("Your decrypted message is: %s\n", decrypted);

    return 0;
}