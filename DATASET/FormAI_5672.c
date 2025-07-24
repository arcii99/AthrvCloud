//FormAI DATASET v1.0 Category: Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Step 1: Get user input
    char input[1000];
    printf("Enter the input string: ");
    fgets(input, 1000, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove trailing newline character

    // Step 2: Generate encryption key
    char key[1000];
    printf("Enter the encryption key: ");
    fgets(key, 1000, stdin);
    key[strcspn(key, "\n")] = '\0';

    // Step 3: Generate encrypted string
    char encrypted[1000];
    int keyLen = strlen(key);
    int inputLen = strlen(input);
    int index = 0;
    for(int i = 0; i < inputLen; i++) {
        encrypted[i] = input[i] ^ key[index];
        index++;
        if(index == keyLen) {
            index = 0;
        }
    }

    // Step 4: Print encrypted string
    printf("Encrypted string: %s\n", encrypted);

    // Step 5: Generate decrypted string
    char decrypted[1000];
    index = 0;
    for(int i = 0; i < inputLen; i++) {
        decrypted[i] = encrypted[i] ^ key[index];
        index++;
        if(index == keyLen) {
            index = 0;
        }
    }

    // Step 6: Print decrypted string
    printf("Decrypted string: %s\n", decrypted);

    return 0;
}