//FormAI DATASET v1.0 Category: File Backup System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_PATH_LENGTH 100
#define MAX_BACKUPS_ALLOWED 10

typedef struct File {
    char filename[MAX_FILENAME_LENGTH];
    char path[MAX_FILE_PATH_LENGTH];
} File;

typedef struct Backup {
    File file;
    char timestamp[20];
} Backup;

typedef struct BackupList {
    Backup backups[MAX_BACKUPS_ALLOWED];
    int count;
} BackupList;

void create_backup(File file, BackupList* backupList) {
    if (backupList->count >= MAX_BACKUPS_ALLOWED) {
        printf("Maximum number of backups reached.\n");
        return;
    }
    
    Backup backup = {
        .file = file
    };
    time_t t = time(NULL);
    strftime(backup.timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&t));
    
    backupList->backups[backupList->count++] = backup;
    
    printf("Backup created successfully.\n");
}

void show_backup_details(Backup backup) {
    printf("%s\nFilename: %s\nPath: %s\nTimestamp: %s\n\n", "Backup Details", backup.file.filename, backup.file.path, backup.timestamp);
}

void show_all_backups(BackupList backupList) {
    if (backupList.count == 0) {
        printf("No backups found.\n");
        return;
    }
    
    for (int i = 0; i < backupList.count; i++) {
        show_backup_details(backupList.backups[i]);
    }
}

int main() {
    File file1 = {
        .filename = "file1.txt",
        .path = "/home/user1/documents/"
    };
    
    BackupList backupList = {
        .count = 0
    };
    
    create_backup(file1, &backupList);
    
    show_all_backups(backupList);
    
    return 0;
}