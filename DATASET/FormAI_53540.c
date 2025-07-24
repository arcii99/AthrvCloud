//FormAI DATASET v1.0 Category: File Backup System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BACKUP_LENGTH 10
#define FILE_EXTENSION ".bak"

int main()
{
    // Declare variables
    char filename[MAX_FILENAME_LENGTH];
    char backup_name[MAX_FILENAME_LENGTH + sizeof(FILE_EXTENSION) + 1];
    char *current_time;
    int backup_counter = 1;
    int max_backups = MAX_BACKUP_LENGTH;
    FILE *source_file, *backup_file;

    // Get the filename from the user
    printf("Enter a filename to backup: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);

    // Remove newline from filename
    filename[strcspn(filename, "\n")] = 0;

    // Build backup name with current time and backup number
    current_time = __TIME__;  // Use current time as part of backup name
    strcpy(backup_name, filename);
    strcat(backup_name, "_");
    strcat(backup_name, current_time);
    strcat(backup_name, FILE_EXTENSION);

    // Check if backup already exists. If it does, add a number to the filename
    while (max_backups--)
    {
        backup_file = fopen(backup_name, "r");
        if (backup_file != NULL )
        {
            fclose(backup_file);
            backup_counter++;
            sprintf(backup_name, "%s_%s%d%s", filename,
                    current_time, backup_counter, FILE_EXTENSION);
        }
        else
        {
            backup_file = fopen(backup_name, "w");

            if (backup_file != NULL )
            {
                // Backup the file
                source_file = fopen(filename, "r");
                if (source_file != NULL )
                {
                    int c;
                    while ((c = fgetc(source_file)) != EOF)
                    {
                        fputc(c, backup_file);
                    }
                    fclose(source_file);
                    fclose(backup_file);
                    printf("Backup successful: %s\n", backup_name);
                    break;
                }
                else
                {
                    printf("Error: Failed to backup file %s\n", filename);
                }
            }
            else
            {
                printf("Error: Failed to create backup file %s\n", backup_name);
            }
        }
    }

    return EXIT_SUCCESS;
}