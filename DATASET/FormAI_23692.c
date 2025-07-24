//FormAI DATASET v1.0 Category: Ebook reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 2048

void displayContents(char *filePath)
{
    FILE *ebookFile = fopen(filePath, "rb"); //opening the e-book file in binary mode
    
    if(ebookFile == NULL)
    {
        printf("Error: Cannot open file \"%s\"\n", filePath);
        return;
    }
    
    char buffer[BUFFER_SIZE];
    size_t readBytes = 0;
    
    while((readBytes = fread(buffer, sizeof(char), sizeof(buffer), ebookFile)) > 0) //reading the E-book contents
    {
        printf("%.*s", (int)readBytes, buffer);
    }
    
    fclose(ebookFile);
}

int main()
{
    char filePath[256];
    
    printf("Enter path to e-book: ");
    scanf("%s", filePath);
    
    displayContents(filePath);
    
    return 0;
}