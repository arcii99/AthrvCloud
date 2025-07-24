//FormAI DATASET v1.0 Category: File Backup System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME 50 // Maximum filename length
#define MAX_PATH 100 // Maximum file path length
#define MAX_BACKUPS 5 // Maximum number of backups for each file

// Struct to represent a backup file
typedef struct {
    char filename[MAX_FILENAME];
    char path[MAX_PATH];
    time_t timestamp;
} Backup;

// Function to print a backup file's details
void print_backup(Backup backup) {
    printf("Filename:\t%s\n", backup.filename);
    printf("Path:\t\t%s\n", backup.path);
    printf("Timestamp:\t%s\n", ctime(&backup.timestamp));
}

int main() {
    // Initialize backup directory path
    char backup_dir[MAX_PATH] = "/home/user/backup/";

    // Create backups for 3 different files
    for (int i = 1; i <= 3; i++) {
        char filename[MAX_FILENAME];
        sprintf(filename, "file%d.txt", i); // Generate filename based on loop index

        // Create backup filenames based on timestamp
        char backup_filenames[MAX_BACKUPS][MAX_FILENAME];
        time_t current_time = time(NULL);
        for (int j = 0; j < MAX_BACKUPS; j++) {
            sprintf(backup_filenames[j], "%s_%d_%d.txt", filename, j+1, (int)current_time);
        }

        // Create backup files
        Backup backups[MAX_BACKUPS];
        for (int j = 0; j < MAX_BACKUPS; j++) {
            Backup backup;
            strcpy(backup.filename, backup_filenames[j]);
            strcpy(backup.path, strcat(backup_dir, backup_filenames[j]));
            backup.timestamp = current_time;
            backups[j] = backup;

            // Print backup details
            printf("Backup %d of %s:\n", j+1, filename);
            print_backup(backup);
        }
    }

    return 0;
}