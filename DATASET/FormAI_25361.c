//FormAI DATASET v1.0 Category: File Encyptor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* encrypt(char* text, int key) {
    int length = strlen(text);
    char *result = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        result[i] = text[i] ^ key;
    }
    result[length] = '\0';
    return result;
}

char* decrypt(char* cipher, int key) {
    int length = strlen(cipher);
    char *result = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        result[i] = cipher[i] ^ key;
    }
    result[length] = '\0';
    return result;
}

int main() {
    char text[100];
    int key, choice;
    printf("Enter the text to be encrypted: ");
    scanf("%[^\n]%*c", text);
    printf("Enter the key (must be an integer between 1 and 255): ");
    scanf("%d", &key);

    char* cipher = encrypt(text, key);
    printf("\nEncrypted Text: %s\n", cipher);

    char* decrypted = decrypt(cipher, key);
    printf("\nDecrypted Text: %s\n", decrypted);

    free(cipher);
    free(decrypted); 
    return 0; 
}