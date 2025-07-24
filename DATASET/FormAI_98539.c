//FormAI DATASET v1.0 Category: File Encyptor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPTION_KEY 10

int main()
{
    char inputFileName[50];
    char outputFileName[50];

    printf("Enter name of file to encrypt: ");
    scanf("%s", inputFileName);

    printf("Enter name of output file: ");
    scanf("%s", outputFileName);

    FILE *inputFile = fopen(inputFileName, "r");
    if(inputFile == NULL)
    {
        printf("Error opening file %s", inputFileName);
        exit(1);
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if(outputFile == NULL)
    {
        printf("Error creating output file %s", outputFileName);
        exit(1);
    }

    char buffer[1024];
    while(fgets(buffer, 1024, inputFile))
    {
        int len = strlen(buffer);
        for(int i = 0; i < len; i++)
        {
            buffer[i] = buffer[i] ^ ENCRYPTION_KEY; // XOR encryption
        }

        fprintf(outputFile, "%s", buffer);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("File encryption completed.");
    return 0;
}