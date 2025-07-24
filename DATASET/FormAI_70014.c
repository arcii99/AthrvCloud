//FormAI DATASET v1.0 Category: File Encyptor ; Style: surprised
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int key = 42; //the encryption key
    char filename[100] = {0}; //the filename
    char ch; //the character to be read
    FILE *fp1, *fp2; //file pointers
    printf("Welcome to the C File Encryptor!\n\n");
    printf("Enter the filename to encrypt: ");
    scanf("%s", filename);
    fp1 = fopen(filename, "r");
    if(fp1 == NULL) //if file not found
    {
        printf("Error: File not found!\n");
        exit(1);
    }
    fp2 = fopen("encrypted.txt", "w");
    if(fp2 == NULL)
    {
        printf("Error: Could not create encrypted file\n");
        exit(1);
    }
    while((ch = fgetc(fp1)) != EOF) //read the file character by character
    {
        fprintf(fp2, "%c", ch ^ key); //xor with the key and write to the encrypted file
    }
    printf("File encrypted successfully. Encrypted file saved as encrypted.txt\n");
    fclose(fp1);
    fclose(fp2);
    return 0;
}