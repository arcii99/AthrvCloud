//FormAI DATASET v1.0 Category: File Encyptor ; Style: synchronous
#include<stdio.h>
#define MAX_FILE_SIZE 100000

int main()
{
    FILE *fptr1, *fptr2;
    char filename[100], ch;
    int key;

    // Getting file name
    printf("Enter file name to encrypt:");
    scanf("%s", filename);

    // Opening file to read
    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL)
    {
        printf("Unable to open file\n");
        return 0;
    }

    // Opening file to write (encrypted file)
    fptr2 = fopen("encrypted.txt", "w");
    if (fptr2 == NULL)
    {
        printf("Unable to open file\n");
        fclose(fptr1);
        return 0;
    }

    // Getting key for encryption
    printf("Enter encryption key:");
    scanf("%d", &key);

    // Reading character by character, encrypting and writing to encrypted file
    while ((ch = fgetc(fptr1)) != EOF)
    {
        ch = ch + key;
        fputc(ch, fptr2);
    }

    printf("File encrypted successfully!\n");

    // Closing files
    fclose(fptr1);
    fclose(fptr2);

    return 0;
}