//FormAI DATASET v1.0 Category: File Synchronizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define FILE_NAME_LEN 128

void synchronize_files(char *source_file_name, char *destination_file_name);

int main(void)
{
    char source_file_name[FILE_NAME_LEN];
    char destination_file_name[FILE_NAME_LEN];

    printf("Enter source file name: ");
    scanf("%s", source_file_name);

    printf("Enter destination file name: ");
    scanf("%s", destination_file_name);

    synchronize_files(source_file_name, destination_file_name);

    printf("File synchronization complete\n");

    return 0;
}

void synchronize_files(char *source_file_name, char *destination_file_name)
{
    FILE *source_file = fopen(source_file_name, "rb");
    FILE *destination_file = fopen(destination_file_name, "wb");

    if (source_file == NULL || destination_file == NULL)
    {
        printf("Could not open file\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    size_t read_bytes;

    while ((read_bytes = fread(buffer, 1, BUFFER_SIZE, source_file)) != 0)
    {
        fwrite(buffer, 1, read_bytes, destination_file);
    }

    fclose(source_file);
    fclose(destination_file);
}