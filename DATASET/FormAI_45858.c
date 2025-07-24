//FormAI DATASET v1.0 Category: modern Encryption ; Style: grateful
#include<stdio.h>
#include<string.h>

// The Encryption function takes in the message string and the key
char* encrypt(char* message, char* key){
    int i, j = 0;
    char* result = (char*)malloc(strlen(message) * sizeof(char));

    for(i=0; i<strlen(message); i++){
        // Apply the XOR operation on each character of the message
        // using the corresponding character from the key
        result[i] = message[i] ^ key[j];

        // Move to the next character of the key, wrapping around
        // if we reach the end of the key string
        j = (j+1) % strlen(key);
    }

    // Add the null terminator to the result string
    result[i] = '\0';

    // Return the encrypted message
    return result;
}

int main(){
    // Get the message and key from the user
    char message[100], key[100];
    printf("Enter the message: ");
    scanf("%99[^\n]", message);
    getchar();
    printf("Enter the key: ");
    scanf("%99[^\n]", key);

    // Encrypt the message using the key
    char* encrypted = encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted);

    // Free the memory used by the encrypted message
    free(encrypted);

    // Return success
    return 0;
}