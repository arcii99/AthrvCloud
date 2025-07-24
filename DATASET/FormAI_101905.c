//FormAI DATASET v1.0 Category: File handling ; Style: Ada Lovelace
/* The following program demonstrates Ada Lovelace's pioneering work in computing, specifically her understanding of file handling principles.
She was able to recognize the need to convert data into a machine-readable format for processing. */
#include <stdio.h>

int main()
{
    FILE *filePointer; //Declaring file pointer
    char data[100]; //Data to be written to file
    char fileName[20]; //Name of file

    printf("Enter the filename to create: ");
    scanf("%s", fileName);

    filePointer = fopen(fileName, "w"); //Opening file in write mode

    if(filePointer == NULL)
    {
        printf("Failed to create file.");
        return 0;
    }

    printf("Enter data to write to file: ");
    scanf("%s", data);

    fprintf(filePointer, "%s", data); //Writing data to file

    printf("File created and data written!");

    fclose(filePointer); //Closing file

    return 0;
}