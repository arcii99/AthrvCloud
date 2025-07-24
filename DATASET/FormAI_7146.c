//FormAI DATASET v1.0 Category: Modern Encryption ; Style: invasive
#include<stdio.h>
#include<string.h>

char key[] = "dU95cL32GxV7Z6tE4bN8kY0HjX1pAqSfRgyhoWMIOmaBwQJsrnFvPzT"; // 54 character key for encryption

void encrypt(char *message, char *result) {
    int i, j;
    int msgLen = strlen(message);
    for (i=0; i<msgLen; i++) {
        for (j=0; j<54; j++) {
            if (message[i] == key[j]) {
                result[i] = key[(j+31)%54];     // Encryption logic
                break;
            }
        }
    }
    result[i] = '\0';   // Add null character at end of string
}

void decrypt(char *message, char *result) {
    int i, j;
    int msgLen = strlen(message);
    for (i=0; i<msgLen; i++) {
        for (j=0; j<54; j++) {
            if (message[i] == key[j]) {
                result[i] = key[(j+23)%54];     // Decryption logic
                break;
            }
        }
    }
    result[i] = '\0';   // Add null character at end of string
}

int main() {
    char message[100], encResult[100], decResult[100];
    printf("Enter the message to encrypt: ");
    gets(message);
    encrypt(message, encResult);     // Calling the encrypt function
    printf("Encrypted message: %s\n", encResult);
    decrypt(encResult, decResult);   // Calling the decrypt function
    printf("Decrypted message: %s\n", decResult);
    return 0;
}