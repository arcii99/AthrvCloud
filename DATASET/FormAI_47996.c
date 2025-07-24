//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: curious
#include<stdio.h>

// Key generation function
int generateKey(int key){
    int p = 3, q = 7;
    return p*q;
}

// Encryption function
int encrypt(int msg, int key){
    return msg * key;
}

// Decryption function
int decrypt(int msg, int key){
    return msg / key;
}

int main(){
    printf("Welcome to the Curious Public-Key Algorithm Implementation Example Program!\n\n");
    
    // Getting message input from user
    printf("Enter a message to encrypt: ");
    int msg;
    scanf("%d", &msg);

    // Generating the key
    printf("Generating a key...\n");
    int key = generateKey(10);
    printf("Generated key: %d\n", key);

    // Encrypting the message
    printf("Encrypting the message...\n");
    int encryptedMsg = encrypt(msg, key);
    printf("Encrypted message: %d\n", encryptedMsg);

    // Decrypting the message
    printf("Decrypting the message...\n");
    int decryptedMsg = decrypt(encryptedMsg, key);
    printf("Decrypted message: %d\n", decryptedMsg);

    printf("\nThank you for using our program!\n");

    return 0;
}