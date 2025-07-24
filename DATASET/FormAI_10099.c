//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// A function to encrypt the text using XOR algorithm
char* encrypt(char* text, int key){
    char* result = (char*)malloc(sizeof(char) * strlen(text));
    int i;
    for(i = 0; i < strlen(text); i++){
        result[i] = text[i] ^ key;
    }
    result[i] = '\0';
    return result;
}

// A function to decrypt the text using XOR algorithm
char* decrypt(char* text, int key){
    return encrypt(text, key);
}

int main(){

    printf("Welcome to the Mind-Bending Cryptography Program in C!\n\n");
    
    // Ask for the user input
    char plain_text[1000];
    printf("Enter the text to be encrypted: ");
    fgets(plain_text, 1000, stdin);
    
    int key;
    printf("Enter the key to encrypt the text: ");
    scanf("%d", &key);

    // Encrypt the text
    char* encrypted_text = encrypt(plain_text, key);

    // Print the encrypted text
    printf("\nEncrypted Text: %s\n", encrypted_text);
    
    // Decrypt the text
    char* decrypted_text = decrypt(encrypted_text, key);

    // Print the decrypted text
    printf("\nDecrypted Text: %s\n", decrypted_text);

    printf("\nCongratulations! You have successfully encrypted and decrypted the text using Mind-Bending Cryptography implementation in C!");

    return 0;
}