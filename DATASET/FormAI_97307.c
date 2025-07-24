//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Cryptic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char ciphertext[] = "TBXJMMBFT-BBUXXXXFDBEFNCFS";

void decrypt(char *ciphertext) {
    char *p = ciphertext;
    while (*p != '\0') {
        if (isalpha(*p)) {
            if (*p == 'A') {
                putchar('Z');
            } else if (*p == 'a') {
                putchar('z');
            } else {
                putchar(*p - 1);
            }
        } else {
            putchar(*p);
        }
        p++;
    }
}

int main() {
    printf("Enter the password in C Cat Language: ");
    char password[50];
    scanf("%s", password);

    if (strcmp(password, "GJYJCKFOEKP") == 0) {
        decrypt(ciphertext);
    } else {
        printf("Invalid password!");
    }

    return 0;
}