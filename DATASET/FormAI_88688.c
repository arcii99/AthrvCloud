//FormAI DATASET v1.0 Category: Encryption ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

char* encrypt(char* message, int key) {
    char* result = (char*) malloc(strlen(message) + 1);
    strcpy(result, message);
    srand(time(NULL));
    int i, j;
    for (i = 0; i < strlen(result); i++) {
        j = rand() % 26;
        result[i] += key + j;
    }
    return result;
}

int main() {
    char message[100];
    int key;
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0;
    printf("Enter a key: ");
    scanf("%d", &key);

    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);

    free(encrypted);
    return 0;
}