//FormAI DATASET v1.0 Category: File Backup System ; Style: invasive
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
    // Create a timestamp for the backup file name
    time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);
    char timestamp[20];
    strftime(timestamp, 20, "%Y-%m-%d_%H-%M-%S", local_time);

    // Create names for the original and backup files
    char original_file[] = "example.txt";
    char backup_file[50];
    sprintf(backup_file, "backup_%s.txt", timestamp);

    // Open the original file for reading
    FILE *f_original = fopen(original_file, "r");
    if (f_original == NULL)
    {
        printf("Error opening original file.\n");
        return 1;
    }

    // Create the backup file for writing
    FILE *f_backup = fopen(backup_file, "w");
    if (f_backup == NULL)
    {
        printf("Error creating backup file.\n");
        fclose(f_original);
        return 1;
    }

    // Copy data from the original file to the backup file
    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), f_original)) > 0)
    {
        fwrite(buffer, 1, bytes_read, f_backup);
    }

    // Close the files
    fclose(f_original);
    fclose(f_backup);

    // Print a success message
    printf("Backup successful! Original file: %s, Backup file: %s\n", original_file, backup_file);

    return 0;
}