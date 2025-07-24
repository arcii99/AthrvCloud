//FormAI DATASET v1.0 Category: Encryption ; Style: immersive
#include <stdio.h>
#include <string.h>

/* Welcome to the immersive world of C encryption */

void encrypt(char string[]) {

    /* The encryption process begins with shuffling the characters in the string */
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }

    /* After shuffling the string, we'll shift the ASCII value of each character */
    int key = 3; // This is our encryption key, feel free to change it
    for (int i = 0; i < length; i++) {
        string[i] += key;
    }

    /* Finally, let's print out the encrypted message */
    printf("Encrypted message: %s\n", string);
}

int main() {

    /* Let's get the message that we want to encrypt from the user */
    printf("Enter the message you want to encrypt: ");
    char message[100];
    scanf("%[^\n]%*c", message);

    /* Now, let's encrypt the message */
    encrypt(message);

    /* Let's congratulate the user on successfully encrypting their message */
    printf("Congratulations! Your message has been successfully encrypted.\n");

    return 0;
}