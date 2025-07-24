//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Welcome message
    printf("Greetings! I am Sherlock Holmes, the master of encryption.\n");
    printf("Please enter the text to be encrypted:\n");

    char message[1000];
    fgets(message, 1000, stdin);

    // Generate random key
    char key[1000] = "";
    for (int i = 0; i < strlen(message); i++) {
        char letter[2];
        letter[0] = (char) (rand() % 26 + 97);
        letter[1] = '\0';
        strcat(key, letter);
    }
    
    // Encrypt message
    char encrypted[1000];
    for (int i = 0; i < strlen(message); i++) {
        char letter[2];
        letter[0] = ((int) message[i] + (int) key[i]) % 26 + 97;
        letter[1] = '\0';
        strcat(encrypted, letter);
    }

    // Display encrypted message and key
    printf("\nYour message has been encrypted using my special algorithm!\n");
    printf("Encrypted message: %s\n", encrypted);
    printf("Encryption key: %s", key);

    return 0;
}