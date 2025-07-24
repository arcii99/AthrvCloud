//FormAI DATASET v1.0 Category: File Backup System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME_LEN 50
#define MAX_FILE_COUNT 10

// Struct to represent a backup file
typedef struct {
    char filename[MAX_FILENAME_LEN];
    bool exists;
} BackupFile;

// Struct to represent the backup system
typedef struct {
    BackupFile files[MAX_FILE_COUNT];
    int file_count;
} BackupSystem;

// Function to initialize the backup system
void init_backup_system(BackupSystem *system) {
    memset(system->files, 0, sizeof(system->files));
    system->file_count = 0;
}

// Function to add a file to the backup system
bool add_file_to_backup(BackupSystem *system, const char *filename) {
    // Check if file already exists in backup
    for (int i = 0; i < system->file_count; i++) {
        if (strcmp(system->files[i].filename, filename) == 0) {
            fprintf(stderr, "Error: File '%s' already exists in backup.\n", filename);
            return false;
        }
    }
    
    // Check if backup system is full
    if (system->file_count >= MAX_FILE_COUNT) {
        fprintf(stderr, "Error: Backup system is full. Cannot add file '%s'.\n", filename);
        return false;
    }
    
    // Add file to backup
    BackupFile file = {0};
    strcpy(file.filename, filename);
    file.exists = true;
    system->files[system->file_count++] = file;
    printf("File '%s' added to backup successfully.\n", filename);
    return true;
}

// Function to remove a file from the backup system
bool remove_file_from_backup(BackupSystem *system, const char *filename) {
    // Find file in backup
    int file_index = -1;
    for (int i = 0; i < system->file_count; i++) {
        if (strcmp(system->files[i].filename, filename) == 0) {
            file_index = i;
            break;
        }
    }
    
    // Check if file exists in backup
    if (file_index == -1) {
        fprintf(stderr, "Error: File '%s' does not exist in backup.\n", filename);
        return false;
    }
    
    // Remove file from backup
    system->files[file_index].exists = false;
    printf("File '%s' removed from backup successfully.\n", filename);
    return true;
}

// Function to list all files in the backup system
void list_backup_files(BackupSystem *system) {
    printf("Backup system contains the following files:\n");
    for (int i = 0; i < system->file_count; i++) {
        if (system->files[i].exists) {
            printf("- %s\n", system->files[i].filename);
        }
    }
}

// Main function to test backup system
int main() {
    BackupSystem system;
    init_backup_system(&system);
    
    add_file_to_backup(&system, "foo.txt");
    add_file_to_backup(&system, "bar.txt");
    add_file_to_backup(&system, "baz.txt");
    
    list_backup_files(&system);
    
    remove_file_from_backup(&system, "bar.txt");
    
    list_backup_files(&system);
    
    add_file_to_backup(&system, "qux.txt");
    add_file_to_backup(&system, "quux.txt");
    add_file_to_backup(&system, "corge.txt");
    
    list_backup_files(&system);
    
    return 0;
}