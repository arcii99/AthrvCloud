//FormAI DATASET v1.0 Category: Encryption ; Style: happy
// Hey there! Welcome to my happy C encryption example program!
// Let's have some fun with encryption!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char message[1000], encrypted[1000], decrypted[1000]; // Declare our message, encrypted message, and decrypted message variables
    char key[100] = "happy"; // Set the key for encryption and decryption
    int i, j;
    
    printf("Let's encrypt a happy message!\nEnter the message you would like to encrypt: ");
    scanf("%[^\n]s", message); // Read in the message, including spaces, until we hit the enter key
    
    // Perform encryption using our key
    for (i = 0; i < strlen(message); i++) {
        j = i % strlen(key);
        encrypted[i] = message[i] + key[j];
    }
    encrypted[i] = '\0'; // Add null terminator to the end of encrypted message
    
    printf("\nYour encrypted message is:\n%s\n", encrypted); // Display the encrypted message
    
    // Perform decryption using the same key
    for (i = 0; i < strlen(encrypted); i++) {
        j = i % strlen(key);
        decrypted[i] = encrypted[i] - key[j];
    }
    decrypted[i] = '\0'; // Add null terminator to the end of decrypted message
    
    printf("\nAnd your decrypted message is:\n%s\n", decrypted); // Display the decrypted message
    
    return 0; // Return from main function, indicating successful program execution
}