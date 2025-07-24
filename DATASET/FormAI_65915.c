//FormAI DATASET v1.0 Category: Encryption ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the given message using a statistical cipher
void encrypt(char *message, char *cipher) {
    int freq[26] = {0}; // array to store the frequency of each alphabet
    int i, j;

    // Counting frequency of each alphabet in the message
    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            freq[message[i] - 'a']++;
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            freq[message[i] - 'A']++;
        }
    }

    // Finding the most frequent alphabet in the message
    int max_freq = freq[0];
    char max_alpha = 'a';
    for(i = 1; i < 26; i++) {
        if(freq[i] > max_freq) {
            max_freq = freq[i];
            max_alpha = 'a' + i;
        }
    }

    // Generating the cipher
    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            cipher[i] = ((message[i] - 'a') + (max_alpha - 'a')) % 26 + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            cipher[i] = ((message[i] - 'A') + (max_alpha - 'a')) % 26 + 'A';
        }
        else {
            cipher[i] = message[i];
        }
    }
    cipher[i] = '\0';
}

int main() {
    char message[1000], cipher[1000];
    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // removing the newline character from the input

    encrypt(message, cipher);
    printf("The encrypted message is: %s\n", cipher);

    return 0;
}