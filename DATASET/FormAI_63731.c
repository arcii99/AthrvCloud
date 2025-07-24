//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_METADATA_LENGTH 100

void extract_metadata(char *filename);

int main()
{
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);

    extract_metadata(filename);

    return 0;
}

void extract_metadata(char *filename)
{
    FILE *fp;
    char metadata[MAX_METADATA_LENGTH];
    
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    else
    {
        fseek(fp, 0, SEEK_END);
        long file_size = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        
        int bytes_to_read = file_size > MAX_METADATA_LENGTH ? MAX_METADATA_LENGTH : (int)file_size;
        
        fread(metadata, bytes_to_read, 1, fp);
        
        printf("Extracted Metadata from file: %s\n", filename);
        printf("%s\n", metadata);
        
        fclose(fp);
    }
}