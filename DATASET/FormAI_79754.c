//FormAI DATASET v1.0 Category: modern Encryption ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// define a function to generate secret key
int generateKey() {
    srand((unsigned)time(NULL));
    int key = rand() % 10000;
    return key;
}

// define a function to encrypt the given message using the secret key
void encrypt(char message[], int key) {
    int len = strlen(message);

    for (int i = 0; i < len; i++) {
        int encrypted_char = (int)message[i] + key;
        message[i] = (char)encrypted_char;
    }
}

// define a function to decrypt the given message using the secret key
void decrypt(char message[], int key) {
    int len = strlen(message);
    
    for (int i = 0; i < len; i++) {
        int decrypted_char = (int)message[i] - key;
        message[i] = (char)decrypted_char;
    }
}

int main() {
    char message[1000];
    int key = 0;
    
    // get the message to be encrypted from the user
    printf("Enter the message to be encrypted:\n");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    
    // generate the secret key
    key = generateKey();
    printf("Your secret key is: %d\n", key);
    
    // encrypt the message using the secret key
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    
    // decrypt the message using the secret key
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    
    return 0;
}