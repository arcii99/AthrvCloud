//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_LENGTH 16

void generate_salt(char *salt) {
    for(int i=0; i<4; i++) {
        salt[i] = 'a' + (rand() % 26);
    }
}

void hash(char *input, char *salt, char *output) {
    char *buffer = (char *)malloc(sizeof(char) * (strlen(input) + 5));
    strcpy(buffer, input);
    strcat(buffer, salt);

    for(int i=0; i<HASH_LENGTH; i++) {
        output[i] = buffer[i] ^ buffer[i % strlen(salt)];
    }

    free(buffer);
}

int main() {
    srand(time(NULL));

    char input[256], salt[5], output[HASH_LENGTH + 1];
    printf("Enter input string: ");
    scanf("%s", input);

    generate_salt(salt);
    printf("Generated salt: %s\n", salt);

    hash(input, salt, output);
    printf("Hashed value: ");
    for(int i=0; i<HASH_LENGTH; i++) {
        printf("%02x", (unsigned char)output[i]);
    }
    printf("\n");

    return 0;
}