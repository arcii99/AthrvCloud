//FormAI DATASET v1.0 Category: File Backup System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BACKUP_COUNT 10

/*
 * Our backup system will operate on a single directory, which will be
 * specified via the command line.
 *
 * On each run, the backup system will create a new directory inside the
 * specified directory, called "backup-<timestamp>", where <timestamp> is
 * the current date/time in YYYY-MM-DD-HH-MM-SS format.
 *
 * When backing up a file, the backup system will copy the file to the
 * new backup directory, but with a ".bak" extension on the filename.
 *
 * The backup system will keep track of the last 10 backups made, and
 * delete the oldest backup if there are more than 10.
 */

// Struct for holding backup information
typedef struct {
    char timestamp[20];
    char filename[MAX_FILENAME_LENGTH];
} BackupInfo;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: backup-system <directory>\n");
        return 1;
    }

    char *backup_dir = argv[1];

    // Generate timestamp for new backup directory
    time_t current_time;
    struct tm *time_info;
    char timestamp[20];
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d-%H-%M-%S", time_info);

    // Create new backup directory
    char backup_path[MAX_FILENAME_LENGTH + 20];
    sprintf(backup_path, "%s/backup-%s", backup_dir, timestamp);
    mkdir(backup_path, 0700);

    // Get list of files in directory
    char command[MAX_FILENAME_LENGTH + 10];
    sprintf(command, "ls %s", backup_dir);
    FILE *pipe = popen(command, "r");

    // Read each line of output and backup each file
    char filename[MAX_FILENAME_LENGTH];
    BackupInfo backups[MAX_BACKUP_COUNT];
    int backup_count = 0;
    while (fgets(filename, sizeof(filename), pipe)) {
        // Remove newline character from filename
        char *newline_ptr = strchr(filename, '\n');
        *newline_ptr = '\0';

        // Backup file
        char backup_filename[MAX_FILENAME_LENGTH + 4];
        sprintf(backup_filename, "%s/%s.bak", backup_path, filename);
        sprintf(command, "cp %s/%s %s", backup_dir, filename, backup_filename);
        system(command);

        // Add backup info to array
        BackupInfo backup_info;
        strcpy(backup_info.timestamp, timestamp);
        strcpy(backup_info.filename, filename);
        backups[backup_count++] = backup_info;

        // Delete oldest backup if over limit
        if (backup_count > MAX_BACKUP_COUNT) {
            BackupInfo oldest_backup = backups[0];
            for (int i = 1; i < backup_count; i++) {
                if (strcmp(backups[i].timestamp, oldest_backup.timestamp) < 0) {
                    oldest_backup = backups[i];
                }
            }
            char oldest_backup_path[MAX_FILENAME_LENGTH + 20];
            sprintf(oldest_backup_path, "%s/backup-%s", backup_dir, oldest_backup.timestamp);
            sprintf(command, "rm -rf %s", oldest_backup_path);
            system(command);
            backup_count--;
        }
    }

    fclose(pipe);
    return 0;
}