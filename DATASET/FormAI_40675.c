//FormAI DATASET v1.0 Category: File Encyptor ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    printf("Welcome to the encryption program!\n");
    printf("Please enter the file name to encrypt: ");

    char filename[50];
    scanf("%s", filename);

    FILE* fptr = NULL;
    fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        printf("Error: File not found or unable to open.\n");
        exit(1);
    }

    int key = 7;

    char encrypted_filename[50] = "encrypted_";
    strcat(encrypted_filename, filename);

    FILE* encrypted_fptr = NULL;
    encrypted_fptr = fopen(encrypted_filename, "w");

    char c = fgetc(fptr);

    while (c != EOF)
    {
        c = c + key;
        fputc(c, encrypted_fptr);
        c = fgetc(fptr);
    }

    fclose(fptr);
    fclose(encrypted_fptr);

    printf("File encrypted successfully!\n");
    printf("The encrypted file is: %s\n", encrypted_filename);

    return 0;
}