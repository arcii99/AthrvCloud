//FormAI DATASET v1.0 Category: String manipulation ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

int main(void) {
    char msg[100];
    printf("Enter secret message: ");
    fgets(msg, sizeof(msg), stdin);

    // Post-apocalyptic encryption
    for (int i=0; i<strlen(msg); i++) {
        if (msg[i] >= 'a' && msg[i] <= 'z') {
            msg[i] = 'z' - msg[i] + 'a';
        } else if (msg[i] >= 'A' && msg[i] <= 'Z') {
            msg[i] = 'Z' - msg[i] + 'A';
        } else if (msg[i] == ' ') {
            msg[i] = '%';
        } else if (msg[i] == '.') {
            msg[i] = '?';
        } else if (msg[i] == ',') {
            msg[i] = '!';
        }
    }

    printf("You cannot decipher this message: %s\n", msg);

    // Post-apocalyptic decryption
    for (int i=0; i<strlen(msg); i++) {
        if (msg[i] >= 'a' && msg[i] <= 'z') {
            msg[i] = 'z' - msg[i] + 'a';
        } else if (msg[i] >= 'A' && msg[i] <= 'Z') {
            msg[i] = 'Z' - msg[i] + 'A';
        } else if (msg[i] == '%') {
            msg[i] = ' ';
        } else if (msg[i] == '?') {
            msg[i] = '.';
        } else if (msg[i] == '!') {
            msg[i] = ',';
        }
    }

    printf("Decrypted message: %s\n", msg);

    return 0;
}