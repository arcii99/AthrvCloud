//FormAI DATASET v1.0 Category: File Backup System ; Style: artistic
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define BACKUP_DIR "backup/"

bool createBackup(char *filename) {
    char backup_file[100], command[100];
    sprintf(backup_file, "%s%s.bak", BACKUP_DIR, filename);

    // Check if file exists
    FILE *fptr = fopen(filename, "rb");
    if (fptr == NULL) {
        printf("File %s does not exist!\n", filename);
        return false;
    }
    fclose(fptr);

    // Check if backup directory exists, if not create it
    fptr = fopen(backup_file, "wb");
    if (fptr == NULL) {
        printf("Error creating backup file %s\n", backup_file);
        return false;
    }
    fclose(fptr);

    // Copy file to backup directory
    sprintf(command, "cp %s %s", filename, backup_file);
    system(command);

    printf("Backup created for %s\n", filename);
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char backup_file[100];
    sprintf(backup_file, "%s%s.bak", BACKUP_DIR, filename);

    // Check if backup exists
    FILE *fptr = fopen(backup_file, "rb");
    if (fptr == NULL) {
        printf("Backup not found for %s, creating backup...\n", filename);
        bool success = createBackup(filename);
        if (!success) {
            printf("Failed to create backup for %s\n", filename);
            return 1;
        }
    } else {
        fclose(fptr);
        printf("Backup found for %s\n", filename);
    }

    printf("Program completed successfully!\n");
    return 0;
}