//FormAI DATASET v1.0 Category: Encryption ; Style: future-proof
#include <stdio.h>
#include <string.h>

void encryption(char* message, int key) {
    int len = strlen(message);
    for(int i = 0; i < len; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] + key;
            if(message[i] > 'z') {
                message[i] = message[i] - 'z' + 'a' - 1;
            }
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] + key;
            if(message[i] > 'Z') {
                message[i] = message[i] - 'Z' + 'A' - 1;
            }
        }
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    encryption(message, key);

    printf("Encrypted message: %s", message);

    return 0;
}