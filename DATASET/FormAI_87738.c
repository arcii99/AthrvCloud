//FormAI DATASET v1.0 Category: File Encyptor ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char *input_file, char *output_file, char *key);

int main()
{
    char *input_file = "input.txt";
    char *output_file = "output.txt";
    char *key = "secret";

    encrypt(input_file, output_file, key);

    printf("File Encrypted Successfully!\n");

    return 0;
}

void encrypt(char *input_file, char *output_file, char *key)
{
    FILE *fp1, *fp2;
    int ch;
    int i = 0;
    int key_length = strlen(key);

    fp1 = fopen(input_file, "r");
    fp2 = fopen(output_file, "w");

    if(fp1 == NULL || fp2 == NULL)
    {
        printf("Error in opening file!\n");
        exit(1);
    }

    while((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch ^ key[i % key_length], fp2);
        i++;
    }

    fclose(fp1);
    fclose(fp2);
}