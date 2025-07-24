//FormAI DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Welcome to my unique C encryption program!
// I'm so excited to show you how it works!
// This program will take a string as input and encrypt it!
// Let's get started!

int main() {
    char str[100];
    int key, i;

    printf("Enter string to encrypt: ");
    gets(str);

    printf("\nEnter key: ");
    scanf("%d", &key);

    printf("\nEncrypting...\n");

    // Here comes the exciting part - encryption algorithm!

    for(i = 0; str[i] != '\0'; ++i) {
        str[i] = str[i] + key; // Add the key to each character
    }

    // Encrypting complete! Now let's print the result!

    printf("\nEncrypted string: %s", str);

    // But wait, there's more! Let's decrypt it too!

    printf("\n\nDecrypting...\n");

    for(i = 0; str[i] != '\0'; ++i) {
        str[i] = str[i] - key; // Subtract the key from each character
    }

    // Decryption done! Let's print the result!

    printf("\nDecrypted string: %s", str);

    // Woohoo! We made an encryption program in C!
    // I hope you had fun following along with me!
    // See you next time with another exciting program!
    return 0;
}