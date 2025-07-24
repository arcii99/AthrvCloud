//FormAI DATASET v1.0 Category: File Encyptor ; Style: unmistakable
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void encrypt(char string[]);

int main() {
    char message[MAX_SIZE];

    printf("Enter a message to be encrypted: ");
    fgets(message, MAX_SIZE, stdin);

    printf("Original message: %s", message);

    encrypt(message);

    printf("Encrypted message: %s", message);

    return 0;
}

void encrypt(char string[]) {
    int length = strlen(string);

    for (int i = 0; i < length; i++) {
        if (string[i] == ' ') {
            continue; // Skip over spaces
        }

        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = (char) ((string[i] - 'A' + 3) % 26 + 'A');
        } else if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] = (char) ((string[i] - 'a' + 3) % 26 + 'a');
        }
    }
}