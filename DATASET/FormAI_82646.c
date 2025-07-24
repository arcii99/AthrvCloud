//FormAI DATASET v1.0 Category: File Backup System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_BACKUPS_PER_FILE 10

typedef struct FileBackupSystem {
    char filename[MAX_FILENAME_LENGTH];
    char backups[MAX_BACKUPS_PER_FILE][MAX_FILENAME_LENGTH];
    int num_backups;
} FileBackupSystem;

void add_backup(FileBackupSystem* fbs, char* backup_name) {
    if (fbs->num_backups == MAX_BACKUPS_PER_FILE) {
        printf("Maximum number of backups reached!\n");
        return;
    }

    strcpy(fbs->backups[fbs->num_backups], backup_name);
    fbs->num_backups++;
}

void delete_backup(FileBackupSystem* fbs, int backup_index) {
    if (backup_index >= fbs->num_backups) {
        printf("Invalid backup index!\n");
        return;
    }

    for (int i = backup_index; i < fbs->num_backups - 1; i++) {
        strcpy(fbs->backups[i], fbs->backups[i+1]);
    }

    fbs->num_backups--;
}

void print_backups(FileBackupSystem* fbs) {
    printf("Backups for %s:\n", fbs->filename);

    for (int i = 0; i < fbs->num_backups; i++) {
        printf("%d. %s\n", i+1, fbs->backups[i]);
    }
}

int main() {
    FileBackupSystem fbs;
    strcpy(fbs.filename, "example.txt");
    fbs.num_backups = 0;

    add_backup(&fbs, "example_backup_1.txt");
    add_backup(&fbs, "example_backup_2.txt");
    add_backup(&fbs, "example_backup_3.txt");
    print_backups(&fbs);

    delete_backup(&fbs, 1);
    print_backups(&fbs);

    return 0;
}