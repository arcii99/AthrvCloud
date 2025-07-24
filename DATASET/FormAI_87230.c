//FormAI DATASET v1.0 Category: File Backup System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BACKUPS 100

/* Define a struct to hold backup information */
typedef struct Backup {
    char filename[MAX_FILENAME_LENGTH];
    char timestamp[20];
} Backup;

/* Declare global variables for current backup index and array of backups */
int current_backup_index = 0;
Backup backups[MAX_BACKUPS];

/* Declare function prototypes */
void create_backup(char* filename);
void list_backups();
void delete_backup(int backup_index);

int main() {
    char command[10];
    char filename[MAX_FILENAME_LENGTH];

    // Read user commands until they exit
    while (true) {
        printf("Enter a command (create, list, delete, exit):\n");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            printf("Enter a filename to backup:\n");
            scanf("%s", filename);
            create_backup(filename);
        } else if (strcmp(command, "list") == 0) {
            list_backups();
        } else if (strcmp(command, "delete") == 0) {
            int backup_index;
            printf("Enter the index of the backup to delete:\n");
            scanf("%d", &backup_index);
            delete_backup(backup_index);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting program.\n");
            return 0;
        } else {
            printf("Invalid command.\n");
        }
    }
}

/* Create a backup of the specified file */
void create_backup(char* filename) {
    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file \"%s\"\n", filename);
        return;
    }

    // Generate a timestamp string
    time_t current_time;
    current_time = time(NULL);
    char timestamp[20];
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&current_time));

    // Check if there is already a backup with the same filename and timestamp
    for (int i = 0; i < current_backup_index; i++) {
        if (strcmp(filename, backups[i].filename) == 0 &&
                strcmp(timestamp, backups[i].timestamp) == 0) {
            printf("Backup already exists for \"%s\" with timestamp \"%s\"\n",
                   filename, timestamp);
            fclose(file);
            return;
        }
    }

    // Create a new backup
    Backup backup;
    strncpy(backup.filename, filename, MAX_FILENAME_LENGTH);
    strncpy(backup.timestamp, timestamp, 20);
    backups[current_backup_index++] = backup;

    // Backup the file
    char backup_filename[MAX_FILENAME_LENGTH + 20];
    snprintf(backup_filename, MAX_FILENAME_LENGTH + 20, "%s.%s.bak",
             filename, timestamp);
    FILE *backup_file = fopen(backup_filename, "w");
    if (!backup_file) {
        printf("Error: could not create backup file \"%s\"\n", backup_filename);
        fclose(file);
        return;
    }

    int c;
    while ((c = fgetc(file)) != EOF) {
        fputc(c, backup_file);
    }

    printf("Created backup \"%s\" on %s\n", filename, timestamp);

    // Close file handles
    fclose(backup_file);
    fclose(file);
}

/* List all backups */
void list_backups() {
    if (current_backup_index == 0) {
        printf("No backups found.\n");
        return;
    }

    printf("Backups:\n");
    for (int i = 0; i < current_backup_index; i++) {
        printf("%d. \"%s.%s.bak\" (%s)\n", i+1, backups[i].filename,
               backups[i].timestamp, (i == current_backup_index-1) ? "(current)" : "");
    }
}

/* Delete a backup with the specified index */
void delete_backup(int backup_index) {
    if (backup_index < 1 || backup_index > current_backup_index) {
        printf("Invalid backup index.\n");
        return;
    }

    Backup backup_to_delete = backups[backup_index-1];
    char backup_filename[MAX_FILENAME_LENGTH + 20];
    snprintf(backup_filename, MAX_FILENAME_LENGTH + 20, "%s.%s.bak",
             backup_to_delete.filename, backup_to_delete.timestamp);
    if (remove(backup_filename) != 0) {
        printf("Error: could not delete backup \"%s\".\n", backup_filename);
        return;
    }

    for (int i = backup_index-1; i < current_backup_index-1; i++) {
        backups[i] = backups[i+1];
    }
    current_backup_index--;

    printf("Deleted backup \"%s.%s.bak\"\n", backup_to_delete.filename,
           backup_to_delete.timestamp);
}