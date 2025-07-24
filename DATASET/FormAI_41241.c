//FormAI DATASET v1.0 Category: Error handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handleError()
{
    printf("An error occurred, the program will terminate.\n");
    exit(1);
}

int main()
{
    FILE *file;
    char fileName[50];
    char content[100];
    
    printf("Enter the name of the file to write to: ");
    scanf("%s", fileName);
    
    file = fopen(fileName, "w");
    
    if(file == NULL)
    {
        printf("Cannot open file %s\n", fileName);
        handleError();
    }
    
    printf("Enter the content to write to the file: ");
    scanf("%s", content);
    
    int result = fputs(content, file);
    fclose(file);
    
    if(result == EOF)
    {
        printf("Error occurred while writing to the file.\n");
        handleError();
    }
    
    printf("File saved successfully!\n");
    
    return 0;
}