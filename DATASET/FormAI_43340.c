//FormAI DATASET v1.0 Category: Modern Encryption ; Style: introspective
#include <stdio.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char message[], int key) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        if(message[i] >= 'a' && message[i] <= 'z'){
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
    }
}

int main() {
    char message[100];
    int key;
    
    printf("Enter the message to be encrypted (only alphabets): ");
    scanf("%s", message);
    printf("Enter the encryption key (an integer between 1 to 25): ");
    scanf("%d", &key);
    
    encrypt(message, key);
    
    printf("The encrypted message is: %s\n", message);
    
    return 0;
}