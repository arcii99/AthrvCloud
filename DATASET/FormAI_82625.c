//FormAI DATASET v1.0 Category: File Backup System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 50

int main()
{
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the name of the file to backup: ");
    scanf("%s", filename);

    FILE* original_file = fopen(filename, "r");
    if (original_file == NULL)
    {
        printf("Error opening file %s! Please try again.\n", filename);
        return 1;
    }

    char backup_filename[MAX_FILENAME_LENGTH + 10];
    sprintf(backup_filename, "%s.bak", filename);

    FILE* backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL)
    {
        printf("Error creating backup file %s!\n", backup_filename);
        fclose(original_file);
        return 1;
    }

    printf("Backing up %s to %s...\n", filename, backup_filename);

    char buffer;
    while (fread(&buffer, sizeof(char), 1, original_file) == 1)
    {
        fwrite(&buffer, sizeof(char), 1, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);

    printf("Backup complete! %s has been backed up to %s.\n", filename, backup_filename);

    return 0;
}