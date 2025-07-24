//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000
#define MAX_FILENAME_LENGTH 100

// Function declarations
int scan_file(char *filename, char *virus_signature);
int is_virus_signature(char *buffer, char *virus_signature);

int main()
{
    char filename[MAX_FILENAME_LENGTH];
    char virus_signature[MAX_SIZE];

    printf("Enter the filename to scan: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);

    // Remove newline character from filename
    filename[strcspn(filename, "\n")] = '\0';

    printf("Enter virus signature: ");
    fgets(virus_signature, MAX_SIZE, stdin);

    // Remove newline character from virus signature
    virus_signature[strcspn(virus_signature, "\n")] = '\0';

    if(scan_file(filename, virus_signature))
    {
        printf("File is infected with virus\n");
    }
    else
    {
        printf("File is not infected with virus\n");
    }

    return 0;
}

/**
 * Scans a given file for a virus signature
 *
 * @param filename - The path to the file to scan
 * @param virus_signature - The virus signature to look for
 * @return 1 if virus signature is found, 0 otherwise
 */
int scan_file(char *filename, char *virus_signature)
{
    FILE *file = fopen(filename, "rb");

    if(file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // Determine file size
    fseek(file, 0, SEEK_END);
    long int file_size = ftell(file);
    rewind(file);

    char *buffer = (char *) malloc(file_size);
    fread(buffer, sizeof(char), file_size, file);

    int result = is_virus_signature(buffer, virus_signature);

    fclose(file);
    free(buffer);

    return result;
}

/**
 * Determines if a given buffer contains a virus signature
 *
 * @param buffer - The buffer to search through
 * @param virus_signature - The virus signature to look for
 * @return 1 if virus signature is found, 0 otherwise
 */
int is_virus_signature(char *buffer, char *virus_signature)
{
    int virus_signature_length = strlen(virus_signature);
    int buffer_length = strlen(buffer);

    for(int i = 0; i <= buffer_length - virus_signature_length; i++)
    {
        if(strncmp(buffer + i, virus_signature, virus_signature_length) == 0)
        {
            return 1;
        }
    }

    return 0;
}