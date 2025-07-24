//FormAI DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int key = 3; // encryption key

int main()
{
    char message[100], c;
    int i;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // encrypt message
    for(i = 0; message[i] != '\0'; ++i){
        c = message[i];
        if(c >= 'a' && c <= 'z'){
            c = c + key;
            if(c > 'z'){
                c = c - 'z' + 'a' - 1;
            }
            message[i] = c;
        }
        else if(c >= 'A' && c <= 'Z'){
            c = c + key;
            if(c > 'Z'){
                c = c - 'Z' + 'A' - 1;
            }
            message[i] = c;
        }
    }

    printf("Encrypted message: %s\n", message);

    // decrypt message
    for(i = 0; message[i] != '\0'; ++i){
        c = message[i];
        if(c >= 'a' && c <= 'z'){
            c = c - key;
            if(c < 'a'){
                c = c + 'z' - 'a' + 1;
            }
            message[i] = c;
        }
        else if(c >= 'A' && c <= 'Z'){
            c = c - key;
            if(c < 'A'){
                c = c + 'Z' - 'A' + 1;
            }
            message[i] = c;
        }
    }

    printf("Decrypted message: %s\n", message);

    return 0;
}