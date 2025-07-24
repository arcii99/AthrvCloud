//FormAI DATASET v1.0 Category: File Encyptor ; Style: Claude Shannon
#include <stdio.h>

int main()
{
    FILE *fp1, *fp2;
    char c;

    int key = 3; // Key for Caesar Cipher

    fp1 = fopen("file.txt", "r"); // Open input file
    fp2 = fopen("encrypted.txt", "w"); // Open output file

    if (fp1 == NULL) // Check if input file exists
    {
        printf("Error: Could not open file. \n");
        return 1;
    }

    while ((c = fgetc(fp1)) != EOF) // Read from input file
    {
        if (c >= 'a' && c <= 'z') // Check if lowercase alphabet
        {
            c = 'a' + (c - 'a' + key) % 26; // Encrypt using Caesar Cipher
        }
        else if (c >= 'A' && c <= 'Z') // Check if uppercase alphabet
        {
            c = 'A' + (c - 'A' + key) % 26; // Encrypt using Caesar Cipher
        }
        fputc(c, fp2); // Write to output file
    }

    fclose(fp1); // Close input file
    fclose(fp2); // Close output file

    printf("File encryption successful! \n");

    return 0;
}