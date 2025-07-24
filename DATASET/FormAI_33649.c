//FormAI DATASET v1.0 Category: Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to Encrypt the given String with Statistical Encryption 
void encrypt(char* message, int key) {
    int length = strlen(message);
    // Generate the random seed using the current time
    srand((unsigned) time(NULL));
    // Generate a random number between 0-25
    int offset = rand() % 25;

    // Iterate through each character in the message and encrypt using the statistical encryption method
    for(int i = 0; i < length; i++) {
        // Only encrypt if the character is an alphabet
        if(isalpha(message[i])) {
            // Convert the character to its ASCII value
            int value = (int) message[i];
            // Calculate the encrypted value using the statistical encryption formula
            int encrypted_value = ((value - 65 + offset + key) % 26) + 65;
            // Convert the encrypted value back to a character and replace the original character in the message
            message[i] = (char) encrypted_value;
        }
    }
}

int main() {
    // Input the message and key from the user
    char message[100];
    int key;
    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the encryption key: ");
    scanf("%d", &key);
    // Remove the newline character from the message string
    message[strcspn(message, "\n")] = 0;

    // Call the encrypt function to encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s", message);

    return 0;
}