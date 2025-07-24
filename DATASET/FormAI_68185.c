//FormAI DATASET v1.0 Category: Modern Encryption ; Style: artistic
#include <stdio.h>

// Function to convert the given char to its encrypted counterpart
char toEncrypted(char c) {
    if(c >= 'a' && c <= 'z') {
        return 'a' + ('z' - c);
    } else if(c >= 'A' && c <= 'Z') {
        return 'A' + ('Z' - c);
    } else if(c >= '0' && c <= '9') {
        return '0' + ('9' - c);
    } else {
        return c;
    }
}

int main() {
    char message[1000];

    printf("Enter the message to encrypt: ");
    fgets(message, 1000, stdin);

    printf("The encrypted message is:\n");
    for(int i = 0; message[i] != '\0' && message[i] != '\n'; ++i) {
        printf("%c", toEncrypted(message[i]));
    }

    return 0;
}