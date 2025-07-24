//FormAI DATASET v1.0 Category: File Encyptor ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int key = 5; //Insert your desired encryption key (an integer)
    char sentence[] = "What's in a name? That which we call a rose, By any other name would smell as sweet."; //Insert the sentence you want to encrypt.

    printf("Original Sentence: %s\n", sentence);

    int length = strlen(sentence);

    // Encrypting the sentence
    for(int i = 0; i < length; i++)
    {
        char ch = sentence[i];

        //For lowercase letters
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;

            if(ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }

            sentence[i] = ch;

        }
        //For uppercase letters
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;

            if(ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }

            sentence[i] = ch;
        }

    }

    printf("Encrypted Sentence: %s\n", sentence);

    // Decrypting the sentence
    for(int i = 0; i < length; i++)
    {
        char ch = sentence[i];

        //For lowercase letters
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch - key;

            if(ch < 'a')
            {
                ch = ch + 'z' - 'a' + 1;
            }

            sentence[i] = ch;

        }
        //For uppercase letters
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch - key;

            if(ch < 'A')
            {
                ch = ch + 'Z' - 'A' + 1;
            }

            sentence[i] = ch;
        }

    }

    printf("Decrypted Sentence: %s\n", sentence);

    return 0;
}