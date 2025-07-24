//FormAI DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input_file, char *output_file);

int main(int argc, char *argv[]) 
{ 
    if (argc != 3) 
    {
        printf("Usage: ./encrypt input_file output_file\n");
        return 1; 
    } 

    encrypt(argv[1], argv[2]);
    printf("File encrypted successfully!\n");

    return 0; 
} 

void encrypt(char *input_file, char *output_file) 
{
    FILE *input_fp, *output_fp;
    input_fp = fopen(input_file, "r");
    output_fp = fopen(output_file, "w");

    if (input_fp == NULL || output_fp == NULL) 
    {
        printf("Error opening files\n");
        exit(1);
    }

    char c;
    int key = 5;
    
    while (!feof(input_fp)) 
    {
         c = fgetc(input_fp);
         c = c + key;
         fputc(c, output_fp);
    }

    fclose(input_fp);
    fclose(output_fp);
    return;
}