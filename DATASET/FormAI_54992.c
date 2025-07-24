//FormAI DATASET v1.0 Category: Data recovery tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char fileName[100];
    char *content;
    int fileSize;

    printf("Enter file name: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "rb");

    if(fp == NULL)
    {
        printf("Error: File not found\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    rewind(fp);

    content = (char*)malloc(fileSize * sizeof(char));

    if (content == NULL)
    {
        printf("Error: Could not allocate memory for file content\n");
        return 1;
    }

    fread(content, sizeof(char), fileSize, fp);

    printf("--------------------\n");
    printf("File Content:\n");
    printf("--------------------\n\n");
    printf("%s\n", content);

    fclose(fp);
    free(content);

    return 0;
}