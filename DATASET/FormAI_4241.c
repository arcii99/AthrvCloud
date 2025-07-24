//FormAI DATASET v1.0 Category: File Encyptor ; Style: immersive
#include <stdio.h>

void encrypt(char *filepath)
{
    FILE *fp = fopen(filepath, "r+");
    char key = 'K'; // the encryption key
    int c;
    while ((c = fgetc(fp)) != EOF) // read file char by char
    {
        fputc(c ^ key, fp); // encrypt each char using XOR
    }
    fclose(fp);
}

void decrypt(char *filepath)
{
    FILE *fp = fopen(filepath, "r+");
    char key = 'K'; // the same encryption key used to encrypt the file
    int c;
    while ((c = fgetc(fp)) != EOF) // read file char by char
    {
        fputc(c ^ key, fp); // decrypt each char using XOR
    }
    fclose(fp);
}

int main()
{
    char *filepath = "example.txt"; // path of the text file to encrypt
    printf("Original file content: ");
    FILE *fp = fopen(filepath, "r");
    int c;
    while ((c = fgetc(fp)) != EOF)
        putchar(c);
    fclose(fp);
    
    encrypt(filepath); // encrypt the file
    printf("\nEncrypted file content: ");
    fp = fopen(filepath, "r");
    while ((c = fgetc(fp)) != EOF)
        putchar(c);
    fclose(fp);
    
    decrypt(filepath); // decrypt the file
    printf("\nDecrypted file content: ");
    fp = fopen(filepath, "r");
    while ((c = fgetc(fp)) != EOF)
        putchar(c);
    fclose(fp);
    
    return 0;
}