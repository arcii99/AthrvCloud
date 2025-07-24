//FormAI DATASET v1.0 Category: File Backup System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

int main() {
    char source_filename[MAX_FILENAME_LENGTH];
    char backup_filename[MAX_FILENAME_LENGTH];
    FILE *source_file = NULL;
    FILE *backup_file = NULL;

    printf("\nWelcome to the Unique C File Backup System Example Program!\n");

    printf("\nEnter the name of the file to backup: ");
    scanf("%s", source_filename);

    printf("\nEnter the name for the backup file: ");
    scanf("%s", backup_filename);

    source_file = fopen(source_filename, "r");
    if (source_file == NULL) {
        printf("\nError: Could not open file %s.\n", source_filename);
        return 1;
    }

    backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL) {
        printf("\nError: Could not open file %s.\n", backup_filename);
        fclose(source_file);
        return 1;
    }

    printf("\nBacking up file %s as %s.\n", source_filename, backup_filename);

    char buffer[1024];
    size_t bytes_read = 0;
    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), source_file))) {
        fwrite(buffer, sizeof(char), bytes_read, backup_file);
    }

    printf("\nFile backup complete!\n");

    fclose(source_file);
    fclose(backup_file);

    return 0;
}