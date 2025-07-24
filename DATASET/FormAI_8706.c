//FormAI DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *message, int key) {
    char c;
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        c = message[i];
        if (isalpha(c)) {
            c = toupper(c);
            c = c - 'A';
            c = (c + key) % 26;
            c = c + 'A';
        }
        message[i] = c;
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s", message);

    return 0;
}