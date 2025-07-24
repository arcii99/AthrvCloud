//FormAI DATASET v1.0 Category: Modern Encryption ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int key = 4; //declare the encryption key
    char message[100], ch;
    printf("Enter your message: ");
    fgets(message, 100, stdin); //input the message

    for(int i = 0; message[i] != '\0'; ++i)
    {
        ch = message[i];
        //encrypt lowercase letters
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;
            if(ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        //encrypt uppercase letters
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;
            if(ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;  
            }
            message[i] = ch;
        }
    }
    printf("Encrypted message: %s", message); //output the encrypted message
    return 0; //exit the program
}