//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: unmistakable
#include <stdio.h>
#include <string.h>

// Function to implement digital watermarking
void digitalWatermark(char *text, char *key) {
    // Calculating the length of the text and key
    int len_txt = strlen(text);
    int len_key = strlen(key);
    
    // Creating a character array for the encrypted text
    char encrypted_text[len_txt];
    
    // Using XOR operation to encrypt the text
    for(int i=0; i<len_txt; i++){
        encrypted_text[i] = text[i] ^ key[i%len_key];
    }
    
    // Printing the encrypted text
    printf("The encrypted text is: %s\n", encrypted_text);
    
    // Using XOR again to decrypt the text
    char decrypted_text[len_txt];
    for(int i=0; i<len_txt; i++){
        decrypted_text[i] = encrypted_text[i] ^ key[i%len_key];
    }
    
    // Printing the decrypted text
    printf("The decrypted text is: %s\n", decrypted_text);
}

int main() {
    // Taking input from the user for the text and key
    char text[1000], key[100];
    printf("Enter the text you want to encrypt: ");
    scanf("%s", text);
    printf("Enter the key for encryption: ");
    scanf("%s", key);
    
    // Calling the digitalWatermark function to implement digital watermarking
    digitalWatermark(text, key);
    return 0;
}