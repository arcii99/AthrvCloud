//FormAI DATASET v1.0 Category: File Encyptor ; Style: beginner-friendly
#include<stdio.h>
#define MAX_SIZE 1000 //maximum size of file to be encrypted

int main()
{
    FILE *fp1, *fp2; //file pointers for input and output files

    char input_file[MAX_SIZE], output_file[MAX_SIZE], key; //array to store file name and encryption key

    printf("Enter the name of the input file: ");
    gets(input_file);

    printf("Enter the name of the output file: ");
    gets(output_file);

    printf("Enter the encryption key: ");
    scanf("%c", &key);

    fp1 = fopen(input_file, "r");
    fp2 = fopen(output_file, "w");

    if(fp1 == NULL)
    {
        printf("Error: Cannot open file %s\n", input_file);
        exit(1);
    }

    if(fp2 == NULL)
    {
        printf("Error: Cannot create file %s\n", output_file);
        exit(1);
    }

    char ch;
    while((ch = fgetc(fp1)) != EOF)
    {
        ch ^= key; //bitwise XOR operation with key to encrypt file
        fputc(ch, fp2);
    }

    printf("File encryption successful.\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}