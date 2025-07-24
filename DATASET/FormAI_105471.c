//FormAI DATASET v1.0 Category: Word Count Tool ; Style: portable
#include <stdio.h>
#include <ctype.h>

void countWords(char *fileName);

int main()
{
    char fileName[100];

    printf("Enter filename: ");
    scanf("%s", fileName);

    countWords(fileName);

    return 0;
}

void countWords(char *fileName)
{
    FILE *filePointer;
    int count = 0;
    char ch;

    filePointer = fopen(fileName, "r");

    if(filePointer == NULL)
    {
        printf("File does not exist.\n");
        return;
    }

    while((ch = fgetc(filePointer)) != EOF)
    {
        if(isspace(ch))
        {
            count++;
        }
    }

    fclose(filePointer);
    printf("Number of words in file %s is %d.\n", fileName, count);

    return;
}