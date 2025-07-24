//FormAI DATASET v1.0 Category: File Backup System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_CONTENT_LENGTH 1000

typedef struct {
    char file_name[MAX_FILENAME_LENGTH];
    char file_contents[MAX_FILE_CONTENT_LENGTH];
} File;

typedef struct {
    int size;
    File *files;
    char backup_dir[MAX_FILENAME_LENGTH];
} BackupSystem;

void display_menu() {
    printf("\n---------MENU---------\n");
    printf("1. Add a new file to backup system\n");
    printf("2. Remove a file from backup system\n");
    printf("3. Display all files in backup system\n");
    printf("4. Backup all files to backup directory\n");
    printf("5. Exit\n");
    printf("-----------------------\n");
}

void add_file(BackupSystem *backup_system) {
    if (backup_system->size == 0) {
        backup_system->files = (File*) malloc(sizeof(File));
    } else {
        backup_system->files = (File*) realloc(backup_system->files, (backup_system->size + 1) * sizeof(File));
    }

    printf("Enter file name: ");
    scanf("%s", backup_system->files[backup_system->size].file_name);

    printf("Enter file contents: ");
    scanf("%s", backup_system->files[backup_system->size].file_contents);

    backup_system->size++;
}

void remove_file(BackupSystem *backup_system) {
    char file_name[MAX_FILENAME_LENGTH];
    printf("Enter the name of the file you want to remove: ");
    scanf("%s", file_name);

    int found_index = -1;
    for (int i = 0; i < backup_system->size; i++) {
        if (strcmp(backup_system->files[i].file_name, file_name) == 0) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("File not found in backup system.\n");
    } else {
        printf("Deleting file '%s' from backup system.\n", file_name);
        for (int i = found_index; i < backup_system->size - 1; i++) {
            backup_system->files[i] = backup_system->files[i + 1];
        }
        backup_system->size--;
        backup_system->files = (File*) realloc(backup_system->files, backup_system->size * sizeof(File));
    }
}

void display_files(BackupSystem *backup_system) {
    printf("Files in backup system:\n");
    for (int i = 0; i < backup_system->size; i++) {
        printf("%s\n", backup_system->files[i].file_name);
    }
}

void backup_files(BackupSystem *backup_system) {
    char command[MAX_FILE_CONTENT_LENGTH];
    sprintf(command, "mkdir %s", backup_system->backup_dir);
    system(command);

    for (int i = 0; i < backup_system->size; i++) {
        char file_location[MAX_FILE_CONTENT_LENGTH];
        sprintf(file_location, "%s/%s", backup_system->backup_dir, backup_system->files[i].file_name);

        FILE *fp = fopen(file_location, "w");
        if (fp == NULL) {
            printf("Error opening file!\n");
            exit(1);
        }

        fprintf(fp, "%s", backup_system->files[i].file_contents);

        fclose(fp);
    }

    printf("Backup complete!\n");
}

int main() {
    BackupSystem backup_system;
    backup_system.size = 0;
    strcpy(backup_system.backup_dir, "backup");

    while (1) {
        display_menu();

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_file(&backup_system);
                break;
            case 2:
                remove_file(&backup_system);
                break;
            case 3:
                display_files(&backup_system);
                break;
            case 4:
                backup_files(&backup_system);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}