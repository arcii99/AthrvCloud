//FormAI DATASET v1.0 Category: File Backup System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILE_SIZE 1048576 // 1 MB

// function to backup a file
void backup_file(char* filename) {
    char backup_filename[MAX_FILENAME_LENGTH];
    memset(backup_filename, 0, MAX_FILENAME_LENGTH);
    strncpy(backup_filename, filename, MAX_FILENAME_LENGTH - 5); // copy filename into backup_filename
    strncat(backup_filename, ".bak", 4); // append .bak to the end of backup_filename
    
    FILE* fptr = fopen(filename, "rb"); // open file in read binary mode
    if (fptr == NULL) {
        printf("Failed to open %s\n", filename);
        return;
    }
    
    FILE* backup_fptr = fopen(backup_filename, "wb"); // open backup file in write binary mode
    if (backup_fptr == NULL) {
        printf("Failed to create backup file %s\n", backup_filename);
        fclose(fptr);
        return;
    }
    
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, fptr); // read file content into buffer
    if (bytes_read > 0) {
        fwrite(buffer, sizeof(char), bytes_read, backup_fptr); // write buffer content into backup file
        printf("Successfully backed up %s to %s\n", filename, backup_filename);
    } else {
        printf("Failed to backup %s\n", filename);
    }
    
    fclose(fptr);
    fclose(backup_fptr);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the file name: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0'; // remove '\n' from filename
    }
    backup_file(filename);
    return 0;
}