//FormAI DATASET v1.0 Category: modern Encryption ; Style: content
#include <stdio.h>
#include <string.h>

void encrypt(char *str, int key) {
    char encrypted[1000];
    int length = strlen(str);
    int i;
    for (i = 0; i < length; i++) {
        int ascii = (int)str[i];
        ascii += key;
        encrypted[i] = (char)(ascii);
    }
    encrypted[i] = '\0';
    printf("Encrypted message: %s\n", encrypted);
}

void decrypt(char *str, int key) {
    char decrypted[1000];
    int length = strlen(str);
    int i;
    for (i = 0; i < length; i++) {
        int ascii = (int)str[i];
        ascii -= key;
        decrypted[i] = (char)(ascii);
    }
    decrypted[i] = '\0';
    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char message[1000];
    int key;
    printf("Enter message to be encrypted: ");
    gets(message);
    printf("Enter key: ");
    scanf("%d", &key);
    encrypt(message, key);
    decrypt("Qtivgtp\200.nqvq", key);
    return 0;
}