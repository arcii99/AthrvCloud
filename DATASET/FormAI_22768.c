//FormAI DATASET v1.0 Category: File Encyptor ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char key[100], filename[100], ch;
    int count = 0;

    printf("Welcome to the File Encryptor! Enter the name of the file to be encrypted: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Sorry, I couldn't open the file. Please try again later.\n");
        exit(0);
    }

    printf("Great! Now enter the encryption key (only alphabets): ");
    scanf("%s", key);

    // Encrypt the file
    while ((ch = fgetc(fp)) != EOF)
    {
        if (count == strlen(key))
        {
            count = 0;
        }
        ch = (ch + key[count]) % 256;
        count++;

        printf("%c", ch);

    }

    fclose(fp);
    printf("\n");
    printf("Your file has been successfully encrypted. See you soon! :)\n");

    return 0;
}