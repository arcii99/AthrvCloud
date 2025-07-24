//FormAI DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
#include <string.h>

void encrypt(char *plaintext, int key) {
    // Add key to each character in the plaintext
    int i;
    for(i = 0; i < strlen(plaintext); i++) {
        plaintext[i] += key;
    }
}

int main() {
    char message[] = "Why do programmers prefer dark mode? Because light attracts bugs.";

    printf("Original message: %s\n", message);

    int key = 13; // Best encryption key ever!
    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    char response[10];

    printf("Would you like to decrypt the message? (y/n)\n");
    scanf("%s", response);

    if(strcmp(response, "y") ==0 || strcmp(response, "Y") == 0) {
        // Time to decrypt the message
        printf("Enter the key to decrypt the message:\n");
        int decrypt_key;
        scanf("%d", &decrypt_key);

        if(decrypt_key == key) {
            encrypt(message, -decrypt_key);
            printf("Decrypted message: %s\n", message);
        } else {
            printf("You have entered the wrong key! This message will self-destruct in 10 seconds...\n");
            sleep(10);
            printf("Boom! Just kidding, there's no self-destruct feature here. But seriously, enter the correct key next time.\n");
        }
    } else {
        printf("Suit yourself, keep the encrypted message as a mystery!\n");
    }

    return 0;
}