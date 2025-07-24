//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char str[1000];
    int key, i;

    // get input string
    printf("Enter a string to encrypt:\n");
    fgets(str, 1000, stdin);

    // generate random key
    srand(time(0));
    key = rand() % 100;

    // encrypt string
    for(i = 0; str[i] != '\0'; i++) {
        str[i] = str[i] + key;
    }

    // print encrypted string and key
    printf("Encrypted string: %s\n", str);
    printf("Key: %d", key);

    return 0;
}