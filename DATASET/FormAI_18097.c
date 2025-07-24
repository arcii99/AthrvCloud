//FormAI DATASET v1.0 Category: File Encyptor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to C File Encryptor\n\n");

    // get the file name
    char *filename = (char *)malloc(sizeof(char) * 50);
    printf("Enter the file name (including extension): ");
    scanf("%s", filename);

    // open the file
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Unable to open file\n");
        return 1; // return error status
    }

    // create the output file
    char *out_filename = (char *)malloc(sizeof(char) * 50);
    strcpy(out_filename, filename);
    strcat(out_filename, ".enc");
    FILE *out_fp = fopen(out_filename, "w");

    // read the file contents and encrypt
    char ch;
    while((ch = fgetc(fp)) != EOF) 
    {
        ch ^= 127; // bitwise XOR encryption with key of 127
        fputc(ch, out_fp);
    }

    // close both files
    fclose(fp);
    fclose(out_fp);

    printf("\nEncryption successful! The output file '%s' is created.\n", out_filename);
    free(filename);
    free(out_filename);

    return 0; // return success status
}