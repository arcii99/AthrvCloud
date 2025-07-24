//FormAI DATASET v1.0 Category: Log analysis ; Style: introspective
#include<stdio.h>

int main()
{

    FILE* filePointer;
    
    char fileContent[50];
    
    int count = 0, charCount = 0;
    
    filePointer = fopen("sample.log", "r");

    while(fgets(fileContent, 50, filePointer) != NULL)
    {
        count++;
        charCount += strlen(fileContent);
    }

    fclose(filePointer);

    printf("Total lines in the file : %d \n", count);
    printf("Total characters in the file: %d", charCount);

    return 0;
}