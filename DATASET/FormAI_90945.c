//FormAI DATASET v1.0 Category: Encryption ; Style: excited
/*Woo hoo, get ready for some exciting C Encryption code!*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//First, we declare our function that performs the encryption
void encrypt(char *str, int key) {
    printf("Get ready to see some magic happen!\n");
    printf("Original string: %s\n", str);
    //We will loop through each character of the string
    for (int i = 0; i < strlen(str); i++) {
        str[i] = str[i] + key; //We add the key to the ASCII value of the character
    }
    printf("Encrypted string: %s\n", str);
}

int main() {
    char str[100]; //We declare a character array to store our string
    int key; //We declare our encryption key

    printf("Enter a string to encrypt: ");
    scanf("%s", str);

    printf("Enter a key value: ");
    scanf("%d", &key);

    encrypt(str, key); //We call our encryption function

    return 0;
}

/*That's it folks, your string is now encrypted!
  Remember to keep your key value secret to decrypt it later.*/