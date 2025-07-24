//FormAI DATASET v1.0 Category: Modern Encryption ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
    char msg[100];
    char key[] = "XCYVZHNPQKLOIGJMTUBWAFERDS";
    char enc[100];
    int i, j;

    // Prompt the user to input a message
    printf("Enter a message to encrypt: ");
    fgets(msg, sizeof(msg), stdin);

    // Remove newline character from input
    if(msg[strlen(msg)-1] == '\n')
        msg[strlen(msg)-1] = '\0';

    // Encrypt the message using substitution cipher
    for(i = 0; i < strlen(msg); i++) {
        if(msg[i] >= 'A' && msg[i] <= 'Z') {
            j = msg[i] - 'A';
            enc[i] = key[j];
        }
        else {
            enc[i] = msg[i];
        }
    }

    // Add null terminator to encrypted message
    enc[i] = '\0';

    // Print the encrypted message
    printf("Encrypted message: %s\n", enc);

    return 0;
}