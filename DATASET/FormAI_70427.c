//FormAI DATASET v1.0 Category: File Backup System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define BUFFER_SIZE 1024

void backup(char* source_path, char* backup_path) {
    char command[BUFFER_SIZE];
    sprintf(command, "cp -r %s %s", source_path, backup_path);
    system(command);
}

int main() {
    char source_path[BUFFER_SIZE];
    char backup_path[BUFFER_SIZE];

    printf("Enter the source file/directory path: ");
    fgets(source_path, BUFFER_SIZE, stdin);
    source_path[strcspn(source_path, "\n")] = '\0';

    printf("Enter the backup directory path: ");
    fgets(backup_path, BUFFER_SIZE, stdin);
    backup_path[strcspn(backup_path, "\n")] = '\0';

    DIR* dir = opendir(source_path);

    if (dir == NULL) {
        printf("Error: Invalid directory path.");
        exit(EXIT_FAILURE);
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
            continue;
        }
        
        char file_path[BUFFER_SIZE];
        sprintf(file_path, "%s/%s", source_path, entry->d_name);

        backup(file_path, backup_path);
    }
    
    printf("Backup complete!");
    return 0;
}