//FormAI DATASET v1.0 Category: Encryption ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* message, char* key) {
    int msg_len = strlen(message);
    int key_len = strlen(key);
    char* encrypted_msg = (char*) malloc((msg_len+1) * sizeof(char));
    int i;
    for(i=0;i<msg_len;i++){
        //Medieval-style encryption
        encrypted_msg[i] = ((message[i] + key[i % key_len]) % 26) + 'A';
    }
    encrypted_msg[msg_len] = '\0';
    return encrypted_msg;
}

int main() {
    char message[100], key[100];
    printf("Enter message to encrypt: ");
    scanf("%[^\n]s", message);
    getchar(); //ignores the newline character
    printf("Enter key: ");
    scanf("%[^\n]s", key);
    char* encrypted_msg = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_msg);
    free(encrypted_msg);
    return 0;
}