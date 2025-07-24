//FormAI DATASET v1.0 Category: File Backup System ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILE_NAME_LEN 100

// Structure to store backup file details
struct backup_file {
    char file_name[FILE_NAME_LEN];
    int file_size;
    char* file_contents;
};

// Function to backup a file
void backup_file(char* file_name) {
    // Open file in read mode
    FILE* file = fopen(file_name, "r");
    
    // If file doesn't exist or cannot be opened
    if (file == NULL) {
        printf("File '%s' does not exist or cannot be opened!", file_name);
        return;
    }
    
    // Get file size
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);
    
    // Allocate memory to store file contents
    char* file_contents = (char*) malloc(file_size + 1);
    
    // Read file contents
    fread(file_contents, 1, file_size, file);
    file_contents[file_size] = '\0';
    
    // Close file
    fclose(file);
    
    // Create backup file with timestamp
    time_t current_time = time(NULL);
    char backup_file_name[FILE_NAME_LEN];
    snprintf(backup_file_name, FILE_NAME_LEN, "%s_%ld", file_name, current_time);
    
    // Save backup file
    FILE* backup_file = fopen(backup_file_name, "w");
    fwrite(file_contents, 1, file_size, backup_file);
    fclose(backup_file);
    
    // Free memory allocated for file contents
    free(file_contents);
    
    printf("Backup of file '%s' created as '%s'\n", file_name, backup_file_name);
}

int main() {
    char file_name[FILE_NAME_LEN];
    
    printf("Enter file to backup: ");
    scanf("%s", file_name);
    
    backup_file(file_name);
    
    return 0;
}