//FormAI DATASET v1.0 Category: Encryption ; Style: medieval
#include <stdio.h>
#include <string.h>

char* alphabet = "abcdefghijklmnopqrstuvwxyz";
char* key = "efgabcdhijklmnopqrstuvwxyz";

char* encrypt(char* message) {
    int i, j;
    char* encrypted = (char*)malloc(strlen(message));

    for(i = 0; i < strlen(message); i++) {
        char current = tolower(message[i]);
        for(j = 0; j < strlen(alphabet); j++) {
            if(current == alphabet[j]) {
                encrypted[i] = key[j];
                break;
            }
        }
        if(j == strlen(alphabet)) {
            encrypted[i] = current;
        }
    }

    return encrypted;
}

int main() {
    char message[100];
    char* encrypted;
    printf("Enter a message: ");
    scanf("%[^\n]s", message);

    encrypted = encrypt(message);
    printf("Encrypted message: %s\n", encrypted);

    free(encrypted);

    return 0;
}