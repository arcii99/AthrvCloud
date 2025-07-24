//FormAI DATASET v1.0 Category: Encryption ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* encrypt(char* message, int key) {
    int len = strlen(message);
    char* encrypted_message = (char*) malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        char c = message[i];
        if (isdigit(c) || isspace(c)) {
            encrypted_message[i] = c;
            continue;
        }
        if (islower(c)) {
            int new_c = (c - 'a' + key) % 26 + 'A';
            encrypted_message[i] = (char) new_c;
        } else if (isupper(c)) {
            int new_c = (c - 'A' + key) % 26 + 'a';
            encrypted_message[i] = (char) new_c;
        }
    }
    return encrypted_message;
}

int main() {
    char message[] = "This is a top secret message! 1234";
    int key = 13;
    char* encrypted_message = encrypt(message, key);
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted_message);
    free(encrypted_message);
    return 0;
}