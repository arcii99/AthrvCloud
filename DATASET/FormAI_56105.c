//FormAI DATASET v1.0 Category: Modern Encryption ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform modern encryption on a string
void modernEncrypt(char* str, int key) {
    int len = strlen(str);

    // Add the key value to each character in the string
    for(int i = 0; i < len; i++) {
        str[i] = str[i] + key;
    }

    // Reverse the string
    for(int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

int main() {
    char input[101];
    int key;

    // Accept input string and key from user
    printf("Enter string to encrypt (max 100 characters): ");
    fgets(input, 100, stdin);
    printf("Enter key value: ");
    scanf("%d", &key);

    // Call the modern encrypt function
    modernEncrypt(input, key);

    // Display the encrypted string
    printf("The encrypted string is: %s\n", input);

    return 0;
}