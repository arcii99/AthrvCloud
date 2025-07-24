//FormAI DATASET v1.0 Category: File Backup System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

int main()
{
    char filename[MAX_FILENAME_LENGTH];
    char backupFilename[MAX_FILENAME_LENGTH];
    char command[MAX_FILENAME_LENGTH + 15];

    // Get filename from user
    printf("Enter filename to backup: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);

    // Remove newline character from filename
    filename[strcspn(filename, "\n")] = 0;

    // Generate backup filename
    sprintf(backupFilename, "%s_backup.txt", filename);

    // Construct backup command
    sprintf(command, "cp %s %s", filename, backupFilename);

    // Execute backup command
    if (system(command) == 0)
    {
        printf("Backup completed successfully!\n");
    }
    else
    {
        printf("Backup failed.\n");
    }

    return 0;
}