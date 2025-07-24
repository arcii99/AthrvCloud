//FormAI DATASET v1.0 Category: File Backup System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_NUM_FILES 100

// Struct to hold file information
typedef struct {
    char name[MAX_FILENAME_LENGTH];
    size_t size;
    char created_at[20];
} File;

// Function to backup files
void backup_files(File files[], int num_files) {
    // Create backup file name with timestamp
    time_t current_time;
    time(&current_time);
    char backup_filename[MAX_FILENAME_LENGTH + 15]; // Add 15 for timestamp
    strftime(backup_filename, sizeof backup_filename, "backup_%Y-%m-%d_%H-%M-%S.dat", localtime(&current_time));

    // Open backup file for writing
    FILE* backup_file = fopen(backup_filename, "wb");
    if (backup_file == NULL) {
        perror("Error creating backup file");
        exit(EXIT_FAILURE);
    }

    // Write number of files as first element of backup file
    fwrite(&num_files, sizeof num_files, 1, backup_file);

    // Write each file to backup file in order
    for (int i = 0; i < num_files; i++) {
        // Write name length and name string
        size_t filename_len = strlen(files[i].name) + 1; // Add 1 for null terminator
        fwrite(&filename_len, sizeof filename_len, 1, backup_file);
        fwrite(files[i].name, filename_len, 1, backup_file);

        // Write file size
        fwrite(&files[i].size, sizeof files[i].size, 1, backup_file);

        // Write creation timestamp length and timestamp string
        size_t timestamp_len = strlen(files[i].created_at) + 1; // Add 1 for null terminator
        fwrite(&timestamp_len, sizeof timestamp_len, 1, backup_file);
        fwrite(files[i].created_at, timestamp_len, 1, backup_file);
    }

    fclose(backup_file);
}

// Function to create new file with random data
File create_new_file() {
    // Generate random file size between 1 and 100 MB
    size_t size = rand() % 100000000 + 1;

    // Create new file struct with random name and size
    File file;
    sprintf(file.name, "file%d", rand() % 1000);
    file.size = size;

    // Create creation timestamp string
    time_t current_time;
    time(&current_time);
    strftime(file.created_at, sizeof file.created_at, "%Y-%m-%d %H:%M:%S", localtime(&current_time));
    
    return file;
}

int main() {
    srand(time(NULL)); // Seed random generator with current time

    // Create array of new files
    File files[MAX_NUM_FILES];
    int num_files = rand() % MAX_NUM_FILES + 1; // Generate random number of files between 1 and MAX_NUM_FILES
    for (int i = 0; i < num_files; i++) {
        files[i] = create_new_file();
    }

    // Backup files to disk
    backup_files(files, num_files);

    printf("Backup successful. %d files backed up to disk.\n", num_files);

    return 0;
}