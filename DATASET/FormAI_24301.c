//FormAI DATASET v1.0 Category: Modern Encryption ; Style: curious
#include<stdio.h>
#include<string.h>

// Curious C Modern Encryption!

int main() {
    char str[100];
    char key[100];
    int i, j;
    
    printf("Enter the string to be encrypted: ");
    scanf("%s", str);
    
    printf("Enter the key for encryption: ");
    scanf("%s", key);
    
    int len_str = strlen(str);
    int len_key = strlen(key);

    // Encryption magic!
    for (i = 0; i < len_str; i++) {
        str[i] = str[i] ^ key[i % len_key];
    }

    printf("\nEncrypted string: %s\n", str);

    // Decryption magic!
    for (i = 0; i < len_str; i++) {
        str[i] = str[i] ^ key[i % len_key];
    }

    printf("\nDecrypted string: %s\n", str);
    
    return 0;
}