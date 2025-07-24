//FormAI DATASET v1.0 Category: Data recovery tool ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char fileName[100];
    printf("Enter file name to recover:\n");
    scanf("%s", fileName);

    //Create a file pointer and attempt to open file in read mode
    FILE* fp = fopen(fileName, "r");
    if(fp==NULL)
    {
        printf("File Not Found!\n");
        return 1;
    }

    //Get file size
    fseek(fp, 0L, SEEK_END);
    int fileSize = ftell(fp);

    //Create buffer to hold entire file contents
    char* buffer = (char*) malloc(fileSize);
    fseek(fp, 0L, SEEK_SET);

    //Read in file contents
    size_t result = fread(buffer, 1, fileSize, fp);

    //Cleanup
    fclose(fp);

    //Print recovered file contents
    printf("%s", buffer);

    //Free allocated memory
    free(buffer);

    return 0;
}