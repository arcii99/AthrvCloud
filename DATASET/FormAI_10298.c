//FormAI DATASET v1.0 Category: Modern Encryption ; Style: accurate
#include <stdio.h>

#define KEY 3 // the shifting key

int main()
{
    char message[100], ch;
    int i;

    printf("Enter a message: ");
    fgets(message, 100, stdin); // get message from user

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];

        // encrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z')
            ch = (ch + KEY - 65) % 26 + 65;

        // encrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z')
            ch = (ch + KEY - 97) % 26 + 97;

        message[i] = ch;
    }

    printf("Encrypted message: %s", message);

    return 0;
}