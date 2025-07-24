//FormAI DATASET v1.0 Category: Modern Encryption ; Style: brave
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    int key, i, c;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    for(i = 0; i < strlen(message); ++i) {
        c = message[i];

        if(c >= 'a' && c <= 'z') {
            c = c + key;

            if(c > 'z') {
                c = c - 'z' + 'a' - 1;
            }

            message[i] = c;
        } else if(c >= 'A' && c <= 'Z') {
            c = c + key;

            if(c > 'Z') {
                c = c - 'Z' + 'A' - 1;
            }

            message[i] = c;
        }
    }

    printf("Encrypted message: %s", message);

    return 0;
}