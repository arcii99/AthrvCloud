//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

void decrypt(char *message, char *key);

int main() {
    char *message = "c3BlbnRlcjMgdGhhdCBpdHMgc3RyZWFtIG5ldyBjcml0aWNhbCBzdGF0ZSBhbmQgY29uZmlybSBhdHRhY2htZW50cw==";
    char *key = "secret";
    decrypt(message, key);

    return 0;
}

void decrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int index;

    for(index = 0; index < message_length; index++) {
        message[index] -= key[index % key_length];
    }

    printf("The decrypted message is: %s\n", message);
}