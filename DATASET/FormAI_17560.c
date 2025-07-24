//FormAI DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <string.h>

// peaceful encryption function
void peacefulEncrypt(char *src, char *dest, int key) {
    int n = strlen(src);

    // Iterate through each character in the string
    for(int i = 0; i < n; i++) {
        // If the character is an uppercase letter
        if(src[i] >= 'A' && src[i] <= 'Z') {
            // Add the key to the ASCII value of the letter
            dest[i] = (char)((src[i] - 'A' + key) % 26 + 'A');
        }
        // If the character is a lowercase letter
        else if(src[i] >= 'a' && src[i] <= 'z') {
            // Add the key to the ASCII value of the letter
            dest[i] = (char)((src[i] - 'a' + key) % 26 + 'a');
        }
        // If the character is not a letter (e.g. space, punctuation, etc.)
        else {
            dest[i] = src[i];
        }
    }

    // Null terminate the encrypted string
    dest[n] = '\0';
}

int main() {
    char message[] = "Peaceful programming is the best kind of programming!";
    char encrypted[100];
    int key = 7;

    // Encrypt the message using our peaceful encryption function
    peacefulEncrypt(message, encrypted, key);

    // Output the original message and the encrypted message
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted);

    return 0;
}