//FormAI DATASET v1.0 Category: File Backup System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void backup(char* file_name) {
    // Get current time
    time_t current_time = time(NULL);
    char time_string[64];
    strftime(time_string, sizeof(time_string), "%Y-%m-%d_%H-%M-%S", localtime(&current_time));
    
    // Create backup file name
    char backup_name[256];
    sprintf(backup_name, "%s_%s.bak", file_name, time_string);
    
    // Open files
    FILE* source_file = fopen(file_name, "r");
    FILE* backup_file = fopen(backup_name, "w");
    
    // Copy contents of source file to backup file
    char buffer[4096];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }
    
    // Close files
    fclose(source_file);
    fclose(backup_file);
    
    printf("Backup created: %s\n", backup_name);
}

int main() {
    // Test backup function
    backup("example.c");
    
    return 0;
}