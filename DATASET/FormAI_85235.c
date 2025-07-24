//FormAI DATASET v1.0 Category: File Backup System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_FILENAME_LENGTH 50

// Define data structure to store file names
typedef struct {
    char filename[MAX_FILENAME_LENGTH];
} file_t;

int main()
{
    int num_files;
    file_t files[MAX_LINES];

    printf("Enter the number of files you want to backup: ");
    scanf("%d", &num_files);

    // Read in file names
    printf("Enter the file names:\n");
    for (int i = 0; i < num_files; i++) {
        scanf("%s", files[i].filename);
    }

    // Open backup file for writing
    FILE *backup_file = fopen("backup.txt", "w");
    if (backup_file == NULL) {
        printf("Error: Could not open backup file for writing.\n");
        return 1;
    }

    // Write file names to backup file
    for (int i = 0; i < num_files; i++) {
        fprintf(backup_file, "%s\n", files[i].filename);
    }

    // Close backup file
    fclose(backup_file);

    printf("Backup successful! Backup file created: backup.txt\n");

    return 0;
}