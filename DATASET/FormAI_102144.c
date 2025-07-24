//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define file structure
typedef struct
{
    char name[100];
    char date[20];
    int size;
} File;

int main()
{
    // open file in read binary mode
    FILE *fp = fopen("example.txt", "rb");

    if(fp == NULL)
    {
        printf("Error: Could not open file!\n");
        return 0;
    }

    // read first 20 bytes of file
    char buffer[20];
    fread(buffer, sizeof(char), 20, fp);

    // close file
    fclose(fp);

    // extract metadata from buffer
    File myfile;
    strncpy(myfile.name, buffer, 10);
    myfile.name[10] = '\0';
    strncpy(myfile.date, buffer+10, 10);
    myfile.date[10] = '\0';
    myfile.size = *((int*)(buffer+20));

    // print metadata
    printf("File Name: %s\n", myfile.name);
    printf("Date Created: %s\n", myfile.date);
    printf("File Size: %d bytes\n", myfile.size);

    return 0;
}