//FormAI DATASET v1.0 Category: Encryption ; Style: medieval
#include <stdio.h>
#include <string.h>

// Function to encrypt message
void encrypt(char message[]) {
    int i;
    
    for(i = 0; message[i] != '\0'; ++i) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = 'z' - (message[i] - 'a');
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'Z' - (message[i] - 'A');
        }
    }
    
    printf("Encrypted message: %s\n", message);
}

// Main function
int main() {
    char message[100];
    
    // Get message input
    printf("Enter message: ");
    fgets(message, 100, stdin);
    
    // Remove newline character from message
    message[strcspn(message, "\n")] = 0;
    
    // Call encrypt function
    encrypt(message);
    
    return 0;
}