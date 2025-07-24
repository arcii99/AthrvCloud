//FormAI DATASET v1.0 Category: File Backup System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_SIZE 100
#define MAX_BACKUP_COUNT 5

typedef struct {
    char filename[MAX_FILENAME_LENGTH + 1];
    char data[MAX_FILE_SIZE + 1];
} File;

typedef struct {
    File files[MAX_BACKUP_COUNT];
    int count;
} Backup;

Backup backups[MAX_BACKUP_COUNT];
int backup_count = 0;

void backup_file(char* filename, char* data) {
    // Create a new backup
    Backup new_backup;
    new_backup.count = 1;
    strcpy(new_backup.files[0].filename, filename);
    strcpy(new_backup.files[0].data, data);

    // Add the backup to the collection
    if (backup_count < MAX_BACKUP_COUNT) {
        backups[backup_count++] = new_backup;
    } else {
        // We have reached the maximum number of backups.
        // Shift all backups to make room for the new backup
        for (int i = 0; i < backup_count - 1; i++) {
            backups[i] = backups[i + 1];
        }
        backups[backup_count - 1] = new_backup;
    }
}

void print_backups() {
    printf("Total Backups: %d\n", backup_count);
    for (int i = 0; i < backup_count; i++) {
        printf("Backup #%d:\n", i + 1);
        Backup backup = backups[i];
        printf("Total Files: %d\n", backup.count);
        for (int j = 0; j < backup.count; j++) {
            printf("File #%d:\n", j + 1);
            File file = backup.files[j];
            printf("Filename: %s\n", file.filename);
            printf("Data:\n%s\n", file.data);
        }
    }
}

int main() {
    // Define some sample files
    char file1[] = "Hello, world!";
    char file2[] = "Goodbye, world!";
    char file3[] = "Medieval backups are the best!";

    // Backup the files
    backup_file("file1.txt", file1);
    backup_file("file2.txt", file2);
    backup_file("file3.txt", file3);

    // Print the backups
    print_backups();

    return 0;
}