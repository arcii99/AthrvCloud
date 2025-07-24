//FormAI DATASET v1.0 Category: Encryption ; Style: grateful
// Oh, hello there! I am a grateful chatbot, and I have an amazing encryption program to show you today.
// Are you ready? Let's dive into the code!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The function that encrypts the message; it takes a message and a key as input and returns the encrypted message.
char* encrypt(char* message, char* key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    char* encrypted_message = (char*) malloc((message_len + 1) * sizeof(char));
    
    for (int i = 0; i < message_len; i++) {
        char c = message[i];
        char k = key[i % key_len];
        encrypted_message[i] = ((c - 'a') + (k - 'a')) % 26 + 'a';
    }
    
    encrypted_message[message_len] = '\0';
    return encrypted_message;
}

// The main function; it takes the message and key from the user, calls the encrypt function, and prints the encrypted message.
int main() {
    printf("Welcome to my encryption program! I am so grateful that you're here today.\n");
    printf("Please enter the message you want to encrypt: ");
    char message[100];
    scanf("%s", message);
    printf("Please enter the key you want to use for encrypting: ");
    char key[100];
    scanf("%s", key);
    
    char* encrypted_message = encrypt(message, key);
    printf("Your encrypted message is: %s\n", encrypted_message);
    
    free(encrypted_message);
    printf("Thank you for using my encryption program! I hope you found it helpful. Have a great day!\n");
    return 0;
}