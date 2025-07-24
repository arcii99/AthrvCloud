//FormAI DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
#include <string.h>

void main()
{
    char plain_text[100], cipher_text[100];
    int i, key;

    printf("Welcome to Hilarious Encryption Program!\n");
    printf("Enter the secret message you want to encrypt: ");
    gets(plain_text);
    printf("Enter the key (a positive integer value): ");
    scanf("%d", &key);

    if(key<=0)
    {
        printf("Awww, come on! Can't you give me a positive integer key? I need it to encrypt your message, you know!\n");
        printf("Program Exiting...\n");
        return;
    }

    for(i=0; i<strlen(plain_text); i++)
    {
        if(plain_text[i]>='a' && plain_text[i]<='z')
        {
            cipher_text[i] = (plain_text[i] + key - 'a') % 26 + 'a';
        }
        else if(plain_text[i]>='A' && plain_text[i]<='Z')
        {
            cipher_text[i] = (plain_text[i] + key - 'A') % 26 + 'A';
        }
        else
        {
            cipher_text[i] = plain_text[i];
        }
    }
    cipher_text[i] = '\0';

    printf("\nYour encrypted message is: ");
    puts(cipher_text);
    printf("\nWow! I'm impressed that you chose a positive integer key! I didn't expect that from you, hehe.\n");

    return;
}