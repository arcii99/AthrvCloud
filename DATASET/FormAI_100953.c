//FormAI DATASET v1.0 Category: File Backup System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BACKUP_COUNT 10
#define MAX_BACKUP_FILE_SIZE 1024 * 1024 * 10 // 10 MB
#define BACKUP_DIRECTORY "./backups/"

int backup_count = 0;

char* create_backup_filename(const char* filename) {
    char* backup_filename = (char*)malloc(MAX_FILENAME_LENGTH);

    time_t current_time = time(NULL);
    struct tm* local_time = localtime(&current_time);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d_%H%M%S", local_time);

    sprintf(backup_filename, "%s%s_%s.bak", BACKUP_DIRECTORY, filename, timestamp);

    return backup_filename;
}

void backup_file(const char* filename) {
    FILE* original_file = fopen(filename, "r");

    if (original_file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char* backup_filename = create_backup_filename(filename);

    FILE* backup_file = fopen(backup_filename, "w");

    if (backup_file == NULL) {
        printf("Error: Could not create backup file %s\n", backup_filename);
        fclose(original_file);
        free(backup_filename);
        return;
    }

    char buffer[MAX_BACKUP_FILE_SIZE];
    size_t read_size = fread(buffer, 1, MAX_BACKUP_FILE_SIZE - 1, original_file);
    buffer[read_size] = '\0';

    fwrite(buffer, read_size, 1, backup_file);

    fclose(original_file);
    fclose(backup_file);

    printf("Backup Successful: %s -> %s\n", filename, backup_filename);
    free(backup_filename);

    backup_count++;

    if (backup_count > MAX_BACKUP_COUNT) {
        printf("Warning: Maximum backup count exceeded. Removing oldest backup.\n");

        char oldest_backup_filename[MAX_FILENAME_LENGTH];
        sprintf(oldest_backup_filename, "%s%s_*.bak", BACKUP_DIRECTORY, filename);

        system(oldest_backup_filename);

        backup_count--;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];

    backup_file(filename);

    return 0;
}