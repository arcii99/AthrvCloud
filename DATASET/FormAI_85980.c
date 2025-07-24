//FormAI DATASET v1.0 Category: File Backup System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 // Maximum file size in KB
#define MAX_BACKUPS 10 // Maximum number of backups to keep

typedef struct {
    char filename[20];
    int size;
    char data[MAX_FILE_SIZE];
} File;

File create_file(char* filename) {
    File file;
    strcpy(file.filename, filename);
    file.size = 0;
    file.data[0] = '\0';
    return file;
}

void save_file(File file) {
    // Create backup filename
    char backup_filename[30];
    sprintf(backup_filename, "%s.bak", file.filename);

    // Open backup file in write mode
    FILE* backup_file = fopen(backup_filename, "w");

    // Write file data to backup file
    fwrite(file.data, sizeof(char), file.size, backup_file);

    // Close backup file
    fclose(backup_file);

    // Delete oldest backup if there are too many backups
    char oldest_backup_filename[30];
    sprintf(oldest_backup_filename, "%s.bak%d", file.filename, MAX_BACKUPS);
    remove(oldest_backup_filename);

    // Shift backup files up by 1 index
    for (int i = MAX_BACKUPS - 1; i > 0; i--) {
        char old_filename[30];
        sprintf(old_filename, "%s.bak%d", file.filename, i - 1);

        char new_filename[30];
        sprintf(new_filename, "%s.bak%d", file.filename, i);

        rename(old_filename, new_filename);
    }

    // Rename current file as backup 1
    rename(file.filename, backup_filename);

    // Re-create current file
    FILE* new_file = fopen(file.filename, "w");
    fclose(new_file);
}

void main() {
    // Create test file
    File file = create_file("test.txt");

    // Write data to file
    strcpy(file.data, "Hello, world!");
    file.size = strlen(file.data);

    // Save file
    save_file(file);

    // Read oldest backup
    char oldest_backup_filename[30];
    sprintf(oldest_backup_filename, "%s.bak%d", file.filename, MAX_BACKUPS);
    FILE* oldest_backup_file = fopen(oldest_backup_filename, "r");

    int oldest_backup_size;
    char oldest_backup_data[MAX_FILE_SIZE];

    fseek(oldest_backup_file, 0, SEEK_END);
    oldest_backup_size = ftell(oldest_backup_file);
    fseek(oldest_backup_file, 0, SEEK_SET);

    fread(oldest_backup_data, sizeof(char), oldest_backup_size, oldest_backup_file);
    fclose(oldest_backup_file);

    printf("%s\n", oldest_backup_data);
}