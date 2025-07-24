//FormAI DATASET v1.0 Category: modern Encryption ; Style: curious
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char message[100];
    int key, length, i;
    
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Enter encryption key: ");
    scanf("%d", &key);
    
    length = strlen(message);

    for(i = 0; i < length; i++) {
        
        // Shift each character by the encryption key
        message[i] = (message[i] + key) % 128;

        // Apply a non-linear transformation to each character
        message[i] = (message[i] * (128 - message[i] % 64)) % 128;

        // Apply a bit-wise operation to each character
        message[i] ^= 0b11011011;
    }

    printf("Your encrypted message is: %s", message);

    return 0;
}