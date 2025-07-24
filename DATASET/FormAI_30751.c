//FormAI DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void backup(char* filename) {
    char backup_name[100];
    time_t current_time = time(NULL);
    strftime(backup_name, sizeof(backup_name), "%Y%m%d%H%M%S_", localtime(&current_time));
    strcat(backup_name, filename);
    strcat(backup_name, ".backup");
    
    FILE* original_file = fopen(filename, "r");
    FILE* backup_file = fopen(backup_name, "w");
    
    if(original_file == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        return;
    }
    
    if(backup_file == NULL) {
        printf("Error: Failed to create backup file %s\n", backup_name);
        return;
    }
    
    char* buffer[1000];
    int read_size = 0;
    
    while((read_size = fread(buffer, sizeof(char), sizeof(buffer), original_file)) > 0) {
        fwrite(buffer, sizeof(char), read_size, backup_file);
    }
    
    printf("Success: Backup of %s created\n", filename);
    
    fclose(original_file);
    fclose(backup_file);
}

int main() {
    char filename[100];
    printf("Enter the file name to backup: ");
    scanf("%s", filename);
    backup(filename);
    return 0;
}