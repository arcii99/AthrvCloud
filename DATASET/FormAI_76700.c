//FormAI DATASET v1.0 Category: File Backup System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main()
{
    char file_name[100], backup_file_name[100], buffer[BUFFER_SIZE];
    FILE *file_ptr, *backup_file_ptr;
    int read_size;

    printf("Welcome to the C File Backup System!\n\n");

    printf("Please enter the name of the file you would like to backup: ");
    scanf("%s", file_name);

    printf("Please enter the name to save the backup file as: ");
    scanf("%s", backup_file_name);

    file_ptr = fopen(file_name, "r");
    if (file_ptr == NULL)
    {
        printf("Error opening file %s\n", file_name);
        return 1;
    }

    backup_file_ptr = fopen(backup_file_name, "w");
    if (backup_file_ptr == NULL)
    {
        printf("Error opening backup file %s\n", backup_file_name);
        fclose(file_ptr);
        return 1;
    }

    printf("Backing up file %s as %s...\n", file_name, backup_file_name);

    while ((read_size = fread(buffer, 1, BUFFER_SIZE, file_ptr)) > 0)
    {
        fwrite(buffer, 1, read_size, backup_file_ptr);
    }

    fclose(file_ptr);
    fclose(backup_file_ptr);

    printf("Backup successful! Your file has been backed up as %s\n", backup_file_name);

    return 0;
}