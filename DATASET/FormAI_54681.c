//FormAI DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_SIZE 1000000 // 1MB
#define MAX_BACKUPS_PER_FILE 10

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char backup_files[MAX_BACKUPS_PER_FILE][MAX_FILENAME_LENGTH];
    int num_backups;
    time_t last_updated;
} File;

void backup_file(File* file) {
    // check if there are already MAX_BACKUPS_PER_FILE backups
    if (file->num_backups == MAX_BACKUPS_PER_FILE) {
        // remove the oldest backup file
        remove(file->backup_files[0]);
        // shift the other backup files up by one
        for (int i = 1; i < MAX_BACKUPS_PER_FILE; i++) {
            strcpy(file->backup_files[i-1], file->backup_files[i]);
        }
        // add the new backup file to the end of the array
        char new_backup_file[MAX_FILENAME_LENGTH];
        sprintf(new_backup_file, "%s.%ld", file->filename, file->last_updated);
        strcpy(file->backup_files[MAX_BACKUPS_PER_FILE-1], new_backup_file);
        file->num_backups = MAX_BACKUPS_PER_FILE;
    } else {
        // add a new backup file to the end of the array
        char new_backup_file[MAX_FILENAME_LENGTH];
        sprintf(new_backup_file, "%s.%ld", file->filename, file->last_updated);
        strcpy(file->backup_files[file->num_backups], new_backup_file);
        file->num_backups++;
    }
    // copy the original file to the new backup file
    FILE* original = fopen(file->filename, "r");
    FILE* backup = fopen(file->backup_files[file->num_backups-1], "w");
    char buffer[MAX_FILE_SIZE];
    while (fgets(buffer, MAX_FILE_SIZE, original)) {
        fputs(buffer, backup);
    }
    fclose(original);
    fclose(backup);
}

int main() {
    // create a new file object for a hypothetical C file called "example.c"
    File example;
    strcpy(example.filename, "example.c");
    example.num_backups = 0;
    example.last_updated = time(NULL);

    // backup the file
    backup_file(&example);

    return 0;
}