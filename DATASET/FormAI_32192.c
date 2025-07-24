//FormAI DATASET v1.0 Category: File Backup System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILENAME 30
#define MAX_FILES 10

typedef struct {
    char filename[MAX_FILENAME];
    char data[100];
} File;

typedef struct {
    File files[MAX_FILES];
    int count;
} Backup;

Backup* backup;

int main(){
    int option;
    backup = (Backup*) malloc(sizeof(Backup));
    backup->count = 0;
    printf("Welcome to File Backup System. What would you like to do?\n");
    do {
        printf("1. Create backup\n");
        printf("2. Restore backup\n");
        printf("3. Show all backups\n");
        printf("4. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                createBackup();
                break;
            case 2:
                restoreBackup();
                break;
            case 3:
                showBackups();
                break;
            case 4:
                break;
            default:
                printf("Invalid option\n");
        }
    } while (option != 4);
}

void createBackup() {
    if (backup->count == MAX_FILES) {
        printf("Maximum number of files reached\n");
        return;
    }
    printf("Enter filename to backup: ");
    char filename[MAX_FILENAME];
    scanf("%s", filename);
    File file;
    strcpy(file.filename, filename);
    FILE * fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found\n");
        return;
    }
    fgets(file.data, 100, (FILE*)fp);
    fclose(fp);
    backup->files[backup->count] = file;
    backup->count++;
    printf("Backup created successfully\n");
}

void restoreBackup() {
    if (backup->count == 0) {
        printf("No backups available\n");
        return;
    }
    printf("Enter index of backup to restore: ");
    int index;
    scanf("%d", &index);
    if (index < 0 || index >= backup->count) {
        printf("Invalid index\n");
        return;
    }
    File file = backup->files[index];
    FILE * fp;
    fp = fopen(file.filename, "w");
    if (fp == NULL) {
        printf("Error restoring backup\n");
        return;
    }
    fputs(file.data, fp);
    fclose(fp);
    printf("Backup restored successfully\n");
}

void showBackups() {
    if (backup->count == 0) {
        printf("No backups available\n");
        return;
    }
    printf("Current backups:\n");
    for (int i = 0; i < backup->count; i++) {
        printf("%d. %s\n", i, backup->files[i].filename);
    }
}