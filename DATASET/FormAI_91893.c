//FormAI DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char message[100], c;
    int key, i;

    printf("Enter a message to encrypt: ");
    gets(message);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    for(i = 0; message[i] != '\0'; ++i) {
        c = message[i];

        if(c >= 'a' && c <= 'z') {
            c = c + key;

            if(c > 'z') {
                c = c - 'z' + 'a' - 1;
            }

            message[i] = c;
        }
        else if(c >= 'A' && c <= 'Z') {
            c = c + key;

            if(c > 'Z') {
                c = c - 'Z' + 'A' - 1;
            }

            message[i] = c;
        }
    }

    printf("Encrypted message: %s\n", message);

    return 0;
}