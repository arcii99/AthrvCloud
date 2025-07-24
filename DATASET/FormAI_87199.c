//FormAI DATASET v1.0 Category: Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decrypt(char *encrypted_string) {
    int i;
    int length = strlen(encrypted_string);
    for (i = 0; i < length; i++) {
        if (encrypted_string[i] >= 97 && encrypted_string[i] <= 122) {
            encrypted_string[i] = encrypted_string[i] - 32;
        }
        else if (encrypted_string[i] >= 65 && encrypted_string[i] <= 90) {
            encrypted_string[i] = encrypted_string[i] + 32;
        }
        else if (encrypted_string[i] >= 48 && encrypted_string[i] <= 57) {
            if (encrypted_string[i] == 48) {
                encrypted_string[i] = 57;
            }
            else {
                encrypted_string[i]--;
            }
        }
    }
}

int main() {
    char encrypted_string[100];
    printf("Enter the encrypted string: ");
    scanf("%s", encrypted_string);
    decrypt(encrypted_string);
    printf("The decrypted string is: %s\n", encrypted_string);
    return 0;
}