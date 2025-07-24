//FormAI DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    FILE *source_file, *target_file;
    char buffer[BUFFER_SIZE];

    if(argc != 3)
    {
        printf("Usage: %s <source_file> <target_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    source_file = fopen(argv[1], "r");

    if(source_file == NULL)
    {
        printf("Error: Unable to open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    target_file = fopen(argv[2], "w");

    if(target_file == NULL)
    {
        printf("Error: Unable to open %s\n", argv[2]);
        fclose(source_file);
        exit(EXIT_FAILURE);
    }

    while(fgets(buffer, BUFFER_SIZE, source_file) != NULL)
    {
        fputs(buffer, target_file);
        memset(buffer, 0, BUFFER_SIZE);
    }

    fclose(source_file);
    fclose(target_file);

    printf("File backed up successfully.\n");

    return 0;
}