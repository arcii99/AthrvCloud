//FormAI DATASET v1.0 Category: Encryption ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    int key, length;

    printf("Welcome to the cheerful C encryption program!\n");
    printf("Please enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Please enter a key value (0-25) for encryption: ");
    scanf("%d", &key);

    length = strlen(message);

    // Encrypt the message
    for (int i = 0; i < length; i++) {
        int charCode = message[i];

        if (charCode >= 'A' && charCode <= 'Z') {
            charCode += key;
            
            if (charCode > 'Z') {
                charCode = 'A' + (charCode - 'Z') - 1;
            }
        }
        else if (charCode >= 'a' && charCode <= 'z') {
            charCode += key;

            if (charCode > 'z') {
                charCode = 'a' + (charCode - 'z') - 1;
            }
        }

        message[i] = charCode;
    }

    printf("Your encrypted message is: %s\n", message);

    return 0;
}