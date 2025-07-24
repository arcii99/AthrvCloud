//FormAI DATASET v1.0 Category: File Backup System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILESIZE_IN_MB 500

// Function to backup a file
char* backup_file(char* filename) {
    // Create a new string for the backup filename
    char* backup_filename = (char*) malloc((MAX_FILENAME_LENGTH+7) * sizeof(char));
    sprintf(backup_filename, "%s_backup", filename);

    // Open the original file for binary reading
    FILE* original_file = fopen(filename, "rb");
    if (!original_file) {
        printf("Error: Could not open file %s for backup.\n", filename);
        return NULL;
    }

    // Create a new file for the backup file
    FILE* backup_file = fopen(backup_filename, "wb");
    if (!backup_file) {
        printf("Error: Could not create backup file %s.\n", backup_filename);
        return NULL;
    }

    // Allocate memory for the file data
    int file_size = 0;
    fseek(original_file, 0L, SEEK_END);
    file_size = ftell(original_file);
    rewind(original_file);

    if (file_size > MAX_FILESIZE_IN_MB * 1024 * 1024) {
        printf("Error: File size is too large for backup. Maximum file size is %d MB.\n", MAX_FILESIZE_IN_MB);
        return NULL;
    }

    char* file_data = (char*) malloc(file_size * sizeof(char));

    // Read the file data into the buffer
    fread(file_data, sizeof(char), file_size, original_file);

    // Write the backup data to the file
    fwrite(file_data, sizeof(char), file_size, backup_file);

    // Close the files and free the memory
    fclose(original_file);
    fclose(backup_file);
    free(file_data);

    return backup_filename;
}

int main() {
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter the name of the file to backup: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove the newline character from the filename string

    char* backup_filename = backup_file(filename);

    if (backup_filename) {
        printf("Backup of %s succeeded. Backup file: %s\n", filename, backup_filename);
        free(backup_filename);
    }

    return 0;
}