//FormAI DATASET v1.0 Category: Modern Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    //Encryption algorithm
	char message[] = "Hello World!";
	char key[] = "SecretKey1234";
	char encrypted_message[strlen(message)];
	for(int i = 0; i < strlen(message); i++){
	    encrypted_message[i] = message[i] ^ key[i % strlen(key)];
	}

    //Decryption algorithm
	char decrypted_message[strlen(message)];
    for(int i = 0; i < strlen(message); i++){
        decrypted_message[i] = encrypted_message[i] ^ key[i % strlen(key)];
    }
    
    //Print original message, encrypted message, and decrypted message
    printf("Original message: %s\n", message);
    printf("Encrypted message: ");
    for(int i = 0; i < strlen(message); i++){
        printf("%d ", encrypted_message[i]);
    }
    printf("\nDecrypted message: %s", decrypted_message);
    
    return 0;
}