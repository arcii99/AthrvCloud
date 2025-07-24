//FormAI DATASET v1.0 Category: Modern Encryption ; Style: surrealist
#include <stdio.h>
#include <string.h>

// A surreal C encryption program that transforms letters into geometric shapes

int main() {
    char message[100], encrypted_message[100];
    int key, i;

    printf("Enter a message to encrypt: ");
    scanf("%[^\n]%*c", message);

    printf("Enter a key (0-9): ");
    scanf("%d", &key);

    printf("\nEncrypting...\n");

    for (i = 0; i < strlen(message); i++) {
        switch(message[i]) {
            case 'a':
                encrypted_message[i] = '#';
                break;
            case 'b':
                encrypted_message[i] = '@';
                break;
            case 'c':
                encrypted_message[i] = '%';
                break;
            case 'd':
                encrypted_message[i] = '&';
                break;
            case 'e':
                encrypted_message[i] = '+';
                break;
            case 'f':
                encrypted_message[i] = '=';
                break;
            case 'g':
                encrypted_message[i] = '!';
                break;
            case 'h':
                encrypted_message[i] = '^';
                break;
            case 'i':
                encrypted_message[i] = '/';
                break;
            case 'j':
                encrypted_message[i] = '*';
                break;
            case 'k':
                encrypted_message[i] = '(';
                break;
            case 'l':
                encrypted_message[i] = ')';
                break;
            case 'm':
                encrypted_message[i] = '<';
                break;
            case 'n':
                encrypted_message[i] = '>';
                break;
            case 'o':
                encrypted_message[i] = '{';
                break;
            case 'p':
                encrypted_message[i] = '}';
                break;
            case 'q':
                encrypted_message[i] = '[';
                break;
            case 'r':
                encrypted_message[i] = ']';
                break;
            case 's':
                encrypted_message[i] = '?';
                break;
            case 't':
                encrypted_message[i] = ',';
                break;
            case 'u':
                encrypted_message[i] = '.';
                break;
            case 'v':
                encrypted_message[i] = ';';
                break;
            case 'w':
                encrypted_message[i] = ':';
                break;
            case 'x':
                encrypted_message[i] = '|';
                break;
            case 'y':
                encrypted_message[i] = '"';
                break;
            case 'z':
                encrypted_message[i] = '_';
                break;
            case ' ':
                encrypted_message[i] = ' ';
                break;
            default:
                encrypted_message[i] = message[i];
        }
    }

    encrypted_message[i] = '\0';

    printf("Encrypted Message: %s\n", encrypted_message);

    return 0;
}