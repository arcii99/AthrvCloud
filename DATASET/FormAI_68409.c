//FormAI DATASET v1.0 Category: Modern Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define KEY 5

void encrypt(char* message);

int main() {
    char* message = "Hello, world!";
    printf("Original message: %s\n", message);
    
    encrypt(message);
    printf("Encrypted message: %s\n", message);
    
    return 0;
}

void encrypt(char* message) {
    int i = 0;
    char c;
    while (message[i] != '\0') {
        c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = c + KEY;
            if (c > 'z') {
                c = c - 'z' + 'a' - 1;
            }
            message[i] = c;
        }
        else if (c >= 'A' && c <= 'Z') {
            c = c + KEY;
            if (c > 'Z') {
                c = c - 'Z' + 'A' - 1;
            }
            message[i] = c;
        }
        i++;
    }
}