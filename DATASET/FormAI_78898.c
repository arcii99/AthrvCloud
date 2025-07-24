//FormAI DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_BACKUP_COUNT 5

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    time_t last_modified;
} FileData;

typedef struct {
    FileData files[MAX_BACKUP_COUNT];
    int count;
} BackupData;

BackupData createBackupData() {
    BackupData backup;
    backup.count = 0;
    return backup;
}

int getFileIndexInBackup(BackupData backup, char* filename) {
    for(int i=0; i<backup.count; i++) {
        if(strcmp(backup.files[i].filename, filename)==0) {
            return i;
        }
    }
    return -1;
}

void deleteFile(char* filename) {
    remove(filename);
}

void saveBackup(char* filename, BackupData backup) {
    FILE* file = fopen(filename, "wb");
    fwrite(&backup.count, sizeof(int), 1, file);
    for(int i=0; i<backup.count; i++) {
        fwrite(&backup.files[i], sizeof(FileData), 1, file);
    }
    fclose(file);
}

BackupData loadBackup(char* filename) {
    BackupData backup = createBackupData();
    FILE* file = fopen(filename, "rb");
    if(file) {
        fread(&backup.count, sizeof(int), 1, file);
        for(int i=0; i<backup.count; i++) {
            fread(&backup.files[i], sizeof(FileData), 1, file);
        }
        fclose(file);
    }
    return backup;
}

void addFileToBackup(BackupData* backup, char* filename) {
    int index = getFileIndexInBackup(*backup, filename);
    if(index!=-1) {
        deleteFile(filename);
        return;
    }
    if(backup->count==MAX_BACKUP_COUNT) {
        deleteFile(backup->files[0].filename);
        for(int i=0; i<backup->count-1; i++) {
            backup->files[i] = backup->files[i+1];
        }
        index = backup->count-1;
    } else {
        index = backup->count++;
    }
    strcpy(backup->files[index].filename, filename);
    backup->files[index].last_modified = time(NULL);
}

int main() {
    char* filename = "backup.bin";
    char* file1 = "file1.txt";
    char* file2 = "file2.txt";
    BackupData backup = createBackupData();

    addFileToBackup(&backup, file1);
    addFileToBackup(&backup, file2);

    backup = loadBackup(filename);
    addFileToBackup(&backup, file2);
    addFileToBackup(&backup, "file3.txt");
    addFileToBackup(&backup, "file4.txt");
    saveBackup(filename, backup);

    backup = loadBackup(filename);
    for(int i=0; i<backup.count; i++) {
        printf("%s - %d\n", backup.files[i].filename, (int)backup.files[i].last_modified);
    }

    return 0;
}