//FormAI DATASET v1.0 Category: modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("What?! This encryption program is unlike anything we've ever seen!\n");
    printf("But, okay, let's try it...\n");

    char message[1000];
    printf("Enter the message to encrypt: ");
    fgets(message, 1000, stdin);

    char key[26];
    printf("Enter the encryption key (26 characters, no repeats): ");
    fgets(key, 26, stdin);

    int encrypted[1000];
    int i, j;
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] == ' ') {
            encrypted[i] = (int)message[i];
        } else {
            for (j = 0; j < 26; j++) {
                if (key[j] == message[i]) {
                    encrypted[i] = j + 65;
                    break;
                }
            }
        }
    }

    printf("The encrypted message is: ");
    for (i = 0; encrypted[i] != '\0'; i++) {
        printf("%c", (char)encrypted[i]);
    }
    printf("\n");

    return 0;
}