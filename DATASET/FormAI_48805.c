//FormAI DATASET v1.0 Category: modern Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* encrypt_string(char *message, int key) {
    int len = strlen(message);
    char *encrypted_message = (char*) malloc(len + 1);
    srand(time(NULL)); 
    for(int i = 0; i < len; i++) {
        int ascii_val = (int)(message[i] + key) + rand() % 10;
        encrypted_message[i] = (char) ascii_val;
    }
    encrypted_message[len] = '\0';
    return encrypted_message;
}

int main() {
    char message[100];
    printf("Enter the message to encrypt: ");
    scanf("%[^\n]s", message);
    int key;
    printf("Enter the encryption key: ");
    scanf("%d", &key);
    char *encrypted_message = encrypt_string(message, key);
    printf("Your encrypted message is: %s\n", encrypted_message);
    free(encrypted_message);
    return 0;
}