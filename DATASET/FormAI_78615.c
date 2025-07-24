//FormAI DATASET v1.0 Category: File Backup System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 10
#define FILENAME_LENGTH 20

void backup(char *filename);

int main() {
    char filenames[MAX_FILES][FILENAME_LENGTH] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt",
                                                   "file6.txt", "file7.txt", "file8.txt", "file9.txt", "file10.txt"};
    srand(time(0)); // Set the random seed based on the current time

    printf("Starting file backup system...\n");

    // Loop through all the filenames and backup each one
    for (int i = 0; i < MAX_FILES; i++) {
        printf("Backing up %s...\n", filenames[i]);
        backup(filenames[i]);
    }

    printf("File backup system complete.\n");

    return 0;
}

void backup(char *filename) {
    char backup_name[FILENAME_LENGTH + 10]; // Add 10 characters to account for time string and "-backup.txt"
    char backup_string[1000];

    // Create backup file name with current time
    time_t current_time = time(NULL);
    strftime(backup_name, FILENAME_LENGTH + 10, "%Y%m%d%H%M%S-backup.txt", localtime(&current_time));

    // Copy contents of file into backup_string
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s.\n", filename);
        return;
    }
    fgets(backup_string, 1000, file);
    fclose(file);

    // Write backup string to backup file
    FILE *backup_file = fopen(backup_name, "w");
    if (backup_file == NULL) {
        printf("Error creating backup file %s.\n", backup_name);
        return;
    }
    fputs(backup_string, backup_file);
    fclose(backup_file);

    printf("%s successfully backed up as %s.\n", filename, backup_name);
}