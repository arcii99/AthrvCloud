//FormAI DATASET v1.0 Category: File Backup System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAMES 100
#define MAX_FILENAME_LENGTH 64
#define MAX_BACKUP_COUNT 5
#define MAX_FILE_SIZE 2048

typedef struct {
    char filenames[MAX_FILENAMES][MAX_FILENAME_LENGTH];
    int current_backup_count[MAX_FILENAMES];
    char backup_contents[MAX_FILENAMES][MAX_BACKUP_COUNT][MAX_FILE_SIZE];
} BackupSystem;

void backup_file(BackupSystem *backup_system, char *filename, char *file_content) {
    int i;
    int file_index = -1;
    for(i = 0; i < MAX_FILENAMES; i++) {
        if(strcmp(backup_system->filenames[i], filename) == 0) {
            file_index = i;
            break;
        }
    }

    if(file_index == -1) {
        for(i = 0; i < MAX_FILENAMES; i++) {
            if(strlen(backup_system->filenames[i]) == 0) {
                file_index = i;
                break;
            }
        }
    }

    if(file_index == -1) {
        printf("Could not backup file. Maximum file backup limit reached.\n");
        return;
    }

    int backup_index = backup_system->current_backup_count[file_index];

    strcpy(backup_system->filenames[file_index], filename);
    strcpy(backup_system->backup_contents[file_index][backup_index], file_content);
    backup_system->current_backup_count[file_index]++;
    printf("File backed up: %s\n", filename);
}

void recover_file(BackupSystem *backup_system, char *filename, int backup_index) {
    int i;
    int file_index = -1;
    for(i = 0; i < MAX_FILENAMES; i++) {
        if(strcmp(backup_system->filenames[i], filename) == 0) {
            file_index = i;
            break;
        }
    }

    if(file_index == -1) {
        printf("Could not find file: %s\n", filename);
        return;
    }

    if(backup_index >= backup_system->current_backup_count[file_index]) {
        printf("Invalid backup index: %d\n", backup_index);
        return;
    }

    printf("Contents of file %s at backup %d: %s\n", filename, backup_index, backup_system->backup_contents[file_index][backup_index]);
}

int main() {
    BackupSystem backup_system;
    memset(&backup_system, 0, sizeof(BackupSystem));

    backup_file(&backup_system, "testfile1.txt", "Some example file content.");
    backup_file(&backup_system, "testfile2.txt", "Some more example file content.");

    recover_file(&backup_system, "testfile1.txt", 0);
    recover_file(&backup_system, "testfile2.txt", 0);

    backup_file(&backup_system, "testfile2.txt", "Updated file content.");

    recover_file(&backup_system, "testfile1.txt", 1);
    recover_file(&backup_system, "testfile2.txt", 1);

    return 0;
}